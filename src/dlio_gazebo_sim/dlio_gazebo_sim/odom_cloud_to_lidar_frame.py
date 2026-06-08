import numpy as np
import rclpy
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2, PointField
from sensor_msgs_py import point_cloud2
from tf2_ros import Buffer, TransformException, TransformListener


def quaternion_to_matrix(q):
    x = float(q.x)
    y = float(q.y)
    z = float(q.z)
    w = float(q.w)
    n = x * x + y * y + z * z + w * w
    if n <= 0.0:
        return np.eye(3, dtype=np.float32)
    s = 2.0 / n
    xx = x * x * s
    xy = x * y * s
    xz = x * z * s
    xw = x * w * s
    yy = y * y * s
    yz = y * z * s
    yw = y * w * s
    zz = z * z * s
    zw = z * w * s
    return np.array(
        [
            [1.0 - yy - zz, xy - zw, xz + yw],
            [xy + zw, 1.0 - xx - zz, yz - xw],
            [xz - yw, yz + xw, 1.0 - xx - yy],
        ],
        dtype=np.float32,
    )


def field_map(fields):
    return {field.name: field for field in fields}


class OdomCloudToLidarFrame(Node):
    """Re-express an odom-frame DLIO cloud in the LiDAR frame.

    DLIO publishes its deskewed cloud already transformed into odom.  That is
    useful for visualization, but elevation_mapping needs the sensor frame so
    it can recover the sensor origin from TF.  This node applies the inverse TF
    geometry and preserves all PointCloud2 fields.
    """

    def __init__(self):
        super().__init__('odom_cloud_to_lidar_frame')
        self.declare_parameter('input_topic', '/dlio/odom_node/pointcloud/deskewed')
        self.declare_parameter('output_topic', '/points_deskewed_lidar')
        self.declare_parameter('target_frame', 'pandar')
        self.declare_parameter('tf_timeout_sec', 0.05)

        self.input_topic = self.get_parameter('input_topic').value
        self.output_topic = self.get_parameter('output_topic').value
        self.target_frame = self.get_parameter('target_frame').value
        self.tf_timeout = Duration(seconds=float(self.get_parameter('tf_timeout_sec').value))

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.pub = self.create_publisher(PointCloud2, self.output_topic, 10)
        self.create_subscription(PointCloud2, self.input_topic, self.cloud_callback, 10)
        self.warn_count = 0

        self.get_logger().info(
            f'Re-expressing {self.input_topic} in frame {self.target_frame} on {self.output_topic}'
        )

    def cloud_callback(self, msg):
        source_frame = msg.header.frame_id
        if not source_frame:
            self.get_logger().warn('Skipping cloud with empty header.frame_id')
            return

        fields = field_map(msg.fields)
        if not all(name in fields for name in ('x', 'y', 'z')):
            self.get_logger().warn('Skipping cloud without x/y/z fields')
            return
        if any(fields[name].datatype != PointField.FLOAT32 or fields[name].count != 1 for name in ('x', 'y', 'z')):
            self.get_logger().warn('Skipping cloud because x/y/z are not FLOAT32 scalar fields')
            return
        if msg.is_bigendian:
            self.get_logger().warn('Skipping big-endian PointCloud2; only little-endian clouds are supported')
            return

        if source_frame == self.target_frame:
            out = PointCloud2()
            out.header = msg.header
            out.height = msg.height
            out.width = msg.width
            out.fields = msg.fields
            out.is_bigendian = msg.is_bigendian
            out.point_step = msg.point_step
            out.row_step = msg.row_step
            out.is_dense = msg.is_dense
            out.data = msg.data
            self.pub.publish(out)
            return

        try:
            transform = self.tf_buffer.lookup_transform(
                self.target_frame,
                source_frame,
                msg.header.stamp,
                timeout=self.tf_timeout,
            )
        except TransformException as exc:
            self.warn_count += 1
            if self.warn_count <= 5 or self.warn_count % 50 == 0:
                self.get_logger().warn(
                    f'TF not available for {source_frame} -> {self.target_frame} '
                    f'at {msg.header.stamp.sec}.{msg.header.stamp.nanosec:09d}: {exc}'
                )
            return

        dtype = point_cloud2.dtype_from_fields(msg.fields, msg.point_step)
        point_count = int(msg.width * msg.height)
        if len(msg.data) < point_count * msg.point_step:
            self.get_logger().warn('Skipping malformed cloud with data shorter than width*height*point_step')
            return

        cloud = np.frombuffer(msg.data, dtype=dtype, count=point_count).copy()
        x = cloud['x'].astype(np.float32, copy=False)
        y = cloud['y'].astype(np.float32, copy=False)
        z = cloud['z'].astype(np.float32, copy=False)

        t = transform.transform.translation
        translation = np.array([t.x, t.y, t.z], dtype=np.float32)
        rotation = quaternion_to_matrix(transform.transform.rotation)

        valid = np.isfinite(x) & np.isfinite(y) & np.isfinite(z)
        if np.any(valid):
            xyz = np.stack((x[valid], y[valid], z[valid]), axis=0)
            xyz_t = rotation @ xyz + translation[:, None]
            cloud['x'][valid] = xyz_t[0]
            cloud['y'][valid] = xyz_t[1]
            cloud['z'][valid] = xyz_t[2]

        out = PointCloud2()
        out.header = msg.header
        out.header.frame_id = self.target_frame
        out.height = msg.height
        out.width = msg.width
        out.fields = msg.fields
        out.is_bigendian = msg.is_bigendian
        out.point_step = msg.point_step
        out.row_step = msg.point_step * msg.width
        out.is_dense = bool(msg.is_dense and np.all(valid))
        out.data = cloud.tobytes()

        if msg.height > 1 and msg.row_step != msg.point_step * msg.width:
            self.get_logger().warn(
                'Output cloud was compacted because organized row padding is not preserved'
            )

        self.pub.publish(out)


def main():
    rclpy.init()
    node = OdomCloudToLidarFrame()
    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(node)
    try:
        executor.spin()
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        executor.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
