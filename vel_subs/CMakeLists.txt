cmake_minimum_required(VERSION 3.0.2)
project(vel_subs)


find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  rospy
  vel_test
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(vel_listner src/vel_listner.cpp)
add_dependencies(vel_listner nav_msgs_generate_messages_cpp)
 target_link_libraries(vel_listner
   ${catkin_LIBRARIES}
)