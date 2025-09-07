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
    inline s_vec3() : x(0), y(0), z(0) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     */
    inline s_vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param xyz the value for the x, y and z axis as well as for the red, green and blue channel
     */
    inline s_vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param _z the value for the z axis / blue channel
     */
    inline s_vec3(const vec2& xy, float _z) : x(xy.x), y(xy.y), z(_z) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param _x the value for the x axis / red channel
     * @param yz the value for the y and z axis / green and blue channel
     */
    inline s_vec3(float _x, const vec2& yz) : x(_x), y(yz.x), z(yz.y) {}

    //only implement the SIMD constructor if SIMD is enabled
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief Construct a new vec3
     * 
     * @param _simd the values for the simd processing
     */
    inline s_vec3(const __m128& _simd) : simd(_simd) {}

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

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D float vectors
 * 
 * @param v the first float vector
 * @param u the second float vector
 * @return const float the dot product of both vectors
 */
inline const float dot(const vec3& v, const vec3& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z;}

/**
 * @brief calculate the cross product between two 3D vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return const vec3 the cross product (vector product) of both vectors
 */
inline const vec3 cross(const vec3& v, const vec3& u) noexcept {return vec3(v.y*u.z - v.z*u.y, v.x*u.z - v.z*u.x, v.x*u.y - v.y*u.x);}

#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 3D float vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return vec3 the sum of both vectors
 */
vec3 vec3_add(vec3 v, vec3 u);

/**
 * @brief subtract two 3D float vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return vec3 the difference of both vectors
 */
vec3 vec3_subtract(vec3 v, vec3 u);

/**
 * @brief negate a 3D vector
 * 
 * @param v the vector to negate
 * @return vec3 the negated vector
 */
vec3 vec3_negate(vec3 v);

/**
 * @brief multiply two 3D float vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return vec3 the product of two vectors
 */
vec3 vec3_multiply(vec3 v, vec3 u);

/**
 * @brief divide two 3D float vectors
 * 
 * @param v the 3D vector to use as nominator
 * @param u the 3D vector to use as denominator
 * @return vec3 the fraction of both vectors
 */
vec3 vec3_divide(vec3 v, vec3 u);

/**
 * @brief calculate the dot product of two 3D float vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return float the dot product of two 3D float vectors
 */
float vec3_dot(vec3 v, vec3 u);

/**
 * @brief calculate the cross product of two 3D float vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return vec3 a vector perpendicular to the inputted vectors (or (0,0,0) if both vectors are congruential)
 */
vec3 vec3_cross(vec3 v, vec3 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif