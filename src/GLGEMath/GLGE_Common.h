/**
 * @file GLGE_Common.h
 * @author DM8AT
 * @brief define all functions that don't really fit into a specific section of the library
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_COMMON_
#define _GLGE_COMMON_

//include the settings
#include "GLGEMath_Settings.h"

//define a constexpression collection for C++
#if __cplusplus

//include the C Math library for functions
#include <cmath>

/**
 * @brief use the GLGE namespace as the names used are quite common
 */
namespace glge
{

    /**
     * @brief compute the squareroot of a value
     * 
     * @param value the value to compute the squareroot of
     * @return float the squareroot of the inputted value
     */
    inline constexpr float sqrt(float value) noexcept(true) {return sqrtf(value);} 

};

#endif

//make all functions available for C
#if __cplusplus
extern "C" {
#endif

/**
 * @brief compute the squareroot of a value
 * 
 * @param value the value to compute the squareroot of
 * @return float the squareroot of the inputted value
 */
float glge_sqrt(float value);

//end the C section
#if __cplusplus
}
#endif

#endif