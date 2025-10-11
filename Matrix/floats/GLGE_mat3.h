/**
 * @file GLGE_mat3.h
 * @author DM8AT
 * @brief define a 3x3 float matrix
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_FLOAT_MAT_3x3_
#define _GLGE_FLOAT_MAT_3x3_

//include float 3D vectors
#include "../../Vector/floats/GLGE_vec3.h"

/**
 * @brief a 3x3 matrix of float elements
 */
typedef struct s_mat3
{
    //store all possible lay outs for the data
    union {
        //use a 4 element (3*3) float array for data storage
        float m[9];
        //the matrix is made of 3 rows where each row has 2 elements (2D vector)
        vec3 rows[3];
    };
    
    //check for C++ to implement the member functions
    #if __cplusplus

    /**
     * @brief Construct a new 3*3 matrix
     * default constructor, all values are 0
     */
    inline constexpr s_mat3() noexcept
     : m({1,0,0,0,1,0,0,0,1}) 
    {}

    /**
     * @brief Construct a new 3*3 matrix
     * 
     * @param m00 the top left item of the matrix
     * @param m01 the top right item of the matrix
     * @param m10 the bottom left item of the matrix
     * @param m11 the bottom right item of the matrix
     */
    inline constexpr s_mat3(float m00, float m01, float m02,
                            float m10, float m11, float m12,
                            float m20, float m21, float m22) noexcept
     : m({m00,m01,m02,m10,m11,m12,m20,m21,m22}) 
    {}

    /**
     * @brief Construct a new 3*3 matrix
     * 
     * @param r0 a const reference to a 3D float vector for the top row
     * @param r1 a const reference to a 3D float vector for the middle row
     * @param r2 a const reference to a 3D float vector for the bottom row
     */
    inline constexpr s_mat3(const vec3& r0, const vec3& r1, const vec3& r2) noexcept
     : rows({r0,r1,r2}) 
    {}

    /**
     * @brief set this matrix to another matrix
     * 
     * @param mat the matrix to copy
     */
    inline constexpr void operator=(const s_mat3& mat) noexcept {
        rows[0] = mat.rows[0];
        rows[1] = mat.rows[1];
        rows[2] = mat.rows[2];
    }

    /**
     * @brief set the matrix to a constant
     * 
     * @param c the constant to set all elements to
     */
    inline constexpr void operator=(float c) noexcept {
        rows[0] = c;
        rows[1] = c;
    }

    /**
     * @brief add two 3*3 matrices together and return the result
     * 
     * @param c the other matrix
     * @return s_mat3 the sum of the two matrices
     */
    inline constexpr s_mat3 operator+(s_mat3 c) const noexcept {
        return s_mat3(
            rows[0] + c.rows[0],
            rows[1] + c.rows[1],
            rows[2] + c.rows[2]
        );
    }

    /**
     * @brief add a constant value to the matrix
     * 
     * @param c the value that is going to be added to all values of the matrix
     * @return s_mat3 the matrix + c
     */
    inline constexpr s_mat3 operator+(float c) const noexcept {
        return s_mat3(
            rows[0] + c,
            rows[1] + c,
            rows[2] + c
        );
    }

    /**
     * @brief add a 3*3 matrix to this matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator+=(s_mat3 c) noexcept {
        rows[0] += c.rows[0];
        rows[1] += c.rows[1];
        rows[2] += c.rows[2];
    }

    /**
     * @brief add a constant value to this matrix
     * 
     * @param c the constant value
     */
    inline constexpr void operator+=(float c) noexcept {
        rows[0] += c;
        rows[1] += c;
        rows[2] += c;
    }

    /**
     * @brief subtract a 3*3 matrix from this matrix and return the result
     * 
     * @param c the other matrix
     * @return s_mat3 this matrix - the other matrix
     */
    inline constexpr s_mat3 operator-(s_mat3 c) const noexcept {
        return s_mat3(
            rows[0] - c.rows[0],
            rows[1] - c.rows[1],
            rows[2] - c.rows[2]
        );
    }
    /**
     * @brief subtract a constant value from the matrix and return the result
     * 
     * @param c the constant value
     * @return s_mat3 this matrix - the constant value
     */
    inline constexpr s_mat3 operator-(float c) const noexcept {
        return s_mat3(
            rows[0] - c,
            rows[1] - c,
            rows[2] - c
        );
    }
    /**
     * @brief subtract a 3*3 matrix from this matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator-=(s_mat3 c) noexcept {
        rows[0] -= c.rows[0];
        rows[1] -= c.rows[1];
        rows[2] -= c.rows[2];
    }
    /**
     * @brief subtract a constant value form this matrix
     * 
     * @param c the constant value
     */
    inline constexpr void operator-=(float c) noexcept {
        rows[0] -= c;
        rows[1] -= c;
        rows[2] -= c;
    }

    /**
     * @brief multiply this matrix with another matrix and return the result
     * 
     * @param c the other matrix
     * @return s_mat3 the product of the two matrices
     */
    inline constexpr s_mat3 operator*(s_mat3 c) const noexcept {
        return s_mat3(
            vec3(
                rows[0].x * c.rows[0].x + rows[0].y * c.rows[1].x + rows[0].z * c.rows[2].x, 
                rows[0].x * c.rows[0].y + rows[0].y * c.rows[1].y + rows[0].z * c.rows[2].y, 
                rows[0].x * c.rows[0].z + rows[0].y * c.rows[1].z + rows[0].z * c.rows[2].z
            ), 
            vec3(
                rows[1].x * c.rows[0].x + rows[1].y * c.rows[1].x + rows[1].z * c.rows[2].x, 
                rows[1].x * c.rows[0].y + rows[1].y * c.rows[1].y + rows[1].z * c.rows[2].y, 
                rows[1].x * c.rows[0].z + rows[1].y * c.rows[1].z + rows[1].z * c.rows[2].z
            ),
            vec3(
                rows[2].x * c.rows[0].x + rows[2].y * c.rows[1].x + rows[2].z * c.rows[2].x, 
                rows[2].x * c.rows[0].y + rows[2].y * c.rows[1].y + rows[2].z * c.rows[2].y, 
                rows[2].x * c.rows[0].z + rows[2].y * c.rows[1].z + rows[2].z * c.rows[2].z
            )
        );
    }
    /**
     * @brief scale the matrix and return the result
     * 
     * @param s the scale to scale the matrix
     * @return s_mat3 the scaled matrix
     */
    inline constexpr s_mat3 operator*(float s) const noexcept {
        return s_mat3(
            rows[0] * s,
            rows[1] * s,
            rows[2] * s
        );
    }
    /**
     * @brief multiply this matrix by an vector and return the result
     * 
     * @param v the vector
     * @return vec3 the product of this matrix and the vector
     */
    inline constexpr vec3 operator*(const vec3& v) const noexcept {
        return vec3(
            v.x * rows[0].x + v.y * rows[0].y + v.z * rows[0].z,
            v.x * rows[1].x + v.y * rows[1].y + v.z * rows[1].z,
            v.x * rows[2].x + v.y * rows[2].y + v.z * rows[2].z
        );
    }
    /**
     * @brief multiply this matrix by another matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator*=(s_mat3 c) noexcept {
        //create a temporary container for the matrix elements
        s_mat3 t = *this;
        //override the elements with the calculated values
        rows[0].x = t.rows[0].x * c.rows[0].x + t.rows[0].y * c.rows[1].x + t.rows[0].z * c.rows[2].x; 
        rows[0].y = t.rows[0].x * c.rows[0].y + t.rows[0].y * c.rows[1].y + t.rows[0].z * c.rows[2].y; 
        rows[0].z = t.rows[0].x * c.rows[0].z + t.rows[0].y * c.rows[1].z + t.rows[0].z * c.rows[2].z;
        rows[1].x = t.rows[1].x * c.rows[0].x + t.rows[1].y * c.rows[1].x + t.rows[1].z * c.rows[2].x; 
        rows[1].y = t.rows[1].x * c.rows[0].y + t.rows[1].y * c.rows[1].y + t.rows[1].z * c.rows[2].y; 
        rows[1].z = t.rows[1].x * c.rows[0].z + t.rows[1].y * c.rows[1].z + t.rows[1].z * c.rows[2].z;
        rows[2].x = t.rows[2].x * c.rows[0].x + t.rows[2].y * c.rows[1].x + t.rows[2].z * c.rows[2].x; 
        rows[2].y = t.rows[2].x * c.rows[0].y + t.rows[2].y * c.rows[1].y + t.rows[2].z * c.rows[2].y; 
        rows[2].z = t.rows[2].x * c.rows[0].z + t.rows[2].y * c.rows[1].z + t.rows[2].z * c.rows[2].z;
    }
    /**
     * @brief scale this matrix
     * 
     * @param s the scale
     */
    inline constexpr void operator*=(float s) noexcept {
        rows[0] *= s;
        rows[1] *= s;
        rows[2] *= s;
    }

    /**
     * @brief calculate the determinant of this matrix
     * 
     * @return float the determinant of this matrix
     */
    inline constexpr float determinant() const noexcept {
        return rows[0].x * (rows[1].y * rows[2].z - rows[1].z * rows[2].y) - rows[0].y * (rows[1].x * rows[2].z - rows[1].z * rows[2].x) + rows[0].z * (rows[1].x * rows[2].y - rows[1].y * rows[2].x);
    }

    /**
     * @brief check if the matrix has an inverse matrix
     * 
     * @return true : an inverse matrix exists
     * @return false : no inverse matrix exists
     */
    inline constexpr bool hasInverse() const noexcept {return determinant() != 0;}

    /**
     * @brief get the cofactor matrix of this matrix
     * 
     * @return constexpr s_mat3 the cofactor matrix
     */
    inline constexpr s_mat3 cofactors() const noexcept {
        /**
         * A = {
         *  {a,b,c},
         *  {d,e,f},
         *  {g,h,i}
         * }
         * 
         * cof(A) = {
         *  {  ei-fh, -(di-fg),  dh-eg},
         *  {-(bi-ch),  ai-cg, -(ah-bg)},
         *  {  bf-ce, -(af-cd),  ae-bd}
         * }
         * 
         * Made to fit row-column access of the matrix
         * cof(a) = {
         *  {  1y * 2z - 1z * 2y, -(1x * 2z - 1z * 2x),  1x * 2y - 1y * 2x},
         *  {-(0y * 2z - 0z * 2y),  0x * 2z - 0z * 2x, -(0x * 2y - 0y * 2x)},
         *  {  0y * 1z - 0z * 1y, -(0x * 1z - 0z * 1x),  0x * 1y - 0y * 1x},
         * }
         */
        return s_mat3(
            vec3(
                 rows[1].y * rows[2].z - rows[1].z * rows[2].y, 
                -(rows[1].x * rows[2].z - rows[1].z * rows[2].x),  
                 rows[1].x * rows[2].y - rows[1].y * rows[2].x
            ),
            vec3(
                -(rows[0].y * rows[2].z - rows[0].z * rows[2].y),  
                 rows[0].x * rows[2].z - rows[0].z * rows[2].x, 
                -(rows[0].x * rows[2].y - rows[0].y * rows[2].x)
            ),
            vec3(
                 rows[0].y * rows[1].z - rows[0].z * rows[1].y, 
                -(rows[0].x * rows[1].z - rows[0].z * rows[1].x),  
                 rows[0].x * rows[1].y - rows[0].y * rows[1].x
            )
        );
    };

    /**
     * @brief get the transpose of the matrix
     * 
     * @return constexpr s_mat3 the transposed matrix
     */
    inline constexpr s_mat3 transpose() const noexcept {
        return s_mat3(
            vec3(rows[0].x, rows[1].x, rows[2].x),
            vec3(rows[0].y, rows[1].y, rows[2].y),
            vec3(rows[0].z, rows[1].z, rows[2].z)
        );
    }

    /**
     * @brief compute the adjugate matrix of a 3*3 float matrix
     * 
     * @return constexpr s_mat3 the adjugate matrix of this matrix
     */
    inline constexpr s_mat3 adjugate() const noexcept {
        //same as the cofactor computation, but rows and columns are swapped
        return s_mat3(
            vec3(
                 rows[1].y * rows[2].z - rows[1].z * rows[2].y, 
                -(rows[0].y * rows[2].z - rows[0].z * rows[2].y),  
                 rows[0].y * rows[1].z - rows[0].z * rows[1].y
            ),
            vec3(
                -(rows[1].x * rows[2].z - rows[1].z * rows[2].x),  
                 rows[0].x * rows[2].z - rows[0].z * rows[2].x, 
                -(rows[0].x * rows[1].z - rows[0].z * rows[1].x)
            ),
            vec3(
                 rows[1].x * rows[2].y - rows[1].y * rows[2].x, 
                -(rows[0].x * rows[2].y - rows[0].y * rows[2].x),  
                 rows[0].x * rows[1].y - rows[0].y * rows[1].x
            )
        );
    }

    /**
     * @brief calculate the inverse of the matrix
     * 
     * @return s_mat3 the inverse matrix
     */
    inline constexpr s_mat3 inverse() const noexcept {
        //cache the inverse determinant
        float inv_det = 1.f / determinant();
        //return a matrix where all elements are swapped correctly and scaled by the inverse determinant
        return cofactors() * inv_det;
    }

    #endif

} mat3;

//for C++ start a C-Section
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 3x3 float matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return mat3 the sum of the matrices
 */
mat3 mat3_add(const mat3* a, const mat3* b);

/**
 * @brief add a float to a 3x3 matrix
 * 
 * @param a a constant pointer to the matrix to add to
 * @param b the float to add to the matrix
 * @return mat3 the sum of the matrix and the scalar
 */
mat3 mat3_addFloat(const mat3* a, float b);

/**
 * @brief add a matrix to another matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b a constant pointer to the matrix to add to a
 */
void mat3_addTo(mat3* a, const mat3* b);

/**
 * @brief add a float to a matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b the float to add to a
 */
void mat3_addFloatTo(mat3* a, float b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return mat3 the difference of all elements
 */
mat3 mat3_subtract(const mat3* a, const mat3* b);

/**
 * @brief subtract a float from the matrix
 * 
 * @param a a constant pointer to the matrix to subtract from
 * @param b the float to subtract from the matrix
 * @return mat3 the difference of the matrix and the scalar
 */
mat3 mat3_subtractFloat(const mat3* a, float b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b a constant pointer to the matrix to subtract from a
 */
void mat3_subtractFrom(mat3* a, const mat3* b);

/**
 * @brief subtract a float from a matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b the float to subtract from the matrix
 */
void mat3_subtractFloatFrom(mat3* a, float b);

/**
 * @brief multiply two matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return mat3 the product of both matrices
 */
mat3 mat3_multiply(const mat3* a, const mat3* b);

/**
 * @brief scale a matrix by a scalar
 * 
 * @param a a constant pointer to the matrix to scale
 * @param b the float to scale the matrix with
 * @return mat3 the scaled matrix
 */
mat3 mat3_scale(const mat3* a, float b);

/**
 * @brief apply the matrix to a vector by multiplying them together
 * 
 * @param a a constant pointer to the matrix to apply
 * @param b a constant pointer to the vector to multiply with the matrix
 * @return vec3 the product of the matrix and the vector
 */
vec3 mat3_apply(const mat3* a, const vec3* b);

/**
 * @brief multiply another matrix to a matrix
 * 
 * @param a a pointer to the matrix to multiply with and to
 * @param b a constant pointer to the matrix to multiply with
 */
void mat3_multiplyTo(mat3* a, const mat3* b);

/**
 * @brief scale a matrix to a matrix
 * 
 * @param a a pointer to the matrix to scale
 * @param b the float to scale the matrix with
 */
void mat3_scaleTo(mat3* a, float b);

/**
 * @brief compute the determinant of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the determinant of
 * @return float the determinant of the matrix
 */
float mat3_determinant(const mat3* mat);

/**
 * @brief check if a matrix has an inverse matrix
 * 
 * @param mat a constant pointer to the matrix to check
 * @return true : an inverse matrix can be constructured
 * @return false : no inverse matrix exists
 */
bool mat3_hasInverse(const mat3* mat);

/**
 * @brief get the cofactor matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the cofactors of
 * @return mat3 the cofactor matrix
 */
mat3 mat3_cofactors(const mat3* mat);

/**
 * @brief compute the adjugate matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the adjugate matrix for
 * @return mat3 the adjugate matrix
 */
mat3 mat3_adjugate(const mat3* mat);

/**
 * @brief compute the transpose of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the transpose of
 * @return mat3 the transposed matrix
 */
mat3 mat3_traspose(const mat3* mat);

/**
 * @brief compute the inverse of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the inverse of
 * @return mat3 the inverse matrix
 */
mat3 mat3_inverse(const mat3* mat);

//end a potential C-Section
#if __cplusplus
}
#endif

#endif