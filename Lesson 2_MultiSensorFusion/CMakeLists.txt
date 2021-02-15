cmake_minimum_required(VERSION 3.0.0)
project(multi_sensor_fusion VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(multi_sensor_fusion main.cpp)
add_executable(solution solution.cpp)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries (multi_sensor_fusion Eigen3::Eigen)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
