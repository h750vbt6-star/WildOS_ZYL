// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "object_search_msgs/msg/object_mask_with_tf.hpp"


#ifndef OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__BUILDER_HPP_
#define OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "object_search_msgs/msg/detail/object_mask_with_tf__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace object_search_msgs
{

namespace msg
{

namespace builder
{

class Init_ObjectMaskWithTf_cam_transforms
{
public:
  explicit Init_ObjectMaskWithTf_cam_transforms(::object_search_msgs::msg::ObjectMaskWithTf & msg)
  : msg_(msg)
  {}
  ::object_search_msgs::msg::ObjectMaskWithTf cam_transforms(::object_search_msgs::msg::ObjectMaskWithTf::_cam_transforms_type arg)
  {
    msg_.cam_transforms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::object_search_msgs::msg::ObjectMaskWithTf msg_;
};

class Init_ObjectMaskWithTf_object_mask
{
public:
  explicit Init_ObjectMaskWithTf_object_mask(::object_search_msgs::msg::ObjectMaskWithTf & msg)
  : msg_(msg)
  {}
  Init_ObjectMaskWithTf_cam_transforms object_mask(::object_search_msgs::msg::ObjectMaskWithTf::_object_mask_type arg)
  {
    msg_.object_mask = std::move(arg);
    return Init_ObjectMaskWithTf_cam_transforms(msg_);
  }

private:
  ::object_search_msgs::msg::ObjectMaskWithTf msg_;
};

class Init_ObjectMaskWithTf_cam_infos
{
public:
  explicit Init_ObjectMaskWithTf_cam_infos(::object_search_msgs::msg::ObjectMaskWithTf & msg)
  : msg_(msg)
  {}
  Init_ObjectMaskWithTf_object_mask cam_infos(::object_search_msgs::msg::ObjectMaskWithTf::_cam_infos_type arg)
  {
    msg_.cam_infos = std::move(arg);
    return Init_ObjectMaskWithTf_object_mask(msg_);
  }

private:
  ::object_search_msgs::msg::ObjectMaskWithTf msg_;
};

class Init_ObjectMaskWithTf_odom
{
public:
  explicit Init_ObjectMaskWithTf_odom(::object_search_msgs::msg::ObjectMaskWithTf & msg)
  : msg_(msg)
  {}
  Init_ObjectMaskWithTf_cam_infos odom(::object_search_msgs::msg::ObjectMaskWithTf::_odom_type arg)
  {
    msg_.odom = std::move(arg);
    return Init_ObjectMaskWithTf_cam_infos(msg_);
  }

private:
  ::object_search_msgs::msg::ObjectMaskWithTf msg_;
};

class Init_ObjectMaskWithTf_header
{
public:
  Init_ObjectMaskWithTf_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectMaskWithTf_odom header(::object_search_msgs::msg::ObjectMaskWithTf::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ObjectMaskWithTf_odom(msg_);
  }

private:
  ::object_search_msgs::msg::ObjectMaskWithTf msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::object_search_msgs::msg::ObjectMaskWithTf>()
{
  return object_search_msgs::msg::builder::Init_ObjectMaskWithTf_header();
}

}  // namespace object_search_msgs

#endif  // OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__BUILDER_HPP_
