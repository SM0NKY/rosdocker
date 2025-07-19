cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub_adv)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#Dependencias requeridas
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rosidl_default_runtime REQUIRED)

#Generar los mensajes
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Status.msg"
  DEPENDENCIES std_msgs
)
ament_export_dependencies(rosidl_default_runtime)

# Ejecutables de los Nodos
add_executable(advpublisher src/advpublisher.cpp)
ament_target_dependencies(advpublisher rclcpp std_msgs)
#Revisar esta linea
add_dependencies(advpublisher ${PROJECT_NAME})


add_executable(advlistener src/advlistener.cpp)
ament_target_dependencies(advlistener rclcpp std_msgs)
add_dependencies(advlistener ${PROJECT_NAME})



install (TARGETS advlistener advpublisher DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
