// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from object_search_msgs:msg/ObjectMaskWithTf.idl
// generated code does not contain a copyright notice
#include "object_search_msgs/msg/detail/object_mask_with_tf__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `odom`
#include "nav_msgs/msg/detail/odometry__functions.h"
// Member `cam_infos`
#include "sensor_msgs/msg/detail/camera_info__functions.h"
// Member `object_mask`
#include "std_msgs/msg/detail/u_int8_multi_array__functions.h"
// Member `cam_transforms`
#include "tf2_msgs/msg/detail/tf_message__functions.h"

bool
object_search_msgs__msg__ObjectMaskWithTf__init(object_search_msgs__msg__ObjectMaskWithTf * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    object_search_msgs__msg__ObjectMaskWithTf__fini(msg);
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__init(&msg->odom)) {
    object_search_msgs__msg__ObjectMaskWithTf__fini(msg);
    return false;
  }
  // cam_infos
  if (!sensor_msgs__msg__CameraInfo__Sequence__init(&msg->cam_infos, 0)) {
    object_search_msgs__msg__ObjectMaskWithTf__fini(msg);
    return false;
  }
  // object_mask
  if (!std_msgs__msg__UInt8MultiArray__init(&msg->object_mask)) {
    object_search_msgs__msg__ObjectMaskWithTf__fini(msg);
    return false;
  }
  // cam_transforms
  if (!tf2_msgs__msg__TFMessage__init(&msg->cam_transforms)) {
    object_search_msgs__msg__ObjectMaskWithTf__fini(msg);
    return false;
  }
  return true;
}

void
object_search_msgs__msg__ObjectMaskWithTf__fini(object_search_msgs__msg__ObjectMaskWithTf * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // odom
  nav_msgs__msg__Odometry__fini(&msg->odom);
  // cam_infos
  sensor_msgs__msg__CameraInfo__Sequence__fini(&msg->cam_infos);
  // object_mask
  std_msgs__msg__UInt8MultiArray__fini(&msg->object_mask);
  // cam_transforms
  tf2_msgs__msg__TFMessage__fini(&msg->cam_transforms);
}

bool
object_search_msgs__msg__ObjectMaskWithTf__are_equal(const object_search_msgs__msg__ObjectMaskWithTf * lhs, const object_search_msgs__msg__ObjectMaskWithTf * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__are_equal(
      &(lhs->odom), &(rhs->odom)))
  {
    return false;
  }
  // cam_infos
  if (!sensor_msgs__msg__CameraInfo__Sequence__are_equal(
      &(lhs->cam_infos), &(rhs->cam_infos)))
  {
    return false;
  }
  // object_mask
  if (!std_msgs__msg__UInt8MultiArray__are_equal(
      &(lhs->object_mask), &(rhs->object_mask)))
  {
    return false;
  }
  // cam_transforms
  if (!tf2_msgs__msg__TFMessage__are_equal(
      &(lhs->cam_transforms), &(rhs->cam_transforms)))
  {
    return false;
  }
  return true;
}

bool
object_search_msgs__msg__ObjectMaskWithTf__copy(
  const object_search_msgs__msg__ObjectMaskWithTf * input,
  object_search_msgs__msg__ObjectMaskWithTf * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // odom
  if (!nav_msgs__msg__Odometry__copy(
      &(input->odom), &(output->odom)))
  {
    return false;
  }
  // cam_infos
  if (!sensor_msgs__msg__CameraInfo__Sequence__copy(
      &(input->cam_infos), &(output->cam_infos)))
  {
    return false;
  }
  // object_mask
  if (!std_msgs__msg__UInt8MultiArray__copy(
      &(input->object_mask), &(output->object_mask)))
  {
    return false;
  }
  // cam_transforms
  if (!tf2_msgs__msg__TFMessage__copy(
      &(input->cam_transforms), &(output->cam_transforms)))
  {
    return false;
  }
  return true;
}

object_search_msgs__msg__ObjectMaskWithTf *
object_search_msgs__msg__ObjectMaskWithTf__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_search_msgs__msg__ObjectMaskWithTf * msg = (object_search_msgs__msg__ObjectMaskWithTf *)allocator.allocate(sizeof(object_search_msgs__msg__ObjectMaskWithTf), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(object_search_msgs__msg__ObjectMaskWithTf));
  bool success = object_search_msgs__msg__ObjectMaskWithTf__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
object_search_msgs__msg__ObjectMaskWithTf__destroy(object_search_msgs__msg__ObjectMaskWithTf * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    object_search_msgs__msg__ObjectMaskWithTf__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
object_search_msgs__msg__ObjectMaskWithTf__Sequence__init(object_search_msgs__msg__ObjectMaskWithTf__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_search_msgs__msg__ObjectMaskWithTf * data = NULL;

  if (size) {
    data = (object_search_msgs__msg__ObjectMaskWithTf *)allocator.zero_allocate(size, sizeof(object_search_msgs__msg__ObjectMaskWithTf), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = object_search_msgs__msg__ObjectMaskWithTf__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        object_search_msgs__msg__ObjectMaskWithTf__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
object_search_msgs__msg__ObjectMaskWithTf__Sequence__fini(object_search_msgs__msg__ObjectMaskWithTf__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      object_search_msgs__msg__ObjectMaskWithTf__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

object_search_msgs__msg__ObjectMaskWithTf__Sequence *
object_search_msgs__msg__ObjectMaskWithTf__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  object_search_msgs__msg__ObjectMaskWithTf__Sequence * array = (object_search_msgs__msg__ObjectMaskWithTf__Sequence *)allocator.allocate(sizeof(object_search_msgs__msg__ObjectMaskWithTf__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = object_search_msgs__msg__ObjectMaskWithTf__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
object_search_msgs__msg__ObjectMaskWithTf__Sequence__destroy(object_search_msgs__msg__ObjectMaskWithTf__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    object_search_msgs__msg__ObjectMaskWithTf__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
object_search_msgs__msg__ObjectMaskWithTf__Sequence__are_equal(const object_search_msgs__msg__ObjectMaskWithTf__Sequence * lhs, const object_search_msgs__msg__ObjectMaskWithTf__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!object_search_msgs__msg__ObjectMaskWithTf__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
object_search_msgs__msg__ObjectMaskWithTf__Sequence__copy(
  const object_search_msgs__msg__ObjectMaskWithTf__Sequence * input,
  object_search_msgs__msg__ObjectMaskWithTf__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(object_search_msgs__msg__ObjectMaskWithTf);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    object_search_msgs__msg__ObjectMaskWithTf * data =
      (object_search_msgs__msg__ObjectMaskWithTf *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!object_search_msgs__msg__ObjectMaskWithTf__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          object_search_msgs__msg__ObjectMaskWithTf__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!object_search_msgs__msg__ObjectMaskWithTf__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
