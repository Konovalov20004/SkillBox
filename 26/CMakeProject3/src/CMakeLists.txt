cmake_minimum_required (VERSION 3.8)


set(MY_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable (CMakeProject3 "main.cpp" "CMakeProject3.cpp" "${MY_DIR}/CMakeProject3.h")
target_include_directories(CMakeProject3 PUBLIC ${MY_DIR})
