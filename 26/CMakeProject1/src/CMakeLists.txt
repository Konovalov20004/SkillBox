# CMakeList.txt: проект CMake для CMakeProject1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(MY_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(CMakeProject1 "CMakeProject1.cpp" "${MY_DIR}/CMakeProject1.h")
target_include_directories(CMakeProject1 PUBLIC ${MY_DIR})