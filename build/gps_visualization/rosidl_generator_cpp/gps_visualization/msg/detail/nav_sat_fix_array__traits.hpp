// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gps_visualization/msg/nav_sat_fix_array.hpp"


#ifndef GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__TRAITS_HPP_
#define GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gps_visualization/msg/detail/nav_sat_fix_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'gps_fixes'
#include "sensor_msgs/msg/detail/nav_sat_fix__traits.hpp"

namespace gps_visualization
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavSatFixArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: gps_fixes
  {
    if (msg.gps_fixes.size() == 0) {
      out << "gps_fixes: []";
    } else {
      out << "gps_fixes: [";
      size_t pending_items = msg.gps_fixes.size();
      for (auto item : msg.gps_fixes) {
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
  const NavSatFixArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gps_fixes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.gps_fixes.size() == 0) {
      out << "gps_fixes: []\n";
    } else {
      out << "gps_fixes:\n";
      for (auto item : msg.gps_fixes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavSatFixArray & msg, bool use_flow_style = false)
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

}  // namespace gps_visualization

namespace rosidl_generator_traits
{

[[deprecated("use gps_visualization::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gps_visualization::msg::NavSatFixArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  gps_visualization::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gps_visualization::msg::to_yaml() instead")]]
inline std::string to_yaml(const gps_visualization::msg::NavSatFixArray & msg)
{
  return gps_visualization::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gps_visualization::msg::NavSatFixArray>()
{
  return "gps_visualization::msg::NavSatFixArray";
}

template<>
inline const char * name<gps_visualization::msg::NavSatFixArray>()
{
  return "gps_visualization/msg/NavSatFixArray";
}

template<>
struct has_fixed_size<gps_visualization::msg::NavSatFixArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gps_visualization::msg::NavSatFixArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gps_visualization::msg::NavSatFixArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__TRAITS_HPP_
