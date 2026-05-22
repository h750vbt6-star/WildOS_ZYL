// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from elevation_map_msgs:srv/Initialize.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "elevation_map_msgs/srv/initialize.hpp"


#ifndef ELEVATION_MAP_MSGS__SRV__DETAIL__INITIALIZE__TRAITS_HPP_
#define ELEVATION_MAP_MSGS__SRV__DETAIL__INITIALIZE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "elevation_map_msgs/srv/detail/initialize__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point_stamped__traits.hpp"

namespace elevation_map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Initialize_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: method
  {
    out << "method: ";
    rosidl_generator_traits::value_to_yaml(msg.method, out);
    out << ", ";
  }

  // member: points
  {
    if (msg.points.size() == 0) {
      out << "points: []";
    } else {
      out << "points: [";
      size_t pending_items = msg.points.size();
      for (auto item : msg.points) {
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
  const Initialize_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: method
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "method: ";
    rosidl_generator_traits::value_to_yaml(msg.method, out);
    out << "\n";
  }

  // member: points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.points.size() == 0) {
      out << "points: []\n";
    } else {
      out << "points:\n";
      for (auto item : msg.points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Initialize_Request & msg, bool use_flow_style = false)
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

}  // namespace elevation_map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use elevation_map_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const elevation_map_msgs::srv::Initialize_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  elevation_map_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use elevation_map_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const elevation_map_msgs::srv::Initialize_Request & msg)
{
  return elevation_map_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<elevation_map_msgs::srv::Initialize_Request>()
{
  return "elevation_map_msgs::srv::Initialize_Request";
}

template<>
inline const char * name<elevation_map_msgs::srv::Initialize_Request>()
{
  return "elevation_map_msgs/srv/Initialize_Request";
}

template<>
struct has_fixed_size<elevation_map_msgs::srv::Initialize_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<elevation_map_msgs::srv::Initialize_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<elevation_map_msgs::srv::Initialize_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace elevation_map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Initialize_Response & msg,
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
  const Initialize_Response & msg,
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

inline std::string to_yaml(const Initialize_Response & msg, bool use_flow_style = false)
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

}  // namespace elevation_map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use elevation_map_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const elevation_map_msgs::srv::Initialize_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  elevation_map_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use elevation_map_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const elevation_map_msgs::srv::Initialize_Response & msg)
{
  return elevation_map_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<elevation_map_msgs::srv::Initialize_Response>()
{
  return "elevation_map_msgs::srv::Initialize_Response";
}

template<>
inline const char * name<elevation_map_msgs::srv::Initialize_Response>()
{
  return "elevation_map_msgs/srv/Initialize_Response";
}

template<>
struct has_fixed_size<elevation_map_msgs::srv::Initialize_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<elevation_map_msgs::srv::Initialize_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<elevation_map_msgs::srv::Initialize_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace elevation_map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Initialize_Event & msg,
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
  const Initialize_Event & msg,
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

inline std::string to_yaml(const Initialize_Event & msg, bool use_flow_style = false)
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

}  // namespace elevation_map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use elevation_map_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const elevation_map_msgs::srv::Initialize_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  elevation_map_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use elevation_map_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const elevation_map_msgs::srv::Initialize_Event & msg)
{
  return elevation_map_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<elevation_map_msgs::srv::Initialize_Event>()
{
  return "elevation_map_msgs::srv::Initialize_Event";
}

template<>
inline const char * name<elevation_map_msgs::srv::Initialize_Event>()
{
  return "elevation_map_msgs/srv/Initialize_Event";
}

template<>
struct has_fixed_size<elevation_map_msgs::srv::Initialize_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<elevation_map_msgs::srv::Initialize_Event>
  : std::integral_constant<bool, has_bounded_size<elevation_map_msgs::srv::Initialize_Request>::value && has_bounded_size<elevation_map_msgs::srv::Initialize_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<elevation_map_msgs::srv::Initialize_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<elevation_map_msgs::srv::Initialize>()
{
  return "elevation_map_msgs::srv::Initialize";
}

template<>
inline const char * name<elevation_map_msgs::srv::Initialize>()
{
  return "elevation_map_msgs/srv/Initialize";
}

template<>
struct has_fixed_size<elevation_map_msgs::srv::Initialize>
  : std::integral_constant<
    bool,
    has_fixed_size<elevation_map_msgs::srv::Initialize_Request>::value &&
    has_fixed_size<elevation_map_msgs::srv::Initialize_Response>::value
  >
{
};

template<>
struct has_bounded_size<elevation_map_msgs::srv::Initialize>
  : std::integral_constant<
    bool,
    has_bounded_size<elevation_map_msgs::srv::Initialize_Request>::value &&
    has_bounded_size<elevation_map_msgs::srv::Initialize_Response>::value
  >
{
};

template<>
struct is_service<elevation_map_msgs::srv::Initialize>
  : std::true_type
{
};

template<>
struct is_service_request<elevation_map_msgs::srv::Initialize_Request>
  : std::true_type
{
};

template<>
struct is_service_response<elevation_map_msgs::srv::Initialize_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ELEVATION_MAP_MSGS__SRV__DETAIL__INITIALIZE__TRAITS_HPP_
