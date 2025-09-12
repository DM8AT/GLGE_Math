/**
 * @file GLGE_uivec4.h
 * @author DM8AT
 * @brief define an interface for 4D uint32_t vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_uint32_t_uivec4_
#define _GLGE_uint32_t_uivec4_

//include the 2D vector for upcasting
#include "GLGE_uivec2.h"
//include the 3D vector for upcasting
#include "GLGE_uivec3.h"

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
 * @brief store a 4D vector of uint32_ts
 */
typedef struct s_uivec4 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            uint32_t x;
            uint32_t y;
            uint32_t z;
            uint32_t w;
        };
        //store the values for colors
        struct {
            uint32_t r;
            uint32_t g;
            uint32_t b;
            uint32_t a;
        };
        //store the values as a uint32_t vector
        uint32_t vals[4];

        //only add the SIMD stuff if SIMD is enabled
        #if GLGE_MATH_USE_SIMD
        //store the values for SIMD processing
        __m128i simd;
        #endif
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new uivec4
     * 
     */
    inline constexpr s_uivec4() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Construct a new uivec4
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline constexpr s_uivec4(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t _w) : x(_x), y(_y), z(_z), w(_w) {}

    /**
     * @brief Construct a new uivec4
     * 
     * @param xyzw the value for the x, y, z and w axis as well as for the red, green, blue and alpha channel
     */
    inline constexpr s_uivec4(uint32_t xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

    /**
     * @brief Construct a new uivec4
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param zw the value for the z and w axis / blue and alpha channel
     */
    inline constexpr s_uivec4(const uivec2& xy, const uivec2& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}

    /**
     * @brief Construct a new uivec4
     * 
     * @param xyz the value for the x, y and z axis / red, green and blue channel
     * @param _w the value for the w axis / alpha channel
     */
    inline constexpr s_uivec4(const uivec3& xyz, uint32_t _w) : x(xyz.x), y(xyz.y), z(xyz.z), w(_w) {}
    
    /**
     * @brief Construct a new uivec4
     * 
     * @param _x the value for the x axis / red channel
     * @param yzw the values for the y, z and w axis / green, blue and alpha channel
     */
    inline constexpr s_uivec4(uint32_t _x, const uivec3& yzw) : x(_x), y(yzw.x), z(yzw.y), w(yzw.z) {}

    //only implement the SIMD constructor if SIMD is enabled
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief Construct a new uivec4
     * 
     * @param _simd the values for the simd processing
     */
    inline constexpr s_uivec4(const __m128i& _simd) : simd(_simd) {}

    #endif

    //implement the SIMD operators
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief add two 4D uint32_t vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_uivec4 the sum of both vectors
     */
    inline s_uivec4 operator+(const s_uivec4& u) const noexcept
    {return _mm_add_epi32(simd, u.simd);}

    /**
     * @brief subtract two 4D uint32_t vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_uivec4 the difference of both vectors
     */
    inline s_uivec4 operator-(const s_uivec4& u) const noexcept
    {return _mm_sub_epi32(simd, u.simd);}

    #else //else, implement the not simd operators

    /**
     * @brief add two 4D uint32_t vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_uivec4 the sum of both vectors
     */
    inline constexpr s_uivec4 operator+(const s_uivec4& u) const noexcept
    {return s_uivec4(x + u.x, y + u.y, z + u.z, w + u.w);}

    /**
     * @brief subtract two 4D uint32_t vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_uivec4 the difference of both vectors
     */
    inline constexpr s_uivec4 operator-(const s_uivec4& u) const noexcept
    {return s_uivec4(x - u.x, y - u.y, z - u.z, w - u.w);}

    #endif

    /**
     * @brief multiply two 4D uint32_t vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_uivec4 the product of both vectors
     */
    inline constexpr s_uivec4 operator*(const s_uivec4& u) const noexcept
    {return s_uivec4(x * u.x, y * u.y, z * u.z, w * u.w);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_uivec4 the fraction of both vectors
     */
    inline constexpr s_uivec4 operator/(const s_uivec4& u) const noexcept
    {return s_uivec4(x / u.x, y / u.y, z / u.z, w / u.w);}

    /**
     * @brief negate a 4D uint32_t vector
     * 
     * @return s_uivec4 the negated vector
     */
    inline constexpr s_uivec4 operator-(void)  const noexcept
    {return s_uivec4(-x,-y,-z,-w);}

    #endif

} uivec4;

/**
 * @brief add two 4D uint32_t vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return uivec4 the sum of both vectors
 */
uivec4 uivec4_add(uivec4 v, uivec4 u);

/**
 * @brief subtract two 4D uint32_t vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return uivec4 the difference of both vectors
 */
uivec4 uivec4_subtract(uivec4 v, uivec4 u);

/**
 * @brief negate a 4D vector
 * 
 * @param v the vector to negate
 * @return uivec4 the negated vector
 */
uivec4 uivec4_negate(uivec4 v);

/**
 * @brief multiply two 4D uint32_t vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return uivec4 the product of two vectors
 */
uivec4 uivec4_multiply(uivec4 v, uivec4 u);

/**
 * @brief divide two 4D uint32_t vectors
 * 
 * @param v the 4D vector to use as nominator
 * @param u the 4D vector to use as denominator
 * @return uivec4 the fraction of both vectors
 */
uivec4 uivec4_divide(uivec4 v, uivec4 u);

/**
 * @brief calculate the dot product of two 4D uint32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return uint32_t the dot product of two 4D uint32_t vectors
 */
uint32_t uivec4_dot(uivec4 v, uivec4 u);

//end a potential C section and add the C++ specific functions
#if __cplusplus
}

/**
 * @brief print a 4D vector into an output stream
 * 
 * @param os the output output stream to fill
 * @param u the 4D uint32_t vector to put into the output stream
 * @return std::ostream& the filled output stream
 */
inline std::ostream& operator<<(std::ostream& os, const s_uivec4& u) noexcept
{return os << "(" << u.x << ", " << u.y << ", " << u.z << ", " << u.w << ")";}

/**
 * @brief calculate the dot product of two 2D uint32_t vectors
 * 
 * @param v the first uint32_t vector
 * @param u the second uint32_t vector
 * @return const uint32_t the dot product of both vectors
 */
inline constexpr uint32_t dot(const uivec4& v, const uivec4& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;}

/**
 * @brief calculate the length of a 3D vector
 * 
 * @param v a constant reference to the vector to calculate the length of
 * @return constexpr float the length of the vector
 */
inline float length(const uivec4& v) noexcept {return glge::sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);}

/**
 * @brief calculate a vector that points in the same direction 
 * 
 * @param v a vector to normalize
 * @return vec3 a vector pointing in the same direction as the input but with a length of 1
 */
inline uivec4 normalize(const uivec4& v) noexcept {return v / length(v);}

#endif

#endif