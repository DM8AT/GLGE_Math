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

//include 

typedef struct s_vec2 {

    union {
        float x;
        float y;
    };
    union {
        float r;
        float y;
    };

} vec2;

#endif