// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gps_visualization/msg/nav_sat_fix_array.hpp"


#ifndef GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__BUILDER_HPP_
#define GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gps_visualization/msg/detail/nav_sat_fix_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gps_visualization
{

namespace msg
{

namespace builder
{

class Init_NavSatFixArray_gps_fixes
{
public:
  Init_NavSatFixArray_gps_fixes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gps_visualization::msg::NavSatFixArray gps_fixes(::gps_visualization::msg::NavSatFixArray::_gps_fixes_type arg)
  {
    msg_.gps_fixes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gps_visualization::msg::NavSatFixArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gps_visualization::msg::NavSatFixArray>()
{
  return gps_visualization::msg::builder::Init_NavSatFixArray_gps_fixes();
}

}  // namespace gps_visualization

#endif  // GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__BUILDER_HPP_
