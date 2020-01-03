/// @ref gtx_rotate_vector
/// @file glm/gtx/rotate_vector.hpp
///
/// @see core (dependence)
/// @see gtx_transform (dependence)
///
/// @defgroup gtx_rotate_vector GLM_GTX_rotate_vector
/// @ingroup gtx
///
/// Include <glm/gtx/rotate_vector.hpp> to use the features of this extension.
///
/// Function to directly rotate a vector

#pragma once

// Dependency:
#include "../gtx/transform.hpp"
#include "../gtc/epsilon.hpp"
#include "../ext/vector_relational.hpp"
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_rotate_vector is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_rotate_vector extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_rotate_vector
	/// @{

	/// Returns Spherical interpolation between two vectors
	///
	/// @param x A first vector
	/// @param y A second vector
	/// @param a Interpolation factor. The interpolation is defined beyond the range [0, 1].
	///
	/// @see gtx_rotate_vector
	template<typename T>
	GLM_FUNC_DECL vec<3, T> slerp(
		vec<3, T> const& x,
		vec<3, T> const& y,
		T const& a);

	//! Rotate a two dimensional vector.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<2, T> rotate(
		vec<2, T> const& v,
		T const& angle);

	//! Rotate a three dimensional vector around an axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<3, T> rotate(
		vec<3, T> const& v,
		T const& angle,
		vec<3, T> const& normal);

	//! Rotate a four dimensional vector around an axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<4, T> rotate(
		vec<4, T> const& v,
		T const& angle,
		vec<3, T> const& normal);

	//! Rotate a three dimensional vector around the X axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<3, T> rotateX(
		vec<3, T> const& v,
		T const& angle);

	//! Rotate a three dimensional vector around the Y axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<3, T> rotateY(
		vec<3, T> const& v,
		T const& angle);

	//! Rotate a three dimensional vector around the Z axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<3, T> rotateZ(
		vec<3, T> const& v,
		T const& angle);

	//! Rotate a four dimensional vector around the X axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<4, T> rotateX(
		vec<4, T> const& v,
		T const& angle);

	//! Rotate a four dimensional vector around the Y axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<4, T> rotateY(
		vec<4, T> const& v,
		T const& angle);

	//! Rotate a four dimensional vector around the Z axis.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL vec<4, T> rotateZ(
		vec<4, T> const& v,
		T const& angle);

	//! Build a rotation matrix from a normal and a up vector.
	//! From GLM_GTX_rotate_vector extension.
	template<typename T>
	GLM_FUNC_DECL mat<4, 4, T> orientation(
		vec<3, T> const& Normal,
		vec<3, T> const& Up);

	/// @}
}//namespace glm

#include "rotate_vector.inl"
