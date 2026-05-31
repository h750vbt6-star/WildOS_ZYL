// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gps_visualization/msg/detail/nav_sat_fix_array__rosidl_typesupport_introspection_c.h"
#include "gps_visualization/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gps_visualization/msg/detail/nav_sat_fix_array__functions.h"
#include "gps_visualization/msg/detail/nav_sat_fix_array__struct.h"


// Include directives for member types
// Member `gps_fixes`
#include "sensor_msgs/msg/nav_sat_fix.h"
// Member `gps_fixes`
#include "sensor_msgs/msg/detail/nav_sat_fix__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gps_visualization__msg__NavSatFixArray__init(message_memory);
}

void gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_fini_function(void * message_memory)
{
  gps_visualization__msg__NavSatFixArray__fini(message_memory);
}

size_t gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__size_function__NavSatFixArray__gps_fixes(
  const void * untyped_member)
{
  const sensor_msgs__msg__NavSatFix__Sequence * member =
    (const sensor_msgs__msg__NavSatFix__Sequence *)(untyped_member);
  return member->size;
}

const void * gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__get_const_function__NavSatFixArray__gps_fixes(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__NavSatFix__Sequence * member =
    (const sensor_msgs__msg__NavSatFix__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__get_function__NavSatFixArray__gps_fixes(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__NavSatFix__Sequence * member =
    (sensor_msgs__msg__NavSatFix__Sequence *)(untyped_member);
  return &member->data[index];
}

void gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__fetch_function__NavSatFixArray__gps_fixes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__NavSatFix * item =
    ((const sensor_msgs__msg__NavSatFix *)
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__get_const_function__NavSatFixArray__gps_fixes(untyped_member, index));
  sensor_msgs__msg__NavSatFix * value =
    (sensor_msgs__msg__NavSatFix *)(untyped_value);
  *value = *item;
}

void gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__assign_function__NavSatFixArray__gps_fixes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__NavSatFix * item =
    ((sensor_msgs__msg__NavSatFix *)
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__get_function__NavSatFixArray__gps_fixes(untyped_member, index));
  const sensor_msgs__msg__NavSatFix * value =
    (const sensor_msgs__msg__NavSatFix *)(untyped_value);
  *item = *value;
}

bool gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__resize_function__NavSatFixArray__gps_fixes(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__NavSatFix__Sequence * member =
    (sensor_msgs__msg__NavSatFix__Sequence *)(untyped_member);
  sensor_msgs__msg__NavSatFix__Sequence__fini(member);
  return sensor_msgs__msg__NavSatFix__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_member_array[1] = {
  {
    "gps_fixes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gps_visualization__msg__NavSatFixArray, gps_fixes),  // bytes offset in struct
    NULL,  // default value
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__size_function__NavSatFixArray__gps_fixes,  // size() function pointer
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__get_const_function__NavSatFixArray__gps_fixes,  // get_const(index) function pointer
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__get_function__NavSatFixArray__gps_fixes,  // get(index) function pointer
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__fetch_function__NavSatFixArray__gps_fixes,  // fetch(index, &value) function pointer
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__assign_function__NavSatFixArray__gps_fixes,  // assign(index, value) function pointer
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__resize_function__NavSatFixArray__gps_fixes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_members = {
  "gps_visualization__msg",  // message namespace
  "NavSatFixArray",  // message name
  1,  // number of fields
  sizeof(gps_visualization__msg__NavSatFixArray),
  false,  // has_any_key_member_
  gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_member_array,  // message members
  gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_init_function,  // function to initialize message memory (memory has to be allocated)
  gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_type_support_handle = {
  0,
  &gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_members,
  get_message_typesupport_handle_function,
  &gps_visualization__msg__NavSatFixArray__get_type_hash,
  &gps_visualization__msg__NavSatFixArray__get_type_description,
  &gps_visualization__msg__NavSatFixArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gps_visualization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gps_visualization, msg, NavSatFixArray)() {
  gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, NavSatFix)();
  if (!gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_type_support_handle.typesupport_identifier) {
    gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gps_visualization__msg__NavSatFixArray__rosidl_typesupport_introspection_c__NavSatFixArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
