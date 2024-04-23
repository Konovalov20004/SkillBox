cmake_minimum_required (VERSION 3.8)

project ("CMakeProject2")

set(MY_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable (CMakeProject2 "main.cpp" "CMakeProject2.cpp" "${MY_DIR}/CMakeProject2.h")
target_include_directories(CMakeProject2 PUBLIC ${MY_DIR})
