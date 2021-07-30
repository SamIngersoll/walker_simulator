project(publisher)


add_subdirectory (util)

add_executable (publisher publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES} read_trajectory)
