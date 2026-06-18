import math

import rclpy
from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.node import Node


def yaw_from_quaternion(q):
    siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
    cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
    return math.atan2(siny_cosp, cosy_cosp)


def angle_distance(a, b):
    return abs(math.atan2(math.sin(a - b), math.cos(a - b)))


class GoalPoseToNav2Action(Node):
    def __init__(self):
        super().__init__('goal_pose_to_nav2_action')

        self.declare_parameter('goal_topic', '/goal_pose')
        self.declare_parameter('action_name', '/navigate_to_pose')
        self.declare_parameter('default_frame_id', 'odom')
        self.declare_parameter('send_period', 0.2)
        self.declare_parameter('min_goal_distance', 0.08)
        self.declare_parameter('min_goal_yaw', 0.15)
        self.declare_parameter('stamp_goal_with_now', True)
        self.declare_parameter('cancel_on_new_goal', True)
        self.declare_parameter('server_wait_timeout', 0.1)

        goal_topic = self.get_parameter('goal_topic').value
        action_name = self.get_parameter('action_name').value
        self.default_frame_id = self.get_parameter('default_frame_id').value
        self.send_period = float(self.get_parameter('send_period').value)
        self.min_goal_distance = float(self.get_parameter('min_goal_distance').value)
        self.min_goal_yaw = float(self.get_parameter('min_goal_yaw').value)
        self.stamp_goal_with_now = bool(self.get_parameter('stamp_goal_with_now').value)
        self.cancel_on_new_goal = bool(self.get_parameter('cancel_on_new_goal').value)
        self.server_wait_timeout = float(self.get_parameter('server_wait_timeout').value)

        self.latest_goal = None
        self.sent_goal = None
        self.current_goal_handle = None
        self.goal_active = False
        self.sending_goal = False
        self.canceling_goal = False
        self.last_send_time = None
        self.server_warned = False

        self.action_client = ActionClient(self, NavigateToPose, action_name)
        self.goal_sub = self.create_subscription(PoseStamped, goal_topic, self.goal_callback, 10)
        self.timer = self.create_timer(0.1, self.maybe_send_goal)

        self.get_logger().info(
            f'Forwarding {goal_topic} PoseStamped messages to Nav2 action {action_name}.'
        )

    def goal_callback(self, msg):
        goal = PoseStamped()
        goal.header = msg.header
        goal.pose = msg.pose
        if not goal.header.frame_id:
            goal.header.frame_id = self.default_frame_id
        if self.stamp_goal_with_now:
            goal.header.stamp = self.get_clock().now().to_msg()
        self.latest_goal = goal

    def maybe_send_goal(self):
        if self.latest_goal is None or self.sending_goal or self.canceling_goal:
            return

        if not self.action_client.server_is_ready():
            if not self.action_client.wait_for_server(timeout_sec=self.server_wait_timeout):
                if not self.server_warned:
                    self.get_logger().warn('Waiting for Nav2 NavigateToPose action server...')
                    self.server_warned = True
                return
            self.server_warned = False

        now = self.get_clock().now()
        if self.last_send_time is not None:
            elapsed = (now - self.last_send_time).nanoseconds * 1e-9
            if elapsed < self.send_period:
                return

        if self.sent_goal is not None and not self.goal_changed_enough(self.latest_goal, self.sent_goal):
            return

        if self.goal_active and self.current_goal_handle is not None:
            if self.cancel_on_new_goal:
                self.cancel_current_goal()
            return

        self.send_goal(self.latest_goal)

    def goal_changed_enough(self, new_goal, old_goal):
        dx = new_goal.pose.position.x - old_goal.pose.position.x
        dy = new_goal.pose.position.y - old_goal.pose.position.y
        dz = new_goal.pose.position.z - old_goal.pose.position.z
        dist = math.sqrt(dx * dx + dy * dy + dz * dz)
        if dist >= self.min_goal_distance:
            return True

        new_yaw = yaw_from_quaternion(new_goal.pose.orientation)
        old_yaw = yaw_from_quaternion(old_goal.pose.orientation)
        return angle_distance(new_yaw, old_yaw) >= self.min_goal_yaw

    def cancel_current_goal(self):
        self.canceling_goal = True
        cancel_future = self.current_goal_handle.cancel_goal_async()
        cancel_future.add_done_callback(self.cancel_done_callback)

    def cancel_done_callback(self, future):
        self.canceling_goal = False
        self.goal_active = False
        try:
            future.result()
        except Exception as exc:
            self.get_logger().warn(f'Failed to cancel previous Nav2 goal: {exc}')
        self.send_goal(self.latest_goal)

    def send_goal(self, pose):
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = pose
        goal_msg.behavior_tree = ''

        self.sending_goal = True
        self.last_send_time = self.get_clock().now()
        future = self.action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback,
        )
        future.add_done_callback(lambda done_future: self.goal_response_callback(done_future, pose))

    def goal_response_callback(self, future, pose):
        self.sending_goal = False
        try:
            goal_handle = future.result()
        except Exception as exc:
            self.get_logger().warn(f'Failed to send Nav2 goal: {exc}')
            self.current_goal_handle = None
            self.sent_goal = None
            return

        if not goal_handle.accepted:
            self.get_logger().warn('Nav2 rejected goal.')
            self.current_goal_handle = None
            self.sent_goal = None
            return

        self.current_goal_handle = goal_handle
        self.goal_active = True
        self.sent_goal = pose
        self.get_logger().info(
            f'Sent Nav2 goal ({pose.pose.position.x:.2f}, '
            f'{pose.pose.position.y:.2f}) in {pose.header.frame_id}.'
        )

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.result_callback)

    def result_callback(self, future):
        self.goal_active = False
        self.current_goal_handle = None
        try:
            result = future.result()
        except Exception as exc:
            self.get_logger().warn(f'Failed to get Nav2 result: {exc}')
            self.sent_goal = None
            return
        self.get_logger().info(f'Nav2 goal finished with status {result.status}.')
        self.sent_goal = None

    def feedback_callback(self, _feedback_msg):
        return


def main(args=None):
    rclpy.init(args=args)
    node = GoalPoseToNav2Action()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
