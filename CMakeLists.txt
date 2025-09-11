cmake_minimum_required(VERSION 3.10)

project(MAIN LANGUAGES CXX)

# Enable compiler optimizations
set(CMAKE_CXX_FLAGS "-O0 -Wall -Wextra")

add_executable(MAIN src/main.cpp)

add_subdirectory(src/GLGEMath)

target_link_libraries(MAIN GLGE_MATH)