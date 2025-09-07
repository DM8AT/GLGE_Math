/**
 * @file GLGE_uivec2.h
 * @author DM8AT
 * @brief a simple 2D vector of uint32_ts for GLGE
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_uint32_t_uivec2_
#define _GLGE_uint32_t_uivec2_

//include the settings
#include "../../GLGEMath_Settings.h"
//SIMD is not worth it for small vectors (2D vectors). They are actually slower since only 128 bit vectors
//can be used as uint32_ts, which both wasts RAM and increases the amount to add

//for C++ add the iostream library for print operators
#if __cplusplus
#include <iostream>
#endif

/**
 * @brief store a simple 2D vector
 */
typedef struct s_uivec2 {

    /**
     * @brief store all the data for a 2D vector
     */
    union {
        //store the values for a position
        struct {
            uint32_t x;
            uint32_t y;
        };
        //store the values like for a color
        struct {
            uint32_t r;
            uint32_t g;
        };
        //store the values as an array
        uint32_t vals[2];
    };

    //only add element functions for C++
    #if __cplusplus

    /**
     * @brief Construct a new uivec2
     * 
     * Set everything to 0
     */
    s_uivec2() : x(0), y(0) {}

    /**
     * @brief Construct a new uivec2
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     */
    s_uivec2(uint32_t _x, uint32_t _y) : x(_x), y(_y) {}

    /**
     * @brief Construct a new uivec2
     * 
     * @param _xy the value for both axis / channels
     */
    s_uivec2(uint32_t _xy) : x(_xy), y(_xy) {}

    /**
     * @brief Construct a new uivec2
     * 
     * @param _val a uint32_t array with at least 2 elements
     */
    s_uivec2(uint32_t _val[2]) : vals{_val[0], _val[1]} {}

    /**
     * @brief Destroy the uivec2
     */
    ~s_uivec2() {}

    /**
     * @brief add two vectors together
     * 
     * @param u a constant reference to the other element to add
     * @return s_uivec2 the sum of both vectors
     */
    inline s_uivec2 operator+(const s_uivec2& u) const noexcept
    {return s_uivec2(x + u.x, y + u.y);}

    /**
     * @brief subtract two vectors from another
     * 
     * @param u the vector to subtract from this vector
     * @return s_uivec2 the difference of both vectors
     */
    inline s_uivec2 operator-(const s_uivec2& u) const noexcept
    {return s_uivec2(x - u.x, y - u.y);}

    /**
     * @brief negate a vector
     * 
     * @return s_uivec2 the negated vector
     */
    inline s_uivec2 operator-(void) const noexcept
    {return s_uivec2(-x, -y);}

    /**
     * @brief multiply two vectors per-element together 
     * 
     * @param u the vector to multiply to this vector
     * @return s_uivec2 the product of both vectors
     */
    inline s_uivec2 operator*(const s_uivec2& u) const noexcept
    {return s_uivec2(x * u.x, y * u.y);}

    /**
     * @brief divide two vectors per-element
     * 
     * @param u the vector to use as denominator
     * @return s_uivec2 the fraction of both vectors
     */
    inline s_uivec2 operator/(const s_uivec2& u) const noexcept
    {return s_uivec2(x / u.x, y / u.y);}

    /**
     * @brief print the vector to an output stream
     * 
     * @param os the output stream to fill
     * @param v the vector to print to the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<< (std::ostream& os, const s_uivec2& v) noexcept
    {return os << "(" << v.x << ", " << v.y << ")";}

    #endif

} uivec2;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D uint32_t vectors
 * 
 * @param v the first uint32_t vector
 * @param u the second uint32_t vector
 * @return const uint32_t the dot product of both vectors
 */
inline const uint32_t dot(const uivec2& v, const uivec2& u) noexcept {return v.x * u.x + v.y * u.y;}

#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 2D uint32_t vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return uivec2 the sum of both vectors
 */
uivec2 uivec2_add(uivec2 v, uivec2 u);

/**
 * @brief subtract two 2D uint32_t vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return uivec2 the difference of both vectors
 */
uivec2 uivec2_subtract(uivec2 v, uivec2 u);

/**
 * @brief negate a 2D vector
 * 
 * @param v the vector to negate
 * @return uivec2 the negated vector
 */
uivec2 uivec2_negate(uivec2 v);

/**
 * @brief multiply two 2D uint32_t vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return uivec2 the product of two vectors
 */
uivec2 uivec2_multiply(uivec2 v, uivec2 u);

/**
 * @brief divide two 2D uint32_t vectors
 * 
 * @param v the 2D vector to use as nominator
 * @param u the 2D vector to use as denominator
 * @return uivec2 the fraction of both vectors
 */
uivec2 uivec2_divide(uivec2 v, uivec2 u);

/**
 * @brief calculate the dot product of two 2D uint32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return uint32_t the dot product of two 2D uint32_t vectors
 */
uint32_t uivec2_dot(uivec2 v, uivec2 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif