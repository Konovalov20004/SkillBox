cmake_minimum_required (VERSION 3.8)

set (MY_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable (2CMake "main.cpp" "${MY_DIR}/gpu.h" "${MY_DIR}/cpu.h" "${MY_DIR}/ram.h" "${MY_DIR}/kbd.h" "${MY_DIR}/disk.h"    )
target_include_directories(2CMake PUBLIC ${MY_DIR})