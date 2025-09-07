/**
 * @file GLGE_vec3.h
 * @author DM8AT
 * @brief define an interface for 3D float vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_FLOAT_VEC3_
#define _GLGE_FLOAT_VEC3_

//include the 2D vector for upcasting
#include "GLGE_vec2.h"

//if SIMD is requested, include SIMD intrinsics
#include "../../GLGEMath_Settings.h"
#if GLGE_MATH_USE_SIMD
#include <xmmintrin.h>
#endif

/**
 * @brief store a 3D vector of floats
 */
typedef struct s_vec3 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            float x;
            float y;
            float z;
        };
        //store the values for colors
        struct {
            float r;
            float g;
            float b;
        };
        //store the values as a float vector
        float vals[3];

        //only add the SIMD stuff if SIMD is enabled
        #if GLGE_MATH_USE_SIMD
        //store the values for SIMD processing
        __m128 simd;
        #endif
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new vec3
     * 
     */
    s_vec3() : x(0), y(0), z(0) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     */
    s_vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param xyz the value for the x, y and z axis as well as for the red, green and blue channel
     */
    s_vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param _z the value for the z axis / blue channel
     */
    s_vec3(const vec2& xy, float _z) : x(xy.x), y(xy.y), z(_z) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param _x the value for the x axis / red channel
     * @param yz the value for the y and z axis / green and blue channel
     */
    s_vec3(float _x, const vec2& yz) : x(_x), y(yz.x), z(yz.y) {}

    //only implement the SIMD constructor if SIMD is enabled
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief Construct a new vec3
     * 
     * @param _simd the values for the simd processing
     */
    s_vec3(const __m128& _simd) : simd(_simd) {}

    #endif

    //implement the SIMD operators
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief add two 3D float vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_vec3 the sum of both vectors
     */
    inline s_vec3 operator+(const s_vec3& u) const noexcept
    {return _mm_add_ps(simd, u.simd);}

    /**
     * @brief subtract two 3D float vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_vec3 the difference of both vectors
     */
    inline s_vec3 operator-(const s_vec3& u) const noexcept
    {return _mm_sub_ps(simd, u.simd);}

    /**
     * @brief multiply two 3D float vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_vec3 the product of both vectors
     */
    inline s_vec3 operator*(const s_vec3& u) const noexcept
    {return _mm_mul_ps(simd, u.simd);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_vec3 the fraction of both vectors
     */
    inline s_vec3 operator/(const s_vec3& u) const noexcept
    {return _mm_div_ps(simd, u.simd);}

    #else //else, implement the not simd operators

    /**
     * @brief add two 3D float vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_vec3 the sum of both vectors
     */
    inline s_vec3 operator+(const s_vec3& u) const noexcept
    {return s_vec3(x + u.x, y + u.y, z + u.z);}

    /**
     * @brief subtract two 3D float vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_vec3 the difference of both vectors
     */
    inline s_vec3 operator-(const s_vec3& u) const noexcept
    {return s_vec3(x - u.x, y - u.y, z - u.z);}

    /**
     * @brief multiply two 3D float vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_vec3 the product of both vectors
     */
    inline s_vec3 operator*(const s_vec3& u) const noexcept
    {return s_vec3(x * u.x, y * u.y, z * u.z);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_vec3 the fraction of both vectors
     */
    inline s_vec3 operator/(const s_vec3& u) const noexcept
    {return s_vec3(x / u.x, y / u.y, z / u.z);}

    #endif

    /**
     * @brief negate a 3D float vector
     * 
     * @return s_vec3 the negated vector
     */
    inline s_vec3 operator-(void)  const noexcept
    {return s_vec3(-x,-y,-z);}

    /**
     * @brief print a 3D vector into an output stream
     * 
     * @param os the output output stream to fill
     * @param u the 3D float vector to put into the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<<(std::ostream& os, const s_vec3& u) noexcept
    {return os << "(" << u.x << ", " << u.y << ", " << u.z << ")";}

    #endif

} vec3;

#endif