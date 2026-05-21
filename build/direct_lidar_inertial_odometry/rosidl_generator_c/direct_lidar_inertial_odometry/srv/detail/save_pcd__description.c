// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from direct_lidar_inertial_odometry:srv/SavePCD.idl
// generated code does not contain a copyright notice

#include "direct_lidar_inertial_odometry/srv/detail/save_pcd__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_direct_lidar_inertial_odometry
const rosidl_type_hash_t *
direct_lidar_inertial_odometry__srv__SavePCD__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2b, 0xac, 0x92, 0x4c, 0x8b, 0x9f, 0x6d, 0x18,
      0xa4, 0x9b, 0x68, 0x49, 0x0b, 0x9f, 0x8f, 0x2e,
      0xad, 0xf1, 0xc4, 0x13, 0xf6, 0x67, 0x45, 0xec,
      0xcf, 0xe9, 0x61, 0xe3, 0x85, 0x1e, 0x69, 0xbb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_direct_lidar_inertial_odometry
const rosidl_type_hash_t *
direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf5, 0x49, 0xe0, 0x50, 0xa0, 0xc4, 0x6a, 0x11,
      0x10, 0x6d, 0xd4, 0x8e, 0x1b, 0xa3, 0x6a, 0x81,
      0x9e, 0x26, 0xbf, 0x22, 0xbb, 0x7b, 0x93, 0x0d,
      0x01, 0x56, 0xa0, 0xfb, 0x72, 0x2c, 0xbc, 0x6d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_direct_lidar_inertial_odometry
const rosidl_type_hash_t *
direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x98, 0x1e, 0xff, 0x3d, 0x1e, 0xa6, 0xa3, 0xe6,
      0x4e, 0xdc, 0x32, 0xef, 0x86, 0x11, 0x69, 0xd2,
      0xe6, 0x64, 0xf9, 0x96, 0x8d, 0x0b, 0x5b, 0x15,
      0x98, 0x32, 0xca, 0x89, 0x0f, 0xc6, 0x9f, 0xf5,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_direct_lidar_inertial_odometry
const rosidl_type_hash_t *
direct_lidar_inertial_odometry__srv__SavePCD_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc6, 0x06, 0x3b, 0xd7, 0x3a, 0x12, 0x12, 0x5f,
      0x32, 0xcf, 0x18, 0x52, 0xa8, 0x02, 0x90, 0x44,
      0xcc, 0x33, 0x63, 0xe6, 0xd2, 0xe0, 0x50, 0xfa,
      0x73, 0x9f, 0xad, 0xdf, 0xb9, 0x4e, 0x13, 0x43,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char direct_lidar_inertial_odometry__srv__SavePCD__TYPE_NAME[] = "direct_lidar_inertial_odometry/srv/SavePCD";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char direct_lidar_inertial_odometry__srv__SavePCD_Event__TYPE_NAME[] = "direct_lidar_inertial_odometry/srv/SavePCD_Event";
static char direct_lidar_inertial_odometry__srv__SavePCD_Request__TYPE_NAME[] = "direct_lidar_inertial_odometry/srv/SavePCD_Request";
static char direct_lidar_inertial_odometry__srv__SavePCD_Response__TYPE_NAME[] = "direct_lidar_inertial_odometry/srv/SavePCD_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char direct_lidar_inertial_odometry__srv__SavePCD__FIELD_NAME__request_message[] = "request_message";
static char direct_lidar_inertial_odometry__srv__SavePCD__FIELD_NAME__response_message[] = "response_message";
static char direct_lidar_inertial_odometry__srv__SavePCD__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field direct_lidar_inertial_odometry__srv__SavePCD__FIELDS[] = {
  {
    {direct_lidar_inertial_odometry__srv__SavePCD__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {direct_lidar_inertial_odometry__srv__SavePCD_Request__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {direct_lidar_inertial_odometry__srv__SavePCD_Response__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {direct_lidar_inertial_odometry__srv__SavePCD_Event__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription direct_lidar_inertial_odometry__srv__SavePCD__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Event__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Request__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Response__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
direct_lidar_inertial_odometry__srv__SavePCD__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {direct_lidar_inertial_odometry__srv__SavePCD__TYPE_NAME, 42, 42},
      {direct_lidar_inertial_odometry__srv__SavePCD__FIELDS, 3, 3},
    },
    {direct_lidar_inertial_odometry__srv__SavePCD__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = direct_lidar_inertial_odometry__srv__SavePCD_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char direct_lidar_inertial_odometry__srv__SavePCD_Request__FIELD_NAME__leaf_size[] = "leaf_size";
static char direct_lidar_inertial_odometry__srv__SavePCD_Request__FIELD_NAME__save_path[] = "save_path";

static rosidl_runtime_c__type_description__Field direct_lidar_inertial_odometry__srv__SavePCD_Request__FIELDS[] = {
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Request__FIELD_NAME__leaf_size, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Request__FIELD_NAME__save_path, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {direct_lidar_inertial_odometry__srv__SavePCD_Request__TYPE_NAME, 50, 50},
      {direct_lidar_inertial_odometry__srv__SavePCD_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char direct_lidar_inertial_odometry__srv__SavePCD_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field direct_lidar_inertial_odometry__srv__SavePCD_Response__FIELDS[] = {
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {direct_lidar_inertial_odometry__srv__SavePCD_Response__TYPE_NAME, 51, 51},
      {direct_lidar_inertial_odometry__srv__SavePCD_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELD_NAME__info[] = "info";
static char direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELD_NAME__request[] = "request";
static char direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELDS[] = {
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {direct_lidar_inertial_odometry__srv__SavePCD_Request__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {direct_lidar_inertial_odometry__srv__SavePCD_Response__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription direct_lidar_inertial_odometry__srv__SavePCD_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Request__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {direct_lidar_inertial_odometry__srv__SavePCD_Response__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
direct_lidar_inertial_odometry__srv__SavePCD_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {direct_lidar_inertial_odometry__srv__SavePCD_Event__TYPE_NAME, 48, 48},
      {direct_lidar_inertial_odometry__srv__SavePCD_Event__FIELDS, 3, 3},
    },
    {direct_lidar_inertial_odometry__srv__SavePCD_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 leaf_size\n"
  "string save_path\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
direct_lidar_inertial_odometry__srv__SavePCD__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {direct_lidar_inertial_odometry__srv__SavePCD__TYPE_NAME, 42, 42},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 52, 52},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
direct_lidar_inertial_odometry__srv__SavePCD_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {direct_lidar_inertial_odometry__srv__SavePCD_Request__TYPE_NAME, 50, 50},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
direct_lidar_inertial_odometry__srv__SavePCD_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {direct_lidar_inertial_odometry__srv__SavePCD_Response__TYPE_NAME, 51, 51},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
direct_lidar_inertial_odometry__srv__SavePCD_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {direct_lidar_inertial_odometry__srv__SavePCD_Event__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
direct_lidar_inertial_odometry__srv__SavePCD__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *direct_lidar_inertial_odometry__srv__SavePCD__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *direct_lidar_inertial_odometry__srv__SavePCD_Event__get_individual_type_description_source(NULL);
    sources[3] = *direct_lidar_inertial_odometry__srv__SavePCD_Request__get_individual_type_description_source(NULL);
    sources[4] = *direct_lidar_inertial_odometry__srv__SavePCD_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
direct_lidar_inertial_odometry__srv__SavePCD_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *direct_lidar_inertial_odometry__srv__SavePCD_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
direct_lidar_inertial_odometry__srv__SavePCD_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *direct_lidar_inertial_odometry__srv__SavePCD_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
direct_lidar_inertial_odometry__srv__SavePCD_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *direct_lidar_inertial_odometry__srv__SavePCD_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *direct_lidar_inertial_odometry__srv__SavePCD_Request__get_individual_type_description_source(NULL);
    sources[3] = *direct_lidar_inertial_odometry__srv__SavePCD_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
