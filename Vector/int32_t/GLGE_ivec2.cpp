/**
 * @file GLGE_ivec2.cpp
 * @author DM8AT
 * @brief implement the C++ binding for all functions
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include 2D float vectors
#include "GLGE_ivec2.h"

ivec2 ivec2_add(ivec2 v, ivec2 u) {return v + u;}

ivec2 ivec2_subtract(ivec2 v, ivec2 u) {return v - u;}

ivec2 ivec2_negate(ivec2 v) {return -v;}

ivec2 ivec2_multiply(ivec2 v, ivec2 u) {return v * u;}

ivec2 ivec2_divide(ivec2 v, ivec2 u) {return v / u;}

int32_t ivec2_dot(ivec2 v, ivec2 u) {return dot(v, u);}
