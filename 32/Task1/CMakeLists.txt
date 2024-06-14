cmake_minimum_required(VERSION 3.20)
project(LernJson)

set(CMAKE_CXX_STANDART 17)
set(LernJson OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(LernJson main.cpp)

target_link_libraries(LernJson PRIVATE nlohmann_json::nlohmann_json)
