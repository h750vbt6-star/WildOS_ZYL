import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Imu


class LivoxImuAdapter(Node):
    """Convert Livox acceleration from g to ROS-standard m/s^2."""

    def __init__(self):
        super().__init__('livox_imu_adapter')
        self.declare_parameter('input_topic', '/go2/livox/imu_raw_g')
        self.declare_parameter('output_topic', '/imu_raw')
        self.declare_parameter('output_frame', 'livox_imu_frame')
        self.declare_parameter('acceleration_scale', 9.80665)

        self.input_topic = self.get_parameter('input_topic').value
        self.output_topic = self.get_parameter('output_topic').value
        self.output_frame = self.get_parameter('output_frame').value
        self.acceleration_scale = float(self.get_parameter('acceleration_scale').value)

        self.publisher = self.create_publisher(Imu, self.output_topic, qos_profile_sensor_data)
        self.subscription = self.create_subscription(
            Imu,
            self.input_topic,
            self.imu_callback,
            qos_profile_sensor_data,
        )

        self.get_logger().info(
            f'Converting Livox IMU acceleration on {self.input_topic} by '
            f'{self.acceleration_scale:.5f} and publishing {self.output_topic}'
        )

    def imu_callback(self, msg):
        out = Imu()
        out.header = msg.header
        if self.output_frame:
            out.header.frame_id = self.output_frame

        out.orientation = msg.orientation
        out.orientation_covariance = msg.orientation_covariance
        out.angular_velocity = msg.angular_velocity
        out.angular_velocity_covariance = msg.angular_velocity_covariance

        out.linear_acceleration.x = msg.linear_acceleration.x * self.acceleration_scale
        out.linear_acceleration.y = msg.linear_acceleration.y * self.acceleration_scale
        out.linear_acceleration.z = msg.linear_acceleration.z * self.acceleration_scale

        if msg.linear_acceleration_covariance[0] < 0.0:
            out.linear_acceleration_covariance = msg.linear_acceleration_covariance
        else:
            variance_scale = self.acceleration_scale * self.acceleration_scale
            out.linear_acceleration_covariance = [
                value * variance_scale for value in msg.linear_acceleration_covariance
            ]

        self.publisher.publish(out)


def main():
    rclpy.init()
    node = LivoxImuAdapter()
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
