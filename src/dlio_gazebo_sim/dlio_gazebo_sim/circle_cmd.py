import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node


class CircleCmd(Node):
    def __init__(self):
        super().__init__('dlio_circle_cmd')
        self.declare_parameter('cmd_vel_topic', '/cmd_vel')
        self.declare_parameter('start_delay', 4.0)
        self.declare_parameter('linear_x', 0.45)
        self.declare_parameter('angular_z', 0.22)

        topic = self.get_parameter('cmd_vel_topic').value
        self.start_delay = float(self.get_parameter('start_delay').value)
        self.linear_x = float(self.get_parameter('linear_x').value)
        self.angular_z = float(self.get_parameter('angular_z').value)
        self.start_time = self.get_clock().now()

        self.publisher = self.create_publisher(Twist, topic, 10)
        self.timer = self.create_timer(0.05, self.publish_cmd)

    def publish_cmd(self):
        elapsed = (self.get_clock().now() - self.start_time).nanoseconds * 1e-9
        msg = Twist()
        if elapsed >= self.start_delay:
            msg.linear.x = self.linear_x
            msg.angular.z = self.angular_z
        self.publisher.publish(msg)


def main():
    rclpy.init()
    node = CircleCmd()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
