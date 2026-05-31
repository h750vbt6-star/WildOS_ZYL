// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "object_search_msgs/msg/object_mask_with_tf.hpp"


#ifndef OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__TRAITS_HPP_
#define OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "object_search_msgs/msg/detail/object_mask_with_tf__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__traits.hpp"
// Member 'cam_infos'
#include "sensor_msgs/msg/detail/camera_info__traits.hpp"
// Member 'object_mask'
#include "std_msgs/msg/detail/u_int8_multi_array__traits.hpp"
// Member 'cam_transforms'
#include "tf2_msgs/msg/detail/tf_message__traits.hpp"

namespace object_search_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectMaskWithTf & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: odom
  {
    out << "odom: ";
    to_flow_style_yaml(msg.odom, out);
    out << ", ";
  }

  // member: cam_infos
  {
    if (msg.cam_infos.size() == 0) {
      out << "cam_infos: []";
    } else {
      out << "cam_infos: [";
      size_t pending_items = msg.cam_infos.size();
      for (auto item : msg.cam_infos) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: object_mask
  {
    out << "object_mask: ";
    to_flow_style_yaml(msg.object_mask, out);
    out << ", ";
  }

  // member: cam_transforms
  {
    out << "cam_transforms: ";
    to_flow_style_yaml(msg.cam_transforms, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectMaskWithTf & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: odom
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "odom:\n";
    to_block_style_yaml(msg.odom, out, indentation + 2);
  }

  // member: cam_infos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cam_infos.size() == 0) {
      out << "cam_infos: []\n";
    } else {
      out << "cam_infos:\n";
      for (auto item : msg.cam_infos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: object_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_mask:\n";
    to_block_style_yaml(msg.object_mask, out, indentation + 2);
  }

  // member: cam_transforms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam_transforms:\n";
    to_block_style_yaml(msg.cam_transforms, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectMaskWithTf & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace object_search_msgs

namespace rosidl_generator_traits
{

[[deprecated("use object_search_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const object_search_msgs::msg::ObjectMaskWithTf & msg,
  std::ostream & out, size_t indentation = 0)
{
  object_search_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use object_search_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const object_search_msgs::msg::ObjectMaskWithTf & msg)
{
  return object_search_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<object_search_msgs::msg::ObjectMaskWithTf>()
{
  return "object_search_msgs::msg::ObjectMaskWithTf";
}

template<>
inline const char * name<object_search_msgs::msg::ObjectMaskWithTf>()
{
  return "object_search_msgs/msg/ObjectMaskWithTf";
}

template<>
struct has_fixed_size<object_search_msgs::msg::ObjectMaskWithTf>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<object_search_msgs::msg::ObjectMaskWithTf>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<object_search_msgs::msg::ObjectMaskWithTf>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__TRAITS_HPP_
