/**
 * @file GLGE_dvec3.h
 * @author DM8AT
 * @brief define an interface for 3D double vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_double_dvec3_
#define _GLGE_double_dvec3_

//include the 2D vector for upcasting
#include "GLGE_dvec2.h"

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
 * @brief store a 3D vector of doubles
 */
typedef struct s_dvec3 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            double x;
            double y;
            double z;
        };
        //store the values for colors
        struct {
            double r;
            double g;
            double b;
        };
        //store the values as a double vector
        double vals[3];

        //only add the SIMD stuff if SIMD is enabled
        #if GLGE_MATH_USE_SIMD
        //else, use SSE
        struct {
            __m128d lower;
            double upper;
        };
        #endif
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new dvec3
     * 
     */
    inline constexpr s_dvec3() : x(0), y(0), z(0) {}

    /**
     * @brief Construct a new dvec3
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     */
    inline constexpr s_dvec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    /**
     * @brief Construct a new dvec3
     * 
     * @param xyz the value for the x, y and z axis as well as for the red, green and blue channel
     */
    inline constexpr s_dvec3(double xyz) : x(xyz), y(xyz), z(xyz) {}

    /**
     * @brief Construct a new dvec3
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param _z the value for the z axis / blue channel
     */
    inline constexpr s_dvec3(const dvec2& xy, double _z) : x(xy.x), y(xy.y), z(_z) {}

    /**
     * @brief Construct a new dvec3
     * 
     * @param _x the value for the x axis / red channel
     * @param yz the value for the y and z axis / green and blue channel
     */
    inline constexpr s_dvec3(double _x, const dvec2& yz) : x(_x), y(yz.x), z(yz.y) {}

    //only implement the SIMD constructor if SIMD is enabled
    #if GLGE_MATH_USE_SIMD

        /**
         * @brief Construct a new dvec3
         * 
         * @param _lower the value for the lower two elements
         * @param _upper the value for the upper element
         */
        inline constexpr s_dvec3(const __m128d& _lower, double _upper) : lower(_lower), upper(_upper) {}

    #endif

    //implement the SIMD operators
    #if GLGE_MATH_USE_SIMD

    /**
     * @brief add two 3D double vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_dvec3 the sum of both vectors
     */
    inline s_dvec3 operator+(const s_dvec3& u) const noexcept
    {return s_dvec3(_mm_add_pd(lower, u.lower), upper + u.upper);}

    /**
     * @brief subtract two 3D double vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_dvec3 the difference of both vectors
     */
    inline s_dvec3 operator-(const s_dvec3& u) const noexcept
    {return s_dvec3(_mm_sub_pd(lower, u.lower), upper - u.upper);}

    /**
     * @brief multiply two 3D double vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_dvec3 the product of both vectors
     */
    inline s_dvec3 operator*(const s_dvec3& u) const noexcept
    {return s_dvec3(_mm_mul_pd(lower, u.lower), upper * u.upper);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_dvec3 the fraction of both vectors
     */
    inline s_dvec3 operator/(const s_dvec3& u) const noexcept
    {return s_dvec3(_mm_div_pd(lower, u.lower), upper / u.upper);}

    #else //else, implement the not simd operators

    /**
     * @brief add two 3D double vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_dvec3 the sum of both vectors
     */
    inline constexpr s_dvec3 operator+(const s_dvec3& u) const noexcept
    {return s_dvec3(x + u.x, y + u.y, z + u.z);}

    /**
     * @brief subtract two 3D double vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_dvec3 the difference of both vectors
     */
    inline constexpr s_dvec3 operator-(const s_dvec3& u) const noexcept
    {return s_dvec3(x - u.x, y - u.y, z - u.z);}

    /**
     * @brief multiply two 3D double vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_dvec3 the product of both vectors
     */
    inline constexpr s_dvec3 operator*(const s_dvec3& u) const noexcept
    {return s_dvec3(x * u.x, y * u.y, z * u.z);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_dvec3 the fraction of both vectors
     */
    inline constexpr s_dvec3 operator/(const s_dvec3& u) const noexcept
    {return s_dvec3(x / u.x, y / u.y, z / u.z);}

    #endif

    /**
     * @brief negate a 3D double vector
     * 
     * @return s_dvec3 the negated vector
     */
    inline constexpr s_dvec3 operator-(void)  const noexcept
    {return s_dvec3(-x,-y,-z);}

    #endif

} dvec3;

/**
 * @brief add two 3D double vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return dvec3 the sum of both vectors
 */
dvec3 dvec3_add(dvec3 v, dvec3 u);

/**
 * @brief subtract two 3D double vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return dvec3 the difference of both vectors
 */
dvec3 dvec3_subtract(dvec3 v, dvec3 u);

/**
 * @brief negate a 3D vector
 * 
 * @param v the vector to negate
 * @return dvec3 the negated vector
 */
dvec3 dvec3_negate(dvec3 v);

/**
 * @brief multiply two 3D double vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return dvec3 the product of two vectors
 */
dvec3 dvec3_multiply(dvec3 v, dvec3 u);

/**
 * @brief divide two 3D double vectors
 * 
 * @param v the 3D vector to use as nominator
 * @param u the 3D vector to use as denominator
 * @return dvec3 the fraction of both vectors
 */
dvec3 dvec3_divide(dvec3 v, dvec3 u);

/**
 * @brief calculate the dot product of two 3D double vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return double the dot product of two 3D double vectors
 */
double dvec3_dot(dvec3 v, dvec3 u);

/**
 * @brief calculate the cross product of two 3D double vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return dvec3 a vector perpendicular to the inputted vectors (or (0,0,0) if both vectors are congruential)
 */
dvec3 dvec3_cross(dvec3 v, dvec3 u);

//end a potential C section and add the C++ specific functions
#if __cplusplus
}

/**
 * @brief print a 3D vector into an output stream
 * 
 * @param os the output output stream to fill
 * @param u the 3D double vector to put into the output stream
 * @return std::ostream& the filled output stream
 */
inline std::ostream& operator<<(std::ostream& os, const s_dvec3& u) noexcept
{return os << "(" << u.x << ", " << u.y << ", " << u.z << ")";}

/**
 * @brief calculate the dot product of two 2D double vectors
 * 
 * @param v the first double vector
 * @param u the second double vector
 * @return const double the dot product of both vectors
 */
inline constexpr double dot(const dvec3& v, const dvec3& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z;}

/**
 * @brief calculate the cross product between two 3D vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return const dvec3 the cross product (vector product) of both vectors
 */
inline constexpr dvec3 cross(const dvec3& v, const dvec3& u) noexcept {return dvec3(v.y*u.z - v.z*u.y, v.x*u.z - v.z*u.x, v.x*u.y - v.y*u.x);}

/**
 * @brief calculate the length of a 3D double vector
 * 
 * @param v a constant reference to the vector to calculate the length of
 * @return constexpr float the length of the vector
 */
inline float length(const dvec3& v) noexcept {return glge::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);}

/**
 * @brief calculate a vector that points in the same direction 
 * 
 * @param v a vector to normalize
 * @return vec3 a vector pointing in the same direction as the input but with a length of 1
 */
inline dvec3 normalize(const dvec3& v) noexcept {return v / length(v);}

#endif

#endif