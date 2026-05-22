// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from elevation_map_msgs:srv/CheckSafety.idl
// generated code does not contain a copyright notice

#include "elevation_map_msgs/srv/detail/check_safety__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_elevation_map_msgs
const rosidl_type_hash_t *
elevation_map_msgs__srv__CheckSafety__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd1, 0xf2, 0x27, 0x31, 0x10, 0xa1, 0x13, 0xd9,
      0x5a, 0x19, 0x1d, 0xff, 0x08, 0x4d, 0x8f, 0xb4,
      0x64, 0x51, 0x1b, 0x59, 0x2a, 0x17, 0x2b, 0x88,
      0xa7, 0x03, 0x2d, 0x7b, 0x58, 0x6f, 0x97, 0x36,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_elevation_map_msgs
const rosidl_type_hash_t *
elevation_map_msgs__srv__CheckSafety_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1e, 0xc8, 0xc8, 0x70, 0x2b, 0x47, 0x7f, 0x3c,
      0xe1, 0x2f, 0x1f, 0xcc, 0x90, 0xf8, 0xb0, 0xcb,
      0x14, 0x7b, 0x11, 0x29, 0xad, 0xf5, 0x6b, 0xa2,
      0x3b, 0xa8, 0xba, 0x83, 0xf8, 0x91, 0x55, 0x49,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_elevation_map_msgs
const rosidl_type_hash_t *
elevation_map_msgs__srv__CheckSafety_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x05, 0xf7, 0x37, 0x00, 0x7b, 0x39, 0x38, 0x56,
      0xcf, 0x43, 0xaf, 0xe1, 0x8f, 0x91, 0xd0, 0x02,
      0x45, 0xf5, 0x6a, 0x05, 0xfd, 0x5c, 0xa2, 0x3e,
      0x2a, 0x87, 0x6f, 0xe0, 0x39, 0x0b, 0x65, 0xd1,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_elevation_map_msgs
const rosidl_type_hash_t *
elevation_map_msgs__srv__CheckSafety_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc9, 0x83, 0xf1, 0x45, 0x99, 0x9b, 0xc5, 0xf2,
      0x64, 0xc1, 0xa7, 0xa3, 0xdf, 0x51, 0xaf, 0x52,
      0xee, 0x86, 0xec, 0x70, 0x3d, 0xd5, 0x07, 0xfe,
      0xaf, 0x15, 0x50, 0xb5, 0xa9, 0xa4, 0x99, 0x7b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "geometry_msgs/msg/detail/polygon_stamped__functions.h"
#include "geometry_msgs/msg/detail/polygon__functions.h"
#include "geometry_msgs/msg/detail/point32__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point32__EXPECTED_HASH = {1, {
    0x2f, 0xc4, 0xdb, 0x7c, 0xae, 0x16, 0xa4, 0x58,
    0x2c, 0x79, 0xa5, 0x6b, 0x66, 0x17, 0x3a, 0x8d,
    0x48, 0xd5, 0x2c, 0x7d, 0xc5, 0x20, 0xdd, 0xc5,
    0x5a, 0x0d, 0x4b, 0xcf, 0x2a, 0x4b, 0xfd, 0xbc,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Polygon__EXPECTED_HASH = {1, {
    0x37, 0x82, 0xf9, 0xf0, 0xbf, 0x04, 0x49, 0x64,
    0xd6, 0x92, 0xd6, 0xc0, 0x17, 0xd7, 0x05, 0xe3,
    0x76, 0x11, 0xaf, 0xb1, 0xf0, 0xbf, 0x6a, 0x9d,
    0xee, 0x24, 0x8a, 0x7d, 0xda, 0x0f, 0x78, 0x4a,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__PolygonStamped__EXPECTED_HASH = {1, {
    0xb7, 0xcf, 0x07, 0x93, 0x2f, 0x15, 0x23, 0xd4,
    0xb4, 0x08, 0x80, 0x75, 0x94, 0x5c, 0x1a, 0x01,
    0x41, 0xf7, 0xcd, 0x21, 0xda, 0x87, 0xcc, 0x94,
    0x0f, 0xc6, 0x16, 0x52, 0xe9, 0x13, 0x8b, 0x46,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char elevation_map_msgs__srv__CheckSafety__TYPE_NAME[] = "elevation_map_msgs/srv/CheckSafety";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char elevation_map_msgs__srv__CheckSafety_Event__TYPE_NAME[] = "elevation_map_msgs/srv/CheckSafety_Event";
static char elevation_map_msgs__srv__CheckSafety_Request__TYPE_NAME[] = "elevation_map_msgs/srv/CheckSafety_Request";
static char elevation_map_msgs__srv__CheckSafety_Response__TYPE_NAME[] = "elevation_map_msgs/srv/CheckSafety_Response";
static char geometry_msgs__msg__Point32__TYPE_NAME[] = "geometry_msgs/msg/Point32";
static char geometry_msgs__msg__Polygon__TYPE_NAME[] = "geometry_msgs/msg/Polygon";
static char geometry_msgs__msg__PolygonStamped__TYPE_NAME[] = "geometry_msgs/msg/PolygonStamped";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char elevation_map_msgs__srv__CheckSafety__FIELD_NAME__request_message[] = "request_message";
static char elevation_map_msgs__srv__CheckSafety__FIELD_NAME__response_message[] = "response_message";
static char elevation_map_msgs__srv__CheckSafety__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field elevation_map_msgs__srv__CheckSafety__FIELDS[] = {
  {
    {elevation_map_msgs__srv__CheckSafety__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {elevation_map_msgs__srv__CheckSafety_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {elevation_map_msgs__srv__CheckSafety_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {elevation_map_msgs__srv__CheckSafety_Event__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription elevation_map_msgs__srv__CheckSafety__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Event__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point32__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Polygon__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__PolygonStamped__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
elevation_map_msgs__srv__CheckSafety__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {elevation_map_msgs__srv__CheckSafety__TYPE_NAME, 34, 34},
      {elevation_map_msgs__srv__CheckSafety__FIELDS, 3, 3},
    },
    {elevation_map_msgs__srv__CheckSafety__REFERENCED_TYPE_DESCRIPTIONS, 9, 9},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = elevation_map_msgs__srv__CheckSafety_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = elevation_map_msgs__srv__CheckSafety_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = elevation_map_msgs__srv__CheckSafety_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point32__EXPECTED_HASH, geometry_msgs__msg__Point32__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = geometry_msgs__msg__Point32__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Polygon__EXPECTED_HASH, geometry_msgs__msg__Polygon__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = geometry_msgs__msg__Polygon__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__PolygonStamped__EXPECTED_HASH, geometry_msgs__msg__PolygonStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = geometry_msgs__msg__PolygonStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char elevation_map_msgs__srv__CheckSafety_Request__FIELD_NAME__polygons[] = "polygons";
static char elevation_map_msgs__srv__CheckSafety_Request__FIELD_NAME__compute_untraversable_polygon[] = "compute_untraversable_polygon";

static rosidl_runtime_c__type_description__Field elevation_map_msgs__srv__CheckSafety_Request__FIELDS[] = {
  {
    {elevation_map_msgs__srv__CheckSafety_Request__FIELD_NAME__polygons, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {geometry_msgs__msg__PolygonStamped__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Request__FIELD_NAME__compute_untraversable_polygon, 29, 29},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription elevation_map_msgs__srv__CheckSafety_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point32__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Polygon__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__PolygonStamped__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
elevation_map_msgs__srv__CheckSafety_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {elevation_map_msgs__srv__CheckSafety_Request__TYPE_NAME, 42, 42},
      {elevation_map_msgs__srv__CheckSafety_Request__FIELDS, 2, 2},
    },
    {elevation_map_msgs__srv__CheckSafety_Request__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point32__EXPECTED_HASH, geometry_msgs__msg__Point32__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point32__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Polygon__EXPECTED_HASH, geometry_msgs__msg__Polygon__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Polygon__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__PolygonStamped__EXPECTED_HASH, geometry_msgs__msg__PolygonStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__PolygonStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char elevation_map_msgs__srv__CheckSafety_Response__FIELD_NAME__is_safe[] = "is_safe";
static char elevation_map_msgs__srv__CheckSafety_Response__FIELD_NAME__traversability[] = "traversability";
static char elevation_map_msgs__srv__CheckSafety_Response__FIELD_NAME__untraversable_polygons[] = "untraversable_polygons";

static rosidl_runtime_c__type_description__Field elevation_map_msgs__srv__CheckSafety_Response__FIELDS[] = {
  {
    {elevation_map_msgs__srv__CheckSafety_Response__FIELD_NAME__is_safe, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Response__FIELD_NAME__traversability, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Response__FIELD_NAME__untraversable_polygons, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {geometry_msgs__msg__PolygonStamped__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription elevation_map_msgs__srv__CheckSafety_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point32__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Polygon__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__PolygonStamped__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
elevation_map_msgs__srv__CheckSafety_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {elevation_map_msgs__srv__CheckSafety_Response__TYPE_NAME, 43, 43},
      {elevation_map_msgs__srv__CheckSafety_Response__FIELDS, 3, 3},
    },
    {elevation_map_msgs__srv__CheckSafety_Response__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point32__EXPECTED_HASH, geometry_msgs__msg__Point32__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point32__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Polygon__EXPECTED_HASH, geometry_msgs__msg__Polygon__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Polygon__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__PolygonStamped__EXPECTED_HASH, geometry_msgs__msg__PolygonStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__PolygonStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char elevation_map_msgs__srv__CheckSafety_Event__FIELD_NAME__info[] = "info";
static char elevation_map_msgs__srv__CheckSafety_Event__FIELD_NAME__request[] = "request";
static char elevation_map_msgs__srv__CheckSafety_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field elevation_map_msgs__srv__CheckSafety_Event__FIELDS[] = {
  {
    {elevation_map_msgs__srv__CheckSafety_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {elevation_map_msgs__srv__CheckSafety_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {elevation_map_msgs__srv__CheckSafety_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription elevation_map_msgs__srv__CheckSafety_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {elevation_map_msgs__srv__CheckSafety_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point32__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Polygon__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__PolygonStamped__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
elevation_map_msgs__srv__CheckSafety_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {elevation_map_msgs__srv__CheckSafety_Event__TYPE_NAME, 40, 40},
      {elevation_map_msgs__srv__CheckSafety_Event__FIELDS, 3, 3},
    },
    {elevation_map_msgs__srv__CheckSafety_Event__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = elevation_map_msgs__srv__CheckSafety_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = elevation_map_msgs__srv__CheckSafety_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point32__EXPECTED_HASH, geometry_msgs__msg__Point32__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__Point32__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Polygon__EXPECTED_HASH, geometry_msgs__msg__Polygon__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = geometry_msgs__msg__Polygon__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__PolygonStamped__EXPECTED_HASH, geometry_msgs__msg__PolygonStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = geometry_msgs__msg__PolygonStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Polygons to check\n"
  "geometry_msgs/PolygonStamped[] polygons\n"
  "bool compute_untraversable_polygon\n"
  "\n"
  "# Results\n"
  "---\n"
  "bool[] is_safe\n"
  "\n"
  "# Estimate of the traversability of the path.\n"
  "# Ranges from 0 to 1 where 0 means not traversable and 1 highly traversable.\n"
  "float64[] traversability\n"
  "\n"
  "# Polygons that are untraversable.\n"
  "geometry_msgs/PolygonStamped[] untraversable_polygons";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
elevation_map_msgs__srv__CheckSafety__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {elevation_map_msgs__srv__CheckSafety__TYPE_NAME, 34, 34},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 364, 364},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
elevation_map_msgs__srv__CheckSafety_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {elevation_map_msgs__srv__CheckSafety_Request__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
elevation_map_msgs__srv__CheckSafety_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {elevation_map_msgs__srv__CheckSafety_Response__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
elevation_map_msgs__srv__CheckSafety_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {elevation_map_msgs__srv__CheckSafety_Event__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
elevation_map_msgs__srv__CheckSafety__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[10];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 10, 10};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *elevation_map_msgs__srv__CheckSafety__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *elevation_map_msgs__srv__CheckSafety_Event__get_individual_type_description_source(NULL);
    sources[3] = *elevation_map_msgs__srv__CheckSafety_Request__get_individual_type_description_source(NULL);
    sources[4] = *elevation_map_msgs__srv__CheckSafety_Response__get_individual_type_description_source(NULL);
    sources[5] = *geometry_msgs__msg__Point32__get_individual_type_description_source(NULL);
    sources[6] = *geometry_msgs__msg__Polygon__get_individual_type_description_source(NULL);
    sources[7] = *geometry_msgs__msg__PolygonStamped__get_individual_type_description_source(NULL);
    sources[8] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[9] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
elevation_map_msgs__srv__CheckSafety_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *elevation_map_msgs__srv__CheckSafety_Request__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point32__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Polygon__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__PolygonStamped__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
elevation_map_msgs__srv__CheckSafety_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *elevation_map_msgs__srv__CheckSafety_Response__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point32__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Polygon__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__PolygonStamped__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
elevation_map_msgs__srv__CheckSafety_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *elevation_map_msgs__srv__CheckSafety_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *elevation_map_msgs__srv__CheckSafety_Request__get_individual_type_description_source(NULL);
    sources[3] = *elevation_map_msgs__srv__CheckSafety_Response__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__Point32__get_individual_type_description_source(NULL);
    sources[5] = *geometry_msgs__msg__Polygon__get_individual_type_description_source(NULL);
    sources[6] = *geometry_msgs__msg__PolygonStamped__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[8] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
