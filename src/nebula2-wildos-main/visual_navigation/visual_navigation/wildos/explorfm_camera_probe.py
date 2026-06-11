import argparse
import json
import time
from pathlib import Path

import cv2
import numpy as np
import rclpy
import torch
from ament_index_python.packages import get_package_share_directory
from cv_bridge import CvBridge
from message_filters import ApproximateTimeSynchronizer, Subscriber
from omegaconf import OmegaConf
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image as ImageMsg
from std_msgs.msg import String
from torchvision import transforms

from explorfm import ExploRFMInference
from visual_navigation.utils.viz import make_colorbar, make_subplot_grid, overlay_heatmap


HOME_DIR = Path.home()
CAMERA_MAPPING = {
    0: "front",
    1: "left",
    2: "right",
}


def _resolve_ckpt_path(path_value):
    path = Path(str(path_value))
    if path.is_absolute():
        return path
    return HOME_DIR / "ckpts" / path


def _range_stats(value_map: np.ndarray):
    values = np.asarray(value_map, dtype=np.float32)
    finite = values[np.isfinite(values)]
    total = int(values.size)
    finite_count = int(finite.size)
    nan_count = int(np.isnan(values).sum())
    posinf_count = int(np.isposinf(values).sum())
    neginf_count = int(np.isneginf(values).sum())
    if finite.size == 0:
        return {
            "min": None,
            "max": None,
            "mean": None,
            "finite_count": finite_count,
            "total": total,
            "nan_count": nan_count,
            "posinf_count": posinf_count,
            "neginf_count": neginf_count,
        }
    return {
        "min": float(finite.min()),
        "max": float(finite.max()),
        "mean": float(finite.mean()),
        "finite_count": finite_count,
        "total": total,
        "nan_count": nan_count,
        "posinf_count": posinf_count,
        "neginf_count": neginf_count,
    }


def _range_title(label: str, value_map: np.ndarray) -> str:
    stats = _range_stats(value_map)
    if stats["min"] is None:
        return f"{label} nan"
    return f"{label} {stats['min']:.2f}-{stats['max']:.2f}"


def _dynamic_overlay(rgb_img: np.ndarray, value_map: np.ndarray) -> np.ndarray:
    values = np.asarray(value_map, dtype=np.float32)
    finite = values[np.isfinite(values)]
    if finite.size == 0:
        return rgb_img.copy()

    vmin = float(np.percentile(finite, 2.0))
    vmax = float(np.percentile(finite, 98.0))
    if vmax - vmin < 1e-4:
        vmin = float(finite.min())
        vmax = float(finite.max())
    if vmax - vmin < 1e-4:
        vmax = vmin + 1e-4

    return overlay_heatmap(rgb_img, values, alpha=0.5, vmin=vmin, vmax=vmax)


def _sanitize_prob_map(value_map: np.ndarray) -> np.ndarray:
    clean = np.nan_to_num(value_map, nan=0.0, posinf=1.0, neginf=0.0)
    return np.clip(clean, 0.0, 1.0).astype(np.float32)


def _make_prediction_grid(rgb_imgs, batch_frontiers, batch_trav, fig_resize_factor: float):
    img_grid = {}
    stats = {}
    num_cameras = len(rgb_imgs)

    for i in range(num_cameras):
        cam_name = CAMERA_MAPPING[i]
        raw_frontier_map = batch_frontiers[i, 0].astype(np.float32)
        raw_trav_map = batch_trav[i, 0].astype(np.float32)
        frontier_map = _sanitize_prob_map(raw_frontier_map)
        trav_map = _sanitize_prob_map(raw_trav_map)
        stats[cam_name] = {
            "frontier_raw": _range_stats(raw_frontier_map),
            "traversability_raw": _range_stats(raw_trav_map),
            "frontier": _range_stats(frontier_map),
            "traversability": _range_stats(trav_map),
        }

        rgb_img = cv2.resize(
            rgb_imgs[i],
            (0, 0),
            fx=fig_resize_factor,
            fy=fig_resize_factor,
        )
        frontier_resized = cv2.resize(
            frontier_map,
            (rgb_img.shape[1], rgb_img.shape[0]),
            interpolation=cv2.INTER_LINEAR,
        )
        trav_resized = cv2.resize(
            trav_map,
            (rgb_img.shape[1], rgb_img.shape[0]),
            interpolation=cv2.INTER_LINEAR,
        )

        img_grid[(0, i)] = (rgb_img, f"RGB {cam_name}")
        img_grid[(1, i)] = (
            overlay_heatmap(rgb_img, frontier_resized, alpha=0.5),
            _range_title("Frontier abs", frontier_resized),
        )
        img_grid[(2, i)] = (
            _dynamic_overlay(rgb_img, frontier_resized),
            _range_title("Frontier dyn", frontier_resized),
        )
        img_grid[(3, i)] = (
            overlay_heatmap(rgb_img, trav_resized, alpha=0.5),
            _range_title("Trav abs", trav_resized),
        )
        img_grid[(4, i)] = (
            _dynamic_overlay(rgb_img, trav_resized),
            _range_title("Trav dyn", trav_resized),
        )

    grid = make_subplot_grid(img_grid, (5, num_cameras), pad=8, title_font_scale=0.34)
    cbar = make_colorbar(
        height=max(20, grid.shape[0] - 60),
        width=20,
        vmin=0,
        vmax=1,
        cmap=cv2.COLORMAP_JET,
        num_ticks=10,
        font_scale=0.32,
        pad=30,
    )
    return cv2.hconcat([grid, cbar]), stats


def _load_rgb(path: str) -> np.ndarray:
    img_bgr = cv2.imread(str(path), cv2.IMREAD_COLOR)
    if img_bgr is None:
        raise FileNotFoundError(f"Could not read image: {path}")
    return cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)


def run_offline_image_test(config, image_paths, output_path: str):
    rgb_imgs = [_load_rgb(path) for path in image_paths]
    target_h, target_w = rgb_imgs[0].shape[:2]
    rgb_imgs = [
        cv2.resize(img, (target_w, target_h), interpolation=cv2.INTER_AREA)
        if img.shape[:2] != (target_h, target_w) else img
        for img in rgb_imgs
    ]

    model = ExploRFMInference(
        frontier_ckpt=_resolve_ckpt_path(config.frontier_ckpt),
        traversability_ckpt=_resolve_ckpt_path(config.traversability_ckpt),
        model_version=config.model_version,
        adaptor_version=config.adaptor_version,
        adaptor_ckpt_path=HOME_DIR / "ckpts",
        use_naclip=config.use_naclip,
        use_summary_for_spatial=config.use_summary_for_spatial,
        radio_dim=config.radio_dim,
        static_scale_factor=config.static_scale_factor,
        model_precision=config.model_precision,
    )
    to_tensor = transforms.Compose([transforms.ToTensor()])
    batch_tensor = torch.stack([to_tensor(img.copy()) for img in rgb_imgs])

    with torch.inference_mode():
        batch_trav, batch_frontiers, _ = model.forward(batch_tensor)

    batch_frontiers = batch_frontiers.detach().cpu().numpy().astype(np.float32)
    batch_trav = batch_trav.detach().cpu().numpy().astype(np.float32)
    grid, stats = _make_prediction_grid(
        rgb_imgs,
        batch_frontiers,
        batch_trav,
        fig_resize_factor=float(config.fig_resize_factor),
    )

    output = Path(output_path)
    output.parent.mkdir(parents=True, exist_ok=True)
    cv2.imwrite(str(output), cv2.cvtColor(grid, cv2.COLOR_RGB2BGR))
    return output, stats


class ExploRFMCameraProbe(Node):
    default_config = {
        "frontier_ckpt": "frontier_head.ckpt",
        "traversability_ckpt": "trav_head.ckpt",
        "model_version": "c-radio_v3-b",
        "adaptor_version": None,
        "use_naclip": True,
        "use_summary_for_spatial": True,
        "radio_dim": 768,
        "static_scale_factor": 0.75,
        "model_precision": "FP16",
        "num_cameras": 3,
        "cams_inverted": False,
        "fig_resize_factor": 0.45,
        "camera_img_topic": "/wildos/{}/color/image_raw",
        "model_viz_topic": "/explorfm_probe/model_visualization",
        "stats_topic": "/explorfm_probe/stats",
        "map_topic_prefix": "/explorfm_probe/maps",
        "qos_history_depth": 10,
        "syncsub_queue_size": 30,
        "syncsub_slop": 0.2,
        "publish_raw_maps": True,
        "process_every_n": 1,
    }

    def __init__(self, config: OmegaConf = OmegaConf.create()):
        config = OmegaConf.merge(OmegaConf.create(self.default_config), config)
        super().__init__("explorfm_camera_probe")

        self.br = CvBridge()
        self.num_cameras = int(config.num_cameras)
        self.cam_inverted = bool(config.cams_inverted)
        self.fig_resize_factor = float(config.fig_resize_factor)
        self.process_every_n = max(1, int(config.process_every_n))
        self.using_compressed_imgs = "compressed" in str(config.camera_img_topic)
        self.transforms = transforms.Compose([transforms.ToTensor()])
        self.callback_count = 0
        self.processed_count = 0

        if self.num_cameras != 3:
            raise ValueError("explorfm_camera_probe is intended for the 3-camera Gazebo setup.")

        self.get_logger().info("Loading ExploRFM for RGB-only camera probe...")
        self.model = ExploRFMInference(
            frontier_ckpt=_resolve_ckpt_path(config.frontier_ckpt),
            traversability_ckpt=_resolve_ckpt_path(config.traversability_ckpt),
            model_version=config.model_version,
            adaptor_version=config.adaptor_version,
            adaptor_ckpt_path=HOME_DIR / "ckpts",
            use_naclip=config.use_naclip,
            use_summary_for_spatial=config.use_summary_for_spatial,
            radio_dim=config.radio_dim,
            static_scale_factor=config.static_scale_factor,
            model_precision=config.model_precision,
        )
        self.get_logger().info("Finished loading ExploRFM.")

        self.model_viz_pub = self.create_publisher(ImageMsg, config.model_viz_topic, 10)
        self.stats_pub = self.create_publisher(String, config.stats_topic, 10)
        self.publish_raw_maps = bool(config.publish_raw_maps)
        self.frontier_map_pubs = {}
        self.trav_map_pubs = {}
        if self.publish_raw_maps:
            for cam_name in CAMERA_MAPPING.values():
                self.frontier_map_pubs[cam_name] = self.create_publisher(
                    ImageMsg,
                    f"{config.map_topic_prefix}/{cam_name}/frontier",
                    10,
                )
                self.trav_map_pubs[cam_name] = self.create_publisher(
                    ImageMsg,
                    f"{config.map_topic_prefix}/{cam_name}/traversability",
                    10,
                )

        img_msg_type = CompressedImage if self.using_compressed_imgs else ImageMsg
        self.camera_subs = [
            Subscriber(
                self,
                img_msg_type,
                config.camera_img_topic.format(CAMERA_MAPPING[i]),
                qos_profile=config.qos_history_depth,
            )
            for i in range(self.num_cameras)
        ]
        self.ts = ApproximateTimeSynchronizer(
            self.camera_subs,
            queue_size=config.syncsub_queue_size,
            slop=config.syncsub_slop,
        )
        self.ts.registerCallback(self.listener_callback)

        topics = ", ".join(config.camera_img_topic.format(CAMERA_MAPPING[i]) for i in range(self.num_cameras))
        self.get_logger().info(f"Subscribed to RGB camera topics: {topics}")
        self.get_logger().info(f"Publishing ExploRFM-only visualization on {config.model_viz_topic}")

    def listener_callback(self, *img_msgs):
        self.callback_count += 1
        if self.callback_count % self.process_every_n != 0:
            return

        start = time.perf_counter()
        rgb_imgs = self._decode_images(img_msgs)
        batch_tensor = torch.stack([self.transforms(img.copy()) for img in rgb_imgs])

        with torch.inference_mode():
            batch_trav, batch_frontiers, _ = self.model.forward(batch_tensor)

        batch_frontiers = batch_frontiers.detach().cpu().numpy().astype(np.float32)
        batch_trav = batch_trav.detach().cpu().numpy().astype(np.float32)

        self.processed_count += 1
        stats = self._publish_outputs(img_msgs, rgb_imgs, batch_frontiers, batch_trav)
        elapsed = time.perf_counter() - start
        compact = "; ".join(
            f"{cam}: F {s['frontier']['min']:.3f}-{s['frontier']['max']:.3f} "
            f"T {s['traversability']['min']:.3f}-{s['traversability']['max']:.3f}"
            for cam, s in stats.items()
            if s["frontier"]["min"] is not None and s["traversability"]["min"] is not None
        )
        self.get_logger().info(f"ExploRFM probe frame {self.processed_count} in {elapsed:.2f}s | {compact}")

    def _decode_images(self, img_msgs):
        if self.using_compressed_imgs:
            convert_func = self.br.compressed_imgmsg_to_cv2
        else:
            convert_func = self.br.imgmsg_to_cv2

        rgb_imgs = []
        for msg in img_msgs:
            img = convert_func(msg, desired_encoding="rgb8")
            if self.cam_inverted:
                img = np.rot90(img, k=2)
            rgb_imgs.append(img)
        return rgb_imgs

    def _publish_outputs(self, img_msgs, rgb_imgs, batch_frontiers, batch_trav):
        img_grid = {}
        stats = {}

        for i in range(self.num_cameras):
            cam_name = CAMERA_MAPPING[i]
            frontier_map = _sanitize_prob_map(batch_frontiers[i, 0])
            trav_map = _sanitize_prob_map(batch_trav[i, 0])
            stats[cam_name] = {
                "frontier": _range_stats(frontier_map),
                "traversability": _range_stats(trav_map),
            }

            rgb_img = cv2.resize(
                rgb_imgs[i],
                (0, 0),
                fx=self.fig_resize_factor,
                fy=self.fig_resize_factor,
            )
            frontier_resized = cv2.resize(
                frontier_map,
                (rgb_img.shape[1], rgb_img.shape[0]),
                interpolation=cv2.INTER_LINEAR,
            )
            trav_resized = cv2.resize(
                trav_map,
                (rgb_img.shape[1], rgb_img.shape[0]),
                interpolation=cv2.INTER_LINEAR,
            )

            img_grid[(0, i)] = (rgb_img, f"RGB {cam_name}")
            img_grid[(1, i)] = (
                overlay_heatmap(rgb_img, frontier_resized, alpha=0.5),
                _range_title("Frontier abs", frontier_resized),
            )
            img_grid[(2, i)] = (
                _dynamic_overlay(rgb_img, frontier_resized),
                _range_title("Frontier dyn", frontier_resized),
            )
            img_grid[(3, i)] = (
                overlay_heatmap(rgb_img, trav_resized, alpha=0.5),
                _range_title("Trav abs", trav_resized),
            )
            img_grid[(4, i)] = (
                _dynamic_overlay(rgb_img, trav_resized),
                _range_title("Trav dyn", trav_resized),
            )

            if self.publish_raw_maps:
                header = img_msgs[i].header
                frontier_msg = self.br.cv2_to_imgmsg(frontier_map.astype(np.float32), encoding="32FC1")
                frontier_msg.header = header
                trav_msg = self.br.cv2_to_imgmsg(trav_map.astype(np.float32), encoding="32FC1")
                trav_msg.header = header
                self.frontier_map_pubs[cam_name].publish(frontier_msg)
                self.trav_map_pubs[cam_name].publish(trav_msg)

        grid = make_subplot_grid(img_grid, (5, self.num_cameras), pad=8, title_font_scale=0.34)
        cbar = make_colorbar(
            height=max(20, grid.shape[0] - 60),
            width=20,
            vmin=0,
            vmax=1,
            cmap=cv2.COLORMAP_JET,
            num_ticks=10,
            font_scale=0.32,
            pad=30,
        )
        grid = cv2.hconcat([grid, cbar])
        self.model_viz_pub.publish(self.br.cv2_to_imgmsg(grid, encoding="rgb8"))

        stats_msg = String()
        stats_msg.data = json.dumps(
            {
                "frame": self.processed_count,
                "stats": stats,
            },
            sort_keys=True,
        )
        self.stats_pub.publish(stats_msg)
        return stats


def _resolve_config(config_name: str) -> Path:
    config_path = Path(config_name)
    if config_path.is_absolute():
        return config_path
    if not config_name.endswith(".yaml"):
        config_name += ".yaml"
    package_share_directory = Path(get_package_share_directory("visual_navigation"))
    return package_share_directory / "configs" / config_name


def main(args=None):
    custom_args = rclpy.utilities.remove_ros_args(args)

    parser = argparse.ArgumentParser()
    parser.add_argument("--config", type=str, required=True, help="Configuration file name or path.")
    parser.add_argument("--image_front", type=str, default=None, help="Offline front image path.")
    parser.add_argument("--image_left", type=str, default=None, help="Offline left image path.")
    parser.add_argument("--image_right", type=str, default=None, help="Offline right image path.")
    parser.add_argument("--output", type=str, default="/root/ros2_ws/explorfm_offline_test.png")
    parsed_args = parser.parse_args(custom_args[1:])

    image_paths = [parsed_args.image_front, parsed_args.image_left, parsed_args.image_right]
    if any(image_paths):
        if not all(image_paths):
            parser.error("--image_front, --image_left, and --image_right must be provided together.")
        config = OmegaConf.load(_resolve_config(parsed_args.config))
        output, stats = run_offline_image_test(config, image_paths, parsed_args.output)
        print(f"Wrote {output}")
        print(json.dumps(stats, indent=2, sort_keys=True))
        return

    rclpy.init(args=args)
    node = ExploRFMCameraProbe(OmegaConf.load(_resolve_config(parsed_args.config)))
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
