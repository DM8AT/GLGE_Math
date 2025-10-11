/**
 * @file GLGE_dmat4.cpp
 * @author DM8AT
 * @brief implement the C function binding for the dmat4 object
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 2*2 float matrices
#include "GLGE_dmat4.h"

dmat4 dmat4_add(const dmat4* a, const dmat4* b) {return *a + *b;}

dmat4 dmat4_addFloat(const dmat4* a, float b) {return *a + b;}

void dmat4_addTo(dmat4* a, const dmat4* b) {*a += *b;}

void dmat4_addFloatTo(dmat4* a, float b) {*a += b;}

dmat4 dmat4_subtract(const dmat4* a, const dmat4* b) {return *a - *b;}

dmat4 dmat4_subtractFloat(const dmat4* a, float b) {return *a - b;}

void dmat4_subtractFrom(dmat4* a, const dmat4* b) {*a -= *b;}

void dmat4_subtractFloatFrom(dmat4* a, float b) {*a -= b;}

dmat4 dmat4_multiply(const dmat4* a, const dmat4* b) {return *a * *b;}

dmat4 dmat4_scale(const dmat4* a, float b) {return *a * b;}

dvec4 dmat4_apply(const dmat4* a, const dvec4* b) {return *a * *b;}

void dmat4_multiplyTo(dmat4* a, const dmat4* b) {*a *= *b;}

void dmat4_scaleTo(dmat4* a, float b) {*a * b;}

double dmat4_determinant(const dmat4* mat) {return mat->determinant();}

bool dmat4_hasInverse(const dmat4* mat) {return mat->hasInverse();}

dmat4 dmat4_cofactors(const dmat4* mat) {return mat->cofactors();}

dmat4 dmat4_adjugate(const dmat4* mat) {return mat->adjugate();}

dmat4 dmat4_traspose(const dmat4* mat) {return mat->transpose();}

dmat4 dmat4_inverse(const dmat4* mat) {return mat->inverse();}