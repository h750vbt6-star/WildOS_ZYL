// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from direct_lidar_inertial_odometry:srv/SavePCD.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "direct_lidar_inertial_odometry/srv/save_pcd.hpp"


#ifndef DIRECT_LIDAR_INERTIAL_ODOMETRY__SRV__DETAIL__SAVE_PCD__TRAITS_HPP_
#define DIRECT_LIDAR_INERTIAL_ODOMETRY__SRV__DETAIL__SAVE_PCD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "direct_lidar_inertial_odometry/srv/detail/save_pcd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace direct_lidar_inertial_odometry
{

namespace srv
{

inline void to_flow_style_yaml(
  const SavePCD_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: leaf_size
  {
    out << "leaf_size: ";
    rosidl_generator_traits::value_to_yaml(msg.leaf_size, out);
    out << ", ";
  }

  // member: save_path
  {
    out << "save_path: ";
    rosidl_generator_traits::value_to_yaml(msg.save_path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SavePCD_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: leaf_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leaf_size: ";
    rosidl_generator_traits::value_to_yaml(msg.leaf_size, out);
    out << "\n";
  }

  // member: save_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "save_path: ";
    rosidl_generator_traits::value_to_yaml(msg.save_path, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SavePCD_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace direct_lidar_inertial_odometry

namespace rosidl_generator_traits
{

[[deprecated("use direct_lidar_inertial_odometry::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const direct_lidar_inertial_odometry::srv::SavePCD_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  direct_lidar_inertial_odometry::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use direct_lidar_inertial_odometry::srv::to_yaml() instead")]]
inline std::string to_yaml(const direct_lidar_inertial_odometry::srv::SavePCD_Request & msg)
{
  return direct_lidar_inertial_odometry::srv::to_yaml(msg);
}

template<>
inline const char * data_type<direct_lidar_inertial_odometry::srv::SavePCD_Request>()
{
  return "direct_lidar_inertial_odometry::srv::SavePCD_Request";
}

template<>
inline const char * name<direct_lidar_inertial_odometry::srv::SavePCD_Request>()
{
  return "direct_lidar_inertial_odometry/srv/SavePCD_Request";
}

template<>
struct has_fixed_size<direct_lidar_inertial_odometry::srv::SavePCD_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<direct_lidar_inertial_odometry::srv::SavePCD_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace direct_lidar_inertial_odometry
{

namespace srv
{

inline void to_flow_style_yaml(
  const SavePCD_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SavePCD_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SavePCD_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace direct_lidar_inertial_odometry

namespace rosidl_generator_traits
{

[[deprecated("use direct_lidar_inertial_odometry::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const direct_lidar_inertial_odometry::srv::SavePCD_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  direct_lidar_inertial_odometry::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use direct_lidar_inertial_odometry::srv::to_yaml() instead")]]
inline std::string to_yaml(const direct_lidar_inertial_odometry::srv::SavePCD_Response & msg)
{
  return direct_lidar_inertial_odometry::srv::to_yaml(msg);
}

template<>
inline const char * data_type<direct_lidar_inertial_odometry::srv::SavePCD_Response>()
{
  return "direct_lidar_inertial_odometry::srv::SavePCD_Response";
}

template<>
inline const char * name<direct_lidar_inertial_odometry::srv::SavePCD_Response>()
{
  return "direct_lidar_inertial_odometry/srv/SavePCD_Response";
}

template<>
struct has_fixed_size<direct_lidar_inertial_odometry::srv::SavePCD_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<direct_lidar_inertial_odometry::srv::SavePCD_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace direct_lidar_inertial_odometry
{

namespace srv
{

inline void to_flow_style_yaml(
  const SavePCD_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SavePCD_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SavePCD_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace direct_lidar_inertial_odometry

namespace rosidl_generator_traits
{

[[deprecated("use direct_lidar_inertial_odometry::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const direct_lidar_inertial_odometry::srv::SavePCD_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  direct_lidar_inertial_odometry::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use direct_lidar_inertial_odometry::srv::to_yaml() instead")]]
inline std::string to_yaml(const direct_lidar_inertial_odometry::srv::SavePCD_Event & msg)
{
  return direct_lidar_inertial_odometry::srv::to_yaml(msg);
}

template<>
inline const char * data_type<direct_lidar_inertial_odometry::srv::SavePCD_Event>()
{
  return "direct_lidar_inertial_odometry::srv::SavePCD_Event";
}

template<>
inline const char * name<direct_lidar_inertial_odometry::srv::SavePCD_Event>()
{
  return "direct_lidar_inertial_odometry/srv/SavePCD_Event";
}

template<>
struct has_fixed_size<direct_lidar_inertial_odometry::srv::SavePCD_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD_Event>
  : std::integral_constant<bool, has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD_Request>::value && has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<direct_lidar_inertial_odometry::srv::SavePCD_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<direct_lidar_inertial_odometry::srv::SavePCD>()
{
  return "direct_lidar_inertial_odometry::srv::SavePCD";
}

template<>
inline const char * name<direct_lidar_inertial_odometry::srv::SavePCD>()
{
  return "direct_lidar_inertial_odometry/srv/SavePCD";
}

template<>
struct has_fixed_size<direct_lidar_inertial_odometry::srv::SavePCD>
  : std::integral_constant<
    bool,
    has_fixed_size<direct_lidar_inertial_odometry::srv::SavePCD_Request>::value &&
    has_fixed_size<direct_lidar_inertial_odometry::srv::SavePCD_Response>::value
  >
{
};

template<>
struct has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD>
  : std::integral_constant<
    bool,
    has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD_Request>::value &&
    has_bounded_size<direct_lidar_inertial_odometry::srv::SavePCD_Response>::value
  >
{
};

template<>
struct is_service<direct_lidar_inertial_odometry::srv::SavePCD>
  : std::true_type
{
};

template<>
struct is_service_request<direct_lidar_inertial_odometry::srv::SavePCD_Request>
  : std::true_type
{
};

template<>
struct is_service_response<direct_lidar_inertial_odometry::srv::SavePCD_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DIRECT_LIDAR_INERTIAL_ODOMETRY__SRV__DETAIL__SAVE_PCD__TRAITS_HPP_
