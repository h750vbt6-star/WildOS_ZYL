// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "object_search_msgs/msg/object_mask_with_tf.hpp"


#ifndef OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__STRUCT_HPP_
#define OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__struct.hpp"
// Member 'cam_infos'
#include "sensor_msgs/msg/detail/camera_info__struct.hpp"
// Member 'object_mask'
#include "std_msgs/msg/detail/u_int8_multi_array__struct.hpp"
// Member 'cam_transforms'
#include "tf2_msgs/msg/detail/tf_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__object_search_msgs__msg__ObjectMaskWithTf __attribute__((deprecated))
#else
# define DEPRECATED__object_search_msgs__msg__ObjectMaskWithTf __declspec(deprecated)
#endif

namespace object_search_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectMaskWithTf_
{
  using Type = ObjectMaskWithTf_<ContainerAllocator>;

  explicit ObjectMaskWithTf_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    odom(_init),
    object_mask(_init),
    cam_transforms(_init)
  {
    (void)_init;
  }

  explicit ObjectMaskWithTf_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    odom(_alloc, _init),
    object_mask(_alloc, _init),
    cam_transforms(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _odom_type =
    nav_msgs::msg::Odometry_<ContainerAllocator>;
  _odom_type odom;
  using _cam_infos_type =
    std::vector<sensor_msgs::msg::CameraInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::CameraInfo_<ContainerAllocator>>>;
  _cam_infos_type cam_infos;
  using _object_mask_type =
    std_msgs::msg::UInt8MultiArray_<ContainerAllocator>;
  _object_mask_type object_mask;
  using _cam_transforms_type =
    tf2_msgs::msg::TFMessage_<ContainerAllocator>;
  _cam_transforms_type cam_transforms;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__odom(
    const nav_msgs::msg::Odometry_<ContainerAllocator> & _arg)
  {
    this->odom = _arg;
    return *this;
  }
  Type & set__cam_infos(
    const std::vector<sensor_msgs::msg::CameraInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::CameraInfo_<ContainerAllocator>>> & _arg)
  {
    this->cam_infos = _arg;
    return *this;
  }
  Type & set__object_mask(
    const std_msgs::msg::UInt8MultiArray_<ContainerAllocator> & _arg)
  {
    this->object_mask = _arg;
    return *this;
  }
  Type & set__cam_transforms(
    const tf2_msgs::msg::TFMessage_<ContainerAllocator> & _arg)
  {
    this->cam_transforms = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_search_msgs__msg__ObjectMaskWithTf
    std::shared_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_search_msgs__msg__ObjectMaskWithTf
    std::shared_ptr<object_search_msgs::msg::ObjectMaskWithTf_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectMaskWithTf_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->odom != other.odom) {
      return false;
    }
    if (this->cam_infos != other.cam_infos) {
      return false;
    }
    if (this->object_mask != other.object_mask) {
      return false;
    }
    if (this->cam_transforms != other.cam_transforms) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectMaskWithTf_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectMaskWithTf_

// alias to use template instance with default allocator
using ObjectMaskWithTf =
  object_search_msgs::msg::ObjectMaskWithTf_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_search_msgs

#endif  // OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__STRUCT_HPP_
