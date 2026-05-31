// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "object_search_msgs/msg/detail/object_mask_with_tf__functions.h"
#include "object_search_msgs/msg/detail/object_mask_with_tf__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace object_search_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ObjectMaskWithTf_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) object_search_msgs::msg::ObjectMaskWithTf(_init);
}

void ObjectMaskWithTf_fini_function(void * message_memory)
{
  auto typed_message = static_cast<object_search_msgs::msg::ObjectMaskWithTf *>(message_memory);
  typed_message->~ObjectMaskWithTf();
}

size_t size_function__ObjectMaskWithTf__cam_infos(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::CameraInfo> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ObjectMaskWithTf__cam_infos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::CameraInfo> *>(untyped_member);
  return &member[index];
}

void * get_function__ObjectMaskWithTf__cam_infos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::CameraInfo> *>(untyped_member);
  return &member[index];
}

void fetch_function__ObjectMaskWithTf__cam_infos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::CameraInfo *>(
    get_const_function__ObjectMaskWithTf__cam_infos(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::CameraInfo *>(untyped_value);
  value = item;
}

void assign_function__ObjectMaskWithTf__cam_infos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::CameraInfo *>(
    get_function__ObjectMaskWithTf__cam_infos(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::CameraInfo *>(untyped_value);
  item = value;
}

void resize_function__ObjectMaskWithTf__cam_infos(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::CameraInfo> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ObjectMaskWithTf_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs::msg::ObjectMaskWithTf, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "odom",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_msgs::msg::Odometry>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs::msg::ObjectMaskWithTf, odom),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "cam_infos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::CameraInfo>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs::msg::ObjectMaskWithTf, cam_infos),  // bytes offset in struct
    nullptr,  // default value
    size_function__ObjectMaskWithTf__cam_infos,  // size() function pointer
    get_const_function__ObjectMaskWithTf__cam_infos,  // get_const(index) function pointer
    get_function__ObjectMaskWithTf__cam_infos,  // get(index) function pointer
    fetch_function__ObjectMaskWithTf__cam_infos,  // fetch(index, &value) function pointer
    assign_function__ObjectMaskWithTf__cam_infos,  // assign(index, value) function pointer
    resize_function__ObjectMaskWithTf__cam_infos  // resize(index) function pointer
  },
  {
    "object_mask",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::UInt8MultiArray>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs::msg::ObjectMaskWithTf, object_mask),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "cam_transforms",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tf2_msgs::msg::TFMessage>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs::msg::ObjectMaskWithTf, cam_transforms),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ObjectMaskWithTf_message_members = {
  "object_search_msgs::msg",  // message namespace
  "ObjectMaskWithTf",  // message name
  5,  // number of fields
  sizeof(object_search_msgs::msg::ObjectMaskWithTf),
  false,  // has_any_key_member_
  ObjectMaskWithTf_message_member_array,  // message members
  ObjectMaskWithTf_init_function,  // function to initialize message memory (memory has to be allocated)
  ObjectMaskWithTf_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ObjectMaskWithTf_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ObjectMaskWithTf_message_members,
  get_message_typesupport_handle_function,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_hash,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_description,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace object_search_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<object_search_msgs::msg::ObjectMaskWithTf>()
{
  return &::object_search_msgs::msg::rosidl_typesupport_introspection_cpp::ObjectMaskWithTf_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, object_search_msgs, msg, ObjectMaskWithTf)() {
  return &::object_search_msgs::msg::rosidl_typesupport_introspection_cpp::ObjectMaskWithTf_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
