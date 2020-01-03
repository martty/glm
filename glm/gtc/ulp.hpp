/// @ref gtc_ulp
/// @file glm/gtc/ulp.hpp
///
/// @see core (dependence)
///
/// @defgroup gtc_ulp GLM_GTC_ulp
/// @ingroup gtc
///
/// Include <glm/gtc/ulp.hpp> to use the features of this extension.
///
/// Allow the measurement of the accuracy of a function against a reference
/// implementation. This extension works on floating-point data and provide results
/// in ULP.

#pragma once

// Dependencies
#include "../detail/setup.hpp"
#include "../detail/_vectorize.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTC_ulp extension included")
#endif

namespace glm
{
	/// Return the next ULP value(s) after the input value(s).
	///
	/// @tparam genType A floating-point scalar type.
	///
	/// @see gtc_ulp
	template<typename genType>
	GLM_FUNC_DECL genType next_float(genType x);

	/// Return the previous ULP value(s) before the input value(s).
	///
	/// @tparam genType A floating-point scalar type.
	///
	/// @see gtc_ulp
	template<typename genType>
	GLM_FUNC_DECL genType prev_float(genType x);

	/// Return the value(s) ULP distance after the input value(s).
	///
	/// @tparam genType A floating-point scalar type.
	///
	/// @see gtc_ulp
	template<typename genType>
	GLM_FUNC_DECL genType next_float(genType x, int ULPs);

	/// Return the value(s) ULP distance before the input value(s).
	///
	/// @tparam genType A floating-point scalar type.
	///
	/// @see gtc_ulp
	template<typename genType>
	GLM_FUNC_DECL genType prev_float(genType x, int ULPs);

	/// Return the distance in the number of ULP between 2 single-precision floating-point scalars.
	///
	/// @see gtc_ulp
	GLM_FUNC_DECL int float_distance(float x, float y);

	/// Return the distance in the number of ULP between 2 double-precision floating-point scalars.
	///
	/// @see gtc_ulp
	GLM_FUNC_DECL int64 float_distance(double x, double y);

	/// Return the next ULP value(s) after the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> next_float(vec<L, T> const& x);

	/// Return the value(s) ULP distance after the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> next_float(vec<L, T> const& x, int ULPs);

	/// Return the value(s) ULP distance after the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> next_float(vec<L, T> const& x, vec<L, int> const& ULPs);

	/// Return the previous ULP value(s) before the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> prev_float(vec<L, T> const& x);

	/// Return the value(s) ULP distance before the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> prev_float(vec<L, T> const& x, int ULPs);

	/// Return the value(s) ULP distance before the input value(s).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> prev_float(vec<L, T> const& x, vec<L, int> const& ULPs);

	/// Return the distance in the number of ULP between 2 single-precision floating-point scalars.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, int> float_distance(vec<L, float> const& x, vec<L, float> const& y);

	/// Return the distance in the number of ULP between 2 double-precision floating-point scalars.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam Q Value from qualifier enum
	///
	/// @see gtc_ulp
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, int64> float_distance(vec<L, double> const& x, vec<L, double> const& y);

	/// @}
}//namespace glm

#include "ulp.inl"
