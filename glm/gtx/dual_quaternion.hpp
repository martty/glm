/// @ref gtx_dual_quaternion
/// @file glm/gtx/dual_quaternion.hpp
/// @author Maksim Vorobiev (msomeone@gmail.com)
///
/// @see core (dependence)
/// @see gtc_constants (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtx_dual_quaternion GLM_GTX_dual_quaternion
/// @ingroup gtx
///
/// Include <glm/gtx/dual_quaternion.hpp> to use the features of this extension.
///
/// Defines a templated dual-quaternion type and several dual-quaternion operations.

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/constants.hpp"
#include "../gtc/quaternion.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_dual_quaternion is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_dual_quaternion extension included")
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_dual_quaternion
	/// @{

	template<typename T>
	struct tdualquat
	{
		// -- Implementation detail --

		typedef T value_type;
		typedef qua<T> part_type;

		// -- Data --

		qua<T> real, dual;

		// -- Component accesses --

		typedef length_t length_type;
		/// Return the count of components of a dual quaternion
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length(){return 2;}

		GLM_FUNC_DECL part_type & operator[](length_type i);
		GLM_FUNC_DECL part_type const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR tdualquat() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR tdualquat(tdualquat<T> const& d) GLM_DEFAULT;

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR tdualquat(qua<T> const& real);
		GLM_FUNC_DECL GLM_CONSTEXPR tdualquat(qua<T> const& orientation, vec<3, T> const& translation);
		GLM_FUNC_DECL GLM_CONSTEXPR tdualquat(qua<T> const& real, qua<T> const& dual);

		// -- Conversion constructors --

		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR tdualquat(mat<2, 4, T> const& holder_mat);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR tdualquat(mat<3, 4, T> const& aug_mat);

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL tdualquat<T> & operator=(tdualquat<T> const& m) GLM_DEFAULT;

		template<typename U>
		GLM_FUNC_DECL tdualquat<T> & operator=(tdualquat<U> const& m);
		template<typename U>
		GLM_FUNC_DECL tdualquat<T> & operator*=(U s);
		template<typename U>
		GLM_FUNC_DECL tdualquat<T> & operator/=(U s);
	};

	// -- Unary bit operators --

	template<typename T>
	GLM_FUNC_DECL tdualquat<T> operator+(tdualquat<T> const& q);

	template<typename T>
	GLM_FUNC_DECL tdualquat<T> operator-(tdualquat<T> const& q);

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_DECL tdualquat<T> operator+(tdualquat<T> const& q, tdualquat<T> const& p);

	template<typename T>
	GLM_FUNC_DECL tdualquat<T> operator*(tdualquat<T> const& q, tdualquat<T> const& p);

	template<typename T>
	GLM_FUNC_DECL vec<3, T> operator*(tdualquat<T> const& q, vec<3, T> const& v);

	template<typename T>
	GLM_FUNC_DECL vec<3, T> operator*(vec<3, T> const& v, tdualquat<T> const& q);

	template<typename T>
	GLM_FUNC_DECL vec<4, T> operator*(tdualquat<T> const& q, vec<4, T> const& v);

	template<typename T>
	GLM_FUNC_DECL vec<4, T> operator*(vec<4, T> const& v, tdualquat<T> const& q);

	template<typename T>
	GLM_FUNC_DECL tdualquat<T> operator*(tdualquat<T> const& q, T const& s);

	template<typename T>
	GLM_FUNC_DECL tdualquat<T> operator*(T const& s, tdualquat<T> const& q);

	template<typename T>
	GLM_FUNC_DECL tdualquat<T> operator/(tdualquat<T> const& q, T const& s);

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_DECL bool operator==(tdualquat<T> const& q1, tdualquat<T> const& q2);

	template<typename T>
	GLM_FUNC_DECL bool operator!=(tdualquat<T> const& q1, tdualquat<T> const& q2);

	/// Creates an identity dual quaternion.
	///
	/// @see gtx_dual_quaternion
	template <typename T>
	GLM_FUNC_DECL tdualquat<T> dual_quat_identity();

	/// Returns the normalized quaternion.
	///
	/// @see gtx_dual_quaternion
	template<typename T>
	GLM_FUNC_DECL tdualquat<T> normalize(tdualquat<T> const& q);

	/// Returns the linear interpolation of two dual quaternion.
	///
	/// @see gtc_dual_quaternion
	template<typename T>
	GLM_FUNC_DECL tdualquat<T> lerp(tdualquat<T> const& x, tdualquat<T> const& y, T const& a);

	/// Returns the q inverse.
	///
	/// @see gtx_dual_quaternion
	template<typename T>
	GLM_FUNC_DECL tdualquat<T> inverse(tdualquat<T> const& q);

	/// Converts a quaternion to a 2 * 4 matrix.
	///
	/// @see gtx_dual_quaternion
	template<typename T>
	GLM_FUNC_DECL mat<2, 4, T> mat2x4_cast(tdualquat<T> const& x);

	/// Converts a quaternion to a 3 * 4 matrix.
	///
	/// @see gtx_dual_quaternion
	template<typename T>
	GLM_FUNC_DECL mat<3, 4, T> mat3x4_cast(tdualquat<T> const& x);

	/// Converts a 2 * 4 matrix (matrix which holds real and dual parts) to a quaternion.
	///
	/// @see gtx_dual_quaternion
	template<typename T>
	GLM_FUNC_DECL tdualquat<T> dualquat_cast(mat<2, 4, T> const& x);

	/// Converts a 3 * 4 matrix (augmented matrix rotation + translation) to a quaternion.
	///
	/// @see gtx_dual_quaternion
	template<typename T>
	GLM_FUNC_DECL tdualquat<T> dualquat_cast(mat<3, 4, T> const& x);

	/// Dual-quaternion of floating-point numbers.
	///
	/// @see gtx_dual_quaternion
	typedef tdualquat<float>			dualquat;
	/// Dual-quaternion of single-qualifier floating-point numbers.
	///
	/// @see gtx_dual_quaternion
	typedef tdualquat<float>			fdualquat;
	/// Dual-quaternion of default double-qualifier floating-point numbers.
	///
	/// @see gtx_dual_quaternion
	typedef tdualquat<double>			ddualquat;

	/// @}
} //namespace glm

#include "dual_quaternion.inl"
