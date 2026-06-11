import math
import struct

import rclpy
from geometry_msgs.msg import Pose
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu, PointCloud2, PointField
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data


def quat_from_yaw(yaw):
    half = 0.5 * yaw
    return (0.0, 0.0, math.sin(half), math.cos(half))


class SyntheticDlioSensors(Node):
    def __init__(self):
        super().__init__('synthetic_dlio_sensors')
        self.declare_parameter('pointcloud_topic', '/points_raw')
        self.declare_parameter('imu_topic', '/imu_raw')
        self.declare_parameter('start_delay', 4.0)
        self.declare_parameter('linear_x', 0.45)
        self.declare_parameter('angular_z', 0.22)
        self.declare_parameter('cloud_rate', 10.0)
        self.declare_parameter('imu_rate', 100.0)

        self.pointcloud_topic = self.get_parameter('pointcloud_topic').value
        self.imu_topic = self.get_parameter('imu_topic').value
        self.start_delay = float(self.get_parameter('start_delay').value)
        self.linear_x = float(self.get_parameter('linear_x').value)
        self.angular_z = float(self.get_parameter('angular_z').value)
        self.cloud_rate = float(self.get_parameter('cloud_rate').value)
        self.imu_rate = float(self.get_parameter('imu_rate').value)

        self.cloud_pub = self.create_publisher(PointCloud2, self.pointcloud_topic, 10)
        self.imu_pub = self.create_publisher(Imu, self.imu_topic, qos_profile_sensor_data)

        self.start_time = self.get_clock().now()
        self.odom_state = None
        self.pose_state = None
        self.prev_pose_sample = None
        self.map_points = self._make_world_points()

        self.create_subscription(Pose, '/model/dlio_car/pose', self.pose_callback, 10)
        self.create_subscription(Odometry, '/gazebo/odom', self.odom_callback, 10)
        self.create_timer(1.0 / self.cloud_rate, self.publish_cloud)
        self.create_timer(1.0 / self.imu_rate, self.publish_imu)

    def pose_callback(self, msg):
        yaw = self.yaw_from_quaternion(msg.orientation)
        now = self.get_clock().now().nanoseconds * 1e-9
        x = msg.position.x
        y = msg.position.y
        v = 0.0
        w = 0.0
        if self.prev_pose_sample is not None:
            prev_t, prev_x, prev_y, prev_yaw = self.prev_pose_sample
            dt = max(1e-6, now - prev_t)
            cy = math.cos(prev_yaw)
            sy = math.sin(prev_yaw)
            dx = x - prev_x
            dy = y - prev_y
            v = (cy * dx + sy * dy) / dt
            dyaw = math.atan2(math.sin(yaw - prev_yaw), math.cos(yaw - prev_yaw))
            w = dyaw / dt
        self.prev_pose_sample = (now, x, y, yaw)
        self.pose_state = (x, y, yaw, v, w)

    def odom_callback(self, msg):
        yaw = self.yaw_from_quaternion(msg.pose.pose.orientation)
        self.odom_state = (
            msg.pose.pose.position.x,
            msg.pose.pose.position.y,
            yaw,
            msg.twist.twist.linear.x,
            msg.twist.twist.angular.z,
        )

    @staticmethod
    def yaw_from_quaternion(q):
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        return math.atan2(siny_cosp, cosy_cosp)

    def motion_state(self):
        if self.pose_state is not None:
            return self.pose_state
        if self.odom_state is not None:
            return self.odom_state
        return 0.0, 0.0, 0.0, 0.0, 0.0

    def publish_imu(self):
        msg = Imu()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'imu'

        _, _, yaw, v, w = self.motion_state()
        qx, qy, qz, qw = quat_from_yaw(yaw)
        msg.orientation.x = qx
        msg.orientation.y = qy
        msg.orientation.z = qz
        msg.orientation.w = qw

        msg.angular_velocity.z = w
        msg.linear_acceleration.y = v * w
        msg.linear_acceleration.z = 9.80665
        self.imu_pub.publish(msg)

    def publish_cloud(self):
        stamp = self.get_clock().now().to_msg()
        x, y, yaw, _, _ = self.motion_state()
        cy = math.cos(yaw)
        sy = math.sin(yaw)

        packed = bytearray()
        scan_period = 1.0 / self.cloud_rate
        count = 0

        for index, point in enumerate(self.map_points):
            dx = point[0] - x
            dy = point[1] - y
            lx = cy * dx + sy * dy
            ly = -sy * dx + cy * dy
            lz = point[2] - 0.45
            distance = math.sqrt(lx * lx + ly * ly + lz * lz)
            if 0.35 < distance < 18.0 and lx > -2.0:
                point_time = (index % 1024) / 1024.0 * scan_period
                packed.extend(struct.pack('<fffff', lx, ly, lz, 80.0, point_time))
                count += 1

        msg = PointCloud2()
        msg.header.stamp = stamp
        msg.header.frame_id = 'lidar'
        msg.height = 1
        msg.width = count
        msg.fields = [
            PointField(name='x', offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name='y', offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name='z', offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name='intensity', offset=12, datatype=PointField.FLOAT32, count=1),
            PointField(name='time', offset=16, datatype=PointField.FLOAT32, count=1),
        ]
        msg.is_bigendian = False
        msg.point_step = 20
        msg.row_step = msg.point_step * count
        msg.is_dense = True
        msg.data = bytes(packed)
        self.cloud_pub.publish(msg)

    def _make_world_points(self):
        points = []
        for x in self._frange(-10.0, 10.0, 0.35):
            points.append((x, -5.0, 0.2))
            points.append((x, 5.0, 0.2))
            points.append((x, -5.0, 1.2))
            points.append((x, 5.0, 1.2))
        for y in self._frange(-5.0, 5.0, 0.35):
            points.append((-10.0, y, 0.2))
            points.append((10.0, y, 0.2))
            points.append((-10.0, y, 1.2))
            points.append((10.0, y, 1.2))

        for cx, cy in [(-4.0, -1.5), (-1.0, 2.4), (3.0, -2.0), (6.0, 1.7)]:
            for dx in self._frange(-0.6, 0.6, 0.18):
                for dz in self._frange(0.0, 1.8, 0.18):
                    points.append((cx + dx, cy - 0.6, dz))
                    points.append((cx + dx, cy + 0.6, dz))
            for dy in self._frange(-0.6, 0.6, 0.18):
                for dz in self._frange(0.0, 1.8, 0.18):
                    points.append((cx - 0.6, cy + dy, dz))
                    points.append((cx + 0.6, cy + dy, dz))
        return points

    @staticmethod
    def _frange(start, stop, step):
        value = start
        while value <= stop + 1e-9:
            yield value
            value += step


def main():
    rclpy.init()
    node = SyntheticDlioSensors()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
