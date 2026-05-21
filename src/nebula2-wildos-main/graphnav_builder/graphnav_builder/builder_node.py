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

    def __init__(self, msg: GridMap, layer_name: str, safe_threshold: float):
        if not msg.data:
            raise ValueError('GridMap has no data layers')

        if layer_name and layer_name in msg.layers:
            layer_idx = msg.layers.index(layer_name)
        else:
            layer_idx = 0

        self.msg = msg
        self.layer_name = msg.layers[layer_idx] if layer_idx < len(msg.layers) else layer_name
        self.resolution = float(msg.info.resolution)
        self.length_x = float(msg.info.length_x)
        self.length_y = float(msg.info.length_y)
        self.center_x = float(msg.info.pose.position.x)
        self.center_y = float(msg.info.pose.position.y)
        self.origin_x = self.center_x - 0.5 * self.length_x
        self.origin_y = self.center_y - 0.5 * self.length_y
        self.width = max(1, int(round(self.length_x / self.resolution)))
        self.height = max(1, int(round(self.length_y / self.resolution)))

        values = list(msg.data[layer_idx].data)
        expected_size = self.width * self.height
        if len(values) < expected_size:
            values.extend([float('nan')] * (expected_size - len(values)))

        self.values = values[:expected_size]
        self.state = [self.UNKNOWN] * expected_size
        self.free_cells: List[Cell] = []
        self.unknown_cells: List[Cell] = []
        self.obstacle_cells: List[Cell] = []

        for row in range(self.height):
            for col in range(self.width):
                value = self.value_at_cell((row, col))
                idx = self.flat_index((row, col))
                if not math.isfinite(value):
                    self.state[idx] = self.UNKNOWN
                    self.unknown_cells.append((row, col))
                elif value >= safe_threshold:
                    self.state[idx] = self.FREE
                    self.free_cells.append((row, col))
                else:
                    self.state[idx] = self.OBSTACLE
                    self.obstacle_cells.append((row, col))

    def flat_index(self, cell: Cell) -> int:
        row, col = cell
        return row * self.width + col

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
        col = int(math.floor((x - self.origin_x) / self.resolution))
        row = int(math.floor((y - self.origin_y) / self.resolution))
        cell = (row, col)
        return cell if self.in_bounds_cell(cell) else None

    def cell_to_xy(self, cell: Cell) -> XY:
        row, col = cell
        return (
            self.origin_x + (col + 0.5) * self.resolution,
            self.origin_y + (row + 0.5) * self.resolution,
        )

    def is_free(self, cell: Cell) -> bool:
        return self.in_bounds_cell(cell) and self.state_at_cell(cell) == self.FREE

    def is_known(self, cell: Cell) -> bool:
        return self.in_bounds_cell(cell) and self.state_at_cell(cell) in (self.FREE, self.OBSTACLE)

    def boundary_between_free_and_unknown(self) -> List[Cell]:
        frontiers = []
        for cell in self.free_cells:
            for neighbor in self.neighbors8(cell):
                if self.in_bounds_cell(neighbor) and self.state_at_cell(neighbor) == self.UNKNOWN:
                    frontiers.append(cell)
                    break
        return frontiers

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
        self.declare_parameter('trav_class', 'default')
        self.declare_parameter('safe_threshold', 0.5)
        self.declare_parameter('local_map_radius', 10.0)
        self.declare_parameter('local_map_resolution', 0.1)
        self.declare_parameter('max_free_radius', 4.0)
        self.declare_parameter('traversable_radius', 0.5)
        self.declare_parameter('edge_radius', 8.0)
        self.declare_parameter('num_samples', 1000)
        self.declare_parameter('random_seed', 7)

        self.odom_topic = self.get_parameter('odom_topic').value
        self.grid_map_topic = self.get_parameter('grid_map_topic').value
        self.nav_graph_topic = self.get_parameter('nav_graph_topic').value
        self.traversability_layer = self.get_parameter('traversability_layer').value
        self.trav_class = self.get_parameter('trav_class').value
        self.safe_threshold = float(self.get_parameter('safe_threshold').value)
        self.local_map_radius = float(self.get_parameter('local_map_radius').value)
        self.local_map_resolution = float(self.get_parameter('local_map_resolution').value)
        self.max_free_radius = float(self.get_parameter('max_free_radius').value)
        self.traversable_radius = float(self.get_parameter('traversable_radius').value)
        self.edge_radius = float(self.get_parameter('edge_radius').value)
        self.num_samples = int(self.get_parameter('num_samples').value)
        self.random = random.Random(int(self.get_parameter('random_seed').value))

        self.nodes: List[GraphNodeState] = []
        self.edges: set[Tuple[int, int]] = set()
        self.current_node_idx = 0
        self.latest_odom: Optional[Odometry] = None

        self.graph_pub = self.create_publisher(NavigationGraph, self.nav_graph_topic, 10)
        self.odom_sub = self.create_subscription(Odometry, self.odom_topic, self.odom_callback, 20)
        self.grid_sub = self.create_subscription(GridMap, self.grid_map_topic, self.grid_map_callback, 10)

    def odom_callback(self, msg: Odometry):
        self.latest_odom = msg
        if self.nodes:
            robot_xy = self.pose_xy(msg.pose.pose)
            self.current_node_idx = min(
                range(len(self.nodes)),
                key=lambda idx: self.distance_xy(robot_xy, self.pose_xy(self.nodes[idx].pose)),
            )

    def grid_map_callback(self, msg: GridMap):
        try:
            grid = TraversabilityGrid(msg, self.traversability_layer, self.safe_threshold)
        except ValueError as exc:
            self.get_logger().warn(str(exc))
            return

        if not grid.free_cells:
            self.get_logger().warn('No free cells in traversability grid; skipping graph update')
            return

        sdf_unknown = grid.distance_field(grid.unknown_cells)
        sdf_obstacle = grid.distance_field(grid.obstacle_cells)

        self.update_navigation_graph(grid, sdf_unknown, sdf_obstacle)
        self.publish_graph(msg.header.frame_id, msg.header.stamp)

    def update_navigation_graph(self, grid: TraversabilityGrid, sdf_unknown: List[float], sdf_obstacle: List[float]):
        # Algorithm 1: Update Navigation Graph.
        self.update_nodes(grid, sdf_unknown, sdf_obstacle)
        self.sample_new_nodes(grid, sdf_unknown, sdf_obstacle, self.num_samples)
        self.update_frontier_nodes(grid)
        self.build_edges(grid)

    def update_nodes(self, grid: TraversabilityGrid, sdf_unknown: List[float], sdf_obstacle: List[float]):
        # Algorithm 2: Update Nodes.
        valid_nodes: List[GraphNodeState] = []
        index_remap: Dict[int, int] = {}

        for old_idx, node in enumerate(self.nodes):
            cell = grid.xy_to_cell(self.pose_xy(node.pose))
            if cell is not None:
                cell_idx = grid.flat_index(cell)
                node.free_radius = min(sdf_obstacle[cell_idx], sdf_unknown[cell_idx], self.max_free_radius)
                node.explored_radius = max(node.explored_radius, sdf_unknown[cell_idx])
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

    def sample_new_nodes(self, grid: TraversabilityGrid, sdf_unknown: List[float], sdf_obstacle: List[float], num_samples: int):
        # Algorithm 3: Sample New Nodes.
        # Paper defaults: r_max=10m, r_max^f=4m, N_samples=1000, r_trav=0.5m.
        if not grid.free_cells:
            return

        for _ in range(num_samples):
            cell = self.random.choice(grid.free_cells)
            cell_idx = grid.flat_index(cell)
            if self.latest_odom is not None and self.distance_xy(xy, self.pose_xy(self.latest_odom.pose.pose)) > self.local_map_radius:
                continue
            if min(sdf_obstacle[cell_idx], sdf_unknown[cell_idx]) <= self.traversable_radius:
                continue

            xy = grid.cell_to_xy(cell)
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

    def update_frontier_nodes(self, grid: TraversabilityGrid):
        # Algorithm 4: Detect and Update Frontier Nodes.
        for node in self.nodes:
            kept_frontiers = []
            for point in node.frontier_points:
                xy = (point.x, point.y)
                cell = grid.xy_to_cell(xy)
                if cell is not None and not grid.is_known(cell):
                    kept_frontiers.append(point)
            node.frontier_points = kept_frontiers
            node.is_frontier = bool(node.frontier_points)

        for frontier_cell in grid.boundary_between_free_and_unknown():
            frontier_xy = grid.cell_to_xy(frontier_cell)
            if any(self.distance_xy(frontier_xy, self.pose_xy(node.pose)) <= node.explored_radius for node in self.nodes):
                continue

            best_idx = None
            best_dist = math.inf
            for idx, node in enumerate(self.nodes):
                node_xy = self.pose_xy(node.pose)
                if not grid.collision_free(node_xy, frontier_xy):
                    continue
                dist = self.distance_xy(node_xy, frontier_xy)
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

    def build_edges(self, grid: TraversabilityGrid):
        # Algorithm 5: Build Edges. Paper default: r_edge=8m.
        for i, node_i in enumerate(self.nodes):
            xy_i = self.pose_xy(node_i.pose)
            for j in range(i + 1, len(self.nodes)):
                node_j = self.nodes[j]
                xy_j = self.pose_xy(node_j.pose)
                if self.distance_xy(xy_i, xy_j) > self.edge_radius:
                    continue
                if grid.collision_free(xy_i, xy_j):
                    self.edges.add((i, j))

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
    def make_uuid(node_idx: int) -> UUID:
        uuid_msg = UUID()
        deterministic_uuid = uuid.uuid5(uuid.NAMESPACE_DNS, f'graphnav_builder_node_{node_idx}')
        uuid_msg.id = list(deterministic_uuid.bytes)
        return uuid_msg

    @staticmethod
    def pose_xy(pose: Pose) -> XY:
        return float(pose.position.x), float(pose.position.y)

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
