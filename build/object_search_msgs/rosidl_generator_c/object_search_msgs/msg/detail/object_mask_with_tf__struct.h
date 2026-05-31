// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "object_search_msgs/msg/object_mask_with_tf.h"


#ifndef OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__STRUCT_H_
#define OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'odom'
#include "nav_msgs/msg/detail/odometry__struct.h"
// Member 'cam_infos'
#include "sensor_msgs/msg/detail/camera_info__struct.h"
// Member 'object_mask'
#include "std_msgs/msg/detail/u_int8_multi_array__struct.h"
// Member 'cam_transforms'
#include "tf2_msgs/msg/detail/tf_message__struct.h"

/// Struct defined in msg/ObjectMaskWithTf in the package object_search_msgs.
typedef struct object_search_msgs__msg__ObjectMaskWithTf
{
  std_msgs__msg__Header header;
  nav_msgs__msg__Odometry odom;
  sensor_msgs__msg__CameraInfo__Sequence cam_infos;
  std_msgs__msg__UInt8MultiArray object_mask;
  tf2_msgs__msg__TFMessage cam_transforms;
} object_search_msgs__msg__ObjectMaskWithTf;

// Struct for a sequence of object_search_msgs__msg__ObjectMaskWithTf.
typedef struct object_search_msgs__msg__ObjectMaskWithTf__Sequence
{
  object_search_msgs__msg__ObjectMaskWithTf * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} object_search_msgs__msg__ObjectMaskWithTf__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJECT_SEARCH_MSGS__MSG__DETAIL__OBJECT_MASK_WITH_TF__STRUCT_H_
