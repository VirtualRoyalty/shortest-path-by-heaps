cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(shortest-path-by-heaps)

file(GLOB SOURCES "src/*.cpp")

add_executable(shortest-path-by-heaps ${SOURCES})
target_include_directories(shortest-path-by-heaps PUBLIC ${PROJECT_SOURCE_DIR}/include)
set_property(TARGET shortest-path-by-heaps PROPERTY CXX_STANDARD 11)
