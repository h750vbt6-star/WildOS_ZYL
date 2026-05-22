// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from elevation_map_msgs:srv/CheckSafety.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "elevation_map_msgs/srv/detail/check_safety__functions.h"
#include "elevation_map_msgs/srv/detail/check_safety__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace elevation_map_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CheckSafety_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CheckSafety_Request_type_support_ids_t;

static const _CheckSafety_Request_type_support_ids_t _CheckSafety_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CheckSafety_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CheckSafety_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CheckSafety_Request_type_support_symbol_names_t _CheckSafety_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, elevation_map_msgs, srv, CheckSafety_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, elevation_map_msgs, srv, CheckSafety_Request)),
  }
};

typedef struct _CheckSafety_Request_type_support_data_t
{
  void * data[2];
} _CheckSafety_Request_type_support_data_t;

static _CheckSafety_Request_type_support_data_t _CheckSafety_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CheckSafety_Request_message_typesupport_map = {
  2,
  "elevation_map_msgs",
  &_CheckSafety_Request_message_typesupport_ids.typesupport_identifier[0],
  &_CheckSafety_Request_message_typesupport_symbol_names.symbol_name[0],
  &_CheckSafety_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CheckSafety_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CheckSafety_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &elevation_map_msgs__srv__CheckSafety_Request__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety_Request__get_type_description,
  &elevation_map_msgs__srv__CheckSafety_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace elevation_map_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Request>()
{
  return &::elevation_map_msgs::srv::rosidl_typesupport_cpp::CheckSafety_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, elevation_map_msgs, srv, CheckSafety_Request)() {
  return get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__functions.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace elevation_map_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CheckSafety_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CheckSafety_Response_type_support_ids_t;

static const _CheckSafety_Response_type_support_ids_t _CheckSafety_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CheckSafety_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CheckSafety_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CheckSafety_Response_type_support_symbol_names_t _CheckSafety_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, elevation_map_msgs, srv, CheckSafety_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, elevation_map_msgs, srv, CheckSafety_Response)),
  }
};

typedef struct _CheckSafety_Response_type_support_data_t
{
  void * data[2];
} _CheckSafety_Response_type_support_data_t;

static _CheckSafety_Response_type_support_data_t _CheckSafety_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CheckSafety_Response_message_typesupport_map = {
  2,
  "elevation_map_msgs",
  &_CheckSafety_Response_message_typesupport_ids.typesupport_identifier[0],
  &_CheckSafety_Response_message_typesupport_symbol_names.symbol_name[0],
  &_CheckSafety_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CheckSafety_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CheckSafety_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &elevation_map_msgs__srv__CheckSafety_Response__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety_Response__get_type_description,
  &elevation_map_msgs__srv__CheckSafety_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace elevation_map_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Response>()
{
  return &::elevation_map_msgs::srv::rosidl_typesupport_cpp::CheckSafety_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, elevation_map_msgs, srv, CheckSafety_Response)() {
  return get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__functions.h"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace elevation_map_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CheckSafety_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CheckSafety_Event_type_support_ids_t;

static const _CheckSafety_Event_type_support_ids_t _CheckSafety_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CheckSafety_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CheckSafety_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CheckSafety_Event_type_support_symbol_names_t _CheckSafety_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, elevation_map_msgs, srv, CheckSafety_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, elevation_map_msgs, srv, CheckSafety_Event)),
  }
};

typedef struct _CheckSafety_Event_type_support_data_t
{
  void * data[2];
} _CheckSafety_Event_type_support_data_t;

static _CheckSafety_Event_type_support_data_t _CheckSafety_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CheckSafety_Event_message_typesupport_map = {
  2,
  "elevation_map_msgs",
  &_CheckSafety_Event_message_typesupport_ids.typesupport_identifier[0],
  &_CheckSafety_Event_message_typesupport_symbol_names.symbol_name[0],
  &_CheckSafety_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CheckSafety_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CheckSafety_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &elevation_map_msgs__srv__CheckSafety_Event__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety_Event__get_type_description,
  &elevation_map_msgs__srv__CheckSafety_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace elevation_map_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Event>()
{
  return &::elevation_map_msgs::srv::rosidl_typesupport_cpp::CheckSafety_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, elevation_map_msgs, srv, CheckSafety_Event)() {
  return get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "elevation_map_msgs/srv/detail/check_safety__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace elevation_map_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CheckSafety_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CheckSafety_type_support_ids_t;

static const _CheckSafety_type_support_ids_t _CheckSafety_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CheckSafety_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CheckSafety_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CheckSafety_type_support_symbol_names_t _CheckSafety_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, elevation_map_msgs, srv, CheckSafety)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, elevation_map_msgs, srv, CheckSafety)),
  }
};

typedef struct _CheckSafety_type_support_data_t
{
  void * data[2];
} _CheckSafety_type_support_data_t;

static _CheckSafety_type_support_data_t _CheckSafety_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CheckSafety_service_typesupport_map = {
  2,
  "elevation_map_msgs",
  &_CheckSafety_service_typesupport_ids.typesupport_identifier[0],
  &_CheckSafety_service_typesupport_symbol_names.symbol_name[0],
  &_CheckSafety_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t CheckSafety_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CheckSafety_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<elevation_map_msgs::srv::CheckSafety_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<elevation_map_msgs::srv::CheckSafety>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<elevation_map_msgs::srv::CheckSafety>,
  &elevation_map_msgs__srv__CheckSafety__get_type_hash,
  &elevation_map_msgs__srv__CheckSafety__get_type_description,
  &elevation_map_msgs__srv__CheckSafety__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace elevation_map_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<elevation_map_msgs::srv::CheckSafety>()
{
  return &::elevation_map_msgs::srv::rosidl_typesupport_cpp::CheckSafety_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, elevation_map_msgs, srv, CheckSafety)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<elevation_map_msgs::srv::CheckSafety>();
}

#ifdef __cplusplus
}
#endif
