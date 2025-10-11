/**
 * @file GLGE_dmat3.cpp
 * @author DM8AT
 * @brief implement the C function binding for the dmat3 object
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 2*2 float matrices
#include "GLGE_dmat3.h"

dmat3 dmat3_add(const dmat3* a, const dmat3* b) {return *a + *b;}

dmat3 dmat3_addFloat(const dmat3* a, float b) {return *a + b;}

void dmat3_addTo(dmat3* a, const dmat3* b) {*a += *b;}

void dmat3_addFloatTo(dmat3* a, float b) {*a += b;}

dmat3 dmat3_subtract(const dmat3* a, const dmat3* b) {return *a - *b;}

dmat3 dmat3_subtractFloat(const dmat3* a, float b) {return *a - b;}

void dmat3_subtractFrom(dmat3* a, const dmat3* b) {*a -= *b;}

void dmat3_subtractFloatFrom(dmat3* a, float b) {*a -= b;}

dmat3 dmat3_multiply(const dmat3* a, const dmat3* b) {return *a * *b;}

dmat3 dmat3_scale(const dmat3* a, float b) {return *a * b;}

dvec3 dmat3_apply(const dmat3* a, const dvec3* b) {return *a * *b;}

void dmat3_multiplyTo(dmat3* a, const dmat3* b) {*a *= *b;}

void dmat3_scaleTo(dmat3* a, float b) {*a * b;}

double dmat3_determinant(const dmat3* mat) {return mat->determinant();}

bool dmat3_hasInverse(const dmat3* mat) {return mat->hasInverse();}

dmat3 dmat3_cofactors(const dmat3* mat) {return mat->cofactors();}

dmat3 dmat3_adjugate(const dmat3* mat) {return mat->adjugate();}

dmat3 dmat3_traspose(const dmat3* mat) {return mat->transpose();}

dmat3 dmat3_inverse(const dmat3* mat) {return mat->inverse();}