/**
 * @file GLGE_dvec4.cpp
 * @author DM8AT
 * @brief implement the C binding for the 3D float vector
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 4D float vector
#include "GLGE_dvec4.h"

dvec4 dvec4_add(dvec4 v, dvec4 u) {return v + u;}

dvec4 dvec4_subtract(dvec4 v, dvec4 u) {return v - u;}

dvec4 dvec4_negate(dvec4 v) {return -v;}

dvec4 dvec4_multiply(dvec4 v, dvec4 u) {return v * u;}

dvec4 dvec4_divide(dvec4 v, dvec4 u) {return v / u;}

void dvec4_addTo(dvec4* a, dvec4 b) {*a += b;}

void dvec4_subtractFrom(dvec4* a, dvec4 b) {*a -= b;}

void dvec4_multiplyTo(dvec4* a, dvec4 b) {*a *= b;}

void dvec4_divideBy(dvec4* a, dvec4 b) {*a /= b;}

double dvec4_dot(dvec4 v, dvec4 u) {return dot(v, u);}
