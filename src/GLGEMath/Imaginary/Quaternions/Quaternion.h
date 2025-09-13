/**
 * @file Quaternion.h
 * @author DM8AT
 * @brief define the quaternion structure (a 4D imaginary value)
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_QUATERNION_
#define _GLGE_QUATERNION_

//include 4D vectors to use together with quaternions (quaternions can be used like 4D vectors)
#include "../../Vector/floats/GLGE_vec4.h"
//include 3D vectors to use add rotation / constructors using 3D vectors
#include "../../Vector/floats/GLGE_vec3.h"

//create C linkage for everything
#if __cplusplus
extern "C" {
#endif

/**
 * @brief store an instance of a quaternion
 */
typedef struct s_Quaternion {

    union {
        struct {
            //the real value
            float w;

            union {
                //the imaginary values
                struct {
                    float x, y, z;
                };
                struct {
                    float i, j, k;
                };
            };
        };

        //store an array of the values
        float vals[4];

        //store the values as a vector
        vec4 vec;
    };

    //check for C++ to implement the C++ interface
    #if __cplusplus

    /**
     * @brief Construct a new Quaternion
     * 
     * Initializes the quaternion to 1 (1 in real, imaginary all to 0)
     */
    s_Quaternion() : w(1), i(0), j(0), k(0) {}

    /**
     * @brief Construct a new Quaternion
     * 
     * @param _w the real part of the quaternion
     * @param _i the first imaginary part for the quaternion
     * @param _j the second imaginary part for the quaternion
     * @param _k the third imaginary part for the quaternion
     */
    s_Quaternion(float _w, float _i, float _j, float _k) : w(_w), i(_i), j(_j), k(_k) {}

    /**
     * @brief Construct a new Quaternion
     * 
     * @param angle the angle to rotate around the given axis
     * @param axis the axis to rotate around
     */
    s_Quaternion(float angle, const vec3& axis) : w(angle), x(axis.x), y(axis.y), z(axis.z) {}

    /**
     * @brief Construct a new Quaternion
     * 
     * @param _vec a constant reference to a vector to initialize the quaternion from
     */
    s_Quaternion(const vec4& _vec) : vec(_vec) {}

    /**
     * @brief Destroy the Quaternion
     */
    ~s_Quaternion() {}

    /**
     * @brief add two quaternions together
     * 
     * @param q the quaternion to add to this one
     * @return Quaternion the sum of this and the other quaternion
     */
    inline s_Quaternion operator+(const s_Quaternion& q) const noexcept {return vec + q.vec;}

    /**
     * @brief subtract a quaternion from this one
     * 
     * @param q the quaternion to subtract from this one
     * @return Quaternion the difference of the quaternions
     */
    inline s_Quaternion operator-(const s_Quaternion& q) const noexcept {return vec - q.vec;}

    /**
     * @brief conjugate this quaternion
     * 
     * @return Quaternion the conjugated quaternion
     */
    inline s_Quaternion operator-(void) const noexcept {return s_Quaternion(w, -i, -j, -k);}

    /**
     * @brief get the inverse (conjugation) of this quaternion
     * 
     * @return Quaternion the conjugated (inversed) quaternion
     */
    inline s_Quaternion conjugate() const noexcept {return -(*this);}

    /**
     * @brief multiply two quaternions together
     * 
     * @param q the quaternion to multiply with
     * @return Quaternion the product of both quaternions
     */
    inline s_Quaternion operator*(const s_Quaternion& q) const noexcept {
        return s_Quaternion(
            (w*q.w) - (i*q.i) - (j*q.j) - (k*q.k),
            (i*q.w) + (w*q.i) + (j*q.k) - (k*q.j),
            (j*q.w) + (w*q.j) + (k*q.i) - (i*q.k),
            (k*q.w) + (w*q.k) + (i*q.j) - (j*q.i)
        );
    }

    /**
     * @brief multiply the quaternion by a 3D vector
     * 
     * @param v the 3D vector to multiply with
     * @return Quaternion the result of the quaternion - 3D vector multiplication
     */
    inline s_Quaternion operator*(const vec3& v) const noexcept {
        return s_Quaternion(
            - (x*v.x) - (y*v.y) - (z*v.z),
              (w*v.x) + (y*v.z) - (z*v.y),
              (w*v.y) + (z*v.x) - (x*v.z),
              (w*v.z) + (x*v.y) - (y*v.x)
        );
    }

    /**
     * @brief scale the quaternion by a scalar
     * 
     * @param s the scalar to scale the quaternion with
     * @return Quaternion the scaled quaternion
     */
    inline s_Quaternion operator*(float s) const noexcept {return vec * s;}

    /**
     * @brief scale down the quaternion by a scalar
     * 
     * @param s the scalar to divide all elements of the quaternion by
     * @return Quaternion the scaled down quaternion
     */
    inline s_Quaternion operator/(float s) const noexcept {return vec / s;}

    #endif

} Quaternion;

/**
 * @brief add two quaternions together
 * 
 * @param q a pointer to the first quaternion
 * @param p a pointer to the second quaternion
 * @return Quaternion the sum of both quaternions
 */
Quaternion quaternion_add(Quaternion* q, Quaternion* p);

/**
 * @brief subtract two quaternions
 * 
 * @param q a pointer to the quaternion to subtract from
 * @param p a pointer to the quaternion to subtract
 * @return Quaternion the difference of teh quaternions
 */
Quaternion quaternion_subtract(Quaternion* q, Quaternion* p);

/**
 * @brief conjugate a quaternion
 * 
 * This inverses the imaginary parts and keeps the real part as it is
 * 
 * @param q a pointer to the quaternion to conjugate
 * @return Quaternion the conjugated quaternion
 */
Quaternion quaternion_conjugate(Quaternion* q);

/**
 * @brief multiply two quaternions together
 * 
 * @param q a pointer to the first quaternion
 * @param p a pointer to the second quaternion
 * @return Quaternion the product of both quaternions
 */
Quaternion quaternion_multiply(Quaternion* q, Quaternion* p);

/**
 * @brief multiply a quaternion with a 3D vector
 * 
 * @param q a pointer to the quaternion
 * @param v a pointer to the 3D vector
 * @return Quaternion a pointer to a quaternion containing the product
 */
Quaternion quaternion_multiplyWithVec3(Quaternion* q, vec3* v);

/**
 * @brief scale a quaternion
 * 
 * @param q a pointer to the quaternion to scale
 * @param s the factor to scale the quaternion with
 * @return Quaternion the scaled quaternion
 */
Quaternion quaternion_scale(Quaternion* q, float s);

/**
 * @brief divide a quaternion by a scalar
 * 
 * @param q a pointer to the quaternion to scale down
 * @param s the inverse factor to scale down with
 * @return Quaternion the scaled quaternion
 */
Quaternion quaternion_divide(Quaternion* q, float s);

//end a potential C section
#if __cplusplus
}
#endif

#endif