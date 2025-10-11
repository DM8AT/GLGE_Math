/**
 * @file GLGE_mat2.h
 * @author DM8AT
 * @brief define a 2x2 float matrix
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_FLOAT_MAT_2x2_
#define _GLGE_FLOAT_MAT_2x2_

//include float 2D vectors
#include "../../Vector/floats/GLGE_vec2.h"

/**
 * @brief a 2x2 matrix of float elements
 */
typedef struct s_mat2
{
    //store all possible lay outs for the data
    union {
        //use a 4 element (2*2) float array for data storage
        float m[4];
        //the matrix is made of 2 rows where each row has 2 elements (2D vector)
        vec2 rows[2];
    };
    
    //check for C++ to implement the member functions
    #if __cplusplus

    /**
     * @brief Construct a new 2*2 matrix
     * default constructor, all values are 0
     */
    inline constexpr s_mat2() noexcept
     : m{1,0,0,1}
    {}

    /**
     * @brief Construct a new 2*2 matrix
     * 
     * @param m00 the top left item of the matrix
     * @param m01 the top right item of the matrix
     * @param m10 the bottom left item of the matrix
     * @param m11 the bottom right item of the matrix
     */
    inline constexpr s_mat2(float m00, float m01, 
         float m10, float m11) noexcept
     : m{m00,m01,m10,m11} 
    {}

    /**
     * @brief Construct a new 2*2 matrix
     * 
     * @param r0 a const reference to a 2D float vector for the top row
     * @param r1 a const reference to a 2D float vector for the bottom row
     */
    inline constexpr s_mat2(const vec2& r0, const vec2& r1) noexcept
     : rows{r0,r1}
    {}

    /**
     * @brief set this matrix to another matrix
     * 
     * @param mat the matrix to copy
     */
    inline constexpr void operator=(const s_mat2& mat) noexcept {
        rows[0] = mat.rows[0];
        rows[1] = mat.rows[1];
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
     * @brief add two 2*2 matrices together and return the result
     * 
     * @param c the other matrix
     * @return s_mat2 the sum of the two matrices
     */
    inline constexpr s_mat2 operator+(s_mat2 c) const noexcept {
        return s_mat2(
            rows[0] + c.rows[0],
            rows[1] + c.rows[1]
        );
    }

    /**
     * @brief add a constant value to the matrix
     * 
     * @param c the value that is going to be added to all values of the matrix
     * @return s_mat2 the matrix + c
     */
    inline constexpr s_mat2 operator+(float c) const noexcept {
        return s_mat2(
            rows[0] + c,
            rows[1] + c
        );
    }

    /**
     * @brief add a 2*2 matrix to this matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator+=(s_mat2 c) noexcept {
        rows[0] += c.rows[0];
        rows[1] += c.rows[1];
    }

    /**
     * @brief add a constant value to this matrix
     * 
     * @param c the constant value
     */
    inline constexpr void operator+=(float c) noexcept {
        rows[0] += c;
        rows[1] += c;
    }

    /**
     * @brief subtract a 2*2 matrix from this matrix and return the result
     * 
     * @param c the other matrix
     * @return s_mat2 this matrix - the other matrix
     */
    inline constexpr s_mat2 operator-(s_mat2 c) const noexcept {
        return s_mat2(
            rows[0] - c.rows[0],
            rows[1] - c.rows[1]
        );
    }
    /**
     * @brief subtract a constant value from the matrix and return the result
     * 
     * @param c the constant value
     * @return s_mat2 this matrix - the constant value
     */
    inline constexpr s_mat2 operator-(float c) const noexcept {
        return s_mat2(
            rows[0] - c,
            rows[1] - c
        );
    }
    /**
     * @brief subtract a 2*2 matrix from this matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator-=(s_mat2 c) noexcept {
        rows[0] -= c.rows[0];
        rows[1] -= c.rows[1];
    }
    /**
     * @brief subtract a constant value form this matrix
     * 
     * @param c the constant value
     */
    inline constexpr void operator-=(float c) noexcept {
        rows[0] -= c;
        rows[1] -= c;
    }

    /**
     * @brief multiply this matrix with another matrix and return the result
     * 
     * @param c the other matrix
     * @return s_mat2 the product of the two matrices
     */
    inline constexpr s_mat2 operator*(s_mat2 c) const noexcept {
        return s_mat2(
            vec2(
                rows[0].x * c.rows[0].x + rows[0].y * c.rows[1].x, 
                rows[0].x * c.rows[0].y + rows[0].y * c.rows[1].y
            ), 
            vec2(
                rows[1].x * c.rows[0].x + rows[1].y * c.rows[1].x, 
                rows[1].x * c.rows[0].y + rows[1].y * c.rows[1].y
            )
        );
    }
    /**
     * @brief scale the matrix and return the result
     * 
     * @param s the scale to scale the matrix
     * @return s_mat2 the scaled matrix
     */
    inline constexpr s_mat2 operator*(float s) const noexcept {
        return s_mat2(
            rows[0] * s,
            rows[1] * s
        );
    }
    /**
     * @brief multiply this matrix by an vector and return the result
     * 
     * @param v the vector
     * @return vec2 the product of this matrix and the vector
     */
    inline constexpr vec2 operator*(const vec2& v) const noexcept {
        return vec2(
            rows[0].x*v.x + rows[0].y*v.y,
            rows[1].x*v.x + rows[1].y*v.y
        );
    }
    /**
     * @brief multiply this matrix by another matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator*=(s_mat2 c) noexcept {
        //create a temporary container for the matrix elements
        s_mat2 t = *this;
        //override the elements with the calculated values
        rows[0].x = t.rows[0].x * c.rows[0].x + t.rows[0].y * c.rows[1].x;
        rows[0].y = t.rows[0].x * c.rows[0].y + t.rows[0].y * c.rows[1].y;
        rows[1].x = t.rows[1].x * c.rows[0].x + t.rows[1].y * c.rows[1].x;
        rows[1].y = t.rows[1].x * c.rows[0].y + t.rows[1].y * c.rows[1].y;
    }
    /**
     * @brief scale this matrix
     * 
     * @param s the scale
     */
    inline constexpr void operator*=(float s) noexcept {
        rows[0] *= s;
        rows[1] *= s;
    }

    /**
     * @brief calculate the determinant of this matrix
     * 
     * @return float the determinant of this matrix
     */
    inline constexpr float determinant() const noexcept {
        return (rows[0].x*rows[1].y) - (rows[0].y*rows[1].x);
    }

    /**
     * @brief get the cofactor matrix of this matrix
     * 
     * @return constexpr s_mat2 the cofactor matrix
     */
    inline constexpr s_mat2 cofactors() const noexcept {
        return s_mat2(
            vec2(
                 rows[1].y, 
                -rows[1].y
            ),
            vec2(
                -rows[0].x,
                 rows[0].x
            )
        );
    };

    /**
     * @brief get the transpose of the matrix
     * 
     * @return constexpr s_mat2 the transposed matrix
     */
    inline constexpr s_mat2 transpose() const noexcept {
        return s_mat2(
            vec2(
                rows[0].x, 
                rows[1].x
            ),
            vec2(
                rows[0].y, 
                rows[1].y
            )
        );
    }

    /**
     * @brief compute the adjugate matrix of a 2*2 float matrix
     * 
     * @return constexpr s_mat2 the adjugate matrix of this matrix
     */
    inline constexpr s_mat2 adjugate() const noexcept {
        return s_mat2(
            vec2(
                 rows[1].y, 
                -rows[0].y
            ),
            vec2(
                -rows[1].x,
                 rows[0].x
            )
        );
    }

    /**
     * @brief calculate the inverse of the matrix
     * 
     * @return s_mat2 the inverse matrix
     */
    inline constexpr s_mat2 inverse() const noexcept {
        //cache the inverse determinant
        float inv_det = 1.f / determinant();
        //return a matrix where all elements are swapped correctly and scaled by the inverse determinant
        return cofactors() * inv_det;
    }

    #endif

} mat2;

//for C++ start a C-Section
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 2x2 float matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return mat2 the sum of the matrices
 */
mat2 mat2_add(const mat2* a, const mat2* b);

/**
 * @brief add a float to a 2x2 matrix
 * 
 * @param a a constant pointer to the matrix to add to
 * @param b the float to add to the matrix
 * @return mat2 the sum of the matrix and the scalar
 */
mat2 mat2_addFloat(const mat2* a, float b);

/**
 * @brief add a matrix to another matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b a constant pointer to the matrix to add to a
 */
void mat2_addTo(mat2* a, const mat2* b);

/**
 * @brief add a float to a matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b the float to add to a
 */
void mat2_addFloatTo(mat2* a, float b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return mat2 the difference of all elements
 */
mat2 mat2_subtract(const mat2* a, const mat2* b);

/**
 * @brief subtract a float from the matrix
 * 
 * @param a a constant pointer to the matrix to subtract from
 * @param b the float to subtract from the matrix
 * @return mat2 the difference of the matrix and the scalar
 */
mat2 mat2_subtractFloat(const mat2* a, float b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b a constant pointer to the matrix to subtract from a
 */
void mat2_subtractFrom(mat2* a, const mat2* b);

/**
 * @brief subtract a float from a matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b the float to subtract from the matrix
 */
void mat2_subtractFloatFrom(mat2* a, float b);

/**
 * @brief multiply two matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return mat2 the product of both matrices
 */
mat2 mat2_multiply(const mat2* a, const mat2* b);

/**
 * @brief scale a matrix by a scalar
 * 
 * @param a a constant pointer to the matrix to scale
 * @param b the float to scale the matrix with
 * @return mat2 the scaled matrix
 */
mat2 mat2_scale(const mat2* a, float b);

/**
 * @brief apply the matrix to a vector by multiplying them together
 * 
 * @param a a constant pointer to the matrix to apply
 * @param b a constant pointer to the vector to multiply with the matrix
 * @return vec2 the product of the matrix and the vector
 */
vec2 mat2_apply(const mat2* a, const vec2* b);

/**
 * @brief multiply another matrix to a matrix
 * 
 * @param a a pointer to the matrix to multiply with and to
 * @param b a constant pointer to the matrix to multiply with
 */
void mat2_multiplyTo(mat2* a, const mat2* b);

/**
 * @brief scale a matrix to a matrix
 * 
 * @param a a pointer to the matrix to scale
 * @param b the float to scale the matrix with
 */
void mat2_scaleTo(mat2* a, float b);

/**
 * @brief compute the determinant of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the determinant of
 * @return float the determinant of the matrix
 */
float mat2_determinant(const mat2* mat);

/**
 * @brief get the cofactor matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the cofactors of
 * @return mat2 the cofactor matrix
 */
mat2 mat2_cofactors(const mat2* mat);

/**
 * @brief compute the adjugate matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the adjugate matrix for
 * @return mat2 the adjugate matrix
 */
mat2 mat2_adjugate(const mat2* mat);

/**
 * @brief compute the transpose of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the transpose of
 * @return mat2 the transposed matrix
 */
mat2 mat2_traspose(const mat2* mat);

/**
 * @brief compute the inverse of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the inverse of
 * @return mat2 the inverse matrix
 */
mat2 mat2_inverse(const mat2* mat);

//end a potential C-Section
#if __cplusplus
}
#endif

#endif