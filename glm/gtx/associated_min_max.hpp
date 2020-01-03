/// @ref gtx_associated_min_max
/// @file glm/gtx/associated_min_max.hpp
///
/// @see core (dependence)
/// @see gtx_extented_min_max (dependence)
///
/// @defgroup gtx_associated_min_max GLM_GTX_associated_min_max
/// @ingroup gtx
///
/// Include <glm/gtx/associated_min_max.hpp> to use the features of this extension.
///
/// @brief Min and max functions that return associated values not the compared onces.

#pragma once

// Dependency:
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_associated_min_max is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_associated_min_max extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_associated_min_max
	/// @{

	/// Minimum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<typename T, typename U>
	GLM_FUNC_DECL U associatedMin(T x, U a, T y, U b);

	/// Minimum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<2, U> associatedMin(
		vec<L, T> const& x, vec<L, U> const& a,
		vec<L, T> const& y, vec<L, U> const& b);

	/// Minimum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMin(
		T x, const vec<L, U>& a,
		T y, const vec<L, U>& b);

	/// Minimum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMin(
		vec<L, T> const& x, U a,
		vec<L, T> const& y, U b);

	/// Minimum comparison between 3 variables and returns 3 associated variable values
	/// @see gtx_associated_min_max
	template<typename T, typename U>
	GLM_FUNC_DECL U associatedMin(
		T x, U a,
		T y, U b,
		T z, U c);

	/// Minimum comparison between 3 variables and returns 3 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMin(
		vec<L, T> const& x, vec<L, U> const& a,
		vec<L, T> const& y, vec<L, U> const& b,
		vec<L, T> const& z, vec<L, U> const& c);

	/// Minimum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<typename T, typename U>
	GLM_FUNC_DECL U associatedMin(
		T x, U a,
		T y, U b,
		T z, U c,
		T w, U d);

	/// Minimum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMin(
		vec<L, T> const& x, vec<L, U> const& a,
		vec<L, T> const& y, vec<L, U> const& b,
		vec<L, T> const& z, vec<L, U> const& c,
		vec<L, T> const& w, vec<L, U> const& d);

	/// Minimum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMin(
		T x, vec<L, U> const& a,
		T y, vec<L, U> const& b,
		T z, vec<L, U> const& c,
		T w, vec<L, U> const& d);

	/// Minimum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMin(
		vec<L, T> const& x, U a,
		vec<L, T> const& y, U b,
		vec<L, T> const& z, U c,
		vec<L, T> const& w, U d);

	/// Maximum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<typename T, typename U>
	GLM_FUNC_DECL U associatedMax(T x, U a, T y, U b);

	/// Maximum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<2, U> associatedMax(
		vec<L, T> const& x, vec<L, U> const& a,
		vec<L, T> const& y, vec<L, U> const& b);

	/// Maximum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, T> associatedMax(
		T x, vec<L, U> const& a,
		T y, vec<L, U> const& b);

	/// Maximum comparison between 2 variables and returns 2 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMax(
		vec<L, T> const& x, U a,
		vec<L, T> const& y, U b);

	/// Maximum comparison between 3 variables and returns 3 associated variable values
	/// @see gtx_associated_min_max
	template<typename T, typename U>
	GLM_FUNC_DECL U associatedMax(
		T x, U a,
		T y, U b,
		T z, U c);

	/// Maximum comparison between 3 variables and returns 3 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMax(
		vec<L, T> const& x, vec<L, U> const& a,
		vec<L, T> const& y, vec<L, U> const& b,
		vec<L, T> const& z, vec<L, U> const& c);

	/// Maximum comparison between 3 variables and returns 3 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, T> associatedMax(
		T x, vec<L, U> const& a,
		T y, vec<L, U> const& b,
		T z, vec<L, U> const& c);

	/// Maximum comparison between 3 variables and returns 3 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMax(
		vec<L, T> const& x, U a,
		vec<L, T> const& y, U b,
		vec<L, T> const& z, U c);

	/// Maximum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<typename T, typename U>
	GLM_FUNC_DECL U associatedMax(
		T x, U a,
		T y, U b,
		T z, U c,
		T w, U d);

	/// Maximum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMax(
		vec<L, T> const& x, vec<L, U> const& a,
		vec<L, T> const& y, vec<L, U> const& b,
		vec<L, T> const& z, vec<L, U> const& c,
		vec<L, T> const& w, vec<L, U> const& d);

	/// Maximum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMax(
		T x, vec<L, U> const& a,
		T y, vec<L, U> const& b,
		T z, vec<L, U> const& c,
		T w, vec<L, U> const& d);

	/// Maximum comparison between 4 variables and returns 4 associated variable values
	/// @see gtx_associated_min_max
	template<length_t L, typename T, typename U>
	GLM_FUNC_DECL vec<L, U> associatedMax(
		vec<L, T> const& x, U a,
		vec<L, T> const& y, U b,
		vec<L, T> const& z, U c,
		vec<L, T> const& w, U d);

	/// @}
} //namespace glm

#include "associated_min_max.inl"
