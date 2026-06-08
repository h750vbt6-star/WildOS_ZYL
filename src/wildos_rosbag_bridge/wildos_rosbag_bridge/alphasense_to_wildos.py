import ast
import math
from typing import List

import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import CameraInfo, CompressedImage, Image


class AlphasenseToWildos(Node):
    """Decode three compressed bag camera streams into WildOS raw image inputs."""

    def __init__(self):
        super().__init__('alphasense_to_wildos')

        self.declare_parameter('camera_names', ['front', 'left', 'right'])
        self.declare_parameter(
            'input_topics',
            (
                '/alphasense_driver_ros/cam0/debayered/image/compressed,'
                '/alphasense_driver_ros/cam1/debayered/image/compressed,'
                '/alphasense_driver_ros/cam2/debayered/image/compressed'
            ),
        )
        self.declare_parameter('cam0_topic', '')
        self.declare_parameter('cam1_topic', '')
        self.declare_parameter('cam2_topic', '')
        self.declare_parameter('output_image_topic_template', '/wildos/{}/color/image_raw')
        self.declare_parameter('output_info_topic_template', '/wildos/{}/color/camera_info')
        self.declare_parameter('output_frame_template', 'wildos_{}_camera_color_optical_frame')

        self.declare_parameter('horizontal_fov_deg', 90.0)
        self.declare_parameter('fx', 0.0)
        self.declare_parameter('fy', 0.0)
        self.declare_parameter('cx', 0.0)
        self.declare_parameter('cy', 0.0)
        self.declare_parameter('distortion', [0.0, 0.0, 0.0, 0.0, 0.0])

        self.camera_names = self.as_string_list(self.get_parameter('camera_names').value)
        self.input_topics = self.as_string_list(self.get_parameter('input_topics').value)
        per_camera_topics = [
            str(self.get_parameter('cam0_topic').value),
            str(self.get_parameter('cam1_topic').value),
            str(self.get_parameter('cam2_topic').value),
        ]
        if any(per_camera_topics):
            if not all(per_camera_topics):
                raise ValueError('cam0_topic, cam1_topic, and cam2_topic must be set together.')
            self.input_topics = per_camera_topics
        self.output_image_template = str(self.get_parameter('output_image_topic_template').value)
        self.output_info_template = str(self.get_parameter('output_info_topic_template').value)
        self.output_frame_template = str(self.get_parameter('output_frame_template').value)

        if len(self.camera_names) != 3:
            raise ValueError('camera_names must contain exactly three entries.')
        if len(self.input_topics) != len(self.camera_names):
            raise ValueError('input_topics must have the same length as camera_names.')

        self.horizontal_fov_deg = float(self.get_parameter('horizontal_fov_deg').value)
        self.fx = float(self.get_parameter('fx').value)
        self.fy = float(self.get_parameter('fy').value)
        self.cx = float(self.get_parameter('cx').value)
        self.cy = float(self.get_parameter('cy').value)
        self.distortion = [float(v) for v in self.get_parameter('distortion').value]

        sub_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )
        pub_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
        )

        self.output_frames: List[str] = []
        self.image_pubs = []
        self.info_pubs = []
        self.seen_first_image = [False] * len(self.camera_names)

        for idx, camera_name in enumerate(self.camera_names):
            self.output_frames.append(self.output_frame_template.format(camera_name))
            self.image_pubs.append(
                self.create_publisher(
                    Image,
                    self.output_image_template.format(camera_name),
                    pub_qos,
                )
            )
            self.info_pubs.append(
                self.create_publisher(
                    CameraInfo,
                    self.output_info_template.format(camera_name),
                    pub_qos,
                )
            )
            self.create_subscription(
                CompressedImage,
                self.input_topics[idx],
                lambda msg, camera_idx=idx: self.image_callback(camera_idx, msg),
                sub_qos,
            )

        self.get_logger().info(
            'Bridging compressed alphasense cameras to WildOS raw image topics: '
            + ', '.join(
                f'{src} -> {self.output_image_template.format(name)}'
                for src, name in zip(self.input_topics, self.camera_names)
            )
        )

    def image_callback(self, camera_idx: int, msg: CompressedImage):
        image = self.decode_compressed_image(msg)
        if image is None:
            self.get_logger().warn(
                f'Failed to decode compressed image for {self.camera_names[camera_idx]}.',
                throttle_duration_sec=2.0,
            )
            return

        image_msg = self.to_image_msg(image, msg, self.output_frames[camera_idx])
        info_msg = self.make_camera_info(image_msg)

        self.image_pubs[camera_idx].publish(image_msg)
        self.info_pubs[camera_idx].publish(info_msg)

        if not self.seen_first_image[camera_idx]:
            self.seen_first_image[camera_idx] = True
            self.get_logger().info(
                f'Publishing {self.camera_names[camera_idx]} images as '
                f'{image_msg.width}x{image_msg.height} rgb8 in frame {image_msg.header.frame_id}.'
            )

    @staticmethod
    def as_string_list(value) -> List[str]:
        if isinstance(value, str):
            try:
                parsed = ast.literal_eval(value)
            except (SyntaxError, ValueError):
                parsed = None
            if isinstance(parsed, (list, tuple)):
                return [str(item) for item in parsed]
            return [item.strip() for item in value.split(',') if item.strip()]
        return [str(item) for item in value]

    @staticmethod
    def decode_compressed_image(msg: CompressedImage):
        encoded = np.frombuffer(bytes(msg.data), dtype=np.uint8)
        bgr = cv2.imdecode(encoded, cv2.IMREAD_COLOR)
        if bgr is None:
            return None
        return cv2.cvtColor(bgr, cv2.COLOR_BGR2RGB)

    @staticmethod
    def to_image_msg(image: np.ndarray, source_msg: CompressedImage, frame_id: str) -> Image:
        height, width, channels = image.shape
        if channels != 3:
            raise ValueError(f'Expected an RGB image with 3 channels, got {channels}.')

        msg = Image()
        msg.header.stamp = source_msg.header.stamp
        msg.header.frame_id = frame_id
        msg.height = height
        msg.width = width
        msg.encoding = 'rgb8'
        msg.is_bigendian = False
        msg.step = width * channels
        msg.data = image.tobytes()
        return msg

    def make_camera_info(self, image_msg: Image) -> CameraInfo:
        width = float(image_msg.width)
        height = float(image_msg.height)

        if self.fx > 0.0:
            fx = self.fx
        else:
            hfov = math.radians(max(1.0, min(179.0, self.horizontal_fov_deg)))
            fx = 0.5 * width / math.tan(0.5 * hfov)

        fy = self.fy if self.fy > 0.0 else fx
        cx = self.cx if self.cx > 0.0 else 0.5 * (width - 1.0)
        cy = self.cy if self.cy > 0.0 else 0.5 * (height - 1.0)

        info = CameraInfo()
        info.header.stamp = image_msg.header.stamp
        info.header.frame_id = image_msg.header.frame_id
        info.height = image_msg.height
        info.width = image_msg.width
        info.distortion_model = 'plumb_bob'
        info.d = self.distortion
        info.k = [
            fx, 0.0, cx,
            0.0, fy, cy,
            0.0, 0.0, 1.0,
        ]
        info.r = [
            1.0, 0.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 0.0, 1.0,
        ]
        info.p = [
            fx, 0.0, cx, 0.0,
            0.0, fy, cy, 0.0,
            0.0, 0.0, 1.0, 0.0,
        ]
        return info


def main(args=None):
    rclpy.init(args=args)
    node = AlphasenseToWildos()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
