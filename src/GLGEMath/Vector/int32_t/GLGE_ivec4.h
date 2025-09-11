/**
 * @file GLGE_ivec4.h
 * @author DM8AT
 * @brief define an interface for 4D int32_t vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_int32_t_ivec4_
#define _GLGE_int32_t_ivec4_

//include the 2D vector for upcasting
#include "GLGE_ivec2.h"
//include the 3D vector for upcasting
#include "GLGE_ivec3.h"

//if SIMD is requested, include SIMD intrinsics
#include "../../GLGEMath_Settings.h"
#if GLGE_MATH_USE_SIMD
#include <xmmintrin.h>
#endif

/**
 * @brief store a 4D vector of int32_ts
 */
typedef struct s_ivec4 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            int32_t x;
            int32_t y;
            int32_t z;
            int32_t w;
        };
        //store the values for colors
        struct {
            int32_t r;
            int32_t g;
            int32_t b;
            int32_t a;
        };
        //store the values as a int32_t vector
        int32_t vals[4];

        //only add the SIMD stuff if SIMD is enabled
        #if GLGE_MATH_USE_SIMD
        //store the values for SIMD processing
        __m128i simd;
        #endif
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new ivec4
     * 
     */
    inline s_ivec4() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Construct a new ivec4
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline s_ivec4(int32_t _x, int32_t _y, int32_t _z, int32_t _w) : x(_x), y(_y), z(_z), w(_w) {}

    /**
     * @brief Construct a new ivec4
     * 
     * @param xyzw the value for the x, y, z and w axis as well as for the red, green, blue and alpha channel
     */
    inline s_ivec4(int32_t xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

    /**
     * @brief Construct a new ivec4
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param zw the value for the z and w axis / blue and alpha channel
     */
    inline s_ivec4(const ivec2& xy, const ivec2& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}

    /**
     * @brief Construct a new ivec4
     * 
     * @param xyz the value for the x, y and z axis / red, green and blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline s_ivec4(const ivec3& xyz, int32_t _w) : x(xyz.x), y(xyz.y), z(xyz.z), w(_w) {}
    
    /**
     * @brief Construct a new ivec4
     * 
     * @param _x the value for the x axis / red channel
     * @param yzw the values for the y, z and w axis / green, blue and alpha channel
     */
    inline s_ivec4(int32_t _x, const ivec3& yzw) : x(_x), y(yzw.x), z(yzw.y), w(yzw.z) {}

    //only implement the SIMD constructor if SIMD is enabled
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief Construct a new ivec4
     * 
     * @param _simd the values for the simd processing
     */
    inline s_ivec4(const __m128i& _simd) : simd(_simd) {}

    #endif

    //implement the SIMD operators
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief add two 4D int32_t vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_ivec4 the sum of both vectors
     */
    inline s_ivec4 operator+(const s_ivec4& u) const noexcept
    {return _mm_add_epi32(simd, u.simd);}

    /**
     * @brief subtract two 4D int32_t vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_ivec4 the difference of both vectors
     */
    inline s_ivec4 operator-(const s_ivec4& u) const noexcept
    {return _mm_sub_epi32(simd, u.simd);}

    #else //else, implement the not simd operators

    /**
     * @brief add two 4D int32_t vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_ivec4 the sum of both vectors
     */
    inline s_ivec4 operator+(const s_ivec4& u) const noexcept
    {return s_ivec4(x + u.x, y + u.y, z + u.z, w + u.w);}

    /**
     * @brief subtract two 4D int32_t vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_ivec4 the difference of both vectors
     */
    inline s_ivec4 operator-(const s_ivec4& u) const noexcept
    {return s_ivec4(x - u.x, y - u.y, z - u.z, w - u.w);}

    #endif

    /**
     * @brief multiply two 4D int32_t vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_ivec4 the product of both vectors
     */
    inline s_ivec4 operator*(const s_ivec4& u) const noexcept
    {return s_ivec4(x * u.x, y * u.y, z * u.z, w * u.w);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_ivec4 the fraction of both vectors
     */
    inline s_ivec4 operator/(const s_ivec4& u) const noexcept
    {return s_ivec4(x / u.x, y / u.y, z / u.z, w / u.w);}

    /**
     * @brief negate a 4D int32_t vector
     * 
     * @return s_ivec4 the negated vector
     */
    inline s_ivec4 operator-(void)  const noexcept
    {return s_ivec4(-x,-y,-z,-w);}

    /**
     * @brief print a 4D vector into an output stream
     * 
     * @param os the output output stream to fill
     * @param u the 4D int32_t vector to put into the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<<(std::ostream& os, const s_ivec4& u) noexcept
    {return os << "(" << u.x << ", " << u.y << ", " << u.z << ", " << u.w << ")";}

    #endif

} ivec4;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D int32_t vectors
 * 
 * @param v the first int32_t vector
 * @param u the second int32_t vector
 * @return const int32_t the dot product of both vectors
 */
inline int32_t dot(const ivec4& v, const ivec4& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;}

#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 4D int32_t vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return ivec4 the sum of both vectors
 */
ivec4 ivec4_add(ivec4 v, ivec4 u);

/**
 * @brief subtract two 4D int32_t vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return ivec4 the difference of both vectors
 */
ivec4 ivec4_subtract(ivec4 v, ivec4 u);

/**
 * @brief negate a 4D vector
 * 
 * @param v the vector to negate
 * @return ivec4 the negated vector
 */
ivec4 ivec4_negate(ivec4 v);

/**
 * @brief multiply two 4D int32_t vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return ivec4 the product of two vectors
 */
ivec4 ivec4_multiply(ivec4 v, ivec4 u);

/**
 * @brief divide two 4D int32_t vectors
 * 
 * @param v the 4D vector to use as nominator
 * @param u the 4D vector to use as denominator
 * @return ivec4 the fraction of both vectors
 */
ivec4 ivec4_divide(ivec4 v, ivec4 u);

/**
 * @brief calculate the dot product of two 4D int32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return int32_t the dot product of two 4D int32_t vectors
 */
int32_t ivec4_dot(ivec4 v, ivec4 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif