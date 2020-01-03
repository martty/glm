/// @ref ext_matrix_common
/// @file glm/ext/matrix_common.hpp
///
/// @defgroup ext_matrix_common GLM_EXT_matrix_common
/// @ingroup ext
///
/// Defines functions for common matrix operations.
///
/// Include <glm/ext/matrix_common.hpp> to use the features of this extension.
///
/// @see ext_matrix_common

#pragma once

#include "../detail/setup.hpp"
#include "../detail/_fixes.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_transform extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_common
	/// @{

	template<length_t C, length_t R, typename T, typename U>
	GLM_FUNC_DECL mat<C, R, T> mix(mat<C, R, T> const& x, mat<C, R, T> const& y, mat<C, R, U> const& a);

	template<length_t C, length_t R, typename T, typename U>
	GLM_FUNC_DECL mat<C, R, T> mix(mat<C, R, T> const& x, mat<C, R, T> const& y, U a);

	/// @}
}//namespace glm

#include "matrix_common.inl"
