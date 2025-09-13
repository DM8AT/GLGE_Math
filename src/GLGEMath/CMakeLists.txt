# Compile list for the math library
cmake_minimum_required(VERSION 3.10)

# store the version for the library
set(GLGE_MATH_VERSION 1.0.0)

# store all the source files
set(GLGE_MATH_SRC 
        GLGE_Common.cpp

        Vector/floats/GLGE_vec2.cpp
        Vector/floats/GLGE_vec3.cpp
        Vector/floats/GLGE_vec4.cpp

        Vector/doubles/GLGE_dvec2.cpp
        Vector/doubles/GLGE_dvec3.cpp
        Vector/doubles/GLGE_dvec4.cpp

        Vector/int32_t/GLGE_ivec2.cpp
        Vector/int32_t/GLGE_ivec3.cpp
        Vector/int32_t/GLGE_ivec4.cpp

        Vector/uint32_t/GLGE_uivec2.cpp
        Vector/uint32_t/GLGE_uivec3.cpp
        Vector/uint32_t/GLGE_uivec4.cpp

        Imaginary/Quaternions/Quaternion.cpp
    )

# needed to check if AVX2 is supported
include(CheckCXXCompilerFlag)

# Function to add AVX2 flags based on compiler
function(enable_avx2 target)
    if(MSVC)
        # Visual Studio: Use /arch:AVX2
        target_compile_options(${target} PUBLIC /arch:AVX2)
    else()
        # GCC or Clang: Test for -mavx2 support first
        check_cxx_compiler_flag("-mavx2" COMPILER_SUPPORTS_MAVX2)
        if(COMPILER_SUPPORTS_MAVX2)
            target_compile_options(${target} PUBLIC -mavx2)
        else()
            message(WARNING "Compiler does not support -mavx2")
        endif()
    endif()
endfunction()

# main project for the library
project(GLGE_MATH LANGUAGES CXX VERSION ${GLGE_MATH_VERSION})

# compile the library
add_library(GLGE_MATH ${GLGE_MATH_SRC})

# enable AVX compiler flags
enable_avx2(GLGE_MATH)