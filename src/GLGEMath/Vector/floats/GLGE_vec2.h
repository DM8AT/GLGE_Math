/**
 * @file GLGE_vec2.h
 * @author DM8AT
 * @brief a simple 2D vector of floats for GLGE
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_FLOAT_VEC2_
#define _GLGE_FLOAT_VEC2_

//include the settings
#include "../../GLGEMath_Settings.h"

//if SIMD is requested, include the vector intrinsics
#if GLGE_MATH_USE_SIMD
#include <xmmintrin.h>
#endif

/**
 * @brief store a simple 2D vector
 */
typedef struct s_vec2 {

    /**
     * @brief store all the data for a 2D vector
     */
    union {
        //store the values for a position
        struct {
            float x;
            float y;
        };
        //store the values like for a color
        struct {
            float r;
            float g;
        };
        //store the values as an array
        float vals[2];

        //if SIMD is requested, also add the intrinsic vector type
        #if GLGE_MATH_USE_SIMD
        //store a simd intrinsic type to access the floats
        __m64 simd;
        #endif
    };

} vec2;

#endif