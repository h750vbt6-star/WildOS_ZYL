#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <Eigen/Dense>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace graphnav_planner
{

class PathFollowerNode : public rclcpp::Node
{
public:
  PathFollowerNode(const rclcpp::NodeOptions& options)
    : Node("path_follower_node", options), tf_buffer_(this->get_clock()), tf_listener_(tf_buffer_, this)
  {
    this->declare_parameter("wp_lookahead_dist", 0.6);
    wp_lookahead_dist_ = this->get_parameter("wp_lookahead_dist").as_double();
    this->declare_parameter("waypoint_arrival_radius", 0.35);
    waypoint_arrival_radius_ = this->get_parameter("waypoint_arrival_radius").as_double();
    this->declare_parameter("path_timeout", 0.0);
    path_timeout_ = this->get_parameter("path_timeout").as_double();
    path_sub_ = this->create_subscription<nav_msgs::msg::Path>(
        "~/path", 10, std::bind(&PathFollowerNode::path_callback, this, std::placeholders::_1));
    pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("~/goal_pose", 10);
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "~/odom", 10, std::bind(&PathFollowerNode::odom_callback, this, std::placeholders::_1));
  }

private:
  struct PathProjection
  {
    double distance = std::numeric_limits<double>::infinity();
    double progress = 0.0;
  };

  void path_callback(const nav_msgs::msg::Path::ConstSharedPtr msg)
  {
    if (msg->poses.empty())
    {
      RCLCPP_WARN_THROTTLE(
          this->get_logger(),
          *this->get_clock(),
          2000,
          "Received empty GraphNav path; keeping the previous valid path.");
      return;
    }

    path_ = msg;
    cumulative_lengths_.clear();
    cumulative_lengths_.reserve(path_->poses.size());
    cumulative_lengths_.push_back(0.0);
    for (size_t i = 1; i < path_->poses.size(); ++i)
    {
      cumulative_lengths_.push_back(
        cumulative_lengths_.back() +
        segment_length(path_->poses[i - 1], path_->poses[i]));
    }
    path_progress_ = 0.0;
  }

  void odom_callback(const nav_msgs::msg::Odometry::ConstSharedPtr msg)
  {
    if (!path_)
    {
      return;
    }
    if (path_timeout_ > 0.0 &&
        (rclcpp::Time(msg->header.stamp) - rclcpp::Time(path_->header.stamp)).seconds() > path_timeout_)
    {
      return;
    }
    if (path_->poses.empty())
    {
      return;
    }

    geometry_msgs::msg::PoseStamped odom_pose;
    odom_pose.header = msg->header;
    odom_pose.pose = msg->pose.pose;
    geometry_msgs::msg::PoseStamped odom_pose_in_path_frame;
    try
    {
      odom_pose_in_path_frame = tf_buffer_.transform(odom_pose, path_->header.frame_id, tf2::durationFromSec(0.1));
    }
    catch (const tf2::TransformException& ex)
    {
      RCLCPP_WARN(this->get_logger(), "Could not transform odometry pose to path frame: %s", ex.what());
      return;
    }
    Eigen::Vector3d robot_pos(odom_pose_in_path_frame.pose.position.x, odom_pose_in_path_frame.pose.position.y,
                              odom_pose_in_path_frame.pose.position.z);

    if (path_->poses.size() == 1)
    {
      auto pose = path_->poses.front();
      pose.header.frame_id = path_->header.frame_id;
      pose.header.stamp = msg->header.stamp;
      pose_pub_->publish(pose);
      return;
    }

    const double total_length = cumulative_lengths_.empty() ? 0.0 : cumulative_lengths_.back();
    const double distance_to_goal = distance_to_waypoint(robot_pos, path_->poses.back());
    if (distance_to_goal <= waypoint_arrival_radius_)
    {
      path_progress_ = total_length;
      auto pose = path_->poses.back();
      pose.header.frame_id = path_->header.frame_id;
      pose.header.stamp = msg->header.stamp;
      pose_pub_->publish(pose);
      return;
    }

    const PathProjection projection = project_robot_onto_path(robot_pos);
    path_progress_ = std::max(path_progress_, projection.progress);

    const double target_progress = std::min(path_progress_ + wp_lookahead_dist_, total_length);
    auto pose = pose_at_progress(target_progress, msg->header.stamp);
    pose_pub_->publish(pose);
  }

  double distance_to_waypoint(
      const Eigen::Vector3d& robot_pos,
      const geometry_msgs::msg::PoseStamped& waypoint) const
  {
    const double dx = waypoint.pose.position.x - robot_pos.x();
    const double dy = waypoint.pose.position.y - robot_pos.y();
    return std::hypot(dx, dy);
  }

  double segment_length(
      const geometry_msgs::msg::PoseStamped& from,
      const geometry_msgs::msg::PoseStamped& to) const
  {
    const double dx = to.pose.position.x - from.pose.position.x;
    const double dy = to.pose.position.y - from.pose.position.y;
    const double dz = to.pose.position.z - from.pose.position.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
  }

  PathProjection project_robot_onto_path(const Eigen::Vector3d& robot_pos) const
  {
    PathProjection best;
    if (!path_ || path_->poses.empty())
    {
      return best;
    }

    for (size_t i = 0; i + 1 < path_->poses.size(); ++i)
    {
      const auto& start = path_->poses[i].pose.position;
      const auto& end = path_->poses[i + 1].pose.position;
      const Eigen::Vector2d p0(start.x, start.y);
      const Eigen::Vector2d p1(end.x, end.y);
      const Eigen::Vector2d robot_xy(robot_pos.x(), robot_pos.y());
      const Eigen::Vector2d segment = p1 - p0;
      const double segment_sq_norm = segment.squaredNorm();

      double t = 0.0;
      if (segment_sq_norm > 1e-9)
      {
        t = std::clamp((robot_xy - p0).dot(segment) / segment_sq_norm, 0.0, 1.0);
      }

      const Eigen::Vector2d projected_xy = p0 + t * segment;
      const double distance = (robot_xy - projected_xy).norm();
      const double progress = cumulative_lengths_[i] + t * segment_length(path_->poses[i], path_->poses[i + 1]);
      if (distance < best.distance)
      {
        best.distance = distance;
        best.progress = progress;
      }
    }

    if (!std::isfinite(best.distance))
    {
      best.distance = distance_to_waypoint(robot_pos, path_->poses.front());
      best.progress = 0.0;
    }

    return best;
  }

  geometry_msgs::msg::Quaternion yaw_to_quaternion(double yaw) const
  {
    geometry_msgs::msg::Quaternion q;
    q.z = std::sin(0.5 * yaw);
    q.w = std::cos(0.5 * yaw);
    return q;
  }

  geometry_msgs::msg::PoseStamped pose_at_progress(
      double progress,
      const builtin_interfaces::msg::Time& stamp) const
  {
    geometry_msgs::msg::PoseStamped pose;
    pose.header.frame_id = path_->header.frame_id;
    pose.header.stamp = stamp;

    if (path_->poses.empty())
    {
      return pose;
    }
    if (path_->poses.size() == 1 || cumulative_lengths_.empty())
    {
      pose = path_->poses.front();
      pose.header.frame_id = path_->header.frame_id;
      pose.header.stamp = stamp;
      return pose;
    }

    const double clamped_progress = std::clamp(progress, 0.0, cumulative_lengths_.back());
    auto upper = std::upper_bound(cumulative_lengths_.begin(), cumulative_lengths_.end(), clamped_progress);
    size_t segment_idx = 0;
    if (upper == cumulative_lengths_.begin())
    {
      segment_idx = 0;
    }
    else if (upper == cumulative_lengths_.end())
    {
      segment_idx = cumulative_lengths_.size() - 2;
    }
    else
    {
      segment_idx = static_cast<size_t>(std::distance(cumulative_lengths_.begin(), upper) - 1);
    }

    const auto& start = path_->poses[segment_idx];
    const auto& end = path_->poses[segment_idx + 1];
    const double segment_start = cumulative_lengths_[segment_idx];
    const double segment_end = cumulative_lengths_[segment_idx + 1];
    const double segment_len = std::max(segment_end - segment_start, 1e-9);
    const double t = std::clamp((clamped_progress - segment_start) / segment_len, 0.0, 1.0);

    pose.pose.position.x = start.pose.position.x + t * (end.pose.position.x - start.pose.position.x);
    pose.pose.position.y = start.pose.position.y + t * (end.pose.position.y - start.pose.position.y);
    pose.pose.position.z = start.pose.position.z + t * (end.pose.position.z - start.pose.position.z);

    const double dx = end.pose.position.x - start.pose.position.x;
    const double dy = end.pose.position.y - start.pose.position.y;
    if (clamped_progress >= cumulative_lengths_.back() - 1e-6)
    {
      pose.pose.orientation = path_->poses.back().pose.orientation;
    }
    else if (std::hypot(dx, dy) > 1e-6)
    {
      pose.pose.orientation = yaw_to_quaternion(std::atan2(dy, dx));
    }
    else
    {
      pose.pose.orientation = start.pose.orientation;
    }

    return pose;
  }

  rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr path_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
  double wp_lookahead_dist_ = 0.6;
  double waypoint_arrival_radius_ = 0.35;
  double path_timeout_ = 0.0;
  double path_progress_ = 0.0;
  std::vector<double> cumulative_lengths_;

  nav_msgs::msg::Path::ConstSharedPtr path_;
};

}  // namespace graphnav_planner

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(graphnav_planner::PathFollowerNode)
