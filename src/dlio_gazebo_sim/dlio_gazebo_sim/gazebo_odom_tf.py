import rclpy
from geometry_msgs.msg import TransformStamped
from nav_msgs.msg import Odometry
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from tf2_ros import TransformBroadcaster


class GazeboOdomTf(Node):
    def __init__(self):
        super().__init__('gazebo_odom_tf')
        self.declare_parameter('odom_topic', '/gazebo/odom')
        self.declare_parameter('parent_frame', 'odom')
        self.declare_parameter('child_frame', 'gazebo_base_link')

        self.parent_frame = self.get_parameter('parent_frame').value
        self.child_frame = self.get_parameter('child_frame').value

        self.br = TransformBroadcaster(self)
        self.create_subscription(
            Odometry,
            self.get_parameter('odom_topic').value,
            self.odom_callback,
            50,
        )

    def odom_callback(self, msg):
        tf = TransformStamped()
        tf.header.stamp = msg.header.stamp
        tf.header.frame_id = self.parent_frame or msg.header.frame_id
        tf.child_frame_id = self.child_frame or msg.child_frame_id
        tf.transform.translation.x = msg.pose.pose.position.x
        tf.transform.translation.y = msg.pose.pose.position.y
        tf.transform.translation.z = msg.pose.pose.position.z
        tf.transform.rotation = msg.pose.pose.orientation
        self.br.sendTransform(tf)


def main():
    rclpy.init()
    node = GazeboOdomTf()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
