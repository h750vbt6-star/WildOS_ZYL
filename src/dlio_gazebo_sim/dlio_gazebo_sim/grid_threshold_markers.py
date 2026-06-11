import math

import rclpy
from grid_map_msgs.msg import GridMap
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from visualization_msgs.msg import Marker, MarkerArray


def rgba(r, g, b, a):
    color = Marker().color
    color.r = float(r)
    color.g = float(g)
    color.b = float(b)
    color.a = float(a)
    return color


class GridThresholdMarkers(Node):
    def __init__(self):
        super().__init__('grid_threshold_markers')
        self.declare_parameter('grid_map_topic', '/elevation_mapping_node/elevation_map_raw')
        self.declare_parameter('marker_topic', '/grid_threshold_markers')
        self.declare_parameter('traversability_layer', 'traversability')
        self.declare_parameter('observed_layer', 'elevation')
        self.declare_parameter('safe_threshold', 0.2)
        self.declare_parameter('sample_stride', 1)
        self.declare_parameter('z_offset', 0.08)

        self.grid_map_topic = self.get_parameter('grid_map_topic').value
        self.marker_topic = self.get_parameter('marker_topic').value
        self.traversability_layer = self.get_parameter('traversability_layer').value
        self.observed_layer = self.get_parameter('observed_layer').value
        self.safe_threshold = float(self.get_parameter('safe_threshold').value)
        self.sample_stride = max(1, int(self.get_parameter('sample_stride').value))
        self.z_offset = float(self.get_parameter('z_offset').value)

        self.pub = self.create_publisher(MarkerArray, self.marker_topic, 1)
        self.create_subscription(GridMap, self.grid_map_topic, self.grid_callback, 10)
        self.get_logger().info(
            f'Visualizing {self.grid_map_topic} thresholded at {self.safe_threshold} on {self.marker_topic}'
        )

    def grid_callback(self, msg: GridMap):
        if not msg.data or self.traversability_layer not in msg.layers:
            return

        rows, cols = self.layer_shape(msg.data[msg.layers.index(self.traversability_layer)])
        trav_idx = msg.layers.index(self.traversability_layer)
        trav = self.decode_layer(msg.data[trav_idx], rows, cols)

        observed = None
        if self.observed_layer and self.observed_layer in msg.layers:
            observed = self.decode_layer(msg.data[msg.layers.index(self.observed_layer)], rows, cols)

        center_x = float(msg.info.pose.position.x)
        center_y = float(msg.info.pose.position.y)
        length_x = float(msg.info.length_x)
        length_y = float(msg.info.length_y)
        resolution = float(msg.info.resolution)

        free_points = []
        obstacle_points = []
        unknown_points = []
        for row in range(0, rows, self.sample_stride):
            for col in range(0, cols, self.sample_stride):
                idx = row * cols + col
                value = trav[idx]
                cell_observed = True if observed is None else math.isfinite(observed[idx])
                point = self.cell_point(center_x, center_y, length_x, length_y, resolution, row, col, msg.info.pose.position.z)
                if not cell_observed or not math.isfinite(value):
                    unknown_points.append(point)
                elif value >= self.safe_threshold:
                    free_points.append(point)
                else:
                    obstacle_points.append(point)

        markers = MarkerArray()
        markers.markers.append(self.delete_all(msg))
        scale = resolution * self.sample_stride
        markers.markers.append(self.points_marker(msg, 1, 'free', free_points, scale, rgba(0.0, 0.9, 0.15, 0.55)))
        markers.markers.append(self.points_marker(msg, 2, 'obstacle', obstacle_points, scale, rgba(1.0, 0.0, 0.0, 0.85)))
        markers.markers.append(self.points_marker(msg, 3, 'unknown', unknown_points, scale, rgba(0.7, 0.7, 0.7, 0.55)))
        markers.markers.append(self.outline_marker(msg, 4, center_x, center_y, length_x, length_y, msg.info.pose.position.z + self.z_offset + 0.03))
        self.pub.publish(markers)

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

    def cell_point(self, center_x, center_y, length_x, length_y, resolution, row, col, z):
        from geometry_msgs.msg import Point
        point = Point()
        point.x = center_x + 0.5 * length_x - (row + 0.5) * resolution
        point.y = center_y + 0.5 * length_y - (col + 0.5) * resolution
        point.z = float(z) + self.z_offset
        return point

    @staticmethod
    def delete_all(msg):
        marker = Marker()
        marker.header = msg.header
        marker.ns = 'grid_threshold'
        marker.action = Marker.DELETEALL
        return marker

    @staticmethod
    def points_marker(msg, marker_id, name, points, scale, color):
        marker = Marker()
        marker.header = msg.header
        marker.ns = f'grid_threshold/{name}'
        marker.id = marker_id
        marker.type = Marker.CUBE_LIST
        marker.action = Marker.ADD
        marker.pose.orientation.w = 1.0
        marker.scale.x = float(scale)
        marker.scale.y = float(scale)
        marker.scale.z = 0.025
        marker.color = color
        marker.points = points
        return marker

    @staticmethod
    def outline_marker(msg, marker_id, center_x, center_y, length_x, length_y, z):
        from geometry_msgs.msg import Point
        marker = Marker()
        marker.header = msg.header
        marker.ns = 'grid_threshold/outline'
        marker.id = marker_id
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD
        marker.pose.orientation.w = 1.0
        marker.scale.x = 0.04
        marker.color = rgba(1.0, 1.0, 1.0, 0.9)
        corners = [
            (center_x - 0.5 * length_x, center_y - 0.5 * length_y),
            (center_x + 0.5 * length_x, center_y - 0.5 * length_y),
            (center_x + 0.5 * length_x, center_y + 0.5 * length_y),
            (center_x - 0.5 * length_x, center_y + 0.5 * length_y),
            (center_x - 0.5 * length_x, center_y - 0.5 * length_y),
        ]
        for x, y in corners:
            point = Point()
            point.x = float(x)
            point.y = float(y)
            point.z = float(z)
            marker.points.append(point)
        return marker


def main(args=None):
    rclpy.init(args=args)
    node = GridThresholdMarkers()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
