/**
 * @file GLGE_ivec4.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D int32_t vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 4D int32_t vector
#include "GLGE_ivec4.h"

ivec4 ivec4_add(ivec4 v, ivec4 u) {return v + u;}

ivec4 ivec4_subtract(ivec4 v, ivec4 u) {return v - u;}

ivec4 ivec4_negate(ivec4 v) {return -v;}

ivec4 ivec4_multiply(ivec4 v, ivec4 u) {return v * u;}

ivec4 ivec4_divide(ivec4 v, ivec4 u) {return v / u;}

int32_t ivec4_dot(ivec4 v, ivec4 u) {return dot(v, u);}
