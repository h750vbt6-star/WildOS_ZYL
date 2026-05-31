// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "object_search_msgs/msg/detail/object_mask_with_tf__rosidl_typesupport_introspection_c.h"
#include "object_search_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "object_search_msgs/msg/detail/object_mask_with_tf__functions.h"
#include "object_search_msgs/msg/detail/object_mask_with_tf__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `odom`
#include "nav_msgs/msg/odometry.h"
// Member `odom`
#include "nav_msgs/msg/detail/odometry__rosidl_typesupport_introspection_c.h"
// Member `cam_infos`
#include "sensor_msgs/msg/camera_info.h"
// Member `cam_infos`
#include "sensor_msgs/msg/detail/camera_info__rosidl_typesupport_introspection_c.h"
// Member `object_mask`
#include "std_msgs/msg/u_int8_multi_array.h"
// Member `object_mask`
#include "std_msgs/msg/detail/u_int8_multi_array__rosidl_typesupport_introspection_c.h"
// Member `cam_transforms`
#include "tf2_msgs/msg/tf_message.h"
// Member `cam_transforms`
#include "tf2_msgs/msg/detail/tf_message__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  object_search_msgs__msg__ObjectMaskWithTf__init(message_memory);
}

void object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_fini_function(void * message_memory)
{
  object_search_msgs__msg__ObjectMaskWithTf__fini(message_memory);
}

size_t object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__size_function__ObjectMaskWithTf__cam_infos(
  const void * untyped_member)
{
  const sensor_msgs__msg__CameraInfo__Sequence * member =
    (const sensor_msgs__msg__CameraInfo__Sequence *)(untyped_member);
  return member->size;
}

const void * object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__get_const_function__ObjectMaskWithTf__cam_infos(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__CameraInfo__Sequence * member =
    (const sensor_msgs__msg__CameraInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void * object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__get_function__ObjectMaskWithTf__cam_infos(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__CameraInfo__Sequence * member =
    (sensor_msgs__msg__CameraInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__fetch_function__ObjectMaskWithTf__cam_infos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__CameraInfo * item =
    ((const sensor_msgs__msg__CameraInfo *)
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__get_const_function__ObjectMaskWithTf__cam_infos(untyped_member, index));
  sensor_msgs__msg__CameraInfo * value =
    (sensor_msgs__msg__CameraInfo *)(untyped_value);
  *value = *item;
}

void object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__assign_function__ObjectMaskWithTf__cam_infos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__CameraInfo * item =
    ((sensor_msgs__msg__CameraInfo *)
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__get_function__ObjectMaskWithTf__cam_infos(untyped_member, index));
  const sensor_msgs__msg__CameraInfo * value =
    (const sensor_msgs__msg__CameraInfo *)(untyped_value);
  *item = *value;
}

bool object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__resize_function__ObjectMaskWithTf__cam_infos(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__CameraInfo__Sequence * member =
    (sensor_msgs__msg__CameraInfo__Sequence *)(untyped_member);
  sensor_msgs__msg__CameraInfo__Sequence__fini(member);
  return sensor_msgs__msg__CameraInfo__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs__msg__ObjectMaskWithTf, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "odom",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs__msg__ObjectMaskWithTf, odom),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cam_infos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs__msg__ObjectMaskWithTf, cam_infos),  // bytes offset in struct
    NULL,  // default value
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__size_function__ObjectMaskWithTf__cam_infos,  // size() function pointer
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__get_const_function__ObjectMaskWithTf__cam_infos,  // get_const(index) function pointer
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__get_function__ObjectMaskWithTf__cam_infos,  // get(index) function pointer
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__fetch_function__ObjectMaskWithTf__cam_infos,  // fetch(index, &value) function pointer
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__assign_function__ObjectMaskWithTf__cam_infos,  // assign(index, value) function pointer
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__resize_function__ObjectMaskWithTf__cam_infos  // resize(index) function pointer
  },
  {
    "object_mask",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs__msg__ObjectMaskWithTf, object_mask),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cam_transforms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(object_search_msgs__msg__ObjectMaskWithTf, cam_transforms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_members = {
  "object_search_msgs__msg",  // message namespace
  "ObjectMaskWithTf",  // message name
  5,  // number of fields
  sizeof(object_search_msgs__msg__ObjectMaskWithTf),
  false,  // has_any_key_member_
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_member_array,  // message members
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_init_function,  // function to initialize message memory (memory has to be allocated)
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_type_support_handle = {
  0,
  &object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_members,
  get_message_typesupport_handle_function,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_hash,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_description,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_object_search_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, object_search_msgs, msg, ObjectMaskWithTf)() {
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Odometry)();
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, CameraInfo)();
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, UInt8MultiArray)();
  object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, msg, TFMessage)();
  if (!object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_type_support_handle.typesupport_identifier) {
    object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &object_search_msgs__msg__ObjectMaskWithTf__rosidl_typesupport_introspection_c__ObjectMaskWithTf_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
