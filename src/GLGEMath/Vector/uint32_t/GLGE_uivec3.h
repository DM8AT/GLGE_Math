/**
 * @file GLGE_uivec3.h
 * @author DM8AT
 * @brief define an interface for 3D uint32_t vectors
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_uint32_t_uivec3_
#define _GLGE_uint32_t_uivec3_

//include the 2D vector for upcasting
#include "GLGE_uivec2.h"

//intrinsics are not available for 3D uint32_t vectors because no intrinsic type fits to the size of 3D vectors
//loading to the intrinsics for each operation takes too much time

/**
 * @brief store a 3D vector of uint32_ts
 */
typedef struct s_uivec3 {

    /**
     * @brief store the actual data for the vector
     */
    union {
        //store the values for all axis
        struct {
            uint32_t x;
            uint32_t y;
            uint32_t z;
        };
        //store the values for colors
        struct {
            uint32_t r;
            uint32_t g;
            uint32_t b;
        };
        //store the values as a uint32_t vector
        uint32_t vals[3];
    };

    //for C++ add all member functions
    #if __cplusplus

    /**
     * @brief Construct a new uivec3
     * 
     */
    inline s_uivec3() : x(0), y(0), z(0) {}

    /**
     * @brief Construct a new uivec3
     * 
     * @param _x the value for the x axis / red channel
     * @param _y the value for the y axis / green channel
     * @param _z the value for the z axis / blue channel
     */
    inline s_uivec3(uint32_t _x, uint32_t _y, uint32_t _z) : x(_x), y(_y), z(_z) {}

    /**
     * @brief Construct a new uivec3
     * 
     * @param xyz the value for the x, y and z axis as well as for the red, green and blue channel
     */
    inline s_uivec3(uint32_t xyz) : x(xyz), y(xyz), z(xyz) {}

    /**
     * @brief Construct a new uivec3
     * 
     * @param xy the values for the x and y axis / red and green channel
     * @param _z the value for the z axis / blue channel
     */
    inline s_uivec3(const uivec2& xy, uint32_t _z) : x(xy.x), y(xy.y), z(_z) {}

    /**
     * @brief Construct a new uivec3
     * 
     * @param _x the value for the x axis / red channel
     * @param yz the value for the y and z axis / green and blue channel
     */
    inline s_uivec3(uint32_t _x, const uivec2& yz) : x(_x), y(yz.x), z(yz.y) {}

    /**
     * @brief add two 3D uint32_t vectors together
     * 
     * @param u the second vector to add to this one
     * @return const s_uivec3 the sum of both vectors
     */
    inline s_uivec3 operator+(const s_uivec3& u) const noexcept
    {return s_uivec3(x + u.x, y + u.y, z + u.z);}

    /**
     * @brief subtract two 3D uint32_t vectors
     * 
     * @param u the vector to subtract from this one
     * @return const s_uivec3 the difference of both vectors
     */
    inline s_uivec3 operator-(const s_uivec3& u) const noexcept
    {return s_uivec3(x - u.x, y - u.y, z - u.z);}

    /**
     * @brief multiply two 3D uint32_t vectors together
     * 
     * @param u the vector to multiply to this one
     * @return s_uivec3 the product of both vectors
     */
    inline s_uivec3 operator*(const s_uivec3& u) const noexcept
    {return s_uivec3(x * u.x, y * u.y, z * u.z);}

    /**
     * @brief divide one vector by another
     * 
     * @param u the vector to use as the denominator
     * @return s_uivec3 the fraction of both vectors
     */
    inline s_uivec3 operator/(const s_uivec3& u) const noexcept
    {return s_uivec3(x / u.x, y / u.y, z / u.z);}

    /**
     * @brief negate a 3D uint32_t vector
     * 
     * @return s_uivec3 the negated vector
     */
    inline s_uivec3 operator-(void)  const noexcept
    {return s_uivec3(-x,-y,-z);}

    /**
     * @brief print a 3D vector into an output stream
     * 
     * @param os the output output stream to fill
     * @param u the 3D uint32_t vector to put into the output stream
     * @return std::ostream& the filled output stream
     */
    inline friend std::ostream& operator<<(std::ostream& os, const s_uivec3& u) noexcept
    {return os << "(" << u.x << ", " << u.y << ", " << u.z << ")";}

    #endif

} uivec3;

//add the C++ specific functions
#if __cplusplus

/**
 * @brief calculate the dot product of two 2D uint32_t vectors
 * 
 * @param v the first uint32_t vector
 * @param u the second uint32_t vector
 * @return const uint32_t the dot product of both vectors
 */
inline const uint32_t dot(const uivec3& v, const uivec3& u) noexcept {return v.x * u.x + v.y * u.y + v.z * u.z;}

/**
 * @brief calculate the cross product between two 3D vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return const uivec3 the cross product (vector product) of both vectors
 */
inline const uivec3 cross(const uivec3& v, const uivec3& u) noexcept {return uivec3(v.y*u.z - v.z*u.y, v.x*u.z - v.z*u.x, v.x*u.y - v.y*u.x);}

#endif

// make the C functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 3D uint32_t vectors together
 * 
 * @param v the first vector
 * @param u the second vector
 * @return uivec3 the sum of both vectors
 */
uivec3 uivec3_add(uivec3 v, uivec3 u);

/**
 * @brief subtract two 3D uint32_t vectors
 * 
 * @param v the vector to subtract from
 * @param u the vector to subtract from the other vector
 * @return uivec3 the difference of both vectors
 */
uivec3 uivec3_subtract(uivec3 v, uivec3 u);

/**
 * @brief negate a 3D vector
 * 
 * @param v the vector to negate
 * @return uivec3 the negated vector
 */
uivec3 uivec3_negate(uivec3 v);

/**
 * @brief multiply two 3D uint32_t vectors together
 * 
 * @param v the first vector to multiply with
 * @param u the second vector to multiply with
 * @return uivec3 the product of two vectors
 */
uivec3 uivec3_multiply(uivec3 v, uivec3 u);

/**
 * @brief divide two 3D uint32_t vectors
 * 
 * @param v the 3D vector to use as nominator
 * @param u the 3D vector to use as denominator
 * @return uivec3 the fraction of both vectors
 */
uivec3 uivec3_divide(uivec3 v, uivec3 u);

/**
 * @brief calculate the dot product of two 3D uint32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return uint32_t the dot product of two 3D uint32_t vectors
 */
uint32_t uivec3_dot(uivec3 v, uivec3 u);

/**
 * @brief calculate the cross product of two 3D uint32_t vectors
 * 
 * @param v the first vector
 * @param u the second vector
 * @return uivec3 a vector perpendicular to the inputted vectors (or (0,0,0) if both vectors are congruential)
 */
uivec3 uivec3_cross(uivec3 v, uivec3 u);

//end a potential C section
#if __cplusplus
}
#endif

#endif