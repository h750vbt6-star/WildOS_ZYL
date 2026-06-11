import math

import rclpy
from geometry_msgs.msg import PoseStamped
from rclpy.node import Node


def yaw_to_quaternion(yaw):
    half_yaw = 0.5 * yaw
    q = PoseStamped().pose.orientation
    q.z = math.sin(half_yaw)
    q.w = math.cos(half_yaw)
    return q


class InitialGoalMux(Node):
    def __init__(self):
        super().__init__('initial_goal_mux')

        self.declare_parameter('real_goal_topic', '/imgnav_waypoint')
        self.declare_parameter('output_goal_topic', '/active_imgnav_waypoint')
        self.declare_parameter('frame_id', 'odom')
        self.declare_parameter('initial_goal_x', 100.0)
        self.declare_parameter('initial_goal_y', 0.0)
        self.declare_parameter('initial_goal_z', 0.0)
        self.declare_parameter('initial_goal_yaw', 0.0)
        self.declare_parameter('publish_rate', 1.0)
        self.declare_parameter('latch_real_goal', True)

        self.frame_id = self.get_parameter('frame_id').value
        self.initial_goal_x = float(self.get_parameter('initial_goal_x').value)
        self.initial_goal_y = float(self.get_parameter('initial_goal_y').value)
        self.initial_goal_z = float(self.get_parameter('initial_goal_z').value)
        self.initial_goal_yaw = float(self.get_parameter('initial_goal_yaw').value)
        self.latch_real_goal = bool(self.get_parameter('latch_real_goal').value)

        real_goal_topic = self.get_parameter('real_goal_topic').value
        output_goal_topic = self.get_parameter('output_goal_topic').value
        check_rate = max(0.1, float(self.get_parameter('publish_rate').value))

        self.real_goal = None
        self.using_real_goal = False
        self.initial_goal_published = False

        self.goal_pub = self.create_publisher(PoseStamped, output_goal_topic, 10)
        self.goal_sub = self.create_subscription(
            PoseStamped,
            real_goal_topic,
            self.real_goal_callback,
            10,
        )
        self.timer = self.create_timer(1.0 / check_rate, self.publish_initial_goal_once)

        self.get_logger().info(
            f'Will publish one prior goal ({self.initial_goal_x:.2f}, '
            f'{self.initial_goal_y:.2f}, {self.initial_goal_z:.2f}) in {self.frame_id}; '
            f'future updates come only from real goals on {real_goal_topic} to {output_goal_topic}.'
        )

    def real_goal_callback(self, msg):
        self.real_goal = msg
        if not self.using_real_goal:
            self.get_logger().info('Received real object goal; switching active goal from prior to triangulated target.')
        self.using_real_goal = True
        self.initial_goal_published = True
        self.stop_initial_timer()
        self.publish_active_goal()

    def make_initial_goal(self):
        goal = PoseStamped()
        goal.header.frame_id = self.frame_id
        goal.pose.position.x = self.initial_goal_x
        goal.pose.position.y = self.initial_goal_y
        goal.pose.position.z = self.initial_goal_z
        goal.pose.orientation = yaw_to_quaternion(self.initial_goal_yaw)
        return goal

    def stop_initial_timer(self):
        if self.timer is not None:
            self.timer.cancel()
            self.destroy_timer(self.timer)
            self.timer = None

    def publish_initial_goal_once(self):
        if self.initial_goal_published or self.using_real_goal:
            self.stop_initial_timer()
            return

        if self.goal_pub.get_subscription_count() == 0:
            return

        goal = self.make_initial_goal()
        goal.header.stamp = self.get_clock().now().to_msg()
        self.goal_pub.publish(goal)
        self.initial_goal_published = True
        self.stop_initial_timer()
        self.get_logger().info('Published initial exploration goal once.')

    def publish_active_goal(self):
        if self.using_real_goal and self.real_goal is not None:
            goal = PoseStamped()
            goal.header = self.real_goal.header
            goal.pose = self.real_goal.pose
            if self.latch_real_goal:
                goal.header.stamp = self.get_clock().now().to_msg()
            self.goal_pub.publish(goal)
            return

        self.publish_initial_goal_once()


def main(args=None):
    rclpy.init(args=args)
    node = InitialGoalMux()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
