/**
 * @file GLGE_mat2.cpp
 * @author DM8AT
 * @brief implement the C function binding for the mat2 object
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 2*2 float matrices
#include "GLGE_mat2.h"

mat2 mat2_add(const mat2* a, const mat2* b) {return *a + *b;}

mat2 mat2_addFloat(const mat2* a, float b) {return *a + b;}

void mat2_addTo(mat2* a, const mat2* b) {*a += *b;}

void mat2_addFloatTo(mat2* a, float b) {*a += b;}

mat2 mat2_subtract(const mat2* a, const mat2* b) {return *a - *b;}

mat2 mat2_subtractFloat(const mat2* a, float b) {return *a - b;}

void mat2_subtractFrom(mat2* a, const mat2* b) {*a -= *b;}

void mat2_subtractFloatFrom(mat2* a, float b) {*a -= b;}

mat2 mat2_multiply(const mat2* a, const mat2* b) {return *a * *b;}

mat2 mat2_scale(const mat2* a, float b) {return *a * b;}

vec2 mat2_apply(const mat2* a, const vec2* b) {return *a * *b;}

void mat2_multiplyTo(mat2* a, const mat2* b) {*a *= *b;}

void mat2_scaleTo(mat2* a, float b) {*a * b;}

float mat2_determinant(const mat2* mat) {return mat->determinant();}

mat2 mat2_cofactors(const mat2* mat) {return mat->cofactors();}

mat2 mat2_adjugate(const mat2* mat) {return mat->adjugate();}

mat2 mat2_traspose(const mat2* mat) {return mat->transpose();}

mat2 mat2_inverse(const mat2* mat) {return mat->inverse();}