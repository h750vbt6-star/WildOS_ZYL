// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gps_visualization/msg/nav_sat_fix_array.hpp"


#ifndef GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__STRUCT_HPP_
#define GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'gps_fixes'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gps_visualization__msg__NavSatFixArray __attribute__((deprecated))
#else
# define DEPRECATED__gps_visualization__msg__NavSatFixArray __declspec(deprecated)
#endif

namespace gps_visualization
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavSatFixArray_
{
  using Type = NavSatFixArray_<ContainerAllocator>;

  explicit NavSatFixArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit NavSatFixArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _gps_fixes_type =
    std::vector<sensor_msgs::msg::NavSatFix_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::NavSatFix_<ContainerAllocator>>>;
  _gps_fixes_type gps_fixes;

  // setters for named parameter idiom
  Type & set__gps_fixes(
    const std::vector<sensor_msgs::msg::NavSatFix_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::NavSatFix_<ContainerAllocator>>> & _arg)
  {
    this->gps_fixes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gps_visualization::msg::NavSatFixArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const gps_visualization::msg::NavSatFixArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gps_visualization::msg::NavSatFixArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gps_visualization::msg::NavSatFixArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gps_visualization__msg__NavSatFixArray
    std::shared_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gps_visualization__msg__NavSatFixArray
    std::shared_ptr<gps_visualization::msg::NavSatFixArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavSatFixArray_ & other) const
  {
    if (this->gps_fixes != other.gps_fixes) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavSatFixArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavSatFixArray_

// alias to use template instance with default allocator
using NavSatFixArray =
  gps_visualization::msg::NavSatFixArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gps_visualization

#endif  // GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__STRUCT_HPP_
