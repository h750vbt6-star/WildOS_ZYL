// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from elevation_map_msgs:srv/CheckSafety.idl
// generated code does not contain a copyright notice
#include "elevation_map_msgs/srv/detail/check_safety__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "elevation_map_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "elevation_map_msgs/srv/detail/check_safety__struct.h"
#include "elevation_map_msgs/srv/detail/check_safety__functions.h"
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

#include "geometry_msgs/msg/detail/polygon_stamped__functions.h"  // polygons

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_serialize_geometry_msgs__msg__PolygonStamped(
  const geometry_msgs__msg__PolygonStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_deserialize_geometry_msgs__msg__PolygonStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PolygonStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t get_serialized_size_geometry_msgs__msg__PolygonStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t max_serialized_size_geometry_msgs__msg__PolygonStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_serialize_key_geometry_msgs__msg__PolygonStamped(
  const geometry_msgs__msg__PolygonStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t get_serialized_size_key_geometry_msgs__msg__PolygonStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t max_serialized_size_key_geometry_msgs__msg__PolygonStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PolygonStamped)();


using _CheckSafety_Request__ros_msg_type = elevation_map_msgs__srv__CheckSafety_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_serialize_elevation_map_msgs__srv__CheckSafety_Request(
  const elevation_map_msgs__srv__CheckSafety_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: polygons
  {
    size_t size = ros_message->polygons.size;
    auto array_ptr = ros_message->polygons.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_geometry_msgs__msg__PolygonStamped(
        &array_ptr[i], cdr);
    }
  }

  // Field name: compute_untraversable_polygon
  {
    cdr << (ros_message->compute_untraversable_polygon ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Request(
  eprosima::fastcdr::Cdr & cdr,
  elevation_map_msgs__srv__CheckSafety_Request * ros_message)
{
  // Field name: polygons
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

    if (ros_message->polygons.data) {
      geometry_msgs__msg__PolygonStamped__Sequence__fini(&ros_message->polygons);
    }
    if (!geometry_msgs__msg__PolygonStamped__Sequence__init(&ros_message->polygons, size)) {
      fprintf(stderr, "failed to create array for field 'polygons'");
      return false;
    }
    auto array_ptr = ros_message->polygons.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_geometry_msgs__msg__PolygonStamped(cdr, &array_ptr[i]);
    }
  }

  // Field name: compute_untraversable_polygon
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->compute_untraversable_polygon = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t get_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckSafety_Request__ros_msg_type * ros_message = static_cast<const _CheckSafety_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: polygons
  {
    size_t array_size = ros_message->polygons.size;
    auto array_ptr = ros_message->polygons.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_geometry_msgs__msg__PolygonStamped(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: compute_untraversable_polygon
  {
    size_t item_size = sizeof(ros_message->compute_untraversable_polygon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t max_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
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

  // Field name: polygons
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
        max_serialized_size_geometry_msgs__msg__PolygonStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: compute_untraversable_polygon
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = elevation_map_msgs__srv__CheckSafety_Request;
    is_plain =
      (
      offsetof(DataType, compute_untraversable_polygon) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_serialize_key_elevation_map_msgs__srv__CheckSafety_Request(
  const elevation_map_msgs__srv__CheckSafety_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: polygons
  {
    size_t size = ros_message->polygons.size;
    auto array_ptr = ros_message->polygons.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_geometry_msgs__msg__PolygonStamped(
        &array_ptr[i], cdr);
    }
  }

  // Field name: compute_untraversable_polygon
  {
    cdr << (ros_message->compute_untraversable_polygon ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t get_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckSafety_Request__ros_msg_type * ros_message = static_cast<const _CheckSafety_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: polygons
  {
    size_t array_size = ros_message->polygons.size;
    auto array_ptr = ros_message->polygons.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_geometry_msgs__msg__PolygonStamped(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: compute_untraversable_polygon
  {
    size_t item_size = sizeof(ros_message->compute_untraversable_polygon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t max_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Request(
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
  // Field name: polygons
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
        max_serialized_size_key_geometry_msgs__msg__PolygonStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: compute_untraversable_polygon
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = elevation_map_msgs__srv__CheckSafety_Request;
    is_plain =
      (
      offsetof(DataType, compute_untraversable_polygon) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CheckSafety_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const elevation_map_msgs__srv__CheckSafety_Request * ros_message = static_cast<const elevation_map_msgs__srv__CheckSafety_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_elevation_map_msgs__srv__CheckSafety_Request(ros_message, cdr);
}

static bool _CheckSafety_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  elevation_map_msgs__srv__CheckSafety_Request * ros_message = static_cast<elevation_map_msgs__srv__CheckSafety_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Request(cdr, ros_message);
}

static uint32_t _CheckSafety_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
      untyped_ros_message, 0));
}

static size_t _CheckSafety_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CheckSafety_Request = {
  "elevation_map_msgs::srv",
  "CheckSafety_Request",
  _CheckSafety_Request__cdr_serialize,
  _CheckSafety_Request__cdr_deserialize,
  _CheckSafety_Request__get_serialized_size,
  _CheckSafety_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CheckSafety_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CheckSafety_Request,
  get_message_typesupport_handle_function,
  &elevation_map_msgs__srv__CheckSafety_Request__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety_Request__get_type_description,
  &elevation_map_msgs__srv__CheckSafety_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety_Request)() {
  return &_CheckSafety_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "elevation_map_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__struct.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "geometry_msgs/msg/detail/polygon_stamped__functions.h"  // untraversable_polygons
#include "rosidl_runtime_c/primitives_sequence.h"  // is_safe, traversability
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // is_safe, traversability

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_serialize_geometry_msgs__msg__PolygonStamped(
  const geometry_msgs__msg__PolygonStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_deserialize_geometry_msgs__msg__PolygonStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PolygonStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t get_serialized_size_geometry_msgs__msg__PolygonStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t max_serialized_size_geometry_msgs__msg__PolygonStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_serialize_key_geometry_msgs__msg__PolygonStamped(
  const geometry_msgs__msg__PolygonStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t get_serialized_size_key_geometry_msgs__msg__PolygonStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t max_serialized_size_key_geometry_msgs__msg__PolygonStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PolygonStamped)();


using _CheckSafety_Response__ros_msg_type = elevation_map_msgs__srv__CheckSafety_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_serialize_elevation_map_msgs__srv__CheckSafety_Response(
  const elevation_map_msgs__srv__CheckSafety_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: is_safe
  {
    size_t size = ros_message->is_safe.size;
    auto array_ptr = ros_message->is_safe.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: traversability
  {
    size_t size = ros_message->traversability.size;
    auto array_ptr = ros_message->traversability.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: untraversable_polygons
  {
    size_t size = ros_message->untraversable_polygons.size;
    auto array_ptr = ros_message->untraversable_polygons.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_geometry_msgs__msg__PolygonStamped(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Response(
  eprosima::fastcdr::Cdr & cdr,
  elevation_map_msgs__srv__CheckSafety_Response * ros_message)
{
  // Field name: is_safe
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

    if (ros_message->is_safe.data) {
      rosidl_runtime_c__boolean__Sequence__fini(&ros_message->is_safe);
    }
    if (!rosidl_runtime_c__boolean__Sequence__init(&ros_message->is_safe, size)) {
      fprintf(stderr, "failed to create array for field 'is_safe'");
      return false;
    }
    auto array_ptr = ros_message->is_safe.data;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: traversability
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

    if (ros_message->traversability.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->traversability);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->traversability, size)) {
      fprintf(stderr, "failed to create array for field 'traversability'");
      return false;
    }
    auto array_ptr = ros_message->traversability.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: untraversable_polygons
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

    if (ros_message->untraversable_polygons.data) {
      geometry_msgs__msg__PolygonStamped__Sequence__fini(&ros_message->untraversable_polygons);
    }
    if (!geometry_msgs__msg__PolygonStamped__Sequence__init(&ros_message->untraversable_polygons, size)) {
      fprintf(stderr, "failed to create array for field 'untraversable_polygons'");
      return false;
    }
    auto array_ptr = ros_message->untraversable_polygons.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_geometry_msgs__msg__PolygonStamped(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t get_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckSafety_Response__ros_msg_type * ros_message = static_cast<const _CheckSafety_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: is_safe
  {
    size_t array_size = ros_message->is_safe.size;
    auto array_ptr = ros_message->is_safe.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: traversability
  {
    size_t array_size = ros_message->traversability.size;
    auto array_ptr = ros_message->traversability.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: untraversable_polygons
  {
    size_t array_size = ros_message->untraversable_polygons.size;
    auto array_ptr = ros_message->untraversable_polygons.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_geometry_msgs__msg__PolygonStamped(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t max_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
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

  // Field name: is_safe
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: traversability
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: untraversable_polygons
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
        max_serialized_size_geometry_msgs__msg__PolygonStamped(
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
    using DataType = elevation_map_msgs__srv__CheckSafety_Response;
    is_plain =
      (
      offsetof(DataType, untraversable_polygons) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_serialize_key_elevation_map_msgs__srv__CheckSafety_Response(
  const elevation_map_msgs__srv__CheckSafety_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: is_safe
  {
    size_t size = ros_message->is_safe.size;
    auto array_ptr = ros_message->is_safe.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: traversability
  {
    size_t size = ros_message->traversability.size;
    auto array_ptr = ros_message->traversability.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: untraversable_polygons
  {
    size_t size = ros_message->untraversable_polygons.size;
    auto array_ptr = ros_message->untraversable_polygons.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_geometry_msgs__msg__PolygonStamped(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t get_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckSafety_Response__ros_msg_type * ros_message = static_cast<const _CheckSafety_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: is_safe
  {
    size_t array_size = ros_message->is_safe.size;
    auto array_ptr = ros_message->is_safe.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: traversability
  {
    size_t array_size = ros_message->traversability.size;
    auto array_ptr = ros_message->traversability.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: untraversable_polygons
  {
    size_t array_size = ros_message->untraversable_polygons.size;
    auto array_ptr = ros_message->untraversable_polygons.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_geometry_msgs__msg__PolygonStamped(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t max_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Response(
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
  // Field name: is_safe
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: traversability
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: untraversable_polygons
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
        max_serialized_size_key_geometry_msgs__msg__PolygonStamped(
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
    using DataType = elevation_map_msgs__srv__CheckSafety_Response;
    is_plain =
      (
      offsetof(DataType, untraversable_polygons) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CheckSafety_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const elevation_map_msgs__srv__CheckSafety_Response * ros_message = static_cast<const elevation_map_msgs__srv__CheckSafety_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_elevation_map_msgs__srv__CheckSafety_Response(ros_message, cdr);
}

static bool _CheckSafety_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  elevation_map_msgs__srv__CheckSafety_Response * ros_message = static_cast<elevation_map_msgs__srv__CheckSafety_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Response(cdr, ros_message);
}

static uint32_t _CheckSafety_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
      untyped_ros_message, 0));
}

static size_t _CheckSafety_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CheckSafety_Response = {
  "elevation_map_msgs::srv",
  "CheckSafety_Response",
  _CheckSafety_Response__cdr_serialize,
  _CheckSafety_Response__cdr_deserialize,
  _CheckSafety_Response__get_serialized_size,
  _CheckSafety_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CheckSafety_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CheckSafety_Response,
  get_message_typesupport_handle_function,
  &elevation_map_msgs__srv__CheckSafety_Response__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety_Response__get_type_description,
  &elevation_map_msgs__srv__CheckSafety_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety_Response)() {
  return &_CheckSafety_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "elevation_map_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__struct.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_elevation_map_msgs__srv__CheckSafety_Request(
  const elevation_map_msgs__srv__CheckSafety_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Request(
  eprosima::fastcdr::Cdr & cdr,
  elevation_map_msgs__srv__CheckSafety_Request * ros_message);

size_t get_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_elevation_map_msgs__srv__CheckSafety_Request(
  const elevation_map_msgs__srv__CheckSafety_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety_Request)();

bool cdr_serialize_elevation_map_msgs__srv__CheckSafety_Response(
  const elevation_map_msgs__srv__CheckSafety_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Response(
  eprosima::fastcdr::Cdr & cdr,
  elevation_map_msgs__srv__CheckSafety_Response * ros_message);

size_t get_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_elevation_map_msgs__srv__CheckSafety_Response(
  const elevation_map_msgs__srv__CheckSafety_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety_Response)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_elevation_map_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();


using _CheckSafety_Event__ros_msg_type = elevation_map_msgs__srv__CheckSafety_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_serialize_elevation_map_msgs__srv__CheckSafety_Event(
  const elevation_map_msgs__srv__CheckSafety_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_elevation_map_msgs__srv__CheckSafety_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_elevation_map_msgs__srv__CheckSafety_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Event(
  eprosima::fastcdr::Cdr & cdr,
  elevation_map_msgs__srv__CheckSafety_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
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

    if (ros_message->request.data) {
      elevation_map_msgs__srv__CheckSafety_Request__Sequence__fini(&ros_message->request);
    }
    if (!elevation_map_msgs__srv__CheckSafety_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
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

    if (ros_message->response.data) {
      elevation_map_msgs__srv__CheckSafety_Response__Sequence__fini(&ros_message->response);
    }
    if (!elevation_map_msgs__srv__CheckSafety_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t get_serialized_size_elevation_map_msgs__srv__CheckSafety_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckSafety_Event__ros_msg_type * ros_message = static_cast<const _CheckSafety_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t max_serialized_size_elevation_map_msgs__srv__CheckSafety_Event(
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

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_elevation_map_msgs__srv__CheckSafety_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_elevation_map_msgs__srv__CheckSafety_Response(
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
    using DataType = elevation_map_msgs__srv__CheckSafety_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
bool cdr_serialize_key_elevation_map_msgs__srv__CheckSafety_Event(
  const elevation_map_msgs__srv__CheckSafety_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_elevation_map_msgs__srv__CheckSafety_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_elevation_map_msgs__srv__CheckSafety_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t get_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CheckSafety_Event__ros_msg_type * ros_message = static_cast<const _CheckSafety_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_elevation_map_msgs
size_t max_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Event(
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
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_elevation_map_msgs__srv__CheckSafety_Response(
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
    using DataType = elevation_map_msgs__srv__CheckSafety_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CheckSafety_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const elevation_map_msgs__srv__CheckSafety_Event * ros_message = static_cast<const elevation_map_msgs__srv__CheckSafety_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_elevation_map_msgs__srv__CheckSafety_Event(ros_message, cdr);
}

static bool _CheckSafety_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  elevation_map_msgs__srv__CheckSafety_Event * ros_message = static_cast<elevation_map_msgs__srv__CheckSafety_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_elevation_map_msgs__srv__CheckSafety_Event(cdr, ros_message);
}

static uint32_t _CheckSafety_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_elevation_map_msgs__srv__CheckSafety_Event(
      untyped_ros_message, 0));
}

static size_t _CheckSafety_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_elevation_map_msgs__srv__CheckSafety_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CheckSafety_Event = {
  "elevation_map_msgs::srv",
  "CheckSafety_Event",
  _CheckSafety_Event__cdr_serialize,
  _CheckSafety_Event__cdr_deserialize,
  _CheckSafety_Event__get_serialized_size,
  _CheckSafety_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CheckSafety_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CheckSafety_Event,
  get_message_typesupport_handle_function,
  &elevation_map_msgs__srv__CheckSafety_Event__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety_Event__get_type_description,
  &elevation_map_msgs__srv__CheckSafety_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety_Event)() {
  return &_CheckSafety_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "elevation_map_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "elevation_map_msgs/srv/check_safety.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t CheckSafety__callbacks = {
  "elevation_map_msgs::srv",
  "CheckSafety",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety_Response)(),
};

static rosidl_service_type_support_t CheckSafety__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &CheckSafety__callbacks,
  get_service_typesupport_handle_function,
  &_CheckSafety_Request__type_support,
  &_CheckSafety_Response__type_support,
  &_CheckSafety_Event__type_support,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    elevation_map_msgs,
    srv,
    CheckSafety
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    elevation_map_msgs,
    srv,
    CheckSafety
  ),
  &elevation_map_msgs__srv__CheckSafety__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety__get_type_description,
  &elevation_map_msgs__srv__CheckSafety__get_type_description_sources,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, elevation_map_msgs, srv, CheckSafety)() {
  return &CheckSafety__handle;
}

#if defined(__cplusplus)
}
#endif
