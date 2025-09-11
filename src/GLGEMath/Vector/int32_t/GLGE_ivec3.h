/**
 * @file GLGE_ivec3.h
 * @author DM8AT
 * @brief define an interface for 3D int32_t vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_int32_t_ivec3_
#define _GLGE_int32_t_ivec3_

//include the 2D vector for upcasting
#include "GLGE_ivec2.h"

//intrinsics are not available for 3D int32_t vectors because no intrinsic type fits to the size of 3D vectors
//loading to the intrinsics for each operation takes too much time

/**
 * @brief store a 3D vector of int32_ts
 */
typedef struct s_ivec3 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            int32_t x;
            int32_t y;
            int32_t z;
        };
        //store the values for colors
        struct {
            int32_t r;
            int32_t g;
            int32_t b;
        };
        //store the values as a int32_t vector
        int32_t vals[3];
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new ivec3
     * 
     */
    inline s_ivec3() : x(0), y(0), z(0) {}

    /**
     * @brief Construct a new ivec3
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     */
    inline s_ivec3(int32_t _x, int32_t _y, int32_t _z) : x(_x), y(_y), z(_z) {}

    /**
     * @brief Construct a new ivec3
     * 
     * @param xyz the value for the x, y and z axis as well as for the red, green and blue channel
     */
    inline s_ivec3(int32_t xyz) : x(xyz), y(xyz), z(xyz) {}

    /**
     * @brief Construct a new ivec3
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param _z the value for the z axis / blue channel
     */
    inline s_ivec3(const ivec2& xy, int32_t _z) : x(xy.x), y(xy.y), z(_z) {}

    /**
     * @brief Construct a new ivec3
     * 
     * @param _x the value for the x axis / red channel
     * @param yz the value for the y and z axis / green and blue channel
     */
    inline s_ivec3(int32_t _x, const ivec2& yz) : x(_x), y(yz.x), z(yz.y) {}

    /**
     * @brief add two 3D int32_t vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_ivec3 the sum of both vectors
     */
    inline s_ivec3 operator+(const s_ivec3& u) const noexcept
    {return s_ivec3(x + u.x, y + u.y, z + u.z);}

    /**
     * @brief subtract two 3D int32_t vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_ivec3 the difference of both vectors
     */
    inline s_ivec3 operator-(const s_ivec3& u) const noexcept
    {return s_ivec3(x - u.x, y - u.y, z - u.z);}

    /**
     * @brief multiply two 3D int32_t vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_ivec3 the product of both vectors
     */
    inline s_ivec3 operator*(const s_ivec3& u) const noexcept
    {return s_ivec3(x * u.x, y * u.y, z * u.z);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_ivec3 the fraction of both vectors
     */
    inline s_ivec3 operator/(const s_ivec3& u) const noexcept
    {return s_ivec3(x / u.x, y / u.y, z / u.z);}

    /**
     * @brief negate a 3D int32_t vector
     * 
     * @return s_ivec3 the negated vector
     */
    inline s_ivec3 operator-(void)  const noexcept
    {return s_ivec3(-x,-y,-z);}

    /**
     * @brief print a 3D vector into an output stream
     * 
     * @param os the output output stream to fill
     * @param u the 3D int32_t vector to put into the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<<(std::ostream& os, const s_ivec3& u) noexcept
    {return os << "(" << u.x << ", " << u.y << ", " << u.z << ")";}

    #endif

} ivec3;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D int32_t vectors
 * 
 * @param v the first int32_t vector
 * @param u the second int32_t vector
 * @return const int32_t the dot product of both vectors
 */
inline int32_t dot(const ivec3& v, const ivec3& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z;}

/**
 * @brief calculate the cross product between two 3D vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return const ivec3 the cross product (vector product) of both vectors
 */
inline ivec3 cross(const ivec3& v, const ivec3& u) noexcept {return ivec3(v.y*u.z - v.z*u.y, v.x*u.z - v.z*u.x, v.x*u.y - v.y*u.x);}

#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 3D int32_t vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return ivec3 the sum of both vectors
 */
ivec3 ivec3_add(ivec3 v, ivec3 u);

/**
 * @brief subtract two 3D int32_t vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return ivec3 the difference of both vectors
 */
ivec3 ivec3_subtract(ivec3 v, ivec3 u);

/**
 * @brief negate a 3D vector
 * 
 * @param v the vector to negate
 * @return ivec3 the negated vector
 */
ivec3 ivec3_negate(ivec3 v);

/**
 * @brief multiply two 3D int32_t vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return ivec3 the product of two vectors
 */
ivec3 ivec3_multiply(ivec3 v, ivec3 u);

/**
 * @brief divide two 3D int32_t vectors
 * 
 * @param v the 3D vector to use as nominator
 * @param u the 3D vector to use as denominator
 * @return ivec3 the fraction of both vectors
 */
ivec3 ivec3_divide(ivec3 v, ivec3 u);

/**
 * @brief calculate the dot product of two 3D int32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return int32_t the dot product of two 3D int32_t vectors
 */
int32_t ivec3_dot(ivec3 v, ivec3 u);

/**
 * @brief calculate the cross product of two 3D int32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return ivec3 a vector perpendicular to the inputted vectors (or (0,0,0) if both vectors are congruential)
 */
ivec3 ivec3_cross(ivec3 v, ivec3 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif