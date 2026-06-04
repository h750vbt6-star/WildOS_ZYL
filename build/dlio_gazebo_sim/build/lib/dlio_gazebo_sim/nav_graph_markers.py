import math

import rclpy
from geometry_msgs.msg import Point
from graphnav_msgs.msg import NavigationGraph
from rclpy.node import Node
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray


def color(r, g, b, a=1.0):
    msg = ColorRGBA()
    msg.r = float(r)
    msg.g = float(g)
    msg.b = float(b)
    msg.a = float(a)
    return msg


def point_from_pose(pose, z_offset=0.0):
    point = Point()
    point.x = float(pose.position.x)
    point.y = float(pose.position.y)
    point.z = float(pose.position.z) + float(z_offset)
    return point


class NavGraphMarkerNode(Node):
    def __init__(self):
        super().__init__('nav_graph_markers')
        self.declare_parameter('nav_graph_topic', '/nav_graph')
        self.declare_parameter('marker_topic', '/nav_graph_markers')
        self.declare_parameter('z_offset', 0.08)
        self.declare_parameter('show_radii', True)
        self.declare_parameter('show_ids', False)

        self.nav_graph_topic = self.get_parameter('nav_graph_topic').value
        self.marker_topic = self.get_parameter('marker_topic').value
        self.z_offset = float(self.get_parameter('z_offset').value)
        self.show_radii = bool(self.get_parameter('show_radii').value)
        self.show_ids = bool(self.get_parameter('show_ids').value)

        self.pub = self.create_publisher(MarkerArray, self.marker_topic, 10)
        self.create_subscription(NavigationGraph, self.nav_graph_topic, self.graph_callback, 10)
        self.get_logger().info(
            f'Visualizing {self.nav_graph_topic} as MarkerArray on {self.marker_topic}'
        )

    def graph_callback(self, msg):
        markers = MarkerArray()
        markers.markers.append(self.delete_all_marker(msg, 'nav_graph'))

        node_points = []
        frontier_node_points = []
        frontier_points = []
        frontier_lines = []

        for node in msg.nodes:
            node_point = point_from_pose(node.pose, self.z_offset)
            is_frontier = any(prop.is_frontier for prop in node.trav_properties)
            if is_frontier:
                frontier_node_points.append(node_point)
            else:
                node_points.append(node_point)

            for prop in node.trav_properties:
                for frontier_point in prop.frontier_points:
                    fp = Point()
                    fp.x = float(frontier_point.x)
                    fp.y = float(frontier_point.y)
                    fp.z = float(frontier_point.z) + self.z_offset
                    frontier_points.append(fp)
                    frontier_lines.extend([node_point, fp])

        markers.markers.append(self.points_marker(msg, 'nav_graph', 1, 'nodes', node_points, Marker.SPHERE_LIST, 0.22, color(0.1, 0.9, 0.1)))
        markers.markers.append(self.points_marker(msg, 'nav_graph', 2, 'frontier_nodes', frontier_node_points, Marker.SPHERE_LIST, 0.32, color(0.1, 0.4, 1.0)))
        markers.markers.append(self.points_marker(msg, 'nav_graph', 3, 'frontier_points', frontier_points, Marker.CUBE_LIST, 0.20, color(1.0, 0.0, 1.0)))
        markers.markers.append(self.line_marker(msg, 'nav_graph', 4, 'frontier_links', frontier_lines, 0.035, color(0.8, 0.2, 1.0)))

        edge_points = []
        for edge in msg.edges:
            if edge.from_idx >= len(msg.nodes) or edge.to_idx >= len(msg.nodes):
                continue
            edge_points.append(point_from_pose(msg.nodes[edge.from_idx].pose, self.z_offset))
            edge_points.append(point_from_pose(msg.nodes[edge.to_idx].pose, self.z_offset))
        markers.markers.append(self.line_marker(msg, 'nav_graph', 5, 'edges', edge_points, 0.018, color(1.0, 0.8, 0.0)))

        current_node_points = []
        if msg.nodes and msg.current_node_idx < len(msg.nodes):
            current_node_points.append(point_from_pose(msg.nodes[msg.current_node_idx].pose, self.z_offset + 0.12))
        markers.markers.append(self.points_marker(msg, 'nav_graph', 6, 'current_node', current_node_points, Marker.SPHERE_LIST, 0.38, color(1.0, 0.2, 0.0)))

        next_id = 20
        if self.show_radii:
            for node in msg.nodes:
                node_point = point_from_pose(node.pose, self.z_offset - 0.04)
                for prop in node.trav_properties:
                    if math.isfinite(prop.free_radius) and prop.free_radius > 0.0:
                        markers.markers.append(
                            self.radius_marker(msg, next_id, 'free_radius', node_point, prop.free_radius, color(1.0, 0.0, 0.0, 0.18))
                        )
                        next_id += 1
                    if math.isfinite(prop.explored_radius) and prop.explored_radius > 0.0:
                        markers.markers.append(
                            self.radius_marker(msg, next_id, 'explored_radius', node_point, prop.explored_radius, color(0.0, 0.2, 1.0, 0.12))
                        )
                        next_id += 1

        if self.show_ids:
            for node in msg.nodes:
                markers.markers.append(self.text_marker(msg, next_id, node))
                next_id += 1

        self.pub.publish(markers)

    @staticmethod
    def delete_all_marker(msg, ns):
        marker = Marker()
        marker.header = msg.header
        marker.ns = ns
        marker.action = Marker.DELETEALL
        return marker

    @staticmethod
    def base_marker(msg, marker_id, ns, marker_type):
        marker = Marker()
        marker.header = msg.header
        marker.ns = ns
        marker.id = int(marker_id)
        marker.type = marker_type
        marker.action = Marker.ADD
        marker.frame_locked = True
        return marker

    def points_marker(self, msg, ns, marker_id, name, points, marker_type, scale, marker_color):
        marker = self.base_marker(msg, marker_id, f'{ns}/{name}', marker_type)
        marker.scale.x = float(scale)
        marker.scale.y = float(scale)
        marker.scale.z = float(scale)
        marker.color = marker_color
        marker.points = points
        return marker

    def line_marker(self, msg, ns, marker_id, name, points, width, marker_color):
        marker = self.base_marker(msg, marker_id, f'{ns}/{name}', Marker.LINE_LIST)
        marker.scale.x = float(width)
        marker.color = marker_color
        marker.points = points
        return marker

    def radius_marker(self, msg, marker_id, name, center, radius, marker_color):
        marker = self.base_marker(msg, marker_id, f'nav_graph/{name}', Marker.CYLINDER)
        marker.pose.position = center
        marker.pose.orientation.w = 1.0
        marker.scale.x = float(radius) * 2.0
        marker.scale.y = float(radius) * 2.0
        marker.scale.z = 0.015
        marker.color = marker_color
        return marker

    def text_marker(self, msg, marker_id, node):
        marker = self.base_marker(msg, marker_id, 'nav_graph/ids', Marker.TEXT_VIEW_FACING)
        marker.pose.position = point_from_pose(node.pose, self.z_offset + 0.25)
        marker.pose.orientation.w = 1.0
        marker.scale.z = 0.18
        marker.color = color(1.0, 1.0, 1.0)
        marker.text = ''.join(f'{value:02x}' for value in node.uuid.id[:4])
        return marker


def main():
    rclpy.init()
    node = NavGraphMarkerNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
