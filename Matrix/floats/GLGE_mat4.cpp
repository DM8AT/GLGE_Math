/**
 * @file GLGE_mat4.cpp
 * @author DM8AT
 * @brief implement the C function binding for the mat4 object
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 2*2 float matrices
#include "GLGE_mat4.h"

mat4 mat4_add(const mat4* a, const mat4* b) {return *a + *b;}

mat4 mat4_addFloat(const mat4* a, float b) {return *a + b;}

void mat4_addTo(mat4* a, const mat4* b) {*a += *b;}

void mat4_addFloatTo(mat4* a, float b) {*a += b;}

mat4 mat4_subtract(const mat4* a, const mat4* b) {return *a - *b;}

mat4 mat4_subtractFloat(const mat4* a, float b) {return *a - b;}

void mat4_subtractFrom(mat4* a, const mat4* b) {*a -= *b;}

void mat4_subtractFloatFrom(mat4* a, float b) {*a -= b;}

mat4 mat4_multiply(const mat4* a, const mat4* b) {return *a * *b;}

mat4 mat4_scale(const mat4* a, float b) {return *a * b;}

vec4 mat4_apply(const mat4* a, const vec4* b) {return *a * *b;}

void mat4_multiplyTo(mat4* a, const mat4* b) {*a *= *b;}

void mat4_scaleTo(mat4* a, float b) {*a * b;}

float mat4_determinant(const mat4* mat) {return mat->determinant();}

bool mat4_hasInverse(const mat4* mat) {return mat->hasInverse();}

mat4 mat4_cofactors(const mat4* mat) {return mat->cofactors();}

mat4 mat4_adjugate(const mat4* mat) {return mat->adjugate();}

mat4 mat4_traspose(const mat4* mat) {return mat->transpose();}

mat4 mat4_inverse(const mat4* mat) {return mat->inverse();}