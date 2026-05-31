// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gps_visualization/msg/nav_sat_fix_array.h"


#ifndef GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__STRUCT_H_
#define GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'gps_fixes'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.h"

/// Struct defined in msg/NavSatFixArray in the package gps_visualization.
typedef struct gps_visualization__msg__NavSatFixArray
{
  sensor_msgs__msg__NavSatFix__Sequence gps_fixes;
} gps_visualization__msg__NavSatFixArray;

// Struct for a sequence of gps_visualization__msg__NavSatFixArray.
typedef struct gps_visualization__msg__NavSatFixArray__Sequence
{
  gps_visualization__msg__NavSatFixArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gps_visualization__msg__NavSatFixArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__STRUCT_H_
