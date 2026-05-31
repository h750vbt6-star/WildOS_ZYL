// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice
#include "gps_visualization/msg/detail/nav_sat_fix_array__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gps_visualization/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gps_visualization/msg/detail/nav_sat_fix_array__struct.h"
#include "gps_visualization/msg/detail/nav_sat_fix_array__functions.h"
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

#include "sensor_msgs/msg/detail/nav_sat_fix__functions.h"  // gps_fixes

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
bool cdr_serialize_sensor_msgs__msg__NavSatFix(
  const sensor_msgs__msg__NavSatFix * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
bool cdr_deserialize_sensor_msgs__msg__NavSatFix(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__NavSatFix * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
size_t get_serialized_size_sensor_msgs__msg__NavSatFix(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
size_t max_serialized_size_sensor_msgs__msg__NavSatFix(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
bool cdr_serialize_key_sensor_msgs__msg__NavSatFix(
  const sensor_msgs__msg__NavSatFix * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
size_t get_serialized_size_key_sensor_msgs__msg__NavSatFix(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
size_t max_serialized_size_key_sensor_msgs__msg__NavSatFix(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gps_visualization
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, NavSatFix)();


using _NavSatFixArray__ros_msg_type = gps_visualization__msg__NavSatFixArray;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
bool cdr_serialize_gps_visualization__msg__NavSatFixArray(
  const gps_visualization__msg__NavSatFixArray * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gps_fixes
  {
    size_t size = ros_message->gps_fixes.size;
    auto array_ptr = ros_message->gps_fixes.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_sensor_msgs__msg__NavSatFix(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
bool cdr_deserialize_gps_visualization__msg__NavSatFixArray(
  eprosima::fastcdr::Cdr & cdr,
  gps_visualization__msg__NavSatFixArray * ros_message)
{
  // Field name: gps_fixes
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

    if (ros_message->gps_fixes.data) {
      sensor_msgs__msg__NavSatFix__Sequence__fini(&ros_message->gps_fixes);
    }
    if (!sensor_msgs__msg__NavSatFix__Sequence__init(&ros_message->gps_fixes, size)) {
      fprintf(stderr, "failed to create array for field 'gps_fixes'");
      return false;
    }
    auto array_ptr = ros_message->gps_fixes.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_sensor_msgs__msg__NavSatFix(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t get_serialized_size_gps_visualization__msg__NavSatFixArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavSatFixArray__ros_msg_type * ros_message = static_cast<const _NavSatFixArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gps_fixes
  {
    size_t array_size = ros_message->gps_fixes.size;
    auto array_ptr = ros_message->gps_fixes.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_msgs__msg__NavSatFix(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t max_serialized_size_gps_visualization__msg__NavSatFixArray(
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

  // Field name: gps_fixes
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
        max_serialized_size_sensor_msgs__msg__NavSatFix(
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
    using DataType = gps_visualization__msg__NavSatFixArray;
    is_plain =
      (
      offsetof(DataType, gps_fixes) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
bool cdr_serialize_key_gps_visualization__msg__NavSatFixArray(
  const gps_visualization__msg__NavSatFixArray * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gps_fixes
  {
    size_t size = ros_message->gps_fixes.size;
    auto array_ptr = ros_message->gps_fixes.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_sensor_msgs__msg__NavSatFix(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t get_serialized_size_key_gps_visualization__msg__NavSatFixArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavSatFixArray__ros_msg_type * ros_message = static_cast<const _NavSatFixArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gps_fixes
  {
    size_t array_size = ros_message->gps_fixes.size;
    auto array_ptr = ros_message->gps_fixes.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_sensor_msgs__msg__NavSatFix(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t max_serialized_size_key_gps_visualization__msg__NavSatFixArray(
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
  // Field name: gps_fixes
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
        max_serialized_size_key_sensor_msgs__msg__NavSatFix(
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
    using DataType = gps_visualization__msg__NavSatFixArray;
    is_plain =
      (
      offsetof(DataType, gps_fixes) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _NavSatFixArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const gps_visualization__msg__NavSatFixArray * ros_message = static_cast<const gps_visualization__msg__NavSatFixArray *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_gps_visualization__msg__NavSatFixArray(ros_message, cdr);
}

static bool _NavSatFixArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  gps_visualization__msg__NavSatFixArray * ros_message = static_cast<gps_visualization__msg__NavSatFixArray *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_gps_visualization__msg__NavSatFixArray(cdr, ros_message);
}

static uint32_t _NavSatFixArray__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gps_visualization__msg__NavSatFixArray(
      untyped_ros_message, 0));
}

static size_t _NavSatFixArray__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gps_visualization__msg__NavSatFixArray(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavSatFixArray = {
  "gps_visualization::msg",
  "NavSatFixArray",
  _NavSatFixArray__cdr_serialize,
  _NavSatFixArray__cdr_deserialize,
  _NavSatFixArray__get_serialized_size,
  _NavSatFixArray__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _NavSatFixArray__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavSatFixArray,
  get_message_typesupport_handle_function,
  &gps_visualization__msg__NavSatFixArray__get_type_hash,
  &gps_visualization__msg__NavSatFixArray__get_type_description,
  &gps_visualization__msg__NavSatFixArray__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gps_visualization, msg, NavSatFixArray)() {
  return &_NavSatFixArray__type_support;
}

#if defined(__cplusplus)
}
#endif
