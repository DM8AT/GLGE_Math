/**
 * @file GLGE_vec4.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D float vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 4D float vector
#include "GLGE_vec4.h"

vec4 vec4_add(vec4 v, vec4 u) {return v + u;}

vec4 vec4_subtract(vec4 v, vec4 u) {return v - u;}

vec4 vec4_negate(vec4 v) {return -v;}

vec4 vec4_multiply(vec4 v, vec4 u) {return v * u;}

vec4 vec4_divide(vec4 v, vec4 u) {return v / u;}

void vec4_addTo(vec4* a, vec4 b) {*a += b;}

void vec4_subtractFrom(vec4* a, vec4 b) {*a -= b;}

void vec4_multiplyTo(vec4* a, vec4 b) {*a *= b;}

void vec4_divideBy(vec4* a, vec4 b) {*a /= b;}

float vec4_dot(vec4 v, vec4 u) {return dot(v, u);}
