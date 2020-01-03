/// @ref ext_vector_relational
/// @file glm/ext/vector_relational.hpp
///
/// @see core (dependence)
/// @see ext_scalar_integer (dependence)
///
/// @defgroup ext_vector_relational GLM_EXT_vector_relational
/// @ingroup ext
///
/// Exposes comparison functions for vector types that take a user defined epsilon values.
///
/// Include <glm/ext/vector_relational.hpp> to use the features of this extension.
///
/// @see core_vector_relational
/// @see ext_scalar_relational
/// @see ext_matrix_relational

#pragma once

#include "../detail/setup.hpp"
namespace glm {
	template<length_t L, typename T> struct vec;
}

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_relational extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_relational
	/// @{

	/// Returns the component-wise comparison of |x - y| < epsilon.
	/// True if this expression is satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> equal(vec<L, T> const& x, vec<L, T> const& y, T epsilon);

	/// Returns the component-wise comparison of |x - y| < epsilon.
	/// True if this expression is satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> equal(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& epsilon);

	/// Returns the component-wise comparison of |x - y| >= epsilon.
	/// True if this expression is not satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> notEqual(vec<L, T> const& x, vec<L, T> const& y, T epsilon);

	/// Returns the component-wise comparison of |x - y| >= epsilon.
	/// True if this expression is not satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> notEqual(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& epsilon);

	/// Returns the component-wise comparison between two vectors in term of ULPs.
	/// True if this expression is satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> equal(vec<L, T> const& x, vec<L, T> const& y, int ULPs);

	/// Returns the component-wise comparison between two vectors in term of ULPs.
	/// True if this expression is satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> equal(vec<L, T> const& x, vec<L, T> const& y, vec<L, int> const& ULPs);

	/// Returns the component-wise comparison between two vectors in term of ULPs.
	/// True if this expression is not satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> notEqual(vec<L, T> const& x, vec<L, T> const& y, int ULPs);

	/// Returns the component-wise comparison between two vectors in term of ULPs.
	/// True if this expression is not satisfied.
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, bool> notEqual(vec<L, T> const& x, vec<L, T> const& y, vec<L, int> const& ULPs);

	/// @}
}//namespace glm

#include "vector_relational.inl"
