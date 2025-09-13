/**
 * @file Quaternion.cpp
 * @author DM8AT
 * @brief implement the C linkage for the quaternion structure
 * @version 0.1
 * @date 2025-09-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the quaternion structure
#include "Quaternion.h"

Quaternion quaternion_add(Quaternion* q, Quaternion* p) {return *q + *p;}

Quaternion quaternion_subtract(Quaternion* q, Quaternion* p) {return *q - *p;}

Quaternion quaternion_conjugate(Quaternion* q) {return -(*q);}

Quaternion quaternion_multiply(Quaternion* q, Quaternion* p) {return *q * *p;}

Quaternion quaternion_multiplyWithVec3(Quaternion* q, vec3* v) {return *q * *v;}

Quaternion quaternion_scale(Quaternion* q, float s) {return *q * s;}

Quaternion quaternion_divide(Quaternion* q, float s) {return *q / s;}