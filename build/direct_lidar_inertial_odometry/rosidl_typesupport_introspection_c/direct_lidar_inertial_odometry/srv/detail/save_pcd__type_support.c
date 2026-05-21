// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from direct_lidar_inertial_odometry:srv/SavePCD.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "direct_lidar_inertial_odometry/srv/detail/save_pcd__rosidl_typesupport_introspection_c.h"
#include "direct_lidar_inertial_odometry/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "direct_lidar_inertial_odometry/srv/detail/save_pcd__functions.h"
#include "direct_lidar_inertial_odometry/srv/detail/save_pcd__struct.h"


// Include directives for member types
// Member `save_path`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  direct_lidar_inertial_odometry__srv__SavePCD_Request__init(message_memory);
}

void direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_fini_function(void * message_memory)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_member_array[2] = {
  {
    "leaf_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(direct_lidar_inertial_odometry__srv__SavePCD_Request, leaf_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "save_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(direct_lidar_inertial_odometry__srv__SavePCD_Request, save_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_members = {
  "direct_lidar_inertial_odometry__srv",  // message namespace
  "SavePCD_Request",  // message name
  2,  // number of fields
  sizeof(direct_lidar_inertial_odometry__srv__SavePCD_Request),
  false,  // has_any_key_member_
  direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_member_array,  // message members
  direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_type_support_handle = {
  0,
  &direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_members,
  get_message_typesupport_handle_function,
  &direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_hash,
  &direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_description,
  &direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_direct_lidar_inertial_odometry
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Request)() {
  if (!direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_type_support_handle.typesupport_identifier) {
    direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__rosidl_typesupport_introspection_c.h"
// already included above
// #include "direct_lidar_inertial_odometry/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__functions.h"
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  direct_lidar_inertial_odometry__srv__SavePCD_Response__init(message_memory);
}

void direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_fini_function(void * message_memory)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(direct_lidar_inertial_odometry__srv__SavePCD_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_members = {
  "direct_lidar_inertial_odometry__srv",  // message namespace
  "SavePCD_Response",  // message name
  1,  // number of fields
  sizeof(direct_lidar_inertial_odometry__srv__SavePCD_Response),
  false,  // has_any_key_member_
  direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_member_array,  // message members
  direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_type_support_handle = {
  0,
  &direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_members,
  get_message_typesupport_handle_function,
  &direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_hash,
  &direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_description,
  &direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_direct_lidar_inertial_odometry
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Response)() {
  if (!direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_type_support_handle.typesupport_identifier) {
    direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__rosidl_typesupport_introspection_c.h"
// already included above
// #include "direct_lidar_inertial_odometry/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__functions.h"
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "direct_lidar_inertial_odometry/srv/save_pcd.h"
// Member `request`
// Member `response`
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  direct_lidar_inertial_odometry__srv__SavePCD_Event__init(message_memory);
}

void direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_fini_function(void * message_memory)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Event__fini(message_memory);
}

size_t direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__size_function__SavePCD_Event__request(
  const void * untyped_member)
{
  const direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence * member =
    (const direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_const_function__SavePCD_Event__request(
  const void * untyped_member, size_t index)
{
  const direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence * member =
    (const direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_function__SavePCD_Event__request(
  void * untyped_member, size_t index)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence * member =
    (direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__fetch_function__SavePCD_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const direct_lidar_inertial_odometry__srv__SavePCD_Request * item =
    ((const direct_lidar_inertial_odometry__srv__SavePCD_Request *)
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_const_function__SavePCD_Event__request(untyped_member, index));
  direct_lidar_inertial_odometry__srv__SavePCD_Request * value =
    (direct_lidar_inertial_odometry__srv__SavePCD_Request *)(untyped_value);
  *value = *item;
}

void direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__assign_function__SavePCD_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Request * item =
    ((direct_lidar_inertial_odometry__srv__SavePCD_Request *)
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_function__SavePCD_Event__request(untyped_member, index));
  const direct_lidar_inertial_odometry__srv__SavePCD_Request * value =
    (const direct_lidar_inertial_odometry__srv__SavePCD_Request *)(untyped_value);
  *item = *value;
}

bool direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__resize_function__SavePCD_Event__request(
  void * untyped_member, size_t size)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence * member =
    (direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence *)(untyped_member);
  direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__fini(member);
  return direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__init(member, size);
}

size_t direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__size_function__SavePCD_Event__response(
  const void * untyped_member)
{
  const direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence * member =
    (const direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_const_function__SavePCD_Event__response(
  const void * untyped_member, size_t index)
{
  const direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence * member =
    (const direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_function__SavePCD_Event__response(
  void * untyped_member, size_t index)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence * member =
    (direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__fetch_function__SavePCD_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const direct_lidar_inertial_odometry__srv__SavePCD_Response * item =
    ((const direct_lidar_inertial_odometry__srv__SavePCD_Response *)
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_const_function__SavePCD_Event__response(untyped_member, index));
  direct_lidar_inertial_odometry__srv__SavePCD_Response * value =
    (direct_lidar_inertial_odometry__srv__SavePCD_Response *)(untyped_value);
  *value = *item;
}

void direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__assign_function__SavePCD_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Response * item =
    ((direct_lidar_inertial_odometry__srv__SavePCD_Response *)
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_function__SavePCD_Event__response(untyped_member, index));
  const direct_lidar_inertial_odometry__srv__SavePCD_Response * value =
    (const direct_lidar_inertial_odometry__srv__SavePCD_Response *)(untyped_value);
  *item = *value;
}

bool direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__resize_function__SavePCD_Event__response(
  void * untyped_member, size_t size)
{
  direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence * member =
    (direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence *)(untyped_member);
  direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__fini(member);
  return direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(direct_lidar_inertial_odometry__srv__SavePCD_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(direct_lidar_inertial_odometry__srv__SavePCD_Event, request),  // bytes offset in struct
    NULL,  // default value
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__size_function__SavePCD_Event__request,  // size() function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_const_function__SavePCD_Event__request,  // get_const(index) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_function__SavePCD_Event__request,  // get(index) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__fetch_function__SavePCD_Event__request,  // fetch(index, &value) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__assign_function__SavePCD_Event__request,  // assign(index, value) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__resize_function__SavePCD_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(direct_lidar_inertial_odometry__srv__SavePCD_Event, response),  // bytes offset in struct
    NULL,  // default value
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__size_function__SavePCD_Event__response,  // size() function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_const_function__SavePCD_Event__response,  // get_const(index) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__get_function__SavePCD_Event__response,  // get(index) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__fetch_function__SavePCD_Event__response,  // fetch(index, &value) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__assign_function__SavePCD_Event__response,  // assign(index, value) function pointer
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__resize_function__SavePCD_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_members = {
  "direct_lidar_inertial_odometry__srv",  // message namespace
  "SavePCD_Event",  // message name
  3,  // number of fields
  sizeof(direct_lidar_inertial_odometry__srv__SavePCD_Event),
  false,  // has_any_key_member_
  direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_member_array,  // message members
  direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_type_support_handle = {
  0,
  &direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_members,
  get_message_typesupport_handle_function,
  &direct_lidar_inertial_odometry__srv__SavePCD_Event__get_type_hash,
  &direct_lidar_inertial_odometry__srv__SavePCD_Event__get_type_description,
  &direct_lidar_inertial_odometry__srv__SavePCD_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_direct_lidar_inertial_odometry
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Event)() {
  direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Request)();
  direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Response)();
  if (!direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_type_support_handle.typesupport_identifier) {
    direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "direct_lidar_inertial_odometry/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "direct_lidar_inertial_odometry/srv/detail/save_pcd__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_service_members = {
  "direct_lidar_inertial_odometry__srv",  // service namespace
  "SavePCD",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_Request_message_type_support_handle,
  NULL,  // response message
  // direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_Response_message_type_support_handle
  NULL  // event_message
  // direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_Response_message_type_support_handle
};


static rosidl_service_type_support_t direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_service_type_support_handle = {
  0,
  &direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_service_members,
  get_service_typesupport_handle_function,
  &direct_lidar_inertial_odometry__srv__SavePCD_Request__rosidl_typesupport_introspection_c__SavePCD_Request_message_type_support_handle,
  &direct_lidar_inertial_odometry__srv__SavePCD_Response__rosidl_typesupport_introspection_c__SavePCD_Response_message_type_support_handle,
  &direct_lidar_inertial_odometry__srv__SavePCD_Event__rosidl_typesupport_introspection_c__SavePCD_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    direct_lidar_inertial_odometry,
    srv,
    SavePCD
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    direct_lidar_inertial_odometry,
    srv,
    SavePCD
  ),
  &direct_lidar_inertial_odometry__srv__SavePCD__get_type_hash,
  &direct_lidar_inertial_odometry__srv__SavePCD__get_type_description,
  &direct_lidar_inertial_odometry__srv__SavePCD__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_direct_lidar_inertial_odometry
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD)(void) {
  if (!direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_service_type_support_handle.typesupport_identifier) {
    direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, direct_lidar_inertial_odometry, srv, SavePCD_Event)()->data;
  }

  return &direct_lidar_inertial_odometry__srv__detail__save_pcd__rosidl_typesupport_introspection_c__SavePCD_service_type_support_handle;
}
