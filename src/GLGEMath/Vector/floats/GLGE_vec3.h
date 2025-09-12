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

//intrinsics are not available for 3D float vectors because no intrinsic type fits to the size of 3D vectors
//loading to the intrinsics for each operation takes too much time

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
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new vec3
     * 
     */
    inline constexpr s_vec3() : x(0), y(0), z(0) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     */
    inline constexpr s_vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param xyz the value for the x, y and z axis as well as for the red, green and blue channel
     */
    inline constexpr s_vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param _z the value for the z axis / blue channel
     */
    inline constexpr s_vec3(const vec2& xy, float _z) : x(xy.x), y(xy.y), z(_z) {}

    /**
     * @brief Construct a new vec3
     * 
     * @param _x the value for the x axis / red channel
     * @param yz the value for the y and z axis / green and blue channel
     */
    inline constexpr s_vec3(float _x, const vec2& yz) : x(_x), y(yz.x), z(yz.y) {}

    /**
     * @brief add two 3D float vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_vec3 the sum of both vectors
     */
    inline constexpr s_vec3 operator+(const s_vec3& u) const noexcept
    {return s_vec3(x + u.x, y + u.y, z + u.z);}

    /**
     * @brief add another vector to this one
     * 
     * @param u the vector to add to this one
     */
    inline constexpr void operator+=(const s_vec3& u) noexcept
    {x += u.x; y += u.y; z += u.z;}

    /**
     * @brief subtract two 3D float vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_vec3 the difference of both vectors
     */
    inline constexpr s_vec3 operator-(const s_vec3& u) const noexcept
    {return s_vec3(x - u.x, y - u.y, z - u.z);}

    /**
     * @brief subtract another vector from this one
     * 
     * @param u the vector to subtract from this one
     */
    inline constexpr void operator-=(const s_vec3& u) noexcept
    {x -= u.x; y -= u.y; z -= u.z;}

    /**
     * @brief negate this vector
     * 
     * @return constexpr s_vec3 the negated vector (flipped the signs of all elements)
     */
    inline constexpr s_vec3 operator-(void) const noexcept
    {return s_vec3(-x, -y, -z);}

    /**
     * @brief multiply two 3D float vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_vec3 the product of both vectors
     */
    inline constexpr s_vec3 operator*(const s_vec3& u) const noexcept
    {return s_vec3(x * u.x, y * u.y, z * u.z);}

    /**
     * @brief scale this vector by another vector
     * 
     * @param u the vector to scale this one with
     */
    inline constexpr void operator*=(const s_vec3& u) noexcept
    {x *= u.x; y *= u.y; z *= u.z;}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_vec3 the fraction of both vectors
     */
    inline constexpr s_vec3 operator/(const s_vec3& u) const noexcept
    {return s_vec3(x / u.x, y / u.y, z / u.z);}

    /**
     * @brief scale down this vector by another vector
     * 
     * @param u the vector to scale down this one with
     */
    inline constexpr void operator/=(const s_vec3& u) noexcept
    {x /= u.x; y /= u.y; z /= u.z;}

    #endif

} vec3;

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

//end a potential C section and add the C++ specific functions
#if __cplusplus
}

/**
 * @brief print a 3D vector into an output stream
 * 
 * @param os the output output stream to fill
 * @param u the 3D float vector to put into the output stream
 * @return std::ostream& the filled output stream
 */
inline std::ostream& operator<<(std::ostream& os, const s_vec3& u) noexcept
{return os << "(" << u.x << ", " << u.y << ", " << u.z << ")";}

/**
 * @brief calculate the dot product of two 2D float vectors
 * 
 * @param v the first float vector
 * @param u the second float vector
 * @return const float the dot product of both vectors
 */
inline constexpr float dot(const vec3& v, const vec3& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z;}

/**
 * @brief calculate the cross product between two 3D vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return const vec3 the cross product (vector product) of both vectors
 */
inline constexpr vec3 cross(const vec3& v, const vec3& u) noexcept {return vec3(v.y*u.z - v.z*u.y, v.x*u.z - v.z*u.x, v.x*u.y - v.y*u.x);}

/**
 * @brief calculate the length of a 3D vector
 * 
 * @param v a constant reference to the vector to calculate the length of
 * @return constexpr float the length of the vector
 */
inline float length(const vec3& v) noexcept {return glge::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);}

/**
 * @brief calculate a vector that points in the same direction 
 * 
 * @param v a vector to normalize
 * @return vec3 a vector pointing in the same direction as the input but with a length of 1
 */
inline vec3 normalize(const vec3& v) noexcept {return v / length(v);}

#endif

#endif