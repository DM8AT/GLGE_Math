/**
 * @file GLGE_dmat2.cpp
 * @author DM8AT
 * @brief implement the C function binding for the dmat2 object
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//include the 2*2 float matrices
#include "GLGE_dmat2.h"

dmat2 dmat2_add(const dmat2* a, const dmat2* b) {return *a + *b;}

dmat2 dmat2_addFloat(const dmat2* a, float b) {return *a + b;}

void dmat2_addTo(dmat2* a, const dmat2* b) {*a += *b;}

void dmat2_addFloatTo(dmat2* a, float b) {*a += b;}

dmat2 dmat2_subtract(const dmat2* a, const dmat2* b) {return *a - *b;}

dmat2 dmat2_subtractFloat(const dmat2* a, float b) {return *a - b;}

void dmat2_subtractFrom(dmat2* a, const dmat2* b) {*a -= *b;}

void dmat2_subtractFloatFrom(dmat2* a, float b) {*a -= b;}

dmat2 dmat2_multiply(const dmat2* a, const dmat2* b) {return *a * *b;}

dmat2 dmat2_scale(const dmat2* a, float b) {return *a * b;}

dvec2 dmat2_apply(const dmat2* a, const dvec2* b) {return *a * *b;}

void dmat2_multiplyTo(dmat2* a, const dmat2* b) {*a *= *b;}

void dmat2_scaleTo(dmat2* a, float b) {*a * b;}

double dmat2_determinant(const dmat2* mat) {return mat->determinant();}

dmat2 dmat2_cofactors(const dmat2* mat) {return mat->cofactors();}

dmat2 dmat2_adjugate(const dmat2* mat) {return mat->adjugate();}

dmat2 dmat2_traspose(const dmat2* mat) {return mat->transpose();}

dmat2 dmat2_inverse(const dmat2* mat) {return mat->inverse();}