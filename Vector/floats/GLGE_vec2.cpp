/**
 * @file GLGE_vec2.cpp
 * @author DM8AT
 * @brief implement the C++ binding for all functions
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include 2D float vectors
#include "GLGE_vec2.h"

vec2 vec2_add(vec2 v, vec2 u) {return v + u;}

vec2 vec2_subtract(vec2 v, vec2 u) {return v - u;}

vec2 vec2_negate(vec2 v) {return -v;}

vec2 vec2_multiply(vec2 v, vec2 u) {return v * u;}

vec2 vec2_divide(vec2 v, vec2 u) {return v / u;}

float vec2_dot(vec2 v, vec2 u) {return dot(v, u);}
