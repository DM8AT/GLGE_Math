/**
 * @file GLGE_dmat4.h
 * @author DM8AT
 * @brief define a 4x4 double matrix
 * @version 0.1
 * @date 2025-10-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_double_MAT_4x4_
#define _GLGE_double_MAT_4x4_

//include double 3D vectors
#include "../../Vector/doubles/GLGE_dvec4.h"

/**
 * @brief a 4x4 matrix of double elements
 */
typedef struct s_dmat4
{
    //store all possible lay outs for the data
    union {
        //use a 4 element (4*4) double array for data storage
        double m[16];
        //the matrix is made of 4 rows where each row has 4 elements (4D vector)
        dvec4 rows[4];
    };
    
    //check for C++ to implement the member functions
    #if __cplusplus

    /**
     * @brief Construct a new 4*4 matrix
     * default constructor, all values are 0
     */
    inline constexpr s_dmat4() noexcept
     : m{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}
    {}

    /**
     * @brief Construct a new 4*4 matrix
     * 
     * @param m00 the top left item of the matrix
     * @param m01 the top right item of the matrix
     * @param m10 the bottom left item of the matrix
     * @param m11 the bottom right item of the matrix
     */
    inline constexpr s_dmat4(double m00, double m01, double m02, double m03,
                            double m10, double m11, double m12, double m13,
                            double m20, double m21, double m22, double m23,
                            double m30, double m31, double m32, double m33) noexcept
     : m{m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33} 
    {}

    /**
     * @brief Construct a new 4*4 matrix
     * 
     * @param r0 a const reference to a 4D double vector for the top row
     * @param r1 a const reference to a 4D double vector for the upper-middle row
     * @param r2 a const reference to a 4D double vector for the lower-middle row
     * @param r3 a const reference to a 4D double vector for the bottom row
     */
    inline constexpr s_dmat4(const dvec4& r0, const dvec4& r1, const dvec4& r2, const dvec4& r3) noexcept
     : rows{r0,r1,r2,r3} 
    {}

    /**
     * @brief set this matrix to another matrix
     * 
     * @param mat the matrix to copy
     */
    inline constexpr void operator=(const s_dmat4& mat) noexcept {
        rows[0] = mat.rows[0];
        rows[1] = mat.rows[1];
        rows[2] = mat.rows[2];
        rows[3] = mat.rows[3];
    }

    /**
     * @brief set the matrix to a constant
     * 
     * @param c the constant to set all elements to
     */
    inline constexpr void operator=(double c) noexcept {
        rows[0] = c;
        rows[1] = c;
        rows[2] = c;
        rows[3] = c;
    }

    /**
     * @brief add two 4*4 matrices together and return the result
     * 
     * @param c the other matrix
     * @return s_dmat4 the sum of the two matrices
     */
    inline s_dmat4 operator+(s_dmat4 c) const noexcept {
        return s_dmat4(
            rows[0] + c.rows[0],
            rows[1] + c.rows[1],
            rows[2] + c.rows[2],
            rows[3] + c.rows[3]
        );
    }

    /**
     * @brief add a constant value to the matrix
     * 
     * @param c the value that is going to be added to all values of the matrix
     * @return s_dmat4 the matrix + c
     */
    inline s_dmat4 operator+(double c) const noexcept {
        return s_dmat4(
            rows[0] + c,
            rows[1] + c,
            rows[2] + c,
            rows[3] + c
        );
    }

    /**
     * @brief add a 4*4 matrix to this matrix
     * 
     * @param c the other matrix
     */
    inline void operator+=(s_dmat4 c) noexcept {
        rows[0] += c.rows[0];
        rows[1] += c.rows[1];
        rows[2] += c.rows[2];
        rows[3] += c.rows[2];
    }

    /**
     * @brief add a constant value to this matrix
     * 
     * @param c the constant value
     */
    inline void operator+=(double c) noexcept {
        rows[0] += c;
        rows[1] += c;
        rows[2] += c;
        rows[3] += c;
    }

    /**
     * @brief subtract a 4*4 matrix from this matrix and return the result
     * 
     * @param c the other matrix
     * @return s_dmat4 this matrix - the other matrix
     */
    inline s_dmat4 operator-(s_dmat4 c) const noexcept {
        return s_dmat4(
            rows[0] - c.rows[0],
            rows[1] - c.rows[1],
            rows[2] - c.rows[2],
            rows[3] - c.rows[3]
        );
    }
    /**
     * @brief subtract a constant value from the matrix and return the result
     * 
     * @param c the constant value
     * @return s_dmat4 this matrix - the constant value
     */
    inline s_dmat4 operator-(double c) const noexcept {
        return s_dmat4(
            rows[0] - c,
            rows[1] - c,
            rows[2] - c,
            rows[3] - c
        );
    }
    /**
     * @brief subtract a 4*4 matrix from this matrix
     * 
     * @param c the other matrix
     */
    inline void operator-=(s_dmat4 c) noexcept {
        rows[0] -= c.rows[0];
        rows[1] -= c.rows[1];
        rows[2] -= c.rows[2];
        rows[3] -= c.rows[3];
    }
    /**
     * @brief subtract a constant value form this matrix
     * 
     * @param c the constant value
     */
    inline void operator-=(double c) noexcept {
        rows[0] -= c;
        rows[1] -= c;
        rows[2] -= c;
        rows[3] -= c;
    }

    /**
     * @brief multiply this matrix with another matrix and return the result
     * 
     * @param c the other matrix
     * @return s_dmat4 the product of the two matrices
     */
    inline constexpr s_dmat4 operator*(s_dmat4 c) const noexcept {
        return s_dmat4(
            dvec4(
                rows[0].x * c.rows[0].x + rows[0].y * c.rows[1].x + rows[0].z * c.rows[2].x + rows[0].w * c.rows[3].x, 
                rows[0].x * c.rows[0].y + rows[0].y * c.rows[1].y + rows[0].z * c.rows[2].y + rows[0].w * c.rows[3].y, 
                rows[0].x * c.rows[0].z + rows[0].y * c.rows[1].z + rows[0].z * c.rows[2].z + rows[0].w * c.rows[3].z, 
                rows[0].x * c.rows[0].w + rows[0].y * c.rows[1].w + rows[0].z * c.rows[2].w + rows[0].w * c.rows[3].w
            ),
            dvec4(
                rows[1].x * c.rows[0].x + rows[1].y * c.rows[1].x + rows[1].z * c.rows[2].x + rows[1].w * c.rows[3].x, 
                rows[1].x * c.rows[0].y + rows[1].y * c.rows[1].y + rows[1].z * c.rows[2].y + rows[1].w * c.rows[3].y, 
                rows[1].x * c.rows[0].z + rows[1].y * c.rows[1].z + rows[1].z * c.rows[2].z + rows[1].w * c.rows[3].z, 
                rows[1].x * c.rows[0].w + rows[1].y * c.rows[1].w + rows[1].z * c.rows[2].w + rows[1].w * c.rows[3].w
            ),
            dvec4(
                rows[2].x * c.rows[0].x + rows[2].y * c.rows[1].x + rows[2].z * c.rows[2].x + rows[2].w * c.rows[3].x, 
                rows[2].x * c.rows[0].y + rows[2].y * c.rows[1].y + rows[2].z * c.rows[2].y + rows[2].w * c.rows[3].y, 
                rows[2].x * c.rows[0].z + rows[2].y * c.rows[1].z + rows[2].z * c.rows[2].z + rows[2].w * c.rows[3].z, 
                rows[2].x * c.rows[0].w + rows[2].y * c.rows[1].w + rows[2].z * c.rows[2].w + rows[2].w * c.rows[3].w
            ),
            dvec4(
                rows[3].x * c.rows[0].x + rows[3].y * c.rows[1].x + rows[3].z * c.rows[2].x + rows[3].w * c.rows[3].x, 
                rows[3].x * c.rows[0].y + rows[3].y * c.rows[1].y + rows[3].z * c.rows[2].y + rows[3].w * c.rows[3].y, 
                rows[3].x * c.rows[0].z + rows[3].y * c.rows[1].z + rows[3].z * c.rows[2].z + rows[3].w * c.rows[3].z, 
                rows[3].x * c.rows[0].w + rows[3].y * c.rows[1].w + rows[3].z * c.rows[2].w + rows[3].w * c.rows[3].w
            )
        );
    }
    /**
     * @brief scale the matrix and return the result
     * 
     * @param s the scale to scale the matrix
     * @return s_dmat4 the scaled matrix
     */
    inline s_dmat4 operator*(double s) const noexcept {
        return s_dmat4(
            rows[0] * s,
            rows[1] * s,
            rows[2] * s,
            rows[3] * s
        );
    }
    /**
     * @brief multiply this matrix by an vector and return the result
     * 
     * @param v the vector
     * @return dvec4 the product of this matrix and the vector
     */
    inline dvec4 operator*(const dvec4& v) const noexcept {
        return dvec4(
            v.x * rows[0].x + v.y * rows[0].y + v.z * rows[0].z + v.w * rows[0].w,
            v.x * rows[1].x + v.y * rows[1].y + v.z * rows[1].z + v.w * rows[1].w,
            v.x * rows[2].x + v.y * rows[2].y + v.z * rows[2].z + v.w * rows[2].w,
            v.x * rows[3].x + v.y * rows[3].y + v.z * rows[3].z + v.w * rows[3].w
        );
    }
    /**
     * @brief multiply this matrix by another matrix
     * 
     * @param c the other matrix
     */
    inline constexpr void operator*=(s_dmat4 c) noexcept {
        //create a temporary container for the matrix elements
        s_dmat4 t = *this;
        //override the elements with the calculated values
        rows[0].x = t.rows[0].x * c.rows[0].x + t.rows[0].y * c.rows[1].x + t.rows[0].z * c.rows[2].x + t.rows[0].w * c.rows[3].x; 
        rows[0].y = t.rows[0].x * c.rows[0].y + t.rows[0].y * c.rows[1].y + t.rows[0].z * c.rows[2].y + t.rows[0].w * c.rows[3].y; 
        rows[0].z = t.rows[0].x * c.rows[0].z + t.rows[0].y * c.rows[1].z + t.rows[0].z * c.rows[2].z + t.rows[0].w * c.rows[3].z; 
        rows[0].w = t.rows[0].x * c.rows[0].w + t.rows[0].y * c.rows[1].w + t.rows[0].z * c.rows[2].w + t.rows[0].w * c.rows[3].w;
        rows[1].x = t.rows[1].x * c.rows[0].x + t.rows[1].y * c.rows[1].x + t.rows[1].z * c.rows[2].x + t.rows[1].w * c.rows[3].x; 
        rows[1].y = t.rows[1].x * c.rows[0].y + t.rows[1].y * c.rows[1].y + t.rows[1].z * c.rows[2].y + t.rows[1].w * c.rows[3].y; 
        rows[1].z = t.rows[1].x * c.rows[0].z + t.rows[1].y * c.rows[1].z + t.rows[1].z * c.rows[2].z + t.rows[1].w * c.rows[3].z; 
        rows[1].w = t.rows[1].x * c.rows[0].w + t.rows[1].y * c.rows[1].w + t.rows[1].z * c.rows[2].w + t.rows[1].w * c.rows[3].w;
        rows[2].x = t.rows[2].x * c.rows[0].x + t.rows[2].y * c.rows[1].x + t.rows[2].z * c.rows[2].x + t.rows[2].w * c.rows[3].x; 
        rows[2].y = t.rows[2].x * c.rows[0].y + t.rows[2].y * c.rows[1].y + t.rows[2].z * c.rows[2].y + t.rows[2].w * c.rows[3].y; 
        rows[2].z = t.rows[2].x * c.rows[0].z + t.rows[2].y * c.rows[1].z + t.rows[2].z * c.rows[2].z + t.rows[2].w * c.rows[3].z; 
        rows[2].w = t.rows[2].x * c.rows[0].w + t.rows[2].y * c.rows[1].w + t.rows[2].z * c.rows[2].w + t.rows[2].w * c.rows[3].w;
        rows[3].x = t.rows[3].x * c.rows[0].x + t.rows[3].y * c.rows[1].x + t.rows[3].z * c.rows[2].x + t.rows[3].w * c.rows[3].x; 
        rows[3].y = t.rows[3].x * c.rows[0].y + t.rows[3].y * c.rows[1].y + t.rows[3].z * c.rows[2].y + t.rows[3].w * c.rows[3].y; 
        rows[3].z = t.rows[3].x * c.rows[0].z + t.rows[3].y * c.rows[1].z + t.rows[3].z * c.rows[2].z + t.rows[3].w * c.rows[3].z; 
        rows[3].w = t.rows[3].x * c.rows[0].w + t.rows[3].y * c.rows[1].w + t.rows[3].z * c.rows[2].w + t.rows[3].w * c.rows[3].w;
    }
    /**
     * @brief scale this matrix
     * 
     * @param s the scale
     */
    inline void operator*=(double s) noexcept {
        rows[0] *= s;
        rows[1] *= s;
        rows[2] *= s;
        rows[3] *= s;
    }

    /**
     * @brief calculate the determinant of this matrix
     * 
     * @return double the determinant of this matrix
     */
    inline constexpr double determinant() const noexcept {
        /**
         * a deterimant of a 4x4 matrix is calculated like this:
         * det = m[0].x * det(M00) + m[0].y * det(M01) + m[0].z * det(M02) + m[0].w * det(M03)
         * Where Mxy denotes a 3x3 sub-matrix where the xth column and yth row are deleted
         * det() is a fictional command to compute the determinant of a 3x3 matrix
         * 
         * The determinant of a 3x3 matrix is computed as follows:
         * m[0].x * (m[1].y * m[2].z - m[1].z * m[2].y) - m[0].y * (m[1].x * m[2].z - m[1].z * m[2].x) + m[0].z * (m[1].x * m[2].y - m[1].y * m[2].x)
         * 
         * Now replacing each element with the correct index to fit the sub-matricies:
         * M00: m[1].y * (m[2].z * m[3].w - m[2].w * m[3].z) - m[1].z * (m[2].y * m[3].w - m[2].w * m[3].y) + m[1].w * (m[2].y * m[3].z - m[2].z * m[3].y)
         * M01: m[1].x * (m[2].z * m[3].w - m[2].w * m[3].z) - m[1].z * (m[2].x * m[3].w - m[2].w * m[3].x) + m[1].w * (m[2].x * m[3].z - m[2].z * m[3].x)
         * M02: m[1].x * (m[2].y * m[3].w - m[2].w * m[3].y) - m[1].y * (m[2].x * m[3].w - m[2].w * m[3].x) + m[1].w * (m[2].x * m[3].y - m[2].y * m[3].x)
         * M03: m[1].x * (m[2].y * m[3].z - m[2].z * m[3].y) - m[1].y * (m[2].x * m[3].z - m[2].z * m[3].x) + m[1].z * (m[2].x * m[3].y - m[2].y * m[3].x)
         * 
         * //plug the determinants into the exquation:
         */
        return (
            //m[0].x * det(M00)
            rows[0].x * (rows[1].y * (rows[2].z * rows[3].w - rows[2].w * rows[3].z) - rows[1].z * (rows[2].y * rows[3].w - rows[2].w * rows[3].y) + rows[1].w * (rows[2].y * rows[3].z - rows[2].z * rows[3].y)) - 
            //m[0].y * det(M01)
            rows[0].y * (rows[1].x * (rows[2].z * rows[3].w - rows[2].w * rows[3].z) - rows[1].z * (rows[2].x * rows[3].w - rows[2].w * rows[3].x) + rows[1].w * (rows[2].x * rows[3].z - rows[2].z * rows[3].x)) + 
            //m[0].z * det(M02)
            rows[0].z * (rows[1].x * (rows[2].y * rows[3].w - rows[2].w * rows[3].y) - rows[1].y * (rows[2].x * rows[3].w - rows[2].w * rows[3].x) + rows[1].w * (rows[2].x * rows[3].y - rows[2].y * rows[3].x)) - 
            //m[0].w * det(M03)
            rows[0].w * (rows[1].x * (rows[2].y * rows[3].z - rows[2].z * rows[3].y) - rows[1].y * (rows[2].x * rows[3].z - rows[2].z * rows[3].x) + rows[1].z * (rows[2].x * rows[3].y - rows[2].y * rows[3].x))
        );
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
     * @return constexpr s_dmat4 the cofactor matrix
     */
    inline constexpr s_dmat4 cofactors() const noexcept {
        /**
         * Value source: https://semath.info/src/cofactor-matrix.html
         * 
         * Representation in an intermediate format represented by a number for the row and a vector element (x,y,z or w) for the column
         * Example: 0x represents the top left element of the matrix and 3w the bottom right element
         * Multiplication can be represented by the multiply operator (*) or a space
         * 
         * Row 0:
         * 0x =  1y 2z 3w + 1z 2w 3y + 1w 2y 3z
         *      -1w 2z 3y - 1z 2y 3w - 1y 2w 3z
         * 0y =  0y 2z 3w + 0z 2w 3y + 0w 2y 3z
         *      -0w 2z 3y - 0z 2y 3w - 0y 2w 3z
         * 0z =  0y 1z 3w + 0z 1w 3y + 0w 1y 3z
         *      -0w 1z 3y - 0z 1y 3w - 0y 1w 3z
         * 0w =  0y 1z 2w + 0z 1w 2y + 0w 1y 2z
         *      -0w 1z 2y - 0z 1y 2w - 0y 1w 2z
         * 
         * Row 1:
         * 1x =  1x 2z 3w + 1z 2w 3x + 1w 2x 3z
         *      -1w 2z 3x - 1z 2x 3w - 1x 2w 3z
         * 1y =  0x 2z 3w + 0z 2w 3x + 0w 2x 3z
         *      -0w 2z 3x - 0z 2x 3w - 0x 2w 3z
         * 1z =  0x 1z 3w + 0z 1w 3x + 0w 1x 3z
         *      -0w 1z 3x - 0z 1x 3w - 0x 1w 3z
         * 1w =  0x 1z 2w + 0z 1w 2x + 0w 1x 2z
         *      -0w 1z 2x - 0z 1x 2w - 0x 1w 2z
         * 
         * Row 2:
         * 2x =  1x 2y 3w + 1y 2w 3x + 1w 2x 3y
         *      -1w 2y 3x - 1y 2x 3w - 1x 2w 3y
         * 2y =  0x 2y 3w + 0y 2w 3x + 0w 2x 3y
         *      -0w 2y 3x - 0y 2x 3w - 0x 2w 3y
         * 2z =  0x 1y 3w + 0y 1w 3x + 0w 1x 3y
         *      -0w 1y 3x - 0y 1x 3w - 0x 1w 3y
         * 2w =  0x 1y 2w + 0y 1w 2x + 0w 1x 2y
         *      -0w 1y 2x - 0y 1x 2w - 0x 1w 2y
         * 
         * Row 3:
         * 3x =  1x 2y 3z + 1y 2z 3x + 1z 2x 3y
         *      -1z 2y 3x - 1y 2x 3z - 1x 2z 3y
         * 3y =  0x 2y 3z + 0y 2z 3x + 0z 2x 3y
         *      -0z 2y 3x - 0y 2x 3z - 0x 2z 3y
         * 3z =  0x 1y 3z + 0y 1z 3x + 0z 1x 3y
         *      -0z 1y 3x - 0y 1x 3z - 0x 1z 3y
         * 1w =  0x 1y 2z + 0y 1z 2x + 0z 1x 2y
         *      -0z 1y 2x - 0y 1x 2z - 0x 1z 2y
         * 
         * Plug all the values into a single matrix to compute the cofactor matrix of any 4x4 matrix
         * Warning: The values above are TRANSPOSED in comparison to my default layout
         */
        return s_dmat4(
            //row 0
            dvec4(
                 (rows[1].y * rows[2].z * rows[3].w + rows[1].z * rows[2].w * rows[3].y + rows[1].w * rows[2].y * rows[3].z
                  -rows[1].w * rows[2].z * rows[3].y - rows[1].z * rows[2].y * rows[3].w - rows[1].y * rows[2].w * rows[3].z),
                -(rows[1].x * rows[2].z * rows[3].w + rows[1].z * rows[2].w * rows[3].x + rows[1].w * rows[2].x * rows[3].z
                  -rows[1].w * rows[2].z * rows[3].x - rows[1].z * rows[2].x * rows[3].w - rows[1].x * rows[2].w * rows[3].z),
                 (rows[1].x * rows[2].y * rows[3].w + rows[1].y * rows[2].w * rows[3].x + rows[1].w * rows[2].x * rows[3].y
                  -rows[1].w * rows[2].y * rows[3].x - rows[1].y * rows[2].x * rows[3].w - rows[1].x * rows[2].w * rows[3].y),
                -(rows[1].x * rows[2].y * rows[3].z + rows[1].y * rows[2].z * rows[3].x + rows[1].z * rows[2].x * rows[3].y
                  -rows[1].z * rows[2].y * rows[3].x - rows[1].y * rows[2].x * rows[3].z - rows[1].x * rows[2].z * rows[3].y)
            ),
            //row 1
            dvec4(
                -(rows[0].y * rows[2].z * rows[3].w + rows[0].z * rows[2].w * rows[3].y + rows[0].w * rows[2].y * rows[3].z
                  -rows[0].w * rows[2].z * rows[3].y - rows[0].z * rows[2].y * rows[3].w - rows[0].y * rows[2].w * rows[3].z),
                 (rows[0].x * rows[2].z * rows[3].w + rows[0].z * rows[2].w * rows[3].x + rows[0].w * rows[2].x * rows[3].z
                  -rows[0].w * rows[2].z * rows[3].x - rows[0].z * rows[2].x * rows[3].w - rows[0].x * rows[2].w * rows[3].z),
                -(rows[0].x * rows[2].y * rows[3].w + rows[0].y * rows[2].w * rows[3].x + rows[0].w * rows[2].x * rows[3].y
                  -rows[0].w * rows[2].y * rows[3].x - rows[0].y * rows[2].x * rows[3].w - rows[0].x * rows[2].w * rows[3].y),
                 (rows[0].x * rows[2].y * rows[3].z + rows[0].y * rows[2].z * rows[3].x + rows[0].z * rows[2].x * rows[3].y
                  -rows[0].z * rows[2].y * rows[3].x - rows[0].y * rows[2].x * rows[3].z - rows[0].x * rows[2].z * rows[3].y)
            ),
            //row 2
            dvec4(
                 (rows[0].y * rows[1].z * rows[3].w + rows[0].z * rows[1].w * rows[3].y + rows[0].w * rows[1].y * rows[3].z
                  -rows[0].w * rows[1].z * rows[3].y - rows[0].z * rows[1].y * rows[3].w - rows[0].y * rows[1].w * rows[3].z),
                -(rows[0].x * rows[1].z * rows[3].w + rows[0].z * rows[1].w * rows[3].x + rows[0].w * rows[1].x * rows[3].z
                  -rows[0].w * rows[1].z * rows[3].x - rows[0].z * rows[1].x * rows[3].w - rows[0].x * rows[1].w * rows[3].z),
                 (rows[0].x * rows[1].y * rows[3].w + rows[0].y * rows[1].w * rows[3].x + rows[0].w * rows[1].x * rows[3].y
                  -rows[0].w * rows[1].y * rows[3].x - rows[0].y * rows[1].x * rows[3].w - rows[0].x * rows[1].w * rows[3].y),
                -(rows[0].x * rows[1].y * rows[3].z + rows[0].y * rows[1].z * rows[3].x + rows[0].z * rows[1].x * rows[3].y
                  -rows[0].z * rows[1].y * rows[3].x - rows[0].y * rows[1].x * rows[3].z - rows[0].x * rows[1].z * rows[3].y)
            ),
            //row 3
            dvec4(
                -(rows[0].y * rows[1].z * rows[2].w + rows[0].z * rows[1].w * rows[2].y + rows[0].w * rows[1].y * rows[2].z
                  -rows[0].w * rows[1].z * rows[2].y - rows[0].z * rows[1].y * rows[2].w - rows[0].y * rows[1].w * rows[2].z),
                 (rows[0].x * rows[1].z * rows[2].w + rows[0].z * rows[1].w * rows[2].x + rows[0].w * rows[1].x * rows[2].z
                  -rows[0].w * rows[1].z * rows[2].x - rows[0].z * rows[1].x * rows[2].w - rows[0].x * rows[1].w * rows[2].z),
                -(rows[0].x * rows[1].y * rows[2].w + rows[0].y * rows[1].w * rows[2].x + rows[0].w * rows[1].x * rows[2].y
                  -rows[0].w * rows[1].y * rows[2].x - rows[0].y * rows[1].x * rows[2].w - rows[0].x * rows[1].w * rows[2].y),
                 (rows[0].x * rows[1].y * rows[2].z + rows[0].y * rows[1].z * rows[2].x + rows[0].z * rows[1].x * rows[2].y
                  -rows[0].z * rows[1].y * rows[2].x - rows[0].y * rows[1].x * rows[2].z - rows[0].x * rows[1].z * rows[2].y)
            )
        );
    };

    /**
     * @brief get the transpose of the matrix
     * 
     * @return constexpr s_dmat4 the transposed matrix
     */
    inline constexpr s_dmat4 transpose() const noexcept {
        return s_dmat4(
            dvec4(rows[0].x, rows[1].x, rows[2].x, rows[3].x),
            dvec4(rows[0].y, rows[1].y, rows[2].y, rows[3].y), 
            dvec4(rows[0].z, rows[1].z, rows[2].z, rows[3].z), 
            dvec4(rows[0].w, rows[1].w, rows[2].w, rows[3].w)
        );
    }

    /**
     * @brief compute the adjugate matrix of a 4*4 double matrix
     * 
     * @return constexpr s_dmat4 the adjugate matrix of this matrix
     */
    inline constexpr s_dmat4 adjugate() const noexcept {
        //same as the cofactor computation, but rows and columns are swapped
        return s_dmat4(
            //row 0
            dvec4(
                  (rows[1].y * rows[2].z * rows[3].w + rows[1].z * rows[2].w * rows[3].y + rows[1].w * rows[2].y * rows[3].z
                   -rows[1].w * rows[2].z * rows[3].y - rows[1].z * rows[2].y * rows[3].w - rows[1].y * rows[2].w * rows[3].z),
                -(rows[0].y * rows[2].z * rows[3].w + rows[0].z * rows[2].w * rows[3].y + rows[0].w * rows[2].y * rows[3].z
                   -rows[0].w * rows[2].z * rows[3].y - rows[0].z * rows[2].y * rows[3].w - rows[0].y * rows[2].w * rows[3].z),
                  (rows[0].y * rows[1].z * rows[3].w + rows[0].z * rows[1].w * rows[3].y + rows[0].w * rows[1].y * rows[3].z
                   -rows[0].w * rows[1].z * rows[3].y - rows[0].z * rows[1].y * rows[3].w - rows[0].y * rows[1].w * rows[3].z),
                -(rows[0].y * rows[1].z * rows[2].w + rows[0].z * rows[1].w * rows[2].y + rows[0].w * rows[1].y * rows[2].z
                   -rows[0].w * rows[1].z * rows[2].y - rows[0].z * rows[1].y * rows[2].w - rows[0].y * rows[1].w * rows[2].z)
            ),
            //row 1
            dvec4(
                -(rows[1].x * rows[2].z * rows[3].w + rows[1].z * rows[2].w * rows[3].x + rows[1].w * rows[2].x * rows[3].z
                  -rows[1].w * rows[2].z * rows[3].x - rows[1].z * rows[2].x * rows[3].w - rows[1].x * rows[2].w * rows[3].z),
                 (rows[0].x * rows[2].z * rows[3].w + rows[0].z * rows[2].w * rows[3].x + rows[0].w * rows[2].x * rows[3].z
                  -rows[0].w * rows[2].z * rows[3].x - rows[0].z * rows[2].x * rows[3].w - rows[0].x * rows[2].w * rows[3].z),
                -(rows[0].x * rows[1].z * rows[3].w + rows[0].z * rows[1].w * rows[3].x + rows[0].w * rows[1].x * rows[3].z
                  -rows[0].w * rows[1].z * rows[3].x - rows[0].z * rows[1].x * rows[3].w - rows[0].x * rows[1].w * rows[3].z),
                 (rows[0].x * rows[1].z * rows[2].w + rows[0].z * rows[1].w * rows[2].x + rows[0].w * rows[1].x * rows[2].z
                  -rows[0].w * rows[1].z * rows[2].x - rows[0].z * rows[1].x * rows[2].w - rows[0].x * rows[1].w * rows[2].z)
            ),
            //row 2
            dvec4(
                 (rows[1].x * rows[2].y * rows[3].w + rows[1].y * rows[2].w * rows[3].x + rows[1].w * rows[2].x * rows[3].y
                  -rows[1].w * rows[2].y * rows[3].x - rows[1].y * rows[2].x * rows[3].w - rows[1].x * rows[2].w * rows[3].y),
                -(rows[0].x * rows[2].y * rows[3].w + rows[0].y * rows[2].w * rows[3].x + rows[0].w * rows[2].x * rows[3].y
                  -rows[0].w * rows[2].y * rows[3].x - rows[0].y * rows[2].x * rows[3].w - rows[0].x * rows[2].w * rows[3].y),
                 (rows[0].x * rows[1].y * rows[3].w + rows[0].y * rows[1].w * rows[3].x + rows[0].w * rows[1].x * rows[3].y
                  -rows[0].w * rows[1].y * rows[3].x - rows[0].y * rows[1].x * rows[3].w - rows[0].x * rows[1].w * rows[3].y),
                -(rows[0].x * rows[1].y * rows[2].w + rows[0].y * rows[1].w * rows[2].x + rows[0].w * rows[1].x * rows[2].y
                  -rows[0].w * rows[1].y * rows[2].x - rows[0].y * rows[1].x * rows[2].w - rows[0].x * rows[1].w * rows[2].y)
            ),
            //row 3
            dvec4(
                -(rows[1].x * rows[2].y * rows[3].z + rows[1].y * rows[2].z * rows[3].x + rows[1].z * rows[2].x * rows[3].y
                  -rows[1].z * rows[2].y * rows[3].x - rows[1].y * rows[2].x * rows[3].z - rows[1].x * rows[2].z * rows[3].y),
                 (rows[0].x * rows[2].y * rows[3].z + rows[0].y * rows[2].z * rows[3].x + rows[0].z * rows[2].x * rows[3].y
                  -rows[0].z * rows[2].y * rows[3].x - rows[0].y * rows[2].x * rows[3].z - rows[0].x * rows[2].z * rows[3].y),
                -(rows[0].x * rows[1].y * rows[3].z + rows[0].y * rows[1].z * rows[3].x + rows[0].z * rows[1].x * rows[3].y
                  -rows[0].z * rows[1].y * rows[3].x - rows[0].y * rows[1].x * rows[3].z - rows[0].x * rows[1].z * rows[3].y),
                 (rows[0].x * rows[1].y * rows[2].z + rows[0].y * rows[1].z * rows[2].x + rows[0].z * rows[1].x * rows[2].y
                  -rows[0].z * rows[1].y * rows[2].x - rows[0].y * rows[1].x * rows[2].z - rows[0].x * rows[1].z * rows[2].y)
            )
        );
    }

    /**
     * @brief calculate the inverse of the matrix
     * 
     * @return s_dmat4 the inverse matrix
     */
    inline s_dmat4 inverse() const noexcept {
        //cache the inverse determinant
        double inv_det = 1.f / determinant();
        //return a matrix where all elements are swapped correctly and scaled by the inverse determinant
        return cofactors() * inv_det;
    }

    #endif

} dmat4;

//for C++ start a C-Section
#if __cplusplus
extern "C" {
#endif

/**
 * @brief add two 4x4 double matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return dmat4 the sum of the matrices
 */
dmat4 dmat4_add(const dmat4* a, const dmat4* b);

/**
 * @brief add a double to a 4x4 matrix
 * 
 * @param a a constant pointer to the matrix to add to
 * @param b the double to add to the matrix
 * @return dmat4 the sum of the matrix and the scalar
 */
dmat4 dmat4_adddouble(const dmat4* a, double b);

/**
 * @brief add a matrix to another matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b a constant pointer to the matrix to add to a
 */
void dmat4_addTo(dmat4* a, const dmat4* b);

/**
 * @brief add a double to a matrix
 * 
 * @param a a pointer to the matrix to add to
 * @param b the double to add to a
 */
void dmat4_adddoubleTo(dmat4* a, double b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return dmat4 the difference of all elements
 */
dmat4 dmat4_subtract(const dmat4* a, const dmat4* b);

/**
 * @brief subtract a double from the matrix
 * 
 * @param a a constant pointer to the matrix to subtract from
 * @param b the double to subtract from the matrix
 * @return dmat4 the difference of the matrix and the scalar
 */
dmat4 dmat4_subtractdouble(const dmat4* a, double b);

/**
 * @brief subtract a matrix from another matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b a constant pointer to the matrix to subtract from a
 */
void dmat4_subtractFrom(dmat4* a, const dmat4* b);

/**
 * @brief subtract a double from a matrix
 * 
 * @param a a pointer to the matrix to subtract from
 * @param b the double to subtract from the matrix
 */
void dmat4_subtractdoubleFrom(dmat4* a, double b);

/**
 * @brief multiply two matrices together
 * 
 * @param a a constant pointer to the first matrix
 * @param b a constant pointer to the second matrix
 * @return dmat4 the product of both matrices
 */
dmat4 dmat4_multiply(const dmat4* a, const dmat4* b);

/**
 * @brief scale a matrix by a scalar
 * 
 * @param a a constant pointer to the matrix to scale
 * @param b the double to scale the matrix with
 * @return dmat4 the scaled matrix
 */
dmat4 dmat4_scale(const dmat4* a, double b);

/**
 * @brief apply the matrix to a vector by multiplying them together
 * 
 * @param a a constant pointer to the matrix to apply
 * @param b a constant pointer to the vector to multiply with the matrix
 * @return dvec4 the product of the matrix and the vector
 */
dvec4 dmat4_apply(const dmat4* a, const dvec4* b);

/**
 * @brief multiply another matrix to a matrix
 * 
 * @param a a pointer to the matrix to multiply with and to
 * @param b a constant pointer to the matrix to multiply with
 */
void dmat4_multiplyTo(dmat4* a, const dmat4* b);

/**
 * @brief scale a matrix to a matrix
 * 
 * @param a a pointer to the matrix to scale
 * @param b the double to scale the matrix with
 */
void dmat4_scaleTo(dmat4* a, double b);

/**
 * @brief compute the determinant of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the determinant of
 * @return double the determinant of the matrix
 */
double dmat4_determinant(const dmat4* mat);

/**
 * @brief check if a matrix has an inverse matrix
 * 
 * @param mat a constant pointer to the matrix to check
 * @return true : an inverse matrix can be constructured
 * @return false : no inverse matrix exists
 */
bool dmat4_hasInverse(const dmat4* mat);

/**
 * @brief get the cofactor matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the cofactors of
 * @return dmat4 the cofactor matrix
 */
dmat4 dmat4_cofactors(const dmat4* mat);

/**
 * @brief compute the adjugate matrix of a matrix
 * 
 * @param mat a constant pointer to the matrix to compute the adjugate matrix for
 * @return dmat4 the adjugate matrix
 */
dmat4 dmat4_adjugate(const dmat4* mat);

/**
 * @brief compute the transpose of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the transpose of
 * @return dmat4 the transposed matrix
 */
dmat4 dmat4_traspose(const dmat4* mat);

/**
 * @brief compute the inverse of a matrix
 * 
 * @param mat a constant pointer to a matrix to compute the inverse of
 * @return dmat4 the inverse matrix
 */
dmat4 dmat4_inverse(const dmat4* mat);

//end a potential C-Section
#if __cplusplus
}
#endif

#endif