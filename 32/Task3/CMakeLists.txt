cmake_minimum_required(VERSION 3.20)
project(LernProto)

set(CMAKE_CXX_STANDART 17)
set(LernProto OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(LernProto main.cpp)

target_link_libraries(LernProto PRIVATE nlohmann_json::nlohmann_json)
