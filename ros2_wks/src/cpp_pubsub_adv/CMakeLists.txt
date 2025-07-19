cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub_adv)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Dependencias requeridas
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rosidl_default_runtime REQUIRED)

# Generar mensajes
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Status.msg"
  DEPENDENCIES std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Ejecutables
add_executable(advpublisher src/advpublisher.cpp)
ament_target_dependencies(advpublisher rclcpp std_msgs)
rosidl_target_interfaces(advpublisher
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(advlistener src/advlistener.cpp)
ament_target_dependencies(advlistener rclcpp std_msgs)
rosidl_target_interfaces(advlistener
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Instalación
install(TARGETS advlistener advpublisher
  DESTINATION lib/${PROJECT_NAME})

# Testing opcional
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
