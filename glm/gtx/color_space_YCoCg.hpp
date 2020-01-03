/// @ref gtx_color_space_YCoCg
/// @file glm/gtx/color_space_YCoCg.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_color_space_YCoCg GLM_GTX_color_space_YCoCg
/// @ingroup gtx
///
/// Include <glm/gtx/color_space_YCoCg.hpp> to use the features of this extension.
///
/// RGB to YCoCg conversions and operations

#pragma once

// Dependency:
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_color_space_YCoCg is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_color_space_YCoCg extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_color_space_YCoCg
	/// @{

	/// Convert a color from RGB color space to YCoCg color space.
	/// @see gtx_color_space_YCoCg
	template<typename T>
	GLM_FUNC_DECL vec<3, T> rgb2YCoCg(
		vec<3, T> const& rgbColor);

	/// Convert a color from YCoCg color space to RGB color space.
	/// @see gtx_color_space_YCoCg
	template<typename T>
	GLM_FUNC_DECL vec<3, T> YCoCg2rgb(
		vec<3, T> const& YCoCgColor);

	/// Convert a color from RGB color space to YCoCgR color space.
	/// @see "YCoCg-R: A Color Space with RGB Reversibility and Low Dynamic Range"
	/// @see gtx_color_space_YCoCg
	template<typename T>
	GLM_FUNC_DECL vec<3, T> rgb2YCoCgR(
		vec<3, T> const& rgbColor);

	/// Convert a color from YCoCgR color space to RGB color space.
	/// @see "YCoCg-R: A Color Space with RGB Reversibility and Low Dynamic Range"
	/// @see gtx_color_space_YCoCg
	template<typename T>
	GLM_FUNC_DECL vec<3, T> YCoCgR2rgb(
		vec<3, T> const& YCoCgColor);

	/// @}
}//namespace glm

#include "color_space_YCoCg.inl"
