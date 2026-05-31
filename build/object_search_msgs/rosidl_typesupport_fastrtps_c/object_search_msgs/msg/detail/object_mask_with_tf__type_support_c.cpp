// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice
#include "object_search_msgs/msg/detail/object_mask_with_tf__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "object_search_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "object_search_msgs/msg/detail/object_mask_with_tf__struct.h"
#include "object_search_msgs/msg/detail/object_mask_with_tf__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "nav_msgs/msg/detail/odometry__functions.h"  // odom
#include "sensor_msgs/msg/detail/camera_info__functions.h"  // cam_infos
#include "std_msgs/msg/detail/header__functions.h"  // header
#include "std_msgs/msg/detail/u_int8_multi_array__functions.h"  // object_mask
#include "tf2_msgs/msg/detail/tf_message__functions.h"  // cam_transforms

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_nav_msgs__msg__Odometry(
  const nav_msgs__msg__Odometry * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_deserialize_nav_msgs__msg__Odometry(
  eprosima::fastcdr::Cdr & cdr,
  nav_msgs__msg__Odometry * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_nav_msgs__msg__Odometry(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_nav_msgs__msg__Odometry(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_key_nav_msgs__msg__Odometry(
  const nav_msgs__msg__Odometry * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_key_nav_msgs__msg__Odometry(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_key_nav_msgs__msg__Odometry(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_msgs, msg, Odometry)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_sensor_msgs__msg__CameraInfo(
  const sensor_msgs__msg__CameraInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_deserialize_sensor_msgs__msg__CameraInfo(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__CameraInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_sensor_msgs__msg__CameraInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_sensor_msgs__msg__CameraInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_key_sensor_msgs__msg__CameraInfo(
  const sensor_msgs__msg__CameraInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_key_sensor_msgs__msg__CameraInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_key_sensor_msgs__msg__CameraInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, CameraInfo)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_std_msgs__msg__UInt8MultiArray(
  const std_msgs__msg__UInt8MultiArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_deserialize_std_msgs__msg__UInt8MultiArray(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__UInt8MultiArray * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_std_msgs__msg__UInt8MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_std_msgs__msg__UInt8MultiArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_key_std_msgs__msg__UInt8MultiArray(
  const std_msgs__msg__UInt8MultiArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_key_std_msgs__msg__UInt8MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_key_std_msgs__msg__UInt8MultiArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, UInt8MultiArray)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_tf2_msgs__msg__TFMessage(
  const tf2_msgs__msg__TFMessage * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_deserialize_tf2_msgs__msg__TFMessage(
  eprosima::fastcdr::Cdr & cdr,
  tf2_msgs__msg__TFMessage * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_tf2_msgs__msg__TFMessage(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_tf2_msgs__msg__TFMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
bool cdr_serialize_key_tf2_msgs__msg__TFMessage(
  const tf2_msgs__msg__TFMessage * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t get_serialized_size_key_tf2_msgs__msg__TFMessage(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
size_t max_serialized_size_key_tf2_msgs__msg__TFMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_object_search_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tf2_msgs, msg, TFMessage)();


using _ObjectMaskWithTf__ros_msg_type = object_search_msgs__msg__ObjectMaskWithTf;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_search_msgs
bool cdr_serialize_object_search_msgs__msg__ObjectMaskWithTf(
  const object_search_msgs__msg__ObjectMaskWithTf * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: odom
  {
    cdr_serialize_nav_msgs__msg__Odometry(
      &ros_message->odom, cdr);
  }

  // Field name: cam_infos
  {
    size_t size = ros_message->cam_infos.size;
    auto array_ptr = ros_message->cam_infos.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_sensor_msgs__msg__CameraInfo(
        &array_ptr[i], cdr);
    }
  }

  // Field name: object_mask
  {
    cdr_serialize_std_msgs__msg__UInt8MultiArray(
      &ros_message->object_mask, cdr);
  }

  // Field name: cam_transforms
  {
    cdr_serialize_tf2_msgs__msg__TFMessage(
      &ros_message->cam_transforms, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_search_msgs
bool cdr_deserialize_object_search_msgs__msg__ObjectMaskWithTf(
  eprosima::fastcdr::Cdr & cdr,
  object_search_msgs__msg__ObjectMaskWithTf * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: odom
  {
    cdr_deserialize_nav_msgs__msg__Odometry(cdr, &ros_message->odom);
  }

  // Field name: cam_infos
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->cam_infos.data) {
      sensor_msgs__msg__CameraInfo__Sequence__fini(&ros_message->cam_infos);
    }
    if (!sensor_msgs__msg__CameraInfo__Sequence__init(&ros_message->cam_infos, size)) {
      fprintf(stderr, "failed to create array for field 'cam_infos'");
      return false;
    }
    auto array_ptr = ros_message->cam_infos.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_sensor_msgs__msg__CameraInfo(cdr, &array_ptr[i]);
    }
  }

  // Field name: object_mask
  {
    cdr_deserialize_std_msgs__msg__UInt8MultiArray(cdr, &ros_message->object_mask);
  }

  // Field name: cam_transforms
  {
    cdr_deserialize_tf2_msgs__msg__TFMessage(cdr, &ros_message->cam_transforms);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_search_msgs
size_t get_serialized_size_object_search_msgs__msg__ObjectMaskWithTf(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObjectMaskWithTf__ros_msg_type * ros_message = static_cast<const _ObjectMaskWithTf__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: odom
  current_alignment += get_serialized_size_nav_msgs__msg__Odometry(
    &(ros_message->odom), current_alignment);

  // Field name: cam_infos
  {
    size_t array_size = ros_message->cam_infos.size;
    auto array_ptr = ros_message->cam_infos.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_msgs__msg__CameraInfo(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: object_mask
  current_alignment += get_serialized_size_std_msgs__msg__UInt8MultiArray(
    &(ros_message->object_mask), current_alignment);

  // Field name: cam_transforms
  current_alignment += get_serialized_size_tf2_msgs__msg__TFMessage(
    &(ros_message->cam_transforms), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_search_msgs
size_t max_serialized_size_object_search_msgs__msg__ObjectMaskWithTf(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: odom
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_msgs__msg__Odometry(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cam_infos
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__CameraInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: object_mask
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__UInt8MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cam_transforms
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_tf2_msgs__msg__TFMessage(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = object_search_msgs__msg__ObjectMaskWithTf;
    is_plain =
      (
      offsetof(DataType, cam_transforms) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_search_msgs
bool cdr_serialize_key_object_search_msgs__msg__ObjectMaskWithTf(
  const object_search_msgs__msg__ObjectMaskWithTf * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: odom
  {
    cdr_serialize_key_nav_msgs__msg__Odometry(
      &ros_message->odom, cdr);
  }

  // Field name: cam_infos
  {
    size_t size = ros_message->cam_infos.size;
    auto array_ptr = ros_message->cam_infos.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_sensor_msgs__msg__CameraInfo(
        &array_ptr[i], cdr);
    }
  }

  // Field name: object_mask
  {
    cdr_serialize_key_std_msgs__msg__UInt8MultiArray(
      &ros_message->object_mask, cdr);
  }

  // Field name: cam_transforms
  {
    cdr_serialize_key_tf2_msgs__msg__TFMessage(
      &ros_message->cam_transforms, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_search_msgs
size_t get_serialized_size_key_object_search_msgs__msg__ObjectMaskWithTf(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObjectMaskWithTf__ros_msg_type * ros_message = static_cast<const _ObjectMaskWithTf__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: odom
  current_alignment += get_serialized_size_key_nav_msgs__msg__Odometry(
    &(ros_message->odom), current_alignment);

  // Field name: cam_infos
  {
    size_t array_size = ros_message->cam_infos.size;
    auto array_ptr = ros_message->cam_infos.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_sensor_msgs__msg__CameraInfo(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: object_mask
  current_alignment += get_serialized_size_key_std_msgs__msg__UInt8MultiArray(
    &(ros_message->object_mask), current_alignment);

  // Field name: cam_transforms
  current_alignment += get_serialized_size_key_tf2_msgs__msg__TFMessage(
    &(ros_message->cam_transforms), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_object_search_msgs
size_t max_serialized_size_key_object_search_msgs__msg__ObjectMaskWithTf(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: odom
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_msgs__msg__Odometry(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cam_infos
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_sensor_msgs__msg__CameraInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: object_mask
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__UInt8MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cam_transforms
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_tf2_msgs__msg__TFMessage(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = object_search_msgs__msg__ObjectMaskWithTf;
    is_plain =
      (
      offsetof(DataType, cam_transforms) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ObjectMaskWithTf__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const object_search_msgs__msg__ObjectMaskWithTf * ros_message = static_cast<const object_search_msgs__msg__ObjectMaskWithTf *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_object_search_msgs__msg__ObjectMaskWithTf(ros_message, cdr);
}

static bool _ObjectMaskWithTf__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  object_search_msgs__msg__ObjectMaskWithTf * ros_message = static_cast<object_search_msgs__msg__ObjectMaskWithTf *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_object_search_msgs__msg__ObjectMaskWithTf(cdr, ros_message);
}

static uint32_t _ObjectMaskWithTf__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_object_search_msgs__msg__ObjectMaskWithTf(
      untyped_ros_message, 0));
}

static size_t _ObjectMaskWithTf__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_object_search_msgs__msg__ObjectMaskWithTf(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ObjectMaskWithTf = {
  "object_search_msgs::msg",
  "ObjectMaskWithTf",
  _ObjectMaskWithTf__cdr_serialize,
  _ObjectMaskWithTf__cdr_deserialize,
  _ObjectMaskWithTf__get_serialized_size,
  _ObjectMaskWithTf__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ObjectMaskWithTf__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ObjectMaskWithTf,
  get_message_typesupport_handle_function,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_hash,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_description,
  &object_search_msgs__msg__ObjectMaskWithTf__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, object_search_msgs, msg, ObjectMaskWithTf)() {
  return &_ObjectMaskWithTf__type_support;
}

#if defined(__cplusplus)
}
#endif
