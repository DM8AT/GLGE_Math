/**
 * @file GLGE_ivec2.h
 * @author DM8AT
 * @brief a simple 2D vector of int32_ts for GLGE
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_int32_t_ivec2_
#define _GLGE_int32_t_ivec2_

//include the common functionality
#include "../../GLGE_Common.h"
//SIMD is not worth it for small vectors (2D vectors). They are actually slower since only 128 bit vectors
//can be used as int32_ts, which both wasts RAM and increases the amount to add

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
typedef struct s_ivec2 {

    /**
     * @brief store all the data for a 2D vector
     */
    union {
        //store the values for a position
        struct {
            int32_t x;
            int32_t y;
        };
        //store the values like for a color
        struct {
            int32_t r;
            int32_t g;
        };
        //store the values as an array
        int32_t vals[2];
    };

    //only add element functions for C++
    #if __cplusplus

    /**
     * @brief Construct a new ivec2
     * 
     * Set everything to 0
     */
    constexpr s_ivec2() : x(0), y(0) {}

    /**
     * @brief Construct a new ivec2
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     */
    constexpr s_ivec2(int32_t _x, int32_t _y) : x(_x), y(_y) {}

    /**
     * @brief Construct a new ivec2
     * 
     * @param _xy the value for both axis / channels
     */
    constexpr s_ivec2(int32_t _xy) : x(_xy), y(_xy) {}

    /**
     * @brief Construct a new ivec2
     * 
     * @param _val a int32_t array with at least 2 elements
     */
    constexpr s_ivec2(int32_t _val[2]) : vals{_val[0], _val[1]} {}

    /**
     * @brief add two vectors together
     * 
     * @param u a constant reference to the other element to add
     * @return s_ivec2 the sum of both vectors
     */
    inline constexpr s_ivec2 operator+(const s_ivec2& u) const noexcept
    {return s_ivec2(x + u.x, y + u.y);}

    /**
     * @brief subtract two vectors from another
     * 
     * @param u the vector to subtract from this vector
     * @return s_ivec2 the difference of both vectors
     */
    inline constexpr s_ivec2 operator-(const s_ivec2& u) const noexcept
    {return s_ivec2(x - u.x, y - u.y);}

    /**
     * @brief negate a vector
     * 
     * @return s_ivec2 the negated vector
     */
    inline constexpr s_ivec2 operator-(void) const noexcept
    {return s_ivec2(-x, -y);}

    /**
     * @brief multiply two vectors per-element together 
     * 
     * @param u the vector to multiply to this vector
     * @return s_ivec2 the product of both vectors
     */
    inline constexpr s_ivec2 operator*(const s_ivec2& u) const noexcept
    {return s_ivec2(x * u.x, y * u.y);}

    /**
     * @brief divide two vectors per-element
     * 
     * @param u the vector to use as denominator
     * @return s_ivec2 the fraction of both vectors
     */
    inline constexpr s_ivec2 operator/(const s_ivec2& u) const noexcept
    {return s_ivec2(x / u.x, y / u.y);}

    #endif

} ivec2;

/**
 * @brief add two 2D int32_t vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return ivec2 the sum of both vectors
 */
ivec2 ivec2_add(ivec2 v, ivec2 u);

/**
 * @brief subtract two 2D int32_t vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return ivec2 the difference of both vectors
 */
ivec2 ivec2_subtract(ivec2 v, ivec2 u);

/**
 * @brief negate a 2D vector
 * 
 * @param v the vector to negate
 * @return ivec2 the negated vector
 */
ivec2 ivec2_negate(ivec2 v);

/**
 * @brief multiply two 2D int32_t vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return ivec2 the product of two vectors
 */
ivec2 ivec2_multiply(ivec2 v, ivec2 u);

/**
 * @brief divide two 2D int32_t vectors
 * 
 * @param v the 2D vector to use as nominator
 * @param u the 2D vector to use as denominator
 * @return ivec2 the fraction of both vectors
 */
ivec2 ivec2_divide(ivec2 v, ivec2 u);

/**
 * @brief calculate the dot product of two 2D int32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return int32_t the dot product of two 2D int32_t vectors
 */
int32_t ivec2_dot(ivec2 v, ivec2 u);

//end a potential C section and add the C++ specific functions
#if __cplusplus
}

/**
 * @brief print the vector to an output stream
 * 
 * @param os the output stream to fill
 * @param v the vector to print to the output stream
 * @return std::ostream& the filled output stream
 */
inline std::ostream& operator<< (std::ostream& os, const s_ivec2& v) noexcept
{return os << "(" << v.x << ", " << v.y << ")";}

/**
 * @brief calculate the dot product of two 2D int32_t vectors
 * 
 * @param v the first int32_t vector
 * @param u the second int32_t vector
 * @return const int32_t the dot product of both vectors
 */
inline constexpr int32_t dot(const ivec2& v, const ivec2& u) noexcept {return v.x * u.x + v.y * u.y;}

/**
 * @brief calculate the length of a 3D vector
 * 
 * @param v a constant reference to the vector to calculate the length of
 * @return constexpr float the length of the vector
 */
inline float length(const ivec2& v) noexcept {return glge::sqrt((float)(v.x*v.x + v.y*v.y));}

/**
 * @brief calculate a vector that points in the same direction 
 * 
 * @param v a vector to normalize
 * @return vec3 a vector pointing in the same direction as the input but with a length of 1
 */
inline ivec2 normalize(const ivec2& v) noexcept {return v / (int32_t)length(v);}

#endif

#endif