#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <nav_msgs/msg/path.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <graphnav_msgs/msg/navigation_graph.hpp>
#include <std_msgs/msg/header.hpp>
#include <cmath>
#include <optional>
#include <string>
#include "graphnav_planner/planner.hpp"

namespace graphnav_planner
{

class PlannerNode : public rclcpp::Node
{
public:
  PlannerNode(const rclcpp::NodeOptions& options)
    : Node("planner_node", options)
    , tf_buffer_(this->get_clock())
    , tf_listener_(tf_buffer_, this)
    , planner_(this->get_logger())
  {
    this->declare_parameter("frontier_dist_cost_factor", 2.0);
    this->declare_parameter("goal_dist_cost_factor", 1.0);
    this->declare_parameter("frontier_score_factor", 10.0);
    this->declare_parameter("use_frontier_scores", true);
    this->declare_parameter("min_frontier_score_for_cost", 1e-3);
    this->declare_parameter("min_local_frontier_score", 0.4);
    this->declare_parameter("local_frontier_radius", 7.0);
    this->declare_parameter("path_smoothness_period", 10.0);
    this->declare_parameter("no_goal_strategy", "wait_for_goal");
    this->declare_parameter("virtual_goal_frame", "odom");
    this->declare_parameter("virtual_goal_x", 100.0);
    this->declare_parameter("virtual_goal_y", 0.0);
    this->declare_parameter("virtual_goal_z", 0.0);
    this->declare_parameter("virtual_goal_yaw", 0.0);
    this->declare_parameter("best_frontier_replan_period", 2.0);
    this->declare_parameter("best_frontier_startup_delay", 5.0);
    this->declare_parameter("best_frontier_min_switch_period", 4.0);
    this->declare_parameter("best_frontier_switch_distance", 1.0);

    planner_.frontier_dist_cost_factor_ = this->get_parameter("frontier_dist_cost_factor").as_double();
    planner_.goal_dist_cost_factor_ = this->get_parameter("goal_dist_cost_factor").as_double();
    planner_.frontier_score_factor_ = this->get_parameter("frontier_score_factor").as_double();
    planner_.use_frontier_scores_ = this->get_parameter("use_frontier_scores").as_bool();
    planner_.min_frontier_score_for_cost_ = this->get_parameter("min_frontier_score_for_cost").as_double();
    planner_.min_local_frontier_score_ = this->get_parameter("min_local_frontier_score").as_double();
    planner_.local_frontier_radius_ = this->get_parameter("local_frontier_radius").as_double();
    planner_.path_smoothness_period_ = this->get_parameter("path_smoothness_period").as_double();

    no_goal_strategy_ = this->normalize_no_goal_strategy(this->get_parameter("no_goal_strategy").as_string());
    virtual_goal_pose_.header.frame_id = this->get_parameter("virtual_goal_frame").as_string();
    virtual_goal_pose_.pose.position.x = this->get_parameter("virtual_goal_x").as_double();
    virtual_goal_pose_.pose.position.y = this->get_parameter("virtual_goal_y").as_double();
    virtual_goal_pose_.pose.position.z = this->get_parameter("virtual_goal_z").as_double();
    virtual_goal_pose_.pose.orientation = this->yaw_to_quaternion(this->get_parameter("virtual_goal_yaw").as_double());
    best_frontier_replan_period_ = this->get_parameter("best_frontier_replan_period").as_double();
    best_frontier_startup_delay_ = this->get_parameter("best_frontier_startup_delay").as_double();
    best_frontier_min_switch_period_ = this->get_parameter("best_frontier_min_switch_period").as_double();
    best_frontier_switch_distance_ = this->get_parameter("best_frontier_switch_distance").as_double();

    this->declare_parameter("trav_class", "default");
    planner_.set_trav_class(this->get_parameter("trav_class").as_string());

    this->declare_parameter("goal_radius", 3.0);
    goal_radius_ = this->get_parameter("goal_radius").as_double();

    graph_sub_ = this->create_subscription<graphnav_msgs::msg::NavigationGraph>(
        "~/nav_graph", 10, [this](const graphnav_msgs::msg::NavigationGraph::ConstSharedPtr msg) {
          this->planner_.update_graph(msg);
          this->latest_graph_header_ = msg->header;
          this->plan_to_goal();
        });
    goal_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
        "~/goal_pose", 10, [this](const geometry_msgs::msg::PoseStamped::ConstSharedPtr msg) {
          this->goal_pose_ = msg;
          this->plan_to_goal();
        });
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "~/odom", 10, [this](const nav_msgs::msg::Odometry::ConstSharedPtr msg) { this->odom_ = msg; });

    path_pub_ = this->create_publisher<nav_msgs::msg::Path>("~/path", 10);
    grid_map_debug_pub_ = this->create_publisher<grid_map_msgs::msg::GridMap>("~/unexplored_space_map", 10);
    scores_debug_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("~/frontier_scores", 10);
  }

private:
  void plan_to_goal()
  {
    if (!latest_graph_header_)
    {
      return;
    }

    if (goal_pose_)
    {
      this->plan_to_pose_goal(*goal_pose_, true);
      return;
    }

    if (no_goal_strategy_ == "virtual_goal")
    {
      this->plan_to_pose_goal(virtual_goal_pose_, false);
      return;
    }

    if (no_goal_strategy_ == "best_frontier_score")
    {
      const auto now = this->get_clock()->now();
      if (!first_best_frontier_strategy_time_)
      {
        first_best_frontier_strategy_time_ = now;
      }
      if (best_frontier_startup_delay_ > 0.0 &&
          (now - *first_best_frontier_strategy_time_).seconds() < best_frontier_startup_delay_)
      {
        return;
      }
      if (last_best_frontier_plan_time_ &&
          best_frontier_replan_period_ > 0.0 &&
          (now - *last_best_frontier_plan_time_).seconds() < best_frontier_replan_period_)
      {
        return;
      }
      last_best_frontier_plan_time_ = now;

      auto path = planner_.plan_to_best_frontier_score(now);
      if (path.size() < 2)
      {
        return;
      }

      const auto& endpoint = path.back();
      if (last_best_frontier_goal_)
      {
        const double endpoint_jump = (endpoint - *last_best_frontier_goal_).head<2>().norm();
        const bool switched_far = endpoint_jump > best_frontier_switch_distance_;
        const bool can_switch = !last_best_frontier_publish_time_ ||
          best_frontier_min_switch_period_ <= 0.0 ||
          (now - *last_best_frontier_publish_time_).seconds() >= best_frontier_min_switch_period_;
        if (switched_far && !can_switch)
        {
          return;
        }
      }

      this->publish_path(path, std::nullopt);
      last_best_frontier_goal_ = endpoint;
      last_best_frontier_publish_time_ = now;
      this->publish_debug_outputs();
    }
  }

  void plan_to_pose_goal(const geometry_msgs::msg::PoseStamped& input_goal, bool clear_goal_when_reached)
  {
    geometry_msgs::msg::PoseStamped goal = input_goal;
    goal.header.stamp = latest_graph_header_->stamp;

    geometry_msgs::msg::PoseStamped goal_in_graph_frame;
    try
    {
      goal_in_graph_frame = tf_buffer_.transform(goal, latest_graph_header_->frame_id, tf2::durationFromSec(0.1));
    }
    catch (const tf2::TransformException& ex)
    {
      RCLCPP_WARN(this->get_logger(), "Could not transform goal pose to graph frame: %s", ex.what());
      return;
    }

    Eigen::Vector3d goal_vec(goal_in_graph_frame.pose.position.x, goal_in_graph_frame.pose.position.y,
                             goal_in_graph_frame.pose.position.z);
    auto path = planner_.plan_to_goal(goal_vec, goal_radius_, this->get_clock()->now());
    this->publish_path(path, goal_in_graph_frame.pose.orientation);
    this->publish_debug_outputs();

    if (clear_goal_when_reached)
    {
      this->clear_goal_if_reached(goal);
    }
  }

  void publish_path(
      const std::vector<Eigen::Vector3d>& path,
      const std::optional<geometry_msgs::msg::Quaternion>& final_orientation)
  {
    nav_msgs::msg::Path path_msg;
    path_msg.header = *latest_graph_header_;
    path_msg.poses.resize(path.size());
    for (size_t i = 0; i < path.size(); i++)
    {
      path_msg.poses[i].pose.position.x = path[i].x();
      path_msg.poses[i].pose.position.y = path[i].y();
      path_msg.poses[i].pose.position.z = path[i].z();

      if (i < path.size() - 1)
      {
        path_msg.poses[i].pose.orientation = this->orientation_between(path[i], path[i + 1]);
      }
      else if (final_orientation)
      {
        path_msg.poses[i].pose.orientation = *final_orientation;
      }
      else if (path.size() > 1)
      {
        path_msg.poses[i].pose.orientation = this->orientation_between(path[i - 1], path[i]);
      }
      else
      {
        path_msg.poses[i].pose.orientation.w = 1.0;
      }
    }
    path_pub_->publish(path_msg);
  }

  void publish_debug_outputs()
  {
    if (grid_map_debug_pub_->get_subscription_count() > 0)
    {
      grid_map_msgs::msg::GridMap grid_map_msg = planner_.get_unexplored_debug_map();
      grid_map_msg.header = *latest_graph_header_;
      grid_map_debug_pub_->publish(grid_map_msg);
    }
    if (scores_debug_pub_->get_subscription_count() > 0)
    {
      visualization_msgs::msg::MarkerArray marker_array = planner_.get_score_visualization(
        this->get_clock()->now(), latest_graph_header_->frame_id, true);
      scores_debug_pub_->publish(marker_array);
    }
  }

  void clear_goal_if_reached(const geometry_msgs::msg::PoseStamped& goal)
  {
    if (!odom_)
    {
      return;
    }

    try
    {
      geometry_msgs::msg::PoseStamped goal_in_odom_frame;
      goal_in_odom_frame = tf_buffer_.transform(goal, odom_->header.frame_id, tf2::durationFromSec(0.1));
      Eigen::Vector3d goal_vec(goal_in_odom_frame.pose.position.x, goal_in_odom_frame.pose.position.y,
                               goal_in_odom_frame.pose.position.z);
      Eigen::Vector3d odom_vec(odom_->pose.pose.position.x, odom_->pose.pose.position.y,
                               odom_->pose.pose.position.z);
      if ((goal_vec - odom_vec).norm() < goal_radius_)
      {
        goal_pose_.reset();
      }
    }
    catch (const tf2::TransformException& ex)
    {
      RCLCPP_WARN(this->get_logger(), "Could not transform goal pose to odom frame: %s", ex.what());
    }
  }

  geometry_msgs::msg::Quaternion orientation_between(
      const Eigen::Vector3d& from,
      const Eigen::Vector3d& to) const
  {
    const Eigen::Vector3d delta = to - from;
    if (delta.head<2>().norm() < 1e-9)
    {
      geometry_msgs::msg::Quaternion q;
      q.w = 1.0;
      return q;
    }
    return this->yaw_to_quaternion(std::atan2(delta.y(), delta.x()));
  }

  geometry_msgs::msg::Quaternion yaw_to_quaternion(double yaw) const
  {
    geometry_msgs::msg::Quaternion q;
    q.z = std::sin(0.5 * yaw);
    q.w = std::cos(0.5 * yaw);
    return q;
  }

  std::string normalize_no_goal_strategy(const std::string& strategy) const
  {
    if (strategy == "wait" || strategy == "wait_for_goal" || strategy == "none")
    {
      return "wait_for_goal";
    }
    if (strategy == "virtual_goal" || strategy == "best_frontier_score")
    {
      return strategy;
    }

    RCLCPP_WARN(
      this->get_logger(),
      "Unknown no_goal_strategy '%s'. Falling back to wait_for_goal.",
      strategy.c_str());
    return "wait_for_goal";
  }

  rclcpp::Subscription<graphnav_msgs::msg::NavigationGraph>::SharedPtr graph_sub_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  rclcpp::Publisher<grid_map_msgs::msg::GridMap>::SharedPtr grid_map_debug_pub_;
  rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr scores_debug_pub_;

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;

  geometry_msgs::msg::PoseStamped::ConstSharedPtr goal_pose_;
  nav_msgs::msg::Odometry::ConstSharedPtr odom_;
  std::string no_goal_strategy_;
  geometry_msgs::msg::PoseStamped virtual_goal_pose_;
  double best_frontier_replan_period_;
  double best_frontier_startup_delay_;
  double best_frontier_min_switch_period_;
  double best_frontier_switch_distance_;
  std::optional<rclcpp::Time> first_best_frontier_strategy_time_;
  std::optional<rclcpp::Time> last_best_frontier_plan_time_;
  std::optional<rclcpp::Time> last_best_frontier_publish_time_;
  std::optional<Eigen::Vector3d> last_best_frontier_goal_;
  std::optional<std_msgs::msg::Header> latest_graph_header_;
  double goal_radius_;

  Planner planner_;
};

}  // namespace graphnav_planner

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(graphnav_planner::PlannerNode)
