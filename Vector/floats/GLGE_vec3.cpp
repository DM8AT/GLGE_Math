/**
 * @file GLGE_vec3.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D float vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 3D float vector
#include "GLGE_vec3.h"

vec3 vec3_add(vec3 v, vec3 u) {return v + u;}

vec3 vec3_subtract(vec3 v, vec3 u) {return v - u;}

vec3 vec3_negate(vec3 v) {return -v;}

vec3 vec3_multiply(vec3 v, vec3 u) {return v * u;}

vec3 vec3_divide(vec3 v, vec3 u) {return v / u;}

float vec3_dot(vec3 v, vec3 u) {return dot(v, u);}

vec3 vec3_cross(vec3 v, vec3 u) {return cross(v, u);}
