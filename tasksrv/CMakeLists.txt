cmake_minimum_required(VERSION 3.0.2)
project(tasksrv)

find_package(catkin REQUIRED COMPONENTS
  gencpp
  roscpp
  rospy
  std_msgs
)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
 add_service_files(
   FILES
   test.srv
#   Service2.srv
 )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tasksrv
#  CATKIN_DEPENDS gencpp roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(service src/service.cpp)
target_link_libraries(service ${catkin_LIBRARIES})
add_dependencies(service tasksrv_gencpp)

add_executable(client src/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client tasksrv_gencpp)





