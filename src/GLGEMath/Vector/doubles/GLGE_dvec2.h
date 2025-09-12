/**
 * @file GLGE_dvec2.h
 * @author DM8AT
 * @brief a simple 2D vector of doubles for GLGE
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_double_dvec2_
#define _GLGE_double_dvec2_

//include common utilities
#include "../../GLGE_Common.h"

//if SIMD is requested, include SIMD intrinsics
#include "../../GLGEMath_Settings.h"
#if GLGE_MATH_USE_SIMD
#include <xmmintrin.h>
#endif

//for C++ add the iostream library for print operators
#if __cplusplus
#include <iostream>
#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief store a simple 2D vector
 */
typedef struct s_dvec2 {

    /**
     * @brief store all the data for a 2D vector
     */
    union {
        //store the values for a position
        struct {
            double x;
            double y;
        };
        //store the values like for a color
        struct {
            double r;
            double g;
        };
        //store the values as an array
        double vals[2];

        //only add the SIMD stuff if SIMD is enabled
        #if GLGE_MATH_USE_SIMD
        //store the values for SIMD processing
        __m128d simd;
        #endif
    };

    //only add element functions for C++
    #if __cplusplus

    /**
     * @brief Construct a new dvec2
     * 
     * Set everything to 0
     */
    inline constexpr s_dvec2() : x(0), y(0) {}

    /**
     * @brief Construct a new dvec2
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     */
    inline constexpr s_dvec2(double _x, double _y) : x(_x), y(_y) {}

    /**
     * @brief Construct a new dvec2
     * 
     * @param _xy the value for both axis / channels
     */
    inline constexpr s_dvec2(double _xy) : x(_xy), y(_xy) {}

    /**
     * @brief Construct a new dvec2
     * 
     * @param _val a double array with at least 2 elements
     */
    inline constexpr s_dvec2(double _val[2]) : vals{_val[0], _val[1]} {}

    //if SIMD is enabled, create a SIMD constructor
    #if GLGE_MATH_USE_SIMD
    /**
     * @brief Construct a new dvec2
     * 
     * @param _simd the SIMD data to create the vector from
     */
    inline constexpr s_dvec2(__m128d _simd) : simd(_simd) {}
    #endif

    //check for SIMD to implement the vector instructions
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief add two vectors together
     * 
     * @param u a constant reference to the other element to add
     * @return s_dvec2 the sum of both vectors
     */
    inline s_dvec2 operator+(const s_dvec2& u) const noexcept
    {return _mm_add_pd(simd, u.simd);}

    /**
     * @brief subtract two vectors from another
     * 
     * @param u the vector to subtract from this vector
     * @return s_dvec2 the difference of both vectors
     */
    inline s_dvec2 operator-(const s_dvec2& u) const noexcept
    {return _mm_sub_pd(simd, u.simd);}

    /**
     * @brief multiply two vectors per-element together 
     * 
     * @param u the vector to multiply to this vector
     * @return s_dvec2 the product of both vectors
     */
    inline s_dvec2 operator*(const s_dvec2& u) const noexcept
    {return _mm_mul_pd(simd, u.simd);}

    /**
     * @brief divide two vectors per-element
     * 
     * @param u the vector to use as denominator
     * @return s_dvec2 the fraction of both vectors
     */
    inline s_dvec2 operator/(const s_dvec2& u) const noexcept
    {return _mm_div_pd(simd, u.simd);}

    #else //else, implement the non-simd variant

    /**
     * @brief add two vectors together
     * 
     * @param u a constant reference to the other element to add
     * @return s_dvec2 the sum of both vectors
     */
    inline constexpr s_dvec2 operator+(const s_dvec2& u) const noexcept
    {return s_dvec2(x + u.x, y + u.y);}

    /**
     * @brief subtract two vectors from another
     * 
     * @param u the vector to subtract from this vector
     * @return s_dvec2 the difference of both vectors
     */
    inline constexpr s_dvec2 operator-(const s_dvec2& u) const noexcept
    {return s_dvec2(x - u.x, y - u.y);}

    /**
     * @brief multiply two vectors per-element together 
     * 
     * @param u the vector to multiply to this vector
     * @return s_dvec2 the product of both vectors
     */
    inline constexpr s_dvec2 operator*(const s_dvec2& u) const noexcept
    {return s_dvec2(x * u.x, y * u.y);}

    /**
     * @brief divide two vectors per-element
     * 
     * @param u the vector to use as denominator
     * @return s_dvec2 the fraction of both vectors
     */
    inline constexpr s_dvec2 operator/(const s_dvec2& u) const noexcept
    {return s_dvec2(x / u.x, y / u.y);}

    #endif

    /**
     * @brief negate a vector
     * 
     * @return s_dvec2 the negated vector
     */
    inline constexpr s_dvec2 operator-(void) const noexcept
    {return s_dvec2(-x, -y);}

    /**
     * @brief print the vector to an output stream
     * 
     * @param os the output stream to fill
     * @param v the vector to print to the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<< (std::ostream& os, const s_dvec2& v) noexcept
    {return os << "(" << v.x << ", " << v.y << ")";}

    #endif

} dvec2;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D double vectors
 * 
 * @param v the first double vector
 * @param u the second double vector
 * @return const double the dot product of both vectors
 */
inline constexpr double dot(const dvec2& v, const dvec2& u) noexcept {return v.x * u.x + v.y * u.y;}

/**
 * @brief calculate the length of a 2D double vector
 * 
 * @param v a constant reference to the vector to calculate the length of
 * @return constexpr float the length of the vector
 */
inline float length(const dvec2& v) noexcept {return glge::sqrt(v.x*v.x + v.y*v.y);}

/**
 * @brief calculate a vector that points in the same direction 
 * 
 * @param v a vector to normalize
 * @return vec3 a vector pointing in the same direction as the input but with a length of 1
 */
inline dvec2 normalize(const dvec2& v) noexcept {return v / length(v);}

#endif

/**
 * @brief add two 2D double vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return dvec2 the sum of both vectors
 */
dvec2 dvec2_add(dvec2 v, dvec2 u);

/**
 * @brief subtract two 2D double vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return dvec2 the difference of both vectors
 */
dvec2 dvec2_subtract(dvec2 v, dvec2 u);

/**
 * @brief negate a 2D vector
 * 
 * @param v the vector to negate
 * @return dvec2 the negated vector
 */
dvec2 dvec2_negate(dvec2 v);

/**
 * @brief multiply two 2D double vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return dvec2 the product of two vectors
 */
dvec2 dvec2_multiply(dvec2 v, dvec2 u);

/**
 * @brief divide two 2D double vectors
 * 
 * @param v the 2D vector to use as nominator
 * @param u the 2D vector to use as denominator
 * @return dvec2 the fraction of both vectors
 */
dvec2 dvec2_divide(dvec2 v, dvec2 u);

/**
 * @brief calculate the dot product of two 2D double vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return double the dot product of two 2D double vectors
 */
double dvec2_dot(dvec2 v, dvec2 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif