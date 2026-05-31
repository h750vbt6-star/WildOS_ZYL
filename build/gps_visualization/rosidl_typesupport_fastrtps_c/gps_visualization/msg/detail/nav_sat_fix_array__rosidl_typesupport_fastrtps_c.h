// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice
#ifndef GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gps_visualization/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gps_visualization/msg/detail/nav_sat_fix_array__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
bool cdr_serialize_gps_visualization__msg__NavSatFixArray(
  const gps_visualization__msg__NavSatFixArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
bool cdr_deserialize_gps_visualization__msg__NavSatFixArray(
  eprosima::fastcdr::Cdr &,
  gps_visualization__msg__NavSatFixArray * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t get_serialized_size_gps_visualization__msg__NavSatFixArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t max_serialized_size_gps_visualization__msg__NavSatFixArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
bool cdr_serialize_key_gps_visualization__msg__NavSatFixArray(
  const gps_visualization__msg__NavSatFixArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t get_serialized_size_key_gps_visualization__msg__NavSatFixArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
size_t max_serialized_size_key_gps_visualization__msg__NavSatFixArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gps_visualization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gps_visualization, msg, NavSatFixArray)();

#ifdef __cplusplus
}
#endif

#endif  // GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
