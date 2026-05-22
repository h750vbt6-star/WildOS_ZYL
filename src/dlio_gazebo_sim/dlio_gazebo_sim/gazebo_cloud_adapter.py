import math
import struct

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2, PointField
from sensor_msgs_py import point_cloud2


class GazeboCloudAdapter(Node):
    def __init__(self):
        super().__init__('gazebo_cloud_adapter')
        self.declare_parameter('input_topic', '/points_raw/points')
        self.declare_parameter('output_topic', '/points_raw')
        self.declare_parameter('frame_id', 'lidar')
        self.declare_parameter('min_range', 0.25)
        self.declare_parameter('max_range', 18.0)

        self.input_topic = self.get_parameter('input_topic').value
        self.output_topic = self.get_parameter('output_topic').value
        self.frame_id = self.get_parameter('frame_id').value
        self.min_range = float(self.get_parameter('min_range').value)
        self.max_range = float(self.get_parameter('max_range').value)

        self.cloud_pub = self.create_publisher(PointCloud2, self.output_topic, 10)
        self.create_subscription(PointCloud2, self.input_topic, self.cloud_callback, 10)

    def cloud_callback(self, msg):
        points = []
        for point in (
            point_cloud2.read_points(
                msg,
                field_names=('x', 'y', 'z', 'intensity'),
                skip_nans=False,
            )
        ):
            x, y, z, intensity = map(float, point)
            if not (math.isfinite(x) and math.isfinite(y) and math.isfinite(z)):
                continue

            distance = math.sqrt(x * x + y * y + z * z)
            if distance < self.min_range or distance > self.max_range:
                continue

            points.append((x, y, z, intensity))

        packed = bytearray()
        for point in points:
            packed.extend(struct.pack('<ffff', *point))

        adapted = PointCloud2()
        adapted.header = msg.header
        adapted.header.frame_id = self.frame_id
        adapted.height = 1
        adapted.width = len(points)
        adapted.fields = [
            PointField(name='x', offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name='y', offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name='z', offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name='intensity', offset=12, datatype=PointField.FLOAT32, count=1),
        ]
        adapted.is_bigendian = False
        adapted.point_step = 16
        adapted.row_step = adapted.point_step * len(points)
        adapted.is_dense = True
        adapted.data = bytes(packed)
        self.cloud_pub.publish(adapted)


def main():
    rclpy.init()
    node = GazeboCloudAdapter()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
