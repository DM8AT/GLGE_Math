/**
 * @file GLGE_ivec3.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D int32_t vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 3D int32_t vector
#include "GLGE_ivec3.h"

ivec3 ivec3_add(ivec3 v, ivec3 u) {return v + u;}

ivec3 ivec3_subtract(ivec3 v, ivec3 u) {return v - u;}

ivec3 ivec3_negate(ivec3 v) {return -v;}

ivec3 ivec3_multiply(ivec3 v, ivec3 u) {return v * u;}

ivec3 ivec3_divide(ivec3 v, ivec3 u) {return v / u;}

int32_t ivec3_dot(ivec3 v, ivec3 u) {return dot(v, u);}

ivec3 ivec3_cross(ivec3 v, ivec3 u) {return cross(v, u);}
