/**
 * @file VectorCast.hpp
 * @author DM8AT
 * @brief define a C++ only API to cast vector types to scalars
 * 
 * The vector type casting can be expanded to custom vectors
 * 
 * @version 0.1
 * @date 2025-10-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//header guard
#ifndef _GLGE_MATH_VECTOR_CAST_
#define _GLGE_MATH_VECTOR_CAST_

//only available for C++
#if __cplusplus

//include C++ type traits
#include <type_traits>

//include integer
#include <cstdint>
//include all vector types
#include "floats/GLGEVecFloats.h"
#include "doubles/GLGEVecDoubles.h"
#include "int32_t/GLGEVecInts.h"
#include "uint32_t/GLGEVecUInts.h"

//A struct to define the casting traits of a type
template <typename T> struct VectorCastTrait {}; 

//Trait specialization with element type, base type, and element count of a vector / scalar type
template <typename _T, typename _Base, uint8_t _ElementCount> struct VectorCastTraitBase {
    //just add an alias for the _T element to be used as the more default T element
    using T = _T;
    //the same as for T
    using Base = _Base;
    //store the element count as a static constexpression for easy access
    static constexpr uint8_t Elements = _ElementCount;

    /**
     * @brief convert from one VectorCastTraitBase type to another
     * 
     * @tparam From the type of the base to convert from
     * @param from the element to cast from
     * @return constexpr _T the casted element
     */
    template <typename From> static constexpr _T make(const From& from) noexcept {
        //get the required elements from the trait corresponding to the from element
        using FromTrait = VectorCastTrait<From>;
        using FromBase = typename FromTrait::Base;

        //Allocate temporary output array
        _Base out[_ElementCount] = {};

        //get the base pointer of the array of elements from the element to cast from
        const FromBase* in = reinterpret_cast<const FromBase*>(&from);

        //cast all elements of the vector element by the following rules:
        //if the element is in range, simply cast the element type
        //if there are too little elements, zero-pad the input
        //if there are too much elements, truncate the vector to the requested size
        for (uint8_t i = 0; i < _ElementCount; ++i) {
            out[i] = (i < FromTrait::Elements) ? static_cast<_Base>(in[i]) : _Base{ 0 };
        }

        //re-interpret the array. Vector types are tightly packed together
        return *reinterpret_cast<const _T*>(out);
    }
};

//overloads

//float stuff
template <> struct VectorCastTrait<float> : VectorCastTraitBase<float, float, 1> {};
template <> struct VectorCastTrait<vec2>  : VectorCastTraitBase<vec2, float, 2> {};
template <> struct VectorCastTrait<vec3>  : VectorCastTraitBase<vec3, float, 3> {};
template <> struct VectorCastTrait<vec4>  : VectorCastTraitBase<vec4, float, 4> {};
//double stuff
template <> struct VectorCastTrait<double> : VectorCastTraitBase<double, double, 1> {};
template <> struct VectorCastTrait<dvec2>  : VectorCastTraitBase<dvec2, double, 2> {};
template <> struct VectorCastTrait<dvec3>  : VectorCastTraitBase<dvec3, double, 3> {};
template <> struct VectorCastTrait<dvec4>  : VectorCastTraitBase<dvec4, double, 4> {};
//int32 stuff
template <> struct VectorCastTrait<int32_t> : VectorCastTraitBase<int32_t, int32_t, 1> {};
template <> struct VectorCastTrait<ivec2>   : VectorCastTraitBase<ivec2, int32_t, 2> {};
template <> struct VectorCastTrait<ivec3>   : VectorCastTraitBase<ivec3, int32_t, 3> {};
template <> struct VectorCastTrait<ivec4>   : VectorCastTraitBase<ivec4, int32_t, 4> {};
//uint32 stuff
template <> struct VectorCastTrait<uint32_t> : VectorCastTraitBase<uint32_t, uint32_t, 1> {};
template <> struct VectorCastTrait<uivec2>   : VectorCastTraitBase<uivec2, uint32_t, 2> {};
template <> struct VectorCastTrait<uivec3>   : VectorCastTraitBase<uivec3, uint32_t, 3> {};
template <> struct VectorCastTrait<uivec4>   : VectorCastTraitBase<uivec4, uint32_t, 4> {};

/**
 * @brief a constant expression to cast from one vector / scalar type to another
 * 
 * If the input has the exact same element count as the output, all elements will be casted. 
 * If the input has less elements than the output, the missing elements will be added with zero padding.
 * If the input has more elements than the output, the elements that don't fit into the output vector will be cut of
 * 
 * @tparam To the type to cast to. A overload of VectorCastTrait must exist for the element. 
 * @tparam From the type to cast to. A overload of VectorCastTrait must exist for the element. 
 * @param from the element to cast to the type To
 * @return constexpr To the result of the cast
 */
template <typename To, typename From> constexpr To vectorCast(const From& from) {return VectorCastTrait<To>::make(from);}

#endif

#endif