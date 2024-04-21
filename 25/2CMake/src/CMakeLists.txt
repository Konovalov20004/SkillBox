cmake_minimum_required (VERSION 3.8)

set (MY_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable (2CMake "main.cpp"   "${MY_DIR}/ram.h"       "cpu.cpp" "gpu.cpp" "ram.cpp" "kbd.cpp" "disk.cpp")
target_include_directories(2CMake PUBLIC ${MY_DIR})