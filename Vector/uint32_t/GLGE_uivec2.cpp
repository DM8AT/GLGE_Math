/**
 * @file GLGE_uivec2.cpp
 * @author DM8AT
 * @brief implement the C++ binding for all functions
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include 2D float vectors
#include "GLGE_uivec2.h"

uivec2 uivec2_add(uivec2 v, uivec2 u) {return v + u;}

uivec2 uivec2_subtract(uivec2 v, uivec2 u) {return v - u;}

uivec2 uivec2_negate(uivec2 v) {return -v;}

uivec2 uivec2_multiply(uivec2 v, uivec2 u) {return v * u;}

uivec2 uivec2_divide(uivec2 v, uivec2 u) {return v / u;}

uint32_t uivec2_dot(uivec2 v, uivec2 u) {return dot(v, u);}
