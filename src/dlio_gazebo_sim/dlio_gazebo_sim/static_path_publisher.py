#!/usr/bin/env python3

import math
from typing import List, Optional, Tuple

import rclpy
from geometry_msgs.msg import PoseStamped, Quaternion
from nav_msgs.msg import Odometry, Path
from rclpy.node import Node


def yaw_to_quaternion(yaw: float) -> Quaternion:
    q = Quaternion()
    q.z = math.sin(yaw * 0.5)
    q.w = math.cos(yaw * 0.5)
    return q


def parse_waypoints(text: str) -> List[Tuple[float, float]]:
    waypoints: List[Tuple[float, float]] = []
    for item in text.split(";"):
        item = item.strip()
        if not item:
            continue
        parts = [p.strip() for p in item.split(",")]
        if len(parts) != 2:
            raise ValueError(f"Waypoint '{item}' must be formatted as x,y")
        waypoints.append((float(parts[0]), float(parts[1])))
    if not waypoints:
        raise ValueError("At least one waypoint is required")
    return waypoints


class StaticPathPublisher(Node):
    """Publish one known-safe path for testing the follower/Nav2 chain."""

    def __init__(self) -> None:
        super().__init__("static_path_publisher")

        self.declare_parameter("path_topic", "/graphnav_planner/path")
        self.declare_parameter("odom_topic", "/dlio/odom_node/odom")
        self.declare_parameter("frame_id", "odom")
        self.declare_parameter("waypoints", "0,0;2,0;4,0;7,0;9,0;12,0;16,0")
        self.declare_parameter("prepend_current_pose", True)
        self.declare_parameter("wait_for_subscriber", True)
        self.declare_parameter("publish_period", 0.5)

        self.path_topic = self.get_parameter("path_topic").value
        self.odom_topic = self.get_parameter("odom_topic").value
        self.frame_id = self.get_parameter("frame_id").value
        self.prepend_current_pose = bool(self.get_parameter("prepend_current_pose").value)
        self.wait_for_subscriber = bool(self.get_parameter("wait_for_subscriber").value)
        publish_period = float(self.get_parameter("publish_period").value)

        self.configured_waypoints = parse_waypoints(str(self.get_parameter("waypoints").value))
        self.latest_odom: Optional[Odometry] = None
        self.published = False

        self.path_pub = self.create_publisher(Path, self.path_topic, 10)
        self.odom_sub = self.create_subscription(
            Odometry, self.odom_topic, self.odom_callback, 10
        )
        self.timer = self.create_timer(publish_period, self.timer_callback)

        self.get_logger().info(
            f"Static path publisher waiting to publish {len(self.configured_waypoints)} "
            f"configured waypoints on {self.path_topic}."
        )

    def odom_callback(self, msg: Odometry) -> None:
        self.latest_odom = msg

    def timer_callback(self) -> None:
        if self.published:
            return
        if self.wait_for_subscriber and self.path_pub.get_subscription_count() == 0:
            return
        if self.prepend_current_pose and self.latest_odom is None:
            return

        waypoints = list(self.configured_waypoints)
        if self.prepend_current_pose and self.latest_odom is not None:
            p = self.latest_odom.pose.pose.position
            current_xy = (float(p.x), float(p.y))
            first_xy = waypoints[0]
            dx = current_xy[0] - first_xy[0]
            dy = current_xy[1] - first_xy[1]
            if math.hypot(dx, dy) > 0.05:
                # Keep the polyline shape, but anchor its start at the current robot pose.
                waypoints = [(x + dx, y + dy) for x, y in waypoints]

        path = Path()
        path.header.stamp = self.get_clock().now().to_msg()
        path.header.frame_id = self.frame_id

        for i, (x, y) in enumerate(waypoints):
            pose = PoseStamped()
            pose.header = path.header
            pose.pose.position.x = x
            pose.pose.position.y = y
            pose.pose.position.z = 0.0
            if i + 1 < len(waypoints):
                nx, ny = waypoints[i + 1]
            elif i > 0:
                nx, ny = x, y
                x, y = waypoints[i - 1]
            else:
                nx, ny = x + 1.0, y
            pose.pose.orientation = yaw_to_quaternion(math.atan2(ny - y, nx - x))
            path.poses.append(pose)

        self.path_pub.publish(path)
        self.published = True
        self.get_logger().info(
            f"Published static path with {len(path.poses)} poses in frame '{self.frame_id}'."
        )


def main(args=None) -> None:
    rclpy.init(args=args)
    node = StaticPathPublisher()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
