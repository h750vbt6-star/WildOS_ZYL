cmake_minimum_required(VERSION 3.8)
project(graaf_vendor)

find_package(ament_cmake REQUIRED)

add_library(graaf_vendor INTERFACE)
target_include_directories(graaf_vendor INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS graaf_vendor
  EXPORT export_graaf_vendor
)

ament_export_targets(export_graaf_vendor HAS_LIBRARY_TARGET)
ament_export_include_directories(include)

ament_package()
