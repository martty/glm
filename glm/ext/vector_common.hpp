/// @ref ext_vector_common
/// @file glm/ext/vector_common.hpp
///
/// @defgroup ext_vector_common GLM_EXT_vector_common
/// @ingroup ext
///
/// Exposes min and max functions for 3 to 4 vector parameters.
///
/// Include <glm/ext/vector_common.hpp> to use the features of this extension.
///
/// @see core_common
/// @see ext_scalar_common

#pragma once

// Dependency:
#include "../ext/scalar_common.hpp"
#include "../common.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_common extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_common
	/// @{

	/// Return the minimum component-wise values of 3 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T> min(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c);

	/// Return the minimum component-wise values of 4 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T> min(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c, vec<L, T> const& d);

	/// Return the maximum component-wise values of 3 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T> max(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& z);

	/// Return the maximum component-wise values of 4 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T> max( vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& z, vec<L, T> const& w);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmin(vec<L, T> const& x, T y);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmin(vec<L, T> const& x, vec<L, T> const& y);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmin(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c);

	/// Returns y if y < x; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmin">std::fmin documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmin(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c, vec<L, T> const& d);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmax(vec<L, T> const& a, T b);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmax(vec<L, T> const& a, vec<L, T> const& b);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmax(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c);

	/// Returns y if x < y; otherwise, it returns x. If one of the two arguments is NaN, the value of the other argument is returned.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see <a href="http://en.cppreference.com/w/cpp/numeric/math/fmax">std::fmax documentation</a>
	template<length_t L, typename T>
	GLM_FUNC_DECL vec<L, T> fmax(vec<L, T> const& a, vec<L, T> const& b, vec<L, T> const& c, vec<L, T> const& d);

	/// @}
}//namespace glm

#include "vector_common.inl"
