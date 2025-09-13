/**
 * @file GLGE_dvec3.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D float vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 3D float vector
#include "GLGE_dvec3.h"

dvec3 dvec3_add(dvec3 v, dvec3 u) {return v + u;}

dvec3 dvec3_subtract(dvec3 v, dvec3 u) {return v - u;}

dvec3 dvec3_negate(dvec3 v) {return -v;}

dvec3 dvec3_multiply(dvec3 v, dvec3 u) {return v * u;}

dvec3 dvec3_divide(dvec3 v, dvec3 u) {return v / u;}

double dvec3_dot(dvec3 v, dvec3 u) {return dot(v, u);}

dvec3 dvec3_cross(dvec3 v, dvec3 u) {return cross(v, u);}
