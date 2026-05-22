// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from elevation_map_msgs:msg/ChannelInfo.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "elevation_map_msgs/msg/detail/channel_info__functions.h"
#include "elevation_map_msgs/msg/detail/channel_info__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace elevation_map_msgs
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _ChannelInfo_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ChannelInfo_type_support_ids_t;

static const _ChannelInfo_type_support_ids_t _ChannelInfo_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ChannelInfo_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ChannelInfo_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ChannelInfo_type_support_symbol_names_t _ChannelInfo_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, elevation_map_msgs, msg, ChannelInfo)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, elevation_map_msgs, msg, ChannelInfo)),
  }
};

typedef struct _ChannelInfo_type_support_data_t
{
  void * data[2];
} _ChannelInfo_type_support_data_t;

static _ChannelInfo_type_support_data_t _ChannelInfo_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ChannelInfo_message_typesupport_map = {
  2,
  "elevation_map_msgs",
  &_ChannelInfo_message_typesupport_ids.typesupport_identifier[0],
  &_ChannelInfo_message_typesupport_symbol_names.symbol_name[0],
  &_ChannelInfo_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ChannelInfo_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ChannelInfo_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &elevation_map_msgs__msg__ChannelInfo__get_type_hash,
  &elevation_map_msgs__msg__ChannelInfo__get_type_description,
  &elevation_map_msgs__msg__ChannelInfo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace elevation_map_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<elevation_map_msgs::msg::ChannelInfo>()
{
  return &::elevation_map_msgs::msg::rosidl_typesupport_cpp::ChannelInfo_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, elevation_map_msgs, msg, ChannelInfo)() {
  return get_message_type_support_handle<elevation_map_msgs::msg::ChannelInfo>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
