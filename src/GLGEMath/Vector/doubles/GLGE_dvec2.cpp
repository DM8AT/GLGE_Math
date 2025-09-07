/**
 * @file GLGE_dvec2.cpp
 * @author DM8AT
 * @brief implement the C++ binding for all functions
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include 2D float vectors
#include "GLGE_dvec2.h"

dvec2 dvec2_add(dvec2 v, dvec2 u) {return v + u;}

dvec2 dvec2_subtract(dvec2 v, dvec2 u) {return v - u;}

dvec2 dvec2_negate(dvec2 v) {return -v;}

dvec2 dvec2_multiply(dvec2 v, dvec2 u) {return v * u;}

dvec2 dvec2_divide(dvec2 v, dvec2 u) {return v / u;}

double dvec2_dot(dvec2 v, dvec2 u) {return dot(v, u);}
