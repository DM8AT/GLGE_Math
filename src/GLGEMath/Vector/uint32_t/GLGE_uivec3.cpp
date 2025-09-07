/**
 * @file GLGE_uivec3.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D uint32_t vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 3D uint32_t vector
#include "GLGE_uivec3.h"

uivec3 uivec3_add(uivec3 v, uivec3 u) {return v + u;}

uivec3 uivec3_subtract(uivec3 v, uivec3 u) {return v - u;}

uivec3 uivec3_negate(uivec3 v) {return -v;}

uivec3 uivec3_multiply(uivec3 v, uivec3 u) {return v * u;}

uivec3 uivec3_divide(uivec3 v, uivec3 u) {return v / u;}

uint32_t uivec3_dot(uivec3 v, uivec3 u) {return dot(v, u);}

uivec3 uivec3_cross(uivec3 v, uivec3 u) {return cross(v, u);}
