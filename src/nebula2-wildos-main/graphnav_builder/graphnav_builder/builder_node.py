import heapq
import math
import random
import uuid
from dataclasses import dataclass, field
from typing import Dict, List, Optional, Sequence, Tuple

import rclpy
from geometry_msgs.msg import Point, Pose
from graphnav_msgs.msg import Edge, EdgeTraversability, NavigationGraph, Node, NodeTraversabilityProperties, UUID
from grid_map_msgs.msg import GridMap
from nav_msgs.msg import Odometry
from rclpy.node import Node as RclpyNode
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSProfile, QoSReliabilityPolicy
from std_msgs.msg import Float32MultiArray, MultiArrayDimension
from visualization_msgs.msg import Marker, MarkerArray


Cell = Tuple[int, int]
XY = Tuple[float, float]


@dataclass
class GraphNodeState:
    pose: Pose
    uuid_msg: UUID
    free_radius: float = 0.0
    explored_radius: float = 0.0
    is_frontier: bool = False
    frontier_points: List[Point] = field(default_factory=list)


class TraversabilityGrid:
    UNKNOWN = 0
    FREE = 1
    OBSTACLE = 2

    def __init__(self, msg: GridMap, layer_name: str, safe_threshold: float, observed_layer_name: str = ''):
        if not msg.data:
            raise ValueError('GridMap has no data layers')

        if layer_name and layer_name in msg.layers:
            layer_idx = msg.layers.index(layer_name)
        else:
            layer_idx = 0

        observed_layer_idx = None
        if observed_layer_name:
            if observed_layer_name not in msg.layers:
                raise ValueError(f"GridMap does not contain observed layer '{observed_layer_name}'")
            observed_layer_idx = msg.layers.index(observed_layer_name)

        self.msg = msg
        self.layer_name = msg.layers[layer_idx] if layer_idx < len(msg.layers) else layer_name
        self.resolution = float(msg.info.resolution)
        self.length_x = float(msg.info.length_x)
        self.length_y = float(msg.info.length_y)
        self.center_x = float(msg.info.pose.position.x)
        self.center_y = float(msg.info.pose.position.y)
        self.origin_x = self.center_x - 0.5 * self.length_x
        self.origin_y = self.center_y - 0.5 * self.length_y
        self.coordinate_mode = 'grid_map'
        self.height, self.width = self.layer_shape(msg.data[layer_idx])
        self.cell_radius = 0.5 * math.sqrt(2.0) * self.resolution

        expected_size = self.width * self.height

        self.values = self.decode_layer(msg.data[layer_idx], self.layer_name, self.height, self.width)
        self.observed_values = (
            self.decode_layer(msg.data[observed_layer_idx], observed_layer_name, self.height, self.width)
            if observed_layer_idx is not None else None
        )
        self.state = [self.UNKNOWN] * expected_size
        self.free_cells: List[Cell] = []
        self.unknown_cells: List[Cell] = []
        self.exterior_unknown_cells: List[Cell] = []
        self.obstacle_cells: List[Cell] = []

        for row in range(self.height):
            for col in range(self.width):
                value = self.value_at_cell((row, col))
                idx = self.flat_index((row, col))
                observed = True
                if self.observed_values is not None:
                    observed = math.isfinite(self.observed_values[idx])

                if not observed or not math.isfinite(value):
                    self.state[idx] = self.UNKNOWN
                    self.unknown_cells.append((row, col))
                elif value >= safe_threshold:
                    self.state[idx] = self.FREE
                    self.free_cells.append((row, col))
                else:
                    self.state[idx] = self.OBSTACLE
                    self.obstacle_cells.append((row, col))

        self.exterior_unknown_cells = self.find_exterior_unknown_cells()

    def flat_index(self, cell: Cell) -> int:
        row, col = cell
        return row * self.width + col

    @staticmethod
    def layer_shape(array_msg: Float32MultiArray) -> Tuple[int, int]:
        dims = array_msg.layout.dim
        if len(dims) >= 2 and dims[0].label == 'column_index' and dims[1].label == 'row_index':
            return max(1, dims[1].size), max(1, dims[0].size)
        if len(dims) >= 2 and dims[0].label == 'row_index' and dims[1].label == 'column_index':
            return max(1, dims[0].size), max(1, dims[1].size)
        size = int(math.sqrt(len(array_msg.data))) if array_msg.data else 1
        return max(1, size), max(1, size)

    @staticmethod
    def decode_layer(array_msg: Float32MultiArray, name: str, rows: int, cols: int) -> List[float]:
        data = list(array_msg.data)
        expected = rows * cols
        dims = array_msg.layout.dim
        if not dims:
            if len(data) < expected:
                data.extend([float('nan')] * (expected - len(data)))
            return data[:expected]

        label0 = dims[0].label if len(dims) > 0 else ''
        label1 = dims[1].label if len(dims) > 1 else ''

        if len(dims) >= 2 and label0 == 'column_index' and label1 == 'row_index':
            layer_cols = dims[0].size or cols
            layer_rows = dims[1].size or rows
            return TraversabilityGrid.remap_column_major(data, layer_rows, layer_cols, rows, cols)

        if len(dims) >= 2 and label0 == 'row_index' and label1 == 'column_index':
            layer_rows = dims[0].size or rows
            layer_cols = dims[1].size or cols
            return TraversabilityGrid.remap_row_major(data, layer_rows, layer_cols, rows, cols)

        if len(data) < expected:
            data.extend([float('nan')] * (expected - len(data)))
        return data[:expected]

    @staticmethod
    def remap_column_major(data: List[float], source_rows: int, source_cols: int, rows: int, cols: int) -> List[float]:
        out = [float('nan')] * (rows * cols)
        for col in range(min(source_cols, cols)):
            for row in range(min(source_rows, rows)):
                src_idx = col * source_rows + row
                dst_idx = row * cols + col
                if src_idx < len(data):
                    out[dst_idx] = data[src_idx]
        return out

    @staticmethod
    def remap_row_major(data: List[float], source_rows: int, source_cols: int, rows: int, cols: int) -> List[float]:
        out = [float('nan')] * (rows * cols)
        for row in range(min(source_rows, rows)):
            for col in range(min(source_cols, cols)):
                src_idx = row * source_cols + col
                dst_idx = row * cols + col
                if src_idx < len(data):
                    out[dst_idx] = data[src_idx]
        return out

    def value_at_cell(self, cell: Cell) -> float:
        return self.values[self.flat_index(cell)]

    def state_at_cell(self, cell: Cell) -> int:
        return self.state[self.flat_index(cell)]

    def in_bounds_cell(self, cell: Cell) -> bool:
        row, col = cell
        return 0 <= row < self.height and 0 <= col < self.width

    def in_bounds_xy(self, xy: XY) -> bool:
        cell = self.xy_to_cell(xy)
        return cell is not None

    def xy_to_cell(self, xy: XY) -> Optional[Cell]:
        x, y = xy
        if self.coordinate_mode == 'grid_map':
            row = int(math.floor((self.center_x + 0.5 * self.length_x - x) / self.resolution))
            col = int(math.floor((self.center_y + 0.5 * self.length_y - y) / self.resolution))
        else:
            col = int(math.floor((x - self.origin_x) / self.resolution))
            row = int(math.floor((y - self.origin_y) / self.resolution))
        cell = (row, col)
        return cell if self.in_bounds_cell(cell) else None

    def cell_to_xy(self, cell: Cell) -> XY:
        row, col = cell
        if self.coordinate_mode == 'grid_map':
            return (
                self.center_x + 0.5 * self.length_x - (row + 0.5) * self.resolution,
                self.center_y + 0.5 * self.length_y - (col + 0.5) * self.resolution,
            )
        return (
            self.origin_x + (col + 0.5) * self.resolution,
            self.origin_y + (row + 0.5) * self.resolution,
        )

    def is_free(self, cell: Cell) -> bool:
        return self.in_bounds_cell(cell) and self.state_at_cell(cell) == self.FREE

    def is_known(self, cell: Cell) -> bool:
        return self.in_bounds_cell(cell) and self.state_at_cell(cell) in (self.FREE, self.OBSTACLE)

    def boundary_between_free_and_unknown(self, free_cells: Optional[Sequence[Cell]] = None) -> List[Cell]:
        exterior_unknown = {self.flat_index(cell) for cell in self.exterior_unknown_cells}
        frontiers = []
        candidates = free_cells if free_cells is not None else self.free_cells
        for cell in candidates:
            for neighbor in self.neighbors8(cell):
                if self.in_bounds_cell(neighbor) and self.flat_index(neighbor) in exterior_unknown:
                    frontiers.append(cell)
                    break
        return frontiers

    def unknown_frontier_cells_next_to_free(self, free_cells: Optional[Sequence[Cell]] = None) -> List[Tuple[Cell, Cell]]:
        exterior_unknown = {self.flat_index(cell) for cell in self.exterior_unknown_cells}
        frontiers: List[Tuple[Cell, Cell]] = []
        seen_unknown = set()
        candidates = free_cells if free_cells is not None else self.free_cells
        for free_cell in candidates:
            for neighbor in self.neighbors8(free_cell):
                if not self.in_bounds_cell(neighbor):
                    continue
                neighbor_idx = self.flat_index(neighbor)
                if neighbor_idx not in exterior_unknown or neighbor_idx in seen_unknown:
                    continue
                seen_unknown.add(neighbor_idx)
                frontiers.append((neighbor, free_cell))
        return frontiers

    def filter_frontier_clusters(
        self,
        frontiers: Sequence[Tuple[Cell, Cell]],
        min_cluster_size: int,
    ) -> List[Tuple[Cell, Cell]]:
        if min_cluster_size <= 1 or not frontiers:
            return list(frontiers)

        free_side_by_frontier = {frontier_cell: free_side_cell for frontier_cell, free_side_cell in frontiers}
        remaining = set(free_side_by_frontier.keys())
        filtered: List[Tuple[Cell, Cell]] = []

        while remaining:
            seed = remaining.pop()
            cluster = [seed]
            stack = [seed]
            while stack:
                cell = stack.pop()
                for neighbor in self.neighbors8(cell):
                    if neighbor not in remaining:
                        continue
                    remaining.remove(neighbor)
                    stack.append(neighbor)
                    cluster.append(neighbor)

            if len(cluster) >= min_cluster_size:
                filtered.extend((cell, free_side_by_frontier[cell]) for cell in cluster)

        return filtered

    def reachable_free_cells(self, seed_xy: Optional[XY]) -> List[Cell]:
        if seed_xy is None or not self.free_cells:
            return list(self.free_cells)

        seed = self.xy_to_cell(seed_xy)
        if seed is None or not self.is_free(seed):
            seed = min(
                self.free_cells,
                key=lambda cell: math.hypot(self.cell_to_xy(cell)[0] - seed_xy[0], self.cell_to_xy(cell)[1] - seed_xy[1]),
            )

        visited = [False] * (self.width * self.height)
        reachable: List[Cell] = []
        queue = [seed]
        head = 0

        while head < len(queue):
            cell = queue[head]
            head += 1
            if not self.is_free(cell):
                continue
            idx = self.flat_index(cell)
            if visited[idx]:
                continue

            visited[idx] = True
            reachable.append(cell)
            for neighbor in self.neighbors8(cell):
                if self.in_bounds_cell(neighbor) and not visited[self.flat_index(neighbor)] and self.is_free(neighbor):
                    queue.append(neighbor)

        return reachable

    def find_exterior_unknown_cells(self) -> List[Cell]:
        visited = [False] * (self.width * self.height)
        queue: List[Cell] = []

        for col in range(self.width):
            queue.append((0, col))
            queue.append((self.height - 1, col))
        for row in range(self.height):
            queue.append((row, 0))
            queue.append((row, self.width - 1))

        exterior = []
        head = 0
        while head < len(queue):
            cell = queue[head]
            head += 1
            if not self.in_bounds_cell(cell):
                continue
            idx = self.flat_index(cell)
            if visited[idx] or self.state[idx] != self.UNKNOWN:
                continue

            visited[idx] = True
            exterior.append(cell)
            for neighbor in self.neighbors8(cell):
                if self.in_bounds_cell(neighbor) and not visited[self.flat_index(neighbor)]:
                    queue.append(neighbor)

        return exterior

    def neighbors8(self, cell: Cell) -> Sequence[Cell]:
        row, col = cell
        return (
            (row - 1, col - 1), (row - 1, col), (row - 1, col + 1),
            (row, col - 1),                     (row, col + 1),
            (row + 1, col - 1), (row + 1, col), (row + 1, col + 1),
        )

    def line_cells(self, start: XY, end: XY) -> Optional[List[Cell]]:
        start_cell = self.xy_to_cell(start)
        end_cell = self.xy_to_cell(end)
        if start_cell is None or end_cell is None:
            return None

        r0, c0 = start_cell
        r1, c1 = end_cell
        dr = abs(r1 - r0)
        dc = abs(c1 - c0)
        step_r = 1 if r0 < r1 else -1
        step_c = 1 if c0 < c1 else -1
        cells = []

        if dc > dr:
            err = dc / 2
            row = r0
            for col in range(c0, c1 + step_c, step_c):
                cells.append((row, col))
                err -= dr
                if err < 0:
                    row += step_r
                    err += dc
        else:
            err = dr / 2
            col = c0
            for row in range(r0, r1 + step_r, step_r):
                cells.append((row, col))
                err -= dc
                if err < 0:
                    col += step_c
                    err += dr
        return cells

    def collision_free(self, start: XY, end: XY) -> bool:
        cells = self.line_cells(start, end)
        if cells is None:
            return False
        return all(self.is_free(cell) for cell in cells)

    def clearance_collision_free(
        self,
        start: XY,
        end: XY,
        sdf_unknown: Sequence[float],
        sdf_obstacle: Sequence[float],
        clearance: float,
    ) -> bool:
        cells = self.line_cells(start, end)
        if cells is None:
            return False

        for cell in cells:
            if not self.is_free(cell):
                return False
            idx = self.flat_index(cell)
            if self.clearance_from_fields(idx, sdf_unknown, sdf_obstacle) <= clearance:
                return False
        return True

    def contradicted_by_obstacle(
        self,
        start: XY,
        end: XY,
        sdf_obstacle: Sequence[float],
        clearance: float,
    ) -> bool:
        cells = self.line_cells(start, end)
        if cells is None:
            return False

        for cell in cells:
            idx = self.flat_index(cell)
            if self.state[idx] == self.OBSTACLE:
                return True
            if self.state[idx] == self.FREE and self.distance_to_cell_boundary(sdf_obstacle[idx]) <= clearance:
                return True
        return False

    def distance_to_cell_boundary(self, distance_to_cell_center: float) -> float:
        if not math.isfinite(distance_to_cell_center):
            return math.inf
        return max(0.0, distance_to_cell_center - self.cell_radius)

    def clearance_from_fields(
        self,
        idx: int,
        sdf_unknown: Sequence[float],
        sdf_obstacle: Sequence[float],
    ) -> float:
        return min(
            self.distance_to_cell_boundary(sdf_unknown[idx]),
            self.distance_to_cell_boundary(sdf_obstacle[idx]),
        )

    def distance_field(self, targets: Sequence[Cell]) -> List[float]:
        distances = [math.inf] * (self.width * self.height)
        queue: List[Tuple[float, Cell]] = []
        for target in targets:
            if self.in_bounds_cell(target):
                idx = self.flat_index(target)
                distances[idx] = 0.0
                heapq.heappush(queue, (0.0, target))

        neighbor_steps = (
            (-1, 0, 1.0), (1, 0, 1.0), (0, -1, 1.0), (0, 1, 1.0),
            (-1, -1, math.sqrt(2.0)), (-1, 1, math.sqrt(2.0)),
            (1, -1, math.sqrt(2.0)), (1, 1, math.sqrt(2.0)),
        )
        while queue:
            current_dist, (row, col) = heapq.heappop(queue)
            current_idx = self.flat_index((row, col))
            if current_dist > distances[current_idx]:
                continue
            for drow, dcol, step_cost in neighbor_steps:
                next_cell = (row + drow, col + dcol)
                if not self.in_bounds_cell(next_cell):
                    continue
                candidate = current_dist + step_cost * self.resolution
                next_idx = self.flat_index(next_cell)
                if candidate < distances[next_idx]:
                    distances[next_idx] = candidate
                    heapq.heappush(queue, (candidate, next_cell))
        return distances


class GlobalTraversabilityMemory:
    def __init__(self, resolution: float):
        self.resolution = float(resolution)
        self.cells: Dict[Tuple[int, int], int] = {}
        self.elevation_sums: Dict[Tuple[int, int], float] = {}
        self.elevation_counts: Dict[Tuple[int, int], int] = {}
        self.z = 0.0

    def integrate(self, local_grid: TraversabilityGrid):
        self.z = float(local_grid.msg.info.pose.position.z)
        for row in range(local_grid.height):
            for col in range(local_grid.width):
                state = local_grid.state_at_cell((row, col))
                if state == TraversabilityGrid.UNKNOWN:
                    continue
                idx = local_grid.flat_index((row, col))
                x, y = local_grid.cell_to_xy((row, col))
                global_cell = self.xy_to_global_cell((x, y))
                self.cells[global_cell] = state
                if local_grid.observed_values is not None:
                    elevation = local_grid.observed_values[idx]
                    if math.isfinite(elevation):
                        self.elevation_sums[global_cell] = self.elevation_sums.get(global_cell, 0.0) + elevation
                        self.elevation_counts[global_cell] = self.elevation_counts.get(global_cell, 0) + 1

    def to_grid(self) -> Optional[TraversabilityGrid]:
        if not self.cells:
            return None

        min_gx = min(cell[0] for cell in self.cells) - 1
        max_gx = max(cell[0] for cell in self.cells) + 1
        min_gy = min(cell[1] for cell in self.cells) - 1
        max_gy = max(cell[1] for cell in self.cells) + 1

        width = max_gx - min_gx + 1
        height = max_gy - min_gy + 1

        grid = object.__new__(TraversabilityGrid)
        grid.msg = GridMap()
        grid.msg.info.resolution = self.resolution
        grid.msg.info.length_x = width * self.resolution
        grid.msg.info.length_y = height * self.resolution
        grid.msg.info.pose.position.x = (min_gx + 0.5 * width) * self.resolution
        grid.msg.info.pose.position.y = (min_gy + 0.5 * height) * self.resolution
        grid.msg.info.pose.position.z = self.z
        grid.layer_name = 'global_memory'
        grid.resolution = self.resolution
        grid.length_x = float(grid.msg.info.length_x)
        grid.length_y = float(grid.msg.info.length_y)
        grid.center_x = float(grid.msg.info.pose.position.x)
        grid.center_y = float(grid.msg.info.pose.position.y)
        grid.origin_x = min_gx * self.resolution
        grid.origin_y = min_gy * self.resolution
        grid.coordinate_mode = 'cartesian'
        grid.width = width
        grid.height = height
        grid.cell_radius = 0.5 * math.sqrt(2.0) * self.resolution
        grid.values = [float('nan')] * (width * height)
        grid.elevation_values = [float('nan')] * (width * height)
        grid.observed_values = None
        grid.state = [TraversabilityGrid.UNKNOWN] * (width * height)
        grid.free_cells = []
        grid.unknown_cells = []
        grid.exterior_unknown_cells = []
        grid.obstacle_cells = []

        for (gx, gy), state in self.cells.items():
            row = gy - min_gy
            col = gx - min_gx
            if not grid.in_bounds_cell((row, col)):
                continue
            idx = grid.flat_index((row, col))
            grid.state[idx] = state
            grid.values[idx] = 1.0 if state == TraversabilityGrid.FREE else 0.0
            elevation_count = self.elevation_counts.get((gx, gy), 0)
            if elevation_count > 0:
                grid.elevation_values[idx] = self.elevation_sums[(gx, gy)] / elevation_count
            if state == TraversabilityGrid.FREE:
                grid.free_cells.append((row, col))
            elif state == TraversabilityGrid.OBSTACLE:
                grid.obstacle_cells.append((row, col))

        for row in range(grid.height):
            for col in range(grid.width):
                if grid.state_at_cell((row, col)) == TraversabilityGrid.UNKNOWN:
                    grid.unknown_cells.append((row, col))

        grid.exterior_unknown_cells = grid.find_exterior_unknown_cells()
        return grid

    def xy_to_global_cell(self, xy: XY) -> Tuple[int, int]:
        x, y = xy
        return (
            int(math.floor(x / self.resolution)),
            int(math.floor(y / self.resolution)),
        )

    def global_cell_to_grid_cell(self, grid: TraversabilityGrid, global_cell: Tuple[int, int]) -> Optional[Cell]:
        gx, gy = global_cell
        xy = ((gx + 0.5) * self.resolution, (gy + 0.5) * self.resolution)
        return grid.xy_to_cell(xy)


class SparseGraphBuilderNode(RclpyNode):
    """Implements WildOS Navigation Graph Construction Algorithms 1-5.

    The input grid follows the WildOS paper convention: T_geo in [0, 1],
    where 1 indicates safe terrain and NaN indicates cells without valid
    LiDAR returns, i.e. unknown space.
    """

    def __init__(self):
        super().__init__('graphnav_builder')

        self.declare_parameter('odom_topic', 'odom')
        self.declare_parameter('grid_map_topic', 'traversability_map')
        self.declare_parameter('nav_graph_topic', 'nav_graph')
        self.declare_parameter('traversability_layer', '')
        self.declare_parameter('observed_layer', '')
        self.declare_parameter('trav_class', 'default')
        self.declare_parameter('safe_threshold', 0.5)
        self.declare_parameter('local_map_radius', 10.0)
        self.declare_parameter('local_map_resolution', 0.1)
        self.declare_parameter('max_free_radius', 4.0)
        self.declare_parameter('traversable_radius', 0.35)
        self.declare_parameter('frontier_association_radius', 1.5)
        self.declare_parameter('min_frontier_cluster_size', 5)
        self.declare_parameter('edge_radius', 8.0)
        self.declare_parameter('num_samples', 1000)
        self.declare_parameter('graph_update_min_travel', 0.75)
        self.declare_parameter('graph_update_free_radius_fraction', 0.7)
        self.declare_parameter('grid_map_queue_depth', 1)
        self.declare_parameter('publish_global_memory_markers', True)
        self.declare_parameter('global_memory_marker_topic', 'global_traversability_markers')
        self.declare_parameter('global_memory_marker_stride', 2)
        self.declare_parameter('publish_global_memory_grid', True)
        self.declare_parameter('global_memory_grid_topic', 'global_traversability_grid')
        self.declare_parameter('random_seed', 7)
        self.declare_parameter('min_x', -math.inf)
        self.declare_parameter('max_x', math.inf)
        self.declare_parameter('min_y', -math.inf)
        self.declare_parameter('max_y', math.inf)

        self.odom_topic = self.get_parameter('odom_topic').value
        self.grid_map_topic = self.get_parameter('grid_map_topic').value
        self.nav_graph_topic = self.get_parameter('nav_graph_topic').value
        self.traversability_layer = self.get_parameter('traversability_layer').value
        self.observed_layer = self.get_parameter('observed_layer').value
        self.trav_class = self.get_parameter('trav_class').value
        self.safe_threshold = float(self.get_parameter('safe_threshold').value)
        self.local_map_radius = float(self.get_parameter('local_map_radius').value)
        self.local_map_resolution = float(self.get_parameter('local_map_resolution').value)
        self.max_free_radius = float(self.get_parameter('max_free_radius').value)
        self.traversable_radius = float(self.get_parameter('traversable_radius').value)
        self.frontier_association_radius = float(self.get_parameter('frontier_association_radius').value)
        self.min_frontier_cluster_size = max(1, int(self.get_parameter('min_frontier_cluster_size').value))
        self.edge_radius = float(self.get_parameter('edge_radius').value)
        self.num_samples = int(self.get_parameter('num_samples').value)
        self.graph_update_min_travel = float(self.get_parameter('graph_update_min_travel').value)
        self.graph_update_free_radius_fraction = float(self.get_parameter('graph_update_free_radius_fraction').value)
        self.grid_map_queue_depth = max(1, int(self.get_parameter('grid_map_queue_depth').value))
        self.publish_global_memory_debug = bool(self.get_parameter('publish_global_memory_markers').value)
        self.global_memory_marker_topic = self.get_parameter('global_memory_marker_topic').value
        self.global_memory_marker_stride = max(1, int(self.get_parameter('global_memory_marker_stride').value))
        self.publish_global_memory_grid_debug = bool(self.get_parameter('publish_global_memory_grid').value)
        self.global_memory_grid_topic = self.get_parameter('global_memory_grid_topic').value
        self.random = random.Random(int(self.get_parameter('random_seed').value))
        self.min_x = float(self.get_parameter('min_x').value)
        self.max_x = float(self.get_parameter('max_x').value)
        self.min_y = float(self.get_parameter('min_y').value)
        self.max_y = float(self.get_parameter('max_y').value)

        self.nodes: List[GraphNodeState] = []
        self.edges: set[Tuple[int, int]] = set()
        self.current_node_idx = 0
        self.latest_odom: Optional[Odometry] = None
        self.last_graph_update_pose: Optional[XY] = None
        self.last_graph_update_node_uuid: Optional[Tuple[int, ...]] = None
        self.global_memory = GlobalTraversabilityMemory(self.local_map_resolution)

        self.graph_pub = self.create_publisher(NavigationGraph, self.nav_graph_topic, 10)
        self.global_memory_marker_pub = self.create_publisher(MarkerArray, self.global_memory_marker_topic, 1)
        self.global_memory_grid_pub = self.create_publisher(GridMap, self.global_memory_grid_topic, 1)
        self.odom_sub = self.create_subscription(Odometry, self.odom_topic, self.odom_callback, 20)
        grid_qos = QoSProfile(
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=self.grid_map_queue_depth,
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            durability=QoSDurabilityPolicy.VOLATILE,
        )
        self.grid_sub = self.create_subscription(GridMap, self.grid_map_topic, self.grid_map_callback, grid_qos)

    def odom_callback(self, msg: Odometry):
        self.latest_odom = msg
        self.update_current_node()

    def grid_map_callback(self, msg: GridMap):
        should_update_graph = self.should_update_navigation_graph()
        publish_global_debug = self.publish_global_memory_grid_debug or self.publish_global_memory_debug
        if not should_update_graph and not publish_global_debug:
            self.publish_graph(msg.header.frame_id, msg.header.stamp)
            return

        try:
            grid = TraversabilityGrid(msg, self.traversability_layer, self.safe_threshold, self.observed_layer)
        except ValueError as exc:
            self.get_logger().warn(str(exc))
            return

        if not grid.free_cells and not grid.obstacle_cells:
            self.get_logger().warn('No observed cells in traversability grid; skipping graph update')
            return

        global_grid = None
        if publish_global_debug:
            self.global_memory.integrate(grid)
            global_grid = self.global_memory.to_grid()

        if should_update_graph:
            sdf_unknown = grid.distance_field(grid.unknown_cells)
            sdf_obstacle = grid.distance_field(grid.obstacle_cells)
            robot_xy = self.pose_xy(self.latest_odom.pose.pose) if self.latest_odom is not None else None
            reachable_free_cells = grid.reachable_free_cells(robot_xy)
            self.update_navigation_graph(grid, sdf_unknown, sdf_obstacle, reachable_free_cells)
            self.update_current_node()
            self.remember_graph_update()

        self.publish_graph(msg.header.frame_id, msg.header.stamp)
        if global_grid is not None and global_grid.free_cells:
            self.publish_global_memory_grid(global_grid, msg.header.frame_id, msg.header.stamp)
            self.publish_global_memory_markers(msg.header.frame_id, msg.header.stamp)

    def publish_global_memory_grid(self, grid: TraversabilityGrid, frame_id: str, stamp):
        if not self.publish_global_memory_grid_debug:
            return

        resolution = float(grid.resolution)
        rows = grid.width
        cols = grid.height
        length_x = rows * resolution
        length_y = cols * resolution
        center_x = grid.origin_x + 0.5 * length_x
        center_y = grid.origin_y + 0.5 * length_y

        elevation = []
        traversability = []
        observed = []
        elevation_values = getattr(grid, 'elevation_values', None)

        for row in range(rows):
            x = center_x + 0.5 * length_x - (row + 0.5) * resolution
            for col in range(cols):
                y = center_y + 0.5 * length_y - (col + 0.5) * resolution
                cell = grid.xy_to_cell((x, y))
                state = grid.state_at_cell(cell) if cell is not None else grid.UNKNOWN
                elevation_value = (
                    elevation_values[grid.flat_index(cell)]
                    if cell is not None and elevation_values is not None else float('nan')
                )

                if state == grid.FREE:
                    elevation.append(elevation_value)
                    traversability.append(1.0)
                    observed.append(1.0)
                elif state == grid.OBSTACLE:
                    elevation.append(elevation_value)
                    traversability.append(0.0)
                    observed.append(1.0)
                else:
                    elevation.append(float('nan'))
                    traversability.append(float('nan'))
                    observed.append(float('nan'))

        msg = GridMap()
        msg.header.frame_id = frame_id
        msg.header.stamp = stamp
        msg.info.resolution = resolution
        msg.info.length_x = length_x
        msg.info.length_y = length_y
        msg.info.pose.position.x = center_x
        msg.info.pose.position.y = center_y
        msg.info.pose.position.z = 0.0
        msg.info.pose.orientation.w = 1.0
        msg.layers = ['elevation', 'traversability', 'observed']
        msg.basic_layers = ['elevation']
        msg.data = [
            self.grid_map_layer(elevation, rows, cols),
            self.grid_map_layer(traversability, rows, cols),
            self.grid_map_layer(observed, rows, cols),
        ]
        self.global_memory_grid_pub.publish(msg)

    def publish_global_memory_markers(self, frame_id: str, stamp):
        if not self.publish_global_memory_debug:
            return

        markers = MarkerArray()
        markers.markers.append(self.delete_marker(frame_id, stamp, 'global_traversability'))

        free_points = []
        obstacle_points = []
        stride = self.global_memory_marker_stride
        for (gx, gy), state in self.global_memory.cells.items():
            if stride > 1 and ((gx + gy) % stride) != 0:
                continue
            point = Point()
            point.x = (gx + 0.5) * self.global_memory.resolution
            point.y = (gy + 0.5) * self.global_memory.resolution
            point.z = 0.04
            if state == TraversabilityGrid.FREE:
                free_points.append(point)
            elif state == TraversabilityGrid.OBSTACLE:
                obstacle_points.append(point)

        scale = self.global_memory.resolution * stride
        markers.markers.append(
            self.points_marker(frame_id, stamp, 'global_traversability/free', 1, free_points, scale, 0.0, 0.75, 0.15, 0.35)
        )
        markers.markers.append(
            self.points_marker(frame_id, stamp, 'global_traversability/obstacle', 2, obstacle_points, scale, 1.0, 0.0, 0.0, 0.75)
        )
        self.global_memory_marker_pub.publish(markers)

    def update_current_node(self):
        if self.latest_odom is None or not self.nodes:
            return
        robot_xy = self.pose_xy(self.latest_odom.pose.pose)
        connected_node_indices = {
            idx
            for edge in self.edges
            for idx in edge
        }
        candidates = connected_node_indices if connected_node_indices else range(len(self.nodes))
        self.current_node_idx = min(
            candidates,
            key=lambda idx: self.distance_xy(robot_xy, self.pose_xy(self.nodes[idx].pose)),
        )

    def should_update_navigation_graph(self) -> bool:
        if not self.nodes or self.latest_odom is None:
            return True

        robot_xy = self.pose_xy(self.latest_odom.pose.pose)
        if self.last_graph_update_pose is None or self.last_graph_update_node_uuid is None:
            return True

        current_idx = min(self.current_node_idx, len(self.nodes) - 1)
        current_node = self.nodes[current_idx]
        current_uuid = self.uuid_key(current_node.uuid_msg)
        if current_uuid != self.last_graph_update_node_uuid:
            return True

        if self.distance_xy(robot_xy, self.last_graph_update_pose) >= self.graph_update_min_travel:
            return True

        node_radius = current_node.free_radius
        if math.isfinite(node_radius) and node_radius > 0.0:
            dist_to_node = self.distance_xy(robot_xy, self.pose_xy(current_node.pose))
            if dist_to_node >= self.graph_update_free_radius_fraction * node_radius:
                return True

        return False

    def remember_graph_update(self):
        if self.latest_odom is None or not self.nodes:
            return
        self.last_graph_update_pose = self.pose_xy(self.latest_odom.pose.pose)
        current_idx = min(self.current_node_idx, len(self.nodes) - 1)
        self.last_graph_update_node_uuid = self.uuid_key(self.nodes[current_idx].uuid_msg)

    def update_navigation_graph(
        self,
        grid: TraversabilityGrid,
        sdf_unknown: List[float],
        sdf_obstacle: List[float],
        reachable_free_cells: Sequence[Cell],
    ):
        # Algorithm 1: Update Navigation Graph over the current sensed local map.
        self.update_nodes(grid, sdf_unknown, sdf_obstacle)
        self.sample_new_nodes(grid, sdf_unknown, sdf_obstacle, reachable_free_cells, self.num_samples)
        self.update_frontier_nodes(grid, reachable_free_cells)
        self.prune_invalid_edges(grid, sdf_unknown, sdf_obstacle)
        self.build_edges(grid, sdf_unknown, sdf_obstacle)

    def update_nodes(self, grid: TraversabilityGrid, sdf_unknown: List[float], sdf_obstacle: List[float]):
        # Algorithm 2: Update Nodes. Nodes outside the current local map are kept unchanged.
        valid_nodes: List[GraphNodeState] = []
        index_remap: Dict[int, int] = {}

        for old_idx, node in enumerate(self.nodes):
            if not self.in_workspace_bounds(self.pose_xy(node.pose)):
                continue # 这里的workspace bounds是限制在某个矩形里面建图，目前是没有任何意义的，但保留这个检查以防未来添加了workspace bounds参数。
            cell = grid.xy_to_cell(self.pose_xy(node.pose))
            if cell is not None:
                cell_idx = grid.flat_index(cell)
                state = grid.state_at_cell(cell)
                if state == grid.FREE:
                    node.free_radius = min(sdf_obstacle[cell_idx], sdf_unknown[cell_idx], self.max_free_radius)
                    node.explored_radius = max(node.explored_radius, sdf_unknown[cell_idx])
                elif state == grid.OBSTACLE:
                    node.free_radius = 0.0
                if node.free_radius <= 0.0:
                    continue
            new_idx = len(valid_nodes)
            index_remap[old_idx] = new_idx
            valid_nodes.append(node)

        self.nodes = valid_nodes
        self.edges = {
            tuple(sorted((index_remap[a], index_remap[b])))
            for a, b in self.edges
            if a in index_remap and b in index_remap and index_remap[a] != index_remap[b]
        }

    def sample_new_nodes(
        self,
        grid: TraversabilityGrid,
        sdf_unknown: List[float],
        sdf_obstacle: List[float],
        reachable_free_cells: Sequence[Cell],
        num_samples: int,
    ):
        # Algorithm 3: Sample New Nodes.
        # Paper defaults: r_max=10m, r_max^f=4m, N_samples=1000, r_trav=0.5m.
        if not reachable_free_cells:
            return

        for _ in range(num_samples):
            cell = self.random.choice(reachable_free_cells)
            cell_idx = grid.flat_index(cell)
            xy = grid.cell_to_xy(cell)
            if not self.in_workspace_bounds(xy):
                continue
            if min(sdf_obstacle[cell_idx], sdf_unknown[cell_idx]) <= self.traversable_radius:
                continue

            redundant = False
            for node in self.nodes:
                if self.distance_xy(xy, self.pose_xy(node.pose)) <= node.free_radius:
                    redundant = True
                    break
            if redundant:
                continue

            pose = Pose()
            pose.position.x = xy[0]
            pose.position.y = xy[1]
            pose.position.z = grid.msg.info.pose.position.z
            pose.orientation.w = 1.0
            free_radius = min(sdf_obstacle[cell_idx], sdf_unknown[cell_idx], self.max_free_radius)
            explored_radius = sdf_unknown[cell_idx]
            self.nodes.append(GraphNodeState(
                pose=pose,
                uuid_msg=self.make_uuid(len(self.nodes)),
                free_radius=free_radius,
                explored_radius=explored_radius,
            ))

    def update_frontier_nodes(self, grid: TraversabilityGrid, reachable_free_cells: Sequence[Cell]):
        # Algorithm 4: Detect and Update Frontier Nodes.
        frontier_cells = grid.unknown_frontier_cells_next_to_free(reachable_free_cells)
        frontier_cells = grid.filter_frontier_clusters(frontier_cells, self.min_frontier_cluster_size)
        valid_frontier_indices = {grid.flat_index(frontier_cell) for frontier_cell, _ in frontier_cells}

        for node in self.nodes:
            if not node.is_frontier:
                continue
            kept_frontiers_cells = []
            for point in node.frontier_points:
                xy = (point.x, point.y)
                cell = grid.xy_to_cell(xy)
                if cell is None:
                    kept_frontiers_cells.append(point)
                    continue
                if not grid.is_known(cell) and grid.flat_index(cell) in valid_frontier_indices:
                    kept_frontiers_cells.append(point)
            node.frontier_points = kept_frontiers_cells
            node.is_frontier = bool(node.frontier_points)

        for frontier_cell, free_side_cell in frontier_cells:
            frontier_xy = grid.cell_to_xy(frontier_cell)
            free_side_xy = grid.cell_to_xy(free_side_cell)
            if any(self.distance_xy(frontier_xy, self.pose_xy(node.pose)) <= node.explored_radius for node in self.nodes):
                continue

            best_idx = None
            best_dist = math.inf
            for idx, node in enumerate(self.nodes):
                node_xy = self.pose_xy(node.pose)
                dist = self.distance_xy(node_xy, frontier_xy)
                if dist > self.frontier_association_radius:# 这个还是认为设置的意思如果一个frontier cell离node太远就不检查了，这里设置的是1.5m
                    continue
                if not grid.collision_free(node_xy, free_side_xy):
                    continue
                if dist < best_dist:
                    best_idx = idx
                    best_dist = dist

            if best_idx is not None:
                point = Point()
                point.x = float(frontier_xy[0])
                point.y = float(frontier_xy[1])
                point.z = float(self.nodes[best_idx].pose.position.z)
                self.nodes[best_idx].frontier_points.append(point)
                self.nodes[best_idx].is_frontier = True

    def prune_invalid_edges(self, grid: TraversabilityGrid, sdf_unknown: List[float], sdf_obstacle: List[float]):
        valid_edges = set()
        for a, b in self.edges:
            if self.existing_edge_is_valid(grid, sdf_obstacle, a, b):
                valid_edges.add((a, b))
        self.edges = valid_edges

    def build_edges(self, grid: TraversabilityGrid, sdf_unknown: List[float], sdf_obstacle: List[float]):
        # Algorithm 5: Build Edges. Paper default: r_edge=8m.
        for i, node_i in enumerate(self.nodes):
            xy_i = self.pose_xy(node_i.pose)
            for j in range(i + 1, len(self.nodes)):
                if self.edge_is_valid(grid, sdf_unknown, sdf_obstacle, i, j, start_xy=xy_i):
                    self.edges.add((i, j))

    def edge_is_valid(
        self,
        grid: TraversabilityGrid,
        sdf_unknown: List[float],
        sdf_obstacle: List[float],
        from_idx: int,
        to_idx: int,
        start_xy: Optional[XY] = None,
    ) -> bool:
        if from_idx >= len(self.nodes) or to_idx >= len(self.nodes) or from_idx == to_idx:
            return False

        xy_i = start_xy if start_xy is not None else self.pose_xy(self.nodes[from_idx].pose)
        xy_j = self.pose_xy(self.nodes[to_idx].pose)
        if self.distance_xy(xy_i, xy_j) > self.edge_radius:
            return False
        return grid.clearance_collision_free(xy_i, xy_j, sdf_unknown, sdf_obstacle, self.traversable_radius)

    def existing_edge_is_valid(
        self,
        grid: TraversabilityGrid,
        sdf_obstacle: List[float],
        from_idx: int,
        to_idx: int,
    ) -> bool:
        if from_idx >= len(self.nodes) or to_idx >= len(self.nodes) or from_idx == to_idx:
            return False

        xy_i = self.pose_xy(self.nodes[from_idx].pose)
        xy_j = self.pose_xy(self.nodes[to_idx].pose)
        if self.distance_xy(xy_i, xy_j) > self.edge_radius:
            return False
        return not grid.contradicted_by_obstacle(xy_i, xy_j, sdf_obstacle, self.traversable_radius)

    def publish_graph(self, frame_id: str, stamp):
        if not self.nodes:
            return

        msg = NavigationGraph()
        msg.header.frame_id = frame_id
        msg.header.stamp = stamp
        msg.trav_classes = [self.trav_class]
        msg.current_node_idx = min(self.current_node_idx, len(self.nodes) - 1)
        msg.nodes = [self.to_graph_msg_node(node) for node in self.nodes]
        msg.edges = [self.to_graph_msg_edge(a, b) for a, b in sorted(self.edges)]
        self.graph_pub.publish(msg)

    def to_graph_msg_node(self, state: GraphNodeState) -> Node:
        node = Node()
        node.uuid = state.uuid_msg
        node.pose = state.pose
        props = NodeTraversabilityProperties()
        props.is_frontier = state.is_frontier
        props.frontier_points = state.frontier_points
        props.explored_radius = float(state.explored_radius if math.isfinite(state.explored_radius) else 0.0)
        props.free_radius = float(state.free_radius if math.isfinite(state.free_radius) else 0.0)
        node.trav_properties = [props]
        return node

    def to_graph_msg_edge(self, from_idx: int, to_idx: int) -> Edge:
        edge = Edge()
        edge.from_idx = from_idx
        edge.to_idx = to_idx
        cost = self.distance_xy(self.pose_xy(self.nodes[from_idx].pose), self.pose_xy(self.nodes[to_idx].pose))
        traversability = EdgeTraversability()
        traversability.traversability_cost = float(max(cost, 1e-3))
        edge.traversability = [traversability]
        return edge

    @staticmethod
    def delete_marker(frame_id: str, stamp, ns: str) -> Marker:
        marker = Marker()
        marker.header.frame_id = frame_id
        marker.header.stamp = stamp
        marker.ns = ns
        marker.action = Marker.DELETEALL
        return marker

    @staticmethod
    def points_marker(frame_id: str, stamp, ns: str, marker_id: int, points: List[Point], scale: float, r: float, g: float, b: float, a: float) -> Marker:
        marker = Marker()
        marker.header.frame_id = frame_id
        marker.header.stamp = stamp
        marker.ns = ns
        marker.id = marker_id
        marker.type = Marker.CUBE_LIST
        marker.action = Marker.ADD
        marker.pose.orientation.w = 1.0
        marker.scale.x = float(scale)
        marker.scale.y = float(scale)
        marker.scale.z = 0.025
        marker.color.r = float(r)
        marker.color.g = float(g)
        marker.color.b = float(b)
        marker.color.a = float(a)
        marker.points = points
        return marker

    @staticmethod
    def grid_map_layer(row_major_values: Sequence[float], rows: int, cols: int) -> Float32MultiArray:
        array = Float32MultiArray()
        array.layout.dim = [
            MultiArrayDimension(label='column_index', size=cols, stride=rows * cols),
            MultiArrayDimension(label='row_index', size=rows, stride=rows),
        ]
        array.layout.data_offset = 0
        array.data = [
            float(row_major_values[row * cols + col])
            for col in range(cols)
            for row in range(rows)
        ]
        return array

    @staticmethod
    def make_uuid(node_idx: int) -> UUID:
        uuid_msg = UUID()
        deterministic_uuid = uuid.uuid5(uuid.NAMESPACE_DNS, f'graphnav_builder_node_{node_idx}')
        uuid_msg.id = list(deterministic_uuid.bytes)
        return uuid_msg

    @staticmethod
    def uuid_key(uuid_msg: UUID) -> Tuple[int, ...]:
        return tuple(int(value) for value in uuid_msg.id)

    @staticmethod
    def pose_xy(pose: Pose) -> XY:
        return float(pose.position.x), float(pose.position.y)

    def in_workspace_bounds(self, xy: XY) -> bool:
        x, y = xy
        return self.min_x <= x <= self.max_x and self.min_y <= y <= self.max_y

    @staticmethod
    def distance_xy(a: XY, b: XY) -> float:
        return math.hypot(a[0] - b[0], a[1] - b[1])


def main(args=None):
    rclpy.init(args=args)
    node = SparseGraphBuilderNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
