/**
 * @file GLGE_dmat2.h
 * @author DM8AT
 * @brief define a 2x2 double matrix
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_double_MAT_2x2_
#define _GLGE_double_MAT_2x2_

//include double 2D vectors
#include "../../Vector/doubles/GLGE_dvec2.h"

/**
 * @brief a 2x2 matrix of double elements
 */
typedef struct s_dmat2
{
    //store all possible lay outs for the data
    union {
        //use a 4 element (2*2) double array for data storage
        double m[4];
        //the matrix is made of 2 rows where each row has 2 elements (2D vector)
        dvec2 rows[2];
    };
    
    //check for C++ to implement the member functions
    #if __cplusplus

    /**
     * @brief Construct a new 2*2 matrix
     * default constructor, all values are 0
     */
    inline constexpr s_dmat2() noexcept
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
    inline constexpr s_dmat2(double m00, double m01, 
         double m10, double m11) noexcept
     : m{m00,m01,m10,m11} 
    {}

    /**
     * @brief Construct a new 2*2 matrix
     * 
     * @param r0 a const reference to a 2D double vector for the top row
     * @param r1 a const reference to a 2D double vector for the bottom row
     */
    inline constexpr s_dmat2(const dvec2& r0, const dvec2& r1) noexcept
     : rows{r0,r1}
    {}

    /**
     * @brief set this matrix to another matrix
     * 
     * @param mat the matrix to copy
     */
    inline constexpr void operator=(const s_dmat2& mat) noexcept {
        rows[0] = mat.rows[0];
        rows[1] = mat.rows[1];
    }

    /**
     * @brief set the matrix to a constant
     * 
     * @param c the constant to set all elements to
     */
    inline constexpr void operator=(double c) noexcept {
        rows[0] = c;
        rows[1] = c;
    }

    /**
     * @brief add two 2*2 matrices together and return the result
     * 
     * @param c the other matrix
     * @return s_dmat2 the sum of the two matrices
     */
    inline s_dmat2 operator+(s_dmat2 c) const noexcept {
        return s_dmat2(
            rows[0] + c.rows[0],
            rows[1] + c.rows[1]
        );
    }

    /**
     * @brief add a constant value to the matrix
     * 
     * @param c the value that is going to be added to all values of the matrix
     * @return s_dmat2 the matrix + c
     */
    inline s_dmat2 operator+(double c) const noexcept {
        return s_dmat2(
            rows[0] + c,
            rows[1] + c
        );
    }

    /**
     * @brief add a 2*2 matrix to this matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator+=(s_dmat2 c) noexcept {
        rows[0].x += c.rows[0].x; rows[0].y += c.rows[0].y;
        rows[1].x += c.rows[1].x; rows[1].y += c.rows[1].y;
    }

    /**
     * @brief add a constant value to this matrix
     * 
     * @param c the constant value
     */
    inline constexpr void operator+=(double c) noexcept {
        rows[0].x += c; rows[0].y += c;
        rows[1].x += c; rows[1].y += c;
    }

    /**
     * @brief subtract a 2*2 matrix from this matrix and return the result
     * 
     * @param c the other matrix
     * @return s_dmat2 this matrix - the other matrix
     */
    inline s_dmat2 operator-(s_dmat2 c) const noexcept {
        return s_dmat2(
            rows[0] - c.rows[0],
            rows[1] - c.rows[1]
        );
    }
    /**
     * @brief subtract a constant value from the matrix and return the result
     * 
     * @param c the constant value
     * @return s_dmat2 this matrix - the constant value
     */
    inline s_dmat2 operator-(double c) const noexcept {
        return s_dmat2(
            rows[0] - c,
            rows[1] - c
        );
    }
    /**
     * @brief subtract a 2*2 matrix from this matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator-=(s_dmat2 c) noexcept {
        rows[0].x -= c.rows[0].x; rows[0].y -= c.rows[0].y;
        rows[1].x -= c.rows[1].x; rows[1].y -= c.rows[1].y;
    }
    /**
     * @brief subtract a constant value form this matrix
     * 
     * @param c the constant value
     */
    inline constexpr void operator-=(double c) noexcept {
        rows[0].x -= c; rows[0].y -= c;
        rows[1].x -= c; rows[1].y -= c;
    }

    /**
     * @brief multiply this matrix with another matrix and return the result
     * 
     * @param c the other matrix
     * @return s_dmat2 the product of the two matrices
     */
    inline constexpr s_dmat2 operator*(s_dmat2 c) const noexcept {
        return s_dmat2(
            dvec2(
                rows[0].x * c.rows[0].x + rows[0].y * c.rows[1].x, 
                rows[0].x * c.rows[0].y + rows[0].y * c.rows[1].y
            ), 
            dvec2(
                rows[1].x * c.rows[0].x + rows[1].y * c.rows[1].x, 
                rows[1].x * c.rows[0].y + rows[1].y * c.rows[1].y
            )
        );
    }
    /**
     * @brief scale the matrix and return the result
     * 
     * @param s the scale to scale the matrix
     * @return s_dmat2 the scaled matrix
     */
    inline s_dmat2 operator*(double s) const noexcept {
        return s_dmat2(
            rows[0] * s,
            rows[1] * s
        );
    }
    /**
     * @brief multiply this matrix by an vector and return the result
     * 
     * @param v the vector
     * @return dvec2 the product of this matrix and the vector
     */
    inline constexpr dvec2 operator*(const dvec2& v) const noexcept {
        return dvec2(
            rows[0].x*v.x + rows[0].y*v.y,
            rows[1].x*v.x + rows[1].y*v.y
        );
    }
    /**
     * @brief multiply this matrix by another matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator*=(s_dmat2 c) noexcept {
        //create a temporary container for the matrix elements
        s_dmat2 t = *this;
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
    inline constexpr void operator*=(double s) noexcept {
        rows[0].x *= s; rows[0].y *= s;
        rows[1].x *= s; rows[1].y *= s;
    }

    /**
     * @brief calculate the determinant of this matrix
     * 
     * @return double the determinant of this matrix
     */
    inline constexpr double determinant() const noexcept {
        return (rows[0].x*rows[1].y) - (rows[0].y*rows[1].x);
    }

    /**
     * @brief get the cofactor matrix of this matrix
     * 
     * @return constexpr s_dmat2 the cofactor matrix
     */
    inline constexpr s_dmat2 cofactors() const noexcept {
        return s_dmat2(
            dvec2(
                 rows[1].y, 
                -rows[1].y
            ),
            dvec2(
                -rows[0].x,
                 rows[0].x
            )
        );
    };

    /**
     * @brief get the transpose of the matrix
     * 
     * @return constexpr s_dmat2 the transposed matrix
     */
    inline constexpr s_dmat2 transpose() const noexcept {
        return s_dmat2(
            dvec2(
                rows[0].x, 
                rows[1].x
            ),
            dvec2(
                rows[0].y, 
                rows[1].y
            )
        );
    }

    /**
     * @brief compute the adjugate matrix of a 2*2 double matrix
     * 
     * @return constexpr s_dmat2 the adjugate matrix of this matrix
     */
    inline constexpr s_dmat2 adjugate() const noexcept {
        return s_dmat2(
            dvec2(
                 rows[1].y, 
                -rows[0].y
            ),
            dvec2(
                -rows[1].x,
                 rows[0].x
            )
        );
    }

    /**
     * @brief calculate the inverse of the matrix
     * 
     * @return s_dmat2 the inverse matrix
     */
    inline s_dmat2 inverse() const noexcept {
        //cache the inverse determinant
        double inv_det = 1.f / determinant();
        //return a matrix where all elements are swapped correctly and scaled by the inverse determinant
        return cofactors() * inv_det;
    }

    #endif

} dmat2;

//for C++ start a C-Section
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 2x2 double matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return dmat2 the sum of the matrices
 */
dmat2 dmat2_add(const dmat2* a, const dmat2* b);

/**
 * @brief add a double to a 2x2 matrix
 * 
 * @param a a constant pointer to the matrix to add to
 * @param b the double to add to the matrix
 * @return dmat2 the sum of the matrix and the scalar
 */
dmat2 dmat2_adddouble(const dmat2* a, double b);

/**
 * @brief add a matrix to another matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b a constant pointer to the matrix to add to a
 */
void dmat2_addTo(dmat2* a, const dmat2* b);

/**
 * @brief add a double to a matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b the double to add to a
 */
void dmat2_adddoubleTo(dmat2* a, double b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return dmat2 the difference of all elements
 */
dmat2 dmat2_subtract(const dmat2* a, const dmat2* b);

/**
 * @brief subtract a double from the matrix
 * 
 * @param a a constant pointer to the matrix to subtract from
 * @param b the double to subtract from the matrix
 * @return dmat2 the difference of the matrix and the scalar
 */
dmat2 dmat2_subtractdouble(const dmat2* a, double b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b a constant pointer to the matrix to subtract from a
 */
void dmat2_subtractFrom(dmat2* a, const dmat2* b);

/**
 * @brief subtract a double from a matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b the double to subtract from the matrix
 */
void dmat2_subtractdoubleFrom(dmat2* a, double b);

/**
 * @brief multiply two matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return dmat2 the product of both matrices
 */
dmat2 dmat2_multiply(const dmat2* a, const dmat2* b);

/**
 * @brief scale a matrix by a scalar
 * 
 * @param a a constant pointer to the matrix to scale
 * @param b the double to scale the matrix with
 * @return dmat2 the scaled matrix
 */
dmat2 dmat2_scale(const dmat2* a, double b);

/**
 * @brief apply the matrix to a vector by multiplying them together
 * 
 * @param a a constant pointer to the matrix to apply
 * @param b a constant pointer to the vector to multiply with the matrix
 * @return dvec2 the product of the matrix and the vector
 */
dvec2 dmat2_apply(const dmat2* a, const dvec2* b);

/**
 * @brief multiply another matrix to a matrix
 * 
 * @param a a pointer to the matrix to multiply with and to
 * @param b a constant pointer to the matrix to multiply with
 */
void dmat2_multiplyTo(dmat2* a, const dmat2* b);

/**
 * @brief scale a matrix to a matrix
 * 
 * @param a a pointer to the matrix to scale
 * @param b the double to scale the matrix with
 */
void dmat2_scaleTo(dmat2* a, double b);

/**
 * @brief compute the determinant of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the determinant of
 * @return double the determinant of the matrix
 */
double dmat2_determinant(const dmat2* mat);

/**
 * @brief get the cofactor matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the cofactors of
 * @return dmat2 the cofactor matrix
 */
dmat2 dmat2_cofactors(const dmat2* mat);

/**
 * @brief compute the adjugate matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the adjugate matrix for
 * @return dmat2 the adjugate matrix
 */
dmat2 dmat2_adjugate(const dmat2* mat);

/**
 * @brief compute the transpose of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the transpose of
 * @return dmat2 the transposed matrix
 */
dmat2 dmat2_traspose(const dmat2* mat);

/**
 * @brief compute the inverse of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the inverse of
 * @return dmat2 the inverse matrix
 */
dmat2 dmat2_inverse(const dmat2* mat);

//end a potential C-Section
#if __cplusplus
}
#endif

#endif