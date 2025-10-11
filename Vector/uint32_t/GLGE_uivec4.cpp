/**
 * @file GLGE_uivec4.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D uint32_t vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 4D uint32_t vector
#include "GLGE_uivec4.h"

uivec4 uivec4_add(uivec4 v, uivec4 u) {return v + u;}

uivec4 uivec4_subtract(uivec4 v, uivec4 u) {return v - u;}

uivec4 uivec4_negate(uivec4 v) {return -v;}

uivec4 uivec4_multiply(uivec4 v, uivec4 u) {return v * u;}

uivec4 uivec4_divide(uivec4 v, uivec4 u) {return v / u;}

void uivec4_addTo(uivec4* a, uivec4 b) {*a += b;}

void uivec4_subtractFrom(uivec4* a, uivec4 b) {*a -= b;}

void uivec4_multiplyTo(uivec4* a, uivec4 b) {*a *= b;}

void uivec4_divideBy(uivec4* a, uivec4 b) {*a /= b;}

uint32_t uivec4_dot(uivec4 v, uivec4 u) {return dot(v, u);}
