/// @ref ext_vector_ulp
/// @file glm/ext/vector_ulp.hpp
///
/// @defgroup ext_vector_ulp GLM_EXT_vector_ulp
/// @ingroup ext
///
/// Allow the measurement of the accuracy of a function against a reference
/// implementation. This extension works on floating-point data and provide results
/// in ULP.
///
/// Include <glm/ext/vector_ulp.hpp> to use the features of this extension.
///
/// @see ext_scalar_ulp
/// @see ext_scalar_relational
/// @see ext_vector_relational

#pragma once

// Dependencies
#include "../ext/scalar_ulp.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_ulp extension included")
#endif

namespace glm
{
	/// Return the next ULP value(s) after the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> nextFloat(vec<L, T> const& x);

	/// Return the value(s) ULP distance after the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> nextFloat(vec<L, T> const& x, int ULPs);

	/// Return the value(s) ULP distance after the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> nextFloat(vec<L, T> const& x, vec<L, int> const& ULPs);

	/// Return the previous ULP value(s) before the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> prevFloat(vec<L, T> const& x);

	/// Return the value(s) ULP distance before the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> prevFloat(vec<L, T> const& x, int ULPs);

	/// Return the value(s) ULP distance before the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> prevFloat(vec<L, T> const& x, vec<L, int> const& ULPs);

	/// Return the distance in the number of ULP between 2 single-precision floating-point scalars.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, int> floatDistance(vec<L, float> const& x, vec<L, float> const& y);

	/// Return the distance in the number of ULP between 2 double-precision floating-point scalars.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_scalar_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, int64> floatDistance(vec<L, double> const& x, vec<L, double> const& y);

	/// @}
}//namespace glm

#include "vector_ulp.inl"
