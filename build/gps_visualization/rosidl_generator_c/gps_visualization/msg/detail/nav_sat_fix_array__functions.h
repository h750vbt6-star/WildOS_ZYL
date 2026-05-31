// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gps_visualization:msg/NavSatFixArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gps_visualization/msg/nav_sat_fix_array.h"


#ifndef GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__FUNCTIONS_H_
#define GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "gps_visualization/msg/rosidl_generator_c__visibility_control.h"

#include "gps_visualization/msg/detail/nav_sat_fix_array__struct.h"

/// Initialize msg/NavSatFixArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gps_visualization__msg__NavSatFixArray
 * )) before or use
 * gps_visualization__msg__NavSatFixArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
bool
gps_visualization__msg__NavSatFixArray__init(gps_visualization__msg__NavSatFixArray * msg);

/// Finalize msg/NavSatFixArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
void
gps_visualization__msg__NavSatFixArray__fini(gps_visualization__msg__NavSatFixArray * msg);

/// Create msg/NavSatFixArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gps_visualization__msg__NavSatFixArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
gps_visualization__msg__NavSatFixArray *
gps_visualization__msg__NavSatFixArray__create(void);

/// Destroy msg/NavSatFixArray message.
/**
 * It calls
 * gps_visualization__msg__NavSatFixArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
void
gps_visualization__msg__NavSatFixArray__destroy(gps_visualization__msg__NavSatFixArray * msg);

/// Check for msg/NavSatFixArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
bool
gps_visualization__msg__NavSatFixArray__are_equal(const gps_visualization__msg__NavSatFixArray * lhs, const gps_visualization__msg__NavSatFixArray * rhs);

/// Copy a msg/NavSatFixArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
bool
gps_visualization__msg__NavSatFixArray__copy(
  const gps_visualization__msg__NavSatFixArray * input,
  gps_visualization__msg__NavSatFixArray * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
const rosidl_type_hash_t *
gps_visualization__msg__NavSatFixArray__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
const rosidl_runtime_c__type_description__TypeDescription *
gps_visualization__msg__NavSatFixArray__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
const rosidl_runtime_c__type_description__TypeSource *
gps_visualization__msg__NavSatFixArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
const rosidl_runtime_c__type_description__TypeSource__Sequence *
gps_visualization__msg__NavSatFixArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/NavSatFixArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * gps_visualization__msg__NavSatFixArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
bool
gps_visualization__msg__NavSatFixArray__Sequence__init(gps_visualization__msg__NavSatFixArray__Sequence * array, size_t size);

/// Finalize array of msg/NavSatFixArray messages.
/**
 * It calls
 * gps_visualization__msg__NavSatFixArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
void
gps_visualization__msg__NavSatFixArray__Sequence__fini(gps_visualization__msg__NavSatFixArray__Sequence * array);

/// Create array of msg/NavSatFixArray messages.
/**
 * It allocates the memory for the array and calls
 * gps_visualization__msg__NavSatFixArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
gps_visualization__msg__NavSatFixArray__Sequence *
gps_visualization__msg__NavSatFixArray__Sequence__create(size_t size);

/// Destroy array of msg/NavSatFixArray messages.
/**
 * It calls
 * gps_visualization__msg__NavSatFixArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
void
gps_visualization__msg__NavSatFixArray__Sequence__destroy(gps_visualization__msg__NavSatFixArray__Sequence * array);

/// Check for msg/NavSatFixArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
bool
gps_visualization__msg__NavSatFixArray__Sequence__are_equal(const gps_visualization__msg__NavSatFixArray__Sequence * lhs, const gps_visualization__msg__NavSatFixArray__Sequence * rhs);

/// Copy an array of msg/NavSatFixArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gps_visualization
bool
gps_visualization__msg__NavSatFixArray__Sequence__copy(
  const gps_visualization__msg__NavSatFixArray__Sequence * input,
  gps_visualization__msg__NavSatFixArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GPS_VISUALIZATION__MSG__DETAIL__NAV_SAT_FIX_ARRAY__FUNCTIONS_H_
