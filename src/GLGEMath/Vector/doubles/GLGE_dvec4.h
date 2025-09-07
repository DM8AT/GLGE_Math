/**
 * @file GLGE_dvec4.h
 * @author DM8AT
 * @brief define an interface for 4D double vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_double_dvec4_
#define _GLGE_double_dvec4_

//include the 2D vector for upcasting
#include "GLGE_dvec2.h"
//include the 3D vector for upcasting
#include "GLGE_dvec3.h"

//if SIMD is requested, include SIMD intrinsics
#include "../../GLGEMath_Settings.h"
#if GLGE_MATH_USE_SIMD
#if GLGE_MATH_ALLOW_AVX2
#include <immintrin.h>
#else
#include <xmmintrin.h>
#endif
#endif

/**
 * @brief store a 4D vector of doubles
 */
typedef struct s_dvec4 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            double x;
            double y;
            double z;
            double w;
        };
        //store the values for colors
        struct {
            double r;
            double g;
            double b;
            double a;
        };
        //store the values as a double vector
        double vals[4];

        //only add the SIMD stuff if SIMD is enabled
        #if GLGE_MATH_USE_SIMD
        //check for AVX2 support to use AVX2 extensions
        #if GLGE_MATH_ALLOW_AVX2
        //store the AVX2 type to use for SIMD
        __m256d simd;
        #else
        //use two SSE 128 intrinsic types to add with only two instructions
        struct {
            __m128d lower;
            __m128d upper;
        };
        #endif
        #endif
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new dvec4
     * 
     */
    inline s_dvec4() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Construct a new dvec4
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline s_dvec4(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w) {}

    /**
     * @brief Construct a new dvec4
     * 
     * @param xyzw the value for the x, y, z and w axis as well as for the red, green, blue and alpha channel
     */
    inline s_dvec4(double xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

    /**
     * @brief Construct a new dvec4
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param zw the value for the z and w axis / blue and alpha channel
     */
    inline s_dvec4(const dvec2& xy, const dvec2& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}

    /**
     * @brief Construct a new dvec4
     * 
     * @param xyz the value for the x, y and z axis / red, green and blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline s_dvec4(const dvec3& xyz, double _w) : x(xyz.x), y(xyz.y), z(xyz.z), w(_w) {}
    
    /**
     * @brief Construct a new dvec4
     * 
     * @param _x the value for the x axis / red channel
     * @param yzw the values for the y, z and w axis / green, blue and alpha channel
     */
    inline s_dvec4(double _x, const dvec3& yzw) : x(_x), y(yzw.x), z(yzw.y), w(yzw.z) {}

    //only implement the SIMD constructor if SIMD is enabled
    #if GLGE_MATH_USE_SIMD

    //check for the AVX2 intrinsic support to use AVX2 intrinsic types
    #if GLGE_MATH_ALLOW_AVX2

    /**
     * @brief Construct a new dvec4
     * 
     * @param _simd the simd value to create the vector from
     */
    inline s_dvec4(const __m256d& _simd) : simd(_simd) {}

    #else

    /**
     * @brief Construct a new dvec4
     * 
     * @param _lower the lower values for the vector
     * @param _upper the upper values for the vector
     */
    inline s_dvec4(const __m128d& _lower, const __m128d&_upper) : lower(_lower), upper(_upper) {}

    #endif
    
    #endif

    //implement the SIMD operators
    #if GLGE_MATH_USE_SIMD

    //check for support for the AVX2 vector intrinsics
    #if GLGE_MATH_ALLOW_AVX2

    /**
     * @brief add two 4D double vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_dvec4 the sum of both vectors
     */
    inline s_dvec4 operator+(const s_dvec4& u) const noexcept
    {return _mm256_add_pd(simd, u.simd);}

    /**
     * @brief subtract two 4D double vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_dvec4 the difference of both vectors
     */
    inline s_dvec4 operator-(const s_dvec4& u) const noexcept
    {return _mm256_sub_pd(simd, u.simd);}

    /**
     * @brief multiply two 4D double vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_dvec4 the product of both vectors
     */
    inline s_dvec4 operator*(const s_dvec4& u) const noexcept
    {return _mm256_mul_pd(simd, u.simd);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_dvec4 the fraction of both vectors
     */
    inline s_dvec4 operator/(const s_dvec4& u) const noexcept
    {return _mm256_div_pd(simd, u.simd);}

    #else

    //use the SSE intrinsics

    /**
     * @brief add two 4D double vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_dvec4 the sum of both vectors
     */
    inline s_dvec4 operator+(const s_dvec4& u) const noexcept
    {return s_dvec4(_mm_add_pd(lower, u.lower), _mm_add_pd(upper, u.upper));}

    /**
     * @brief subtract two 4D double vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_dvec4 the difference of both vectors
     */
    inline s_dvec4 operator-(const s_dvec4& u) const noexcept
    {return s_dvec4(_mm_sub_pd(lower, u.lower), _mm_sub_pd(upper, u.upper));}

    /**
     * @brief multiply two 4D double vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_dvec4 the product of both vectors
     */
    inline s_dvec4 operator*(const s_dvec4& u) const noexcept
    {return s_dvec4(_mm_mul_pd(lower, u.lower), _mm_mul_pd(upper, u.upper));}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_dvec4 the fraction of both vectors
     */
    inline s_dvec4 operator/(const s_dvec4& u) const noexcept
    {return s_dvec4(_mm_div_pd(lower, u.lower), _mm_div_pd(upper, u.upper));}

    #endif

    #else //else, implement the not simd operators

    /**
     * @brief add two 4D double vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_dvec4 the sum of both vectors
     */
    inline s_dvec4 operator+(const s_dvec4& u) const noexcept
    {return s_dvec4(x + u.x, y + u.y, z + u.z, w + u.w);}

    /**
     * @brief subtract two 4D double vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_dvec4 the difference of both vectors
     */
    inline s_dvec4 operator-(const s_dvec4& u) const noexcept
    {return s_dvec4(x - u.x, y - u.y, z - u.z, w - u.w);}

    /**
     * @brief multiply two 4D double vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_dvec4 the product of both vectors
     */
    inline s_dvec4 operator*(const s_dvec4& u) const noexcept
    {return s_dvec4(x * u.x, y * u.y, z * u.z, w * u.w);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_dvec4 the fraction of both vectors
     */
    inline s_dvec4 operator/(const s_dvec4& u) const noexcept
    {return s_dvec4(x / u.x, y / u.y, z / u.z, w / u.w);}

    #endif

    /**
     * @brief negate a 4D double vector
     * 
     * @return s_dvec4 the negated vector
     */
    inline s_dvec4 operator-(void)  const noexcept
    {return s_dvec4(-x,-y,-z,-w);}

    /**
     * @brief print a 4D vector into an output stream
     * 
     * @param os the output output stream to fill
     * @param u the 4D double vector to put into the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<<(std::ostream& os, const s_dvec4& u) noexcept
    {return os << "(" << u.x << ", " << u.y << ", " << u.z << ", " << u.w << ")";}

    #endif

} dvec4;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D double vectors
 * 
 * @param v the first double vector
 * @param u the second double vector
 * @return const double the dot product of both vectors
 */
inline const double dot(const dvec4& v, const dvec4& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;}

#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 4D double vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return dvec4 the sum of both vectors
 */
dvec4 dvec4_add(dvec4 v, dvec4 u);

/**
 * @brief subtract two 4D double vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return dvec4 the difference of both vectors
 */
dvec4 dvec4_subtract(dvec4 v, dvec4 u);

/**
 * @brief negate a 4D vector
 * 
 * @param v the vector to negate
 * @return dvec4 the negated vector
 */
dvec4 dvec4_negate(dvec4 v);

/**
 * @brief multiply two 4D double vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return dvec4 the product of two vectors
 */
dvec4 dvec4_multiply(dvec4 v, dvec4 u);

/**
 * @brief divide two 4D double vectors
 * 
 * @param v the 4D vector to use as nominator
 * @param u the 4D vector to use as denominator
 * @return dvec4 the fraction of both vectors
 */
dvec4 dvec4_divide(dvec4 v, dvec4 u);

/**
 * @brief calculate the dot product of two 4D double vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return double the dot product of two 4D double vectors
 */
double dvec4_dot(dvec4 v, dvec4 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif