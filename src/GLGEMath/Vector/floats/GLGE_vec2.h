/**
 * @file GLGE_vec2.h
 * @author DM8AT
 * @brief a simple 2D vector of floats for GLGE
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_FLOAT_VEC2_
#define _GLGE_FLOAT_VEC2_

//include the common functoins
#include "../../GLGE_Common.h"
//SIMD is not worth it for small vectors (2D vectors). They are actually slower since only 128 bit vectors
//can be used as floats, which both wasts RAM and increases the amount to add

//for C++ add the iostream library for print operators
#if __cplusplus
#include <iostream>
#endif

/**
 * @brief store a simple 2D vector
 */
typedef struct s_vec2 {

    /**
     * @brief store all the data for a 2D vector
     */
    union {
        //store the values for a position
        struct {
            float x;
            float y;
        };
        //store the values like for a color
        struct {
            float r;
            float g;
        };
        //store the values as an array
        float vals[2];
    };

    //only add element functions for C++
    #if __cplusplus

    /**
     * @brief Construct a new vec2
     * 
     * Set everything to 0
     */
    inline constexpr s_vec2() : x(0), y(0) {}

    /**
     * @brief Construct a new vec2
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     */
    inline constexpr s_vec2(float _x, float _y) : x(_x), y(_y) {}

    /**
     * @brief Construct a new vec2
     * 
     * @param _xy the value for both axis / channels
     */
    inline constexpr s_vec2(float _xy) : x(_xy), y(_xy) {}

    /**
     * @brief Construct a new vec2
     * 
     * @param _val a float array with at least 2 elements
     */
    inline constexpr s_vec2(float _val[2]) : vals{_val[0], _val[1]} {}

    /**
     * @brief add two vectors together
     * 
     * @param u a constant reference to the other element to add
     * @return s_vec2 the sum of both vectors
     */
    inline constexpr s_vec2 operator+(const s_vec2& u) const noexcept
    {return s_vec2(x + u.x, y + u.y);}

    /**
     * @brief add another vector to this vector
     * 
     * @param u the vector to add to this vector
     */
    inline constexpr void operator+=(const s_vec2& u) noexcept
    {x += u.x; y += u.y;}

    /**
     * @brief subtract two vectors from another
     * 
     * @param u the vector to subtract from this vector
     * @return s_vec2 the difference of both vectors
     */
    inline constexpr s_vec2 operator-(const s_vec2& u) const noexcept
    {return s_vec2(x - u.x, y - u.y);}

    /**
     * @brief subtract another vector from this vector
     * 
     * @param u the vector to subtract from this vector
     */
    inline constexpr void operator-=(const s_vec2& u) noexcept
    {x -= u.x; y -= u.y;}

    /**
     * @brief negate a vector
     * 
     * @return s_vec2 the negated vector
     */
    inline constexpr s_vec2 operator-(void) const noexcept
    {return s_vec2(-x, -y);}

    /**
     * @brief multiply two vectors per-element together 
     * 
     * @param u the vector to multiply to this vector
     * @return s_vec2 the product of both vectors
     */
    inline constexpr s_vec2 operator*(const s_vec2& u) const noexcept
    {return s_vec2(x * u.x, y * u.y);}

    /**
     * @brief scale this vector by another vector
     * 
     * @param u the vector to scale with
     */
    inline constexpr void operator*=(const s_vec2& u) noexcept
    {x *= u.x; y *= u.y;}

    /**
     * @brief divide two vectors per-element
     * 
     * @param u the vector to use as denominator
     * @return s_vec2 the fraction of both vectors
     */
    inline constexpr s_vec2 operator/(const s_vec2& u) const noexcept
    {return s_vec2(x / u.x, y / u.y);}

    /**
     * @brief scale down this vector by another vector
     * 
     * @param u the vector to scale down with
     */
    inline constexpr void operator/=(const s_vec2& u) noexcept
    {x /= u.x; y /= u.y;}

    /**
     * @brief print the vector to an output stream
     * 
     * @param os the output stream to fill
     * @param v the vector to print to the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<< (std::ostream& os, const s_vec2& v) noexcept
    {return os << "(" << v.x << ", " << v.y << ")";}

    #endif

} vec2;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D float vectors
 * 
 * @param v the first float vector
 * @param u the second float vector
 * @return const float the dot product of both vectors
 */
inline constexpr float dot(const vec2& v, const vec2& u) noexcept {return v.x * u.x + v.y * u.y;}

/**
 * @brief calculate the length of a 2D vector
 * 
 * @param v the vector to calculate the length of
 * @return constexpr float the length of the 2D vector
 */
inline constexpr float length(const vec2& v) noexcept {return glge::sqrt(v.x*v.x + v.y * v.y);}

/**
 * @brief get a vector that points in the same direction as the input but has a length of 1
 * 
 * @param v the vector to normalized
 * @return constexpr vec2 a vector with length 1 that points in the direction of the inputted vector
 */
inline constexpr vec2 normalize(const vec2& v) noexcept {return v / length(v);}

#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 2D float vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return vec2 the sum of both vectors
 */
vec2 vec2_add(vec2 v, vec2 u);

/**
 * @brief subtract two 2D float vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return vec2 the difference of both vectors
 */
vec2 vec2_subtract(vec2 v, vec2 u);

/**
 * @brief negate a 2D vector
 * 
 * @param v the vector to negate
 * @return vec2 the negated vector
 */
vec2 vec2_negate(vec2 v);

/**
 * @brief multiply two 2D float vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return vec2 the product of two vectors
 */
vec2 vec2_multiply(vec2 v, vec2 u);

/**
 * @brief divide two 2D float vectors
 * 
 * @param v the 2D vector to use as nominator
 * @param u the 2D vector to use as denominator
 * @return vec2 the fraction of both vectors
 */
vec2 vec2_divide(vec2 v, vec2 u);

/**
 * @brief calculate the dot product of two 2D float vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return float the dot product of two 2D float vectors
 */
float vec2_dot(vec2 v, vec2 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif