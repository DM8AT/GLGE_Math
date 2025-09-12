/**
 * @file GLGE_vec4.h
 * @author DM8AT
 * @brief define an interface for 4D float vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_FLOAT_vec4_
#define _GLGE_FLOAT_vec4_

//include the 2D vector for upcasting
#include "GLGE_vec2.h"
//include the 3D vector for upcasting
#include "GLGE_vec3.h"

//if SIMD is requested, include SIMD intrinsics
#include "../../GLGEMath_Settings.h"
#if GLGE_MATH_USE_SIMD
#include <xmmintrin.h>
#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief store a 4D vector of floats
 */
typedef struct s_vec4 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        //store the values for colors
        struct {
            float r;
            float g;
            float b;
            float a;
        };
        //store the values as a float vector
        float vals[4];

        //only add the SIMD stuff if SIMD is enabled
        #if GLGE_MATH_USE_SIMD
        //store the values for SIMD processing
        __m128 simd;
        #endif
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new vec4
     * 
     */
    inline constexpr s_vec4() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Construct a new vec4
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline constexpr s_vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

    /**
     * @brief Construct a new vec4
     * 
     * @param xyzw the value for the x, y, z and w axis as well as for the red, green, blue and alpha channel
     */
    inline constexpr s_vec4(float xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

    /**
     * @brief Construct a new vec4
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param zw the value for the z and w axis / blue and alpha channel
     */
    inline constexpr s_vec4(const vec2& xy, const vec2& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}

    /**
     * @brief Construct a new vec4
     * 
     * @param xyz the value for the x, y and z axis / red, green and blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline constexpr s_vec4(const vec3& xyz, float _w) : x(xyz.x), y(xyz.y), z(xyz.z), w(_w) {}
    
    /**
     * @brief Construct a new vec4
     * 
     * @param _x the value for the x axis / red channel
     * @param yzw the values for the y, z and w axis / green, blue and alpha channel
     */
    inline constexpr s_vec4(float _x, const vec3& yzw) : x(_x), y(yzw.x), z(yzw.y), w(yzw.z) {}

    //only implement the SIMD constructor if SIMD is enabled
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief Construct a new vec4
     * 
     * @param _simd the values for the simd processing
     */
    inline constexpr s_vec4(const __m128& _simd) : simd(_simd) {}

    #endif

    //implement the SIMD operators
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief add two 4D float vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_vec4 the sum of both vectors
     */
    inline s_vec4 operator+(const s_vec4& u) const noexcept
    {return _mm_add_ps(simd, u.simd);}

    /**
     * @brief subtract two 4D float vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_vec4 the difference of both vectors
     */
    inline s_vec4 operator-(const s_vec4& u) const noexcept
    {return _mm_sub_ps(simd, u.simd);}

    /**
     * @brief multiply two 4D float vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_vec4 the product of both vectors
     */
    inline s_vec4 operator*(const s_vec4& u) const noexcept
    {return _mm_mul_ps(simd, u.simd);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_vec4 the fraction of both vectors
     */
    inline s_vec4 operator/(const s_vec4& u) const noexcept
    {return _mm_div_ps(simd, u.simd);}

    #else //else, implement the not simd operators

    /**
     * @brief add two 4D float vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_vec4 the sum of both vectors
     */
    inline constexpr s_vec4 operator+(const s_vec4& u) const noexcept
    {return s_vec4(x + u.x, y + u.y, z + u.z, w + u.w);}

    /**
     * @brief subtract two 4D float vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_vec4 the difference of both vectors
     */
    inline constexpr s_vec4 operator-(const s_vec4& u) const noexcept
    {return s_vec4(x - u.x, y - u.y, z - u.z, w - u.w);}

    /**
     * @brief multiply two 4D float vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_vec4 the product of both vectors
     */
    inline constexpr s_vec4 operator*(const s_vec4& u) const noexcept
    {return s_vec4(x * u.x, y * u.y, z * u.z, w * u.w);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_vec4 the fraction of both vectors
     */
    inline constexpr s_vec4 operator/(const s_vec4& u) const noexcept
    {return s_vec4(x / u.x, y / u.y, z / u.z, w / u.w);}

    #endif

    /**
     * @brief negate a 4D float vector
     * 
     * @return s_vec4 the negated vector
     */
    inline constexpr s_vec4 operator-(void)  const noexcept
    {return s_vec4(-x,-y,-z,-w);}

    /**
     * @brief print a 4D vector into an output stream
     * 
     * @param os the output output stream to fill
     * @param u the 4D float vector to put into the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<<(std::ostream& os, const s_vec4& u) noexcept
    {return os << "(" << u.x << ", " << u.y << ", " << u.z << ", " << u.w << ")";}

    #endif

} vec4;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D float vectors
 * 
 * @param v the first float vector
 * @param u the second float vector
 * @return const float the dot product of both vectors
 */
inline constexpr float dot(const vec4& v, const vec4& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;}

/**
 * @brief calculate the length of a 4D vector
 * 
 * @param v a constant reference to the vector to calculate the length of
 * @return constexpr float the length of the vector
 */
inline float length(const vec4& v) noexcept {return glge::sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);}

/**
 * @brief calculate a vector that points in the same direction 
 * 
 * @param v a vector to normalize
 * @return vec4 a vector pointing in the same direction as the input but with a length of 1
 */
inline vec4 normalize(const vec4& v) noexcept {return v / length(v);}

#endif

/**
 * @brief add two 4D float vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return vec4 the sum of both vectors
 */
vec4 vec4_add(vec4 v, vec4 u);

/**
 * @brief subtract two 4D float vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return vec4 the difference of both vectors
 */
vec4 vec4_subtract(vec4 v, vec4 u);

/**
 * @brief negate a 4D vector
 * 
 * @param v the vector to negate
 * @return vec4 the negated vector
 */
vec4 vec4_negate(vec4 v);

/**
 * @brief multiply two 4D float vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return vec4 the product of two vectors
 */
vec4 vec4_multiply(vec4 v, vec4 u);

/**
 * @brief divide two 4D float vectors
 * 
 * @param v the 4D vector to use as nominator
 * @param u the 4D vector to use as denominator
 * @return vec4 the fraction of both vectors
 */
vec4 vec4_divide(vec4 v, vec4 u);

/**
 * @brief calculate the dot product of two 4D float vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return float the dot product of two 4D float vectors
 */
float vec4_dot(vec4 v, vec4 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif