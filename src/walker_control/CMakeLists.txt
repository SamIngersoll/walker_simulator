cmake_minimum_required(VERSION 2.8.3)
project(walker_control)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})



add_executable(publisher ${CMAKE_CURRENT_SOURCE_DIR}/src/publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})