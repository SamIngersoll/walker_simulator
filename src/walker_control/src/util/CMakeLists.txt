add_library(read_trajectory read_trajectory.cpp)
target_sources(read_trajectory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/read_trajectory.h)
target_include_directories(read_trajectory INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})