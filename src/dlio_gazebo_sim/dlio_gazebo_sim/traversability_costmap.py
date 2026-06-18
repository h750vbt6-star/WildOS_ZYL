import math

import rclpy
from grid_map_msgs.msg import GridMap
from nav_msgs.msg import OccupancyGrid
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from std_msgs.msg import Float32MultiArray


class TraversabilityCostmap(Node):
    def __init__(self):
        super().__init__('traversability_costmap')

        self.declare_parameter('grid_map_topic', '/elevation_mapping_node/elevation_map_raw')
        self.declare_parameter('costmap_topic', '/traversability_costmap')
        self.declare_parameter('traversability_layer', 'traversability')
        self.declare_parameter('observed_layer', 'elevation')
        self.declare_parameter('safe_threshold', 0.2)
        self.declare_parameter('unknown_is_free', True)
        self.declare_parameter('obstacle_cost', 100)
        self.declare_parameter('free_cost', 0)

        self.grid_map_topic = self.get_parameter('grid_map_topic').value
        self.costmap_topic = self.get_parameter('costmap_topic').value
        self.traversability_layer = self.get_parameter('traversability_layer').value
        self.observed_layer = self.get_parameter('observed_layer').value
        self.safe_threshold = float(self.get_parameter('safe_threshold').value)
        self.unknown_is_free = bool(self.get_parameter('unknown_is_free').value)
        self.obstacle_cost = int(self.get_parameter('obstacle_cost').value)
        self.free_cost = int(self.get_parameter('free_cost').value)

        qos = QoSProfile(depth=1)
        qos.reliability = ReliabilityPolicy.RELIABLE
        qos.durability = DurabilityPolicy.VOLATILE

        self.pub = self.create_publisher(OccupancyGrid, self.costmap_topic, qos)
        self.create_subscription(GridMap, self.grid_map_topic, self.grid_callback, 10)
        self.get_logger().info(
            f'Publishing {self.costmap_topic} from {self.grid_map_topic}; '
            f'unknown_is_free={self.unknown_is_free}, safe_threshold={self.safe_threshold:.3f}'
        )

    def grid_callback(self, msg: GridMap):
        if not msg.data or self.traversability_layer not in msg.layers:
            return

        trav_idx = msg.layers.index(self.traversability_layer)
        rows, cols = self.layer_shape(msg.data[trav_idx])
        traversability = self.decode_layer(msg.data[trav_idx], rows, cols)

        observed = None
        if self.observed_layer and self.observed_layer in msg.layers:
            observed = self.decode_layer(msg.data[msg.layers.index(self.observed_layer)], rows, cols)

        out = OccupancyGrid()
        out.header = msg.header
        out.info.map_load_time = msg.header.stamp
        out.info.resolution = float(msg.info.resolution)
        out.info.width = int(rows)
        out.info.height = int(cols)
        out.info.origin.position.x = float(msg.info.pose.position.x - 0.5 * msg.info.length_x)
        out.info.origin.position.y = float(msg.info.pose.position.y - 0.5 * msg.info.length_y)
        out.info.origin.position.z = 0.0
        out.info.origin.orientation.w = 1.0

        data = []
        for oy in range(out.info.height):
            col = cols - 1 - oy
            for ox in range(out.info.width):
                row = rows - 1 - ox
                data.append(self.cell_cost(row, col, cols, traversability, observed))
        out.data = data
        self.pub.publish(out)

    def cell_cost(self, row, col, cols, traversability, observed):
        idx = row * cols + col
        value = traversability[idx]
        cell_observed = True if observed is None else math.isfinite(observed[idx])

        if not cell_observed or not math.isfinite(value):
            return self.free_cost if self.unknown_is_free else -1
        if value >= self.safe_threshold:
            return self.free_cost
        return self.obstacle_cost

    @staticmethod
    def layer_shape(array_msg: Float32MultiArray):
        dims = array_msg.layout.dim
        if len(dims) >= 2 and dims[0].label == 'column_index' and dims[1].label == 'row_index':
            return max(1, dims[1].size), max(1, dims[0].size)
        if len(dims) >= 2 and dims[0].label == 'row_index' and dims[1].label == 'column_index':
            return max(1, dims[0].size), max(1, dims[1].size)
        size = int(math.sqrt(len(array_msg.data))) if array_msg.data else 1
        return max(1, size), max(1, size)

    @staticmethod
    def decode_layer(array_msg: Float32MultiArray, rows: int, cols: int):
        data = list(array_msg.data)
        expected = rows * cols
        dims = array_msg.layout.dim
        out = [float('nan')] * expected

        if len(dims) >= 2 and dims[0].label == 'column_index' and dims[1].label == 'row_index':
            source_cols = dims[0].size or cols
            source_rows = dims[1].size or rows
            for col in range(min(source_cols, cols)):
                for row in range(min(source_rows, rows)):
                    src = col * source_rows + row
                    dst = row * cols + col
                    if src < len(data):
                        out[dst] = data[src]
            return out

        if len(dims) >= 2 and dims[0].label == 'row_index' and dims[1].label == 'column_index':
            source_rows = dims[0].size or rows
            source_cols = dims[1].size or cols
            for row in range(min(source_rows, rows)):
                for col in range(min(source_cols, cols)):
                    src = row * source_cols + col
                    dst = row * cols + col
                    if src < len(data):
                        out[dst] = data[src]
            return out

        for idx in range(min(expected, len(data))):
            out[idx] = data[idx]
        return out


def main(args=None):
    rclpy.init(args=args)
    node = TraversabilityCostmap()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
