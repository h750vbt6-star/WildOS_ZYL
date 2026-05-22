// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from elevation_map_msgs:srv/CheckSafety.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "elevation_map_msgs/srv/check_safety.hpp"


#ifndef ELEVATION_MAP_MSGS__SRV__DETAIL__CHECK_SAFETY__BUILDER_HPP_
#define ELEVATION_MAP_MSGS__SRV__DETAIL__CHECK_SAFETY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "elevation_map_msgs/srv/detail/check_safety__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace elevation_map_msgs
{

namespace srv
{

namespace builder
{

class Init_CheckSafety_Request_compute_untraversable_polygon
{
public:
  explicit Init_CheckSafety_Request_compute_untraversable_polygon(::elevation_map_msgs::srv::CheckSafety_Request & msg)
  : msg_(msg)
  {}
  ::elevation_map_msgs::srv::CheckSafety_Request compute_untraversable_polygon(::elevation_map_msgs::srv::CheckSafety_Request::_compute_untraversable_polygon_type arg)
  {
    msg_.compute_untraversable_polygon = std::move(arg);
    return std::move(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Request msg_;
};

class Init_CheckSafety_Request_polygons
{
public:
  Init_CheckSafety_Request_polygons()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckSafety_Request_compute_untraversable_polygon polygons(::elevation_map_msgs::srv::CheckSafety_Request::_polygons_type arg)
  {
    msg_.polygons = std::move(arg);
    return Init_CheckSafety_Request_compute_untraversable_polygon(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::elevation_map_msgs::srv::CheckSafety_Request>()
{
  return elevation_map_msgs::srv::builder::Init_CheckSafety_Request_polygons();
}

}  // namespace elevation_map_msgs


namespace elevation_map_msgs
{

namespace srv
{

namespace builder
{

class Init_CheckSafety_Response_untraversable_polygons
{
public:
  explicit Init_CheckSafety_Response_untraversable_polygons(::elevation_map_msgs::srv::CheckSafety_Response & msg)
  : msg_(msg)
  {}
  ::elevation_map_msgs::srv::CheckSafety_Response untraversable_polygons(::elevation_map_msgs::srv::CheckSafety_Response::_untraversable_polygons_type arg)
  {
    msg_.untraversable_polygons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Response msg_;
};

class Init_CheckSafety_Response_traversability
{
public:
  explicit Init_CheckSafety_Response_traversability(::elevation_map_msgs::srv::CheckSafety_Response & msg)
  : msg_(msg)
  {}
  Init_CheckSafety_Response_untraversable_polygons traversability(::elevation_map_msgs::srv::CheckSafety_Response::_traversability_type arg)
  {
    msg_.traversability = std::move(arg);
    return Init_CheckSafety_Response_untraversable_polygons(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Response msg_;
};

class Init_CheckSafety_Response_is_safe
{
public:
  Init_CheckSafety_Response_is_safe()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckSafety_Response_traversability is_safe(::elevation_map_msgs::srv::CheckSafety_Response::_is_safe_type arg)
  {
    msg_.is_safe = std::move(arg);
    return Init_CheckSafety_Response_traversability(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::elevation_map_msgs::srv::CheckSafety_Response>()
{
  return elevation_map_msgs::srv::builder::Init_CheckSafety_Response_is_safe();
}

}  // namespace elevation_map_msgs


namespace elevation_map_msgs
{

namespace srv
{

namespace builder
{

class Init_CheckSafety_Event_response
{
public:
  explicit Init_CheckSafety_Event_response(::elevation_map_msgs::srv::CheckSafety_Event & msg)
  : msg_(msg)
  {}
  ::elevation_map_msgs::srv::CheckSafety_Event response(::elevation_map_msgs::srv::CheckSafety_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Event msg_;
};

class Init_CheckSafety_Event_request
{
public:
  explicit Init_CheckSafety_Event_request(::elevation_map_msgs::srv::CheckSafety_Event & msg)
  : msg_(msg)
  {}
  Init_CheckSafety_Event_response request(::elevation_map_msgs::srv::CheckSafety_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_CheckSafety_Event_response(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Event msg_;
};

class Init_CheckSafety_Event_info
{
public:
  Init_CheckSafety_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckSafety_Event_request info(::elevation_map_msgs::srv::CheckSafety_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_CheckSafety_Event_request(msg_);
  }

private:
  ::elevation_map_msgs::srv::CheckSafety_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::elevation_map_msgs::srv::CheckSafety_Event>()
{
  return elevation_map_msgs::srv::builder::Init_CheckSafety_Event_info();
}

}  // namespace elevation_map_msgs

#endif  // ELEVATION_MAP_MSGS__SRV__DETAIL__CHECK_SAFETY__BUILDER_HPP_
