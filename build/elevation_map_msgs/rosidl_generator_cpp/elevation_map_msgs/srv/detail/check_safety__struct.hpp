// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from elevation_map_msgs:srv/CheckSafety.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "elevation_map_msgs/srv/check_safety.hpp"


#ifndef ELEVATION_MAP_MSGS__SRV__DETAIL__CHECK_SAFETY__STRUCT_HPP_
#define ELEVATION_MAP_MSGS__SRV__DETAIL__CHECK_SAFETY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'polygons'
#include "geometry_msgs/msg/detail/polygon_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__elevation_map_msgs__srv__CheckSafety_Request __attribute__((deprecated))
#else
# define DEPRECATED__elevation_map_msgs__srv__CheckSafety_Request __declspec(deprecated)
#endif

namespace elevation_map_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckSafety_Request_
{
  using Type = CheckSafety_Request_<ContainerAllocator>;

  explicit CheckSafety_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->compute_untraversable_polygon = false;
    }
  }

  explicit CheckSafety_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->compute_untraversable_polygon = false;
    }
  }

  // field types and members
  using _polygons_type =
    std::vector<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>>>;
  _polygons_type polygons;
  using _compute_untraversable_polygon_type =
    bool;
  _compute_untraversable_polygon_type compute_untraversable_polygon;

  // setters for named parameter idiom
  Type & set__polygons(
    const std::vector<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>>> & _arg)
  {
    this->polygons = _arg;
    return *this;
  }
  Type & set__compute_untraversable_polygon(
    const bool & _arg)
  {
    this->compute_untraversable_polygon = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__elevation_map_msgs__srv__CheckSafety_Request
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__elevation_map_msgs__srv__CheckSafety_Request
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckSafety_Request_ & other) const
  {
    if (this->polygons != other.polygons) {
      return false;
    }
    if (this->compute_untraversable_polygon != other.compute_untraversable_polygon) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckSafety_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckSafety_Request_

// alias to use template instance with default allocator
using CheckSafety_Request =
  elevation_map_msgs::srv::CheckSafety_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace elevation_map_msgs


// Include directives for member types
// Member 'untraversable_polygons'
// already included above
// #include "geometry_msgs/msg/detail/polygon_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__elevation_map_msgs__srv__CheckSafety_Response __attribute__((deprecated))
#else
# define DEPRECATED__elevation_map_msgs__srv__CheckSafety_Response __declspec(deprecated)
#endif

namespace elevation_map_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckSafety_Response_
{
  using Type = CheckSafety_Response_<ContainerAllocator>;

  explicit CheckSafety_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit CheckSafety_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _is_safe_type =
    std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>>;
  _is_safe_type is_safe;
  using _traversability_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _traversability_type traversability;
  using _untraversable_polygons_type =
    std::vector<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>>>;
  _untraversable_polygons_type untraversable_polygons;

  // setters for named parameter idiom
  Type & set__is_safe(
    const std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>> & _arg)
  {
    this->is_safe = _arg;
    return *this;
  }
  Type & set__traversability(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->traversability = _arg;
    return *this;
  }
  Type & set__untraversable_polygons(
    const std::vector<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PolygonStamped_<ContainerAllocator>>> & _arg)
  {
    this->untraversable_polygons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__elevation_map_msgs__srv__CheckSafety_Response
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__elevation_map_msgs__srv__CheckSafety_Response
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckSafety_Response_ & other) const
  {
    if (this->is_safe != other.is_safe) {
      return false;
    }
    if (this->traversability != other.traversability) {
      return false;
    }
    if (this->untraversable_polygons != other.untraversable_polygons) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckSafety_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckSafety_Response_

// alias to use template instance with default allocator
using CheckSafety_Response =
  elevation_map_msgs::srv::CheckSafety_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace elevation_map_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__elevation_map_msgs__srv__CheckSafety_Event __attribute__((deprecated))
#else
# define DEPRECATED__elevation_map_msgs__srv__CheckSafety_Event __declspec(deprecated)
#endif

namespace elevation_map_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckSafety_Event_
{
  using Type = CheckSafety_Event_<ContainerAllocator>;

  explicit CheckSafety_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit CheckSafety_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<elevation_map_msgs::srv::CheckSafety_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<elevation_map_msgs::srv::CheckSafety_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__elevation_map_msgs__srv__CheckSafety_Event
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__elevation_map_msgs__srv__CheckSafety_Event
    std::shared_ptr<elevation_map_msgs::srv::CheckSafety_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckSafety_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckSafety_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckSafety_Event_

// alias to use template instance with default allocator
using CheckSafety_Event =
  elevation_map_msgs::srv::CheckSafety_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace elevation_map_msgs

namespace elevation_map_msgs
{

namespace srv
{

struct CheckSafety
{
  using Request = elevation_map_msgs::srv::CheckSafety_Request;
  using Response = elevation_map_msgs::srv::CheckSafety_Response;
  using Event = elevation_map_msgs::srv::CheckSafety_Event;
};

}  // namespace srv

}  // namespace elevation_map_msgs

#endif  // ELEVATION_MAP_MSGS__SRV__DETAIL__CHECK_SAFETY__STRUCT_HPP_
