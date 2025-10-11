/**
 * @file GLGE_mat3.cpp
 * @author DM8AT
 * @brief implement the C function binding for the mat3 object
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 2*2 float matrices
#include "GLGE_mat3.h"

mat3 mat3_add(const mat3* a, const mat3* b) {return *a + *b;}

mat3 mat3_addFloat(const mat3* a, float b) {return *a + b;}

void mat3_addTo(mat3* a, const mat3* b) {*a += *b;}

void mat3_addFloatTo(mat3* a, float b) {*a += b;}

mat3 mat3_subtract(const mat3* a, const mat3* b) {return *a - *b;}

mat3 mat3_subtractFloat(const mat3* a, float b) {return *a - b;}

void mat3_subtractFrom(mat3* a, const mat3* b) {*a -= *b;}

void mat3_subtractFloatFrom(mat3* a, float b) {*a -= b;}

mat3 mat3_multiply(const mat3* a, const mat3* b) {return *a * *b;}

mat3 mat3_scale(const mat3* a, float b) {return *a * b;}

vec3 mat3_apply(const mat3* a, const vec3* b) {return *a * *b;}

void mat3_multiplyTo(mat3* a, const mat3* b) {*a *= *b;}

void mat3_scaleTo(mat3* a, float b) {*a * b;}

float mat3_determinant(const mat3* mat) {return mat->determinant();}

bool mat3_hasInverse(const mat3* mat) {return mat->hasInverse();}

mat3 mat3_cofactors(const mat3* mat) {return mat->cofactors();}

mat3 mat3_adjugate(const mat3* mat) {return mat->adjugate();}

mat3 mat3_traspose(const mat3* mat) {return mat->transpose();}

mat3 mat3_inverse(const mat3* mat) {return mat->inverse();}