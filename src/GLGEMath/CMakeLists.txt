# Compile list for the math library
cmake_minimum_required(VERSION 3.10)

# store the version for the library
set(GLGE_MATH_VERSION 1.0.0)

# store all the source files
set(GLGE_MATH_SRC 

    )

# main project for the library
project(GLGE_MATH LANGUAGEs CXX VERSION ${GLGE_MATH_VERSION})

# compile the library
add_library(GLGE_MATH ${GLGE_MATH_SRC})