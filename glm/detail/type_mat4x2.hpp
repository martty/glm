/// @ref core
/// @file glm/detail/type_mat4x2.hpp

#pragma once

#include "type_vec2.hpp"
#include "type_vec4.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template<typename T>
	struct mat<4, 2, T>
	{
		typedef vec<2, T> col_type;
		typedef vec<4, T> row_type;
		typedef mat<4, 2, T> type;
		typedef mat<2, 4, T> transpose_type;
		typedef T value_type;

	private:
		col_type value[4];

	public:
		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length() { return 4; }

		GLM_FUNC_DECL col_type & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR col_type const& operator[](length_type i) const;

		// -- Constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR mat() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR mat(mat<4, 2, T> const& m);

		GLM_FUNC_DECL explicit GLM_CONSTEXPR mat(T scalar);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			T x0, T y0,
			T x1, T y1,
			T x2, T y2,
			T x3, T y3);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			col_type const& v0,
			col_type const& v1,
			col_type const& v2,
			col_type const& v3);

		// -- Conversions --

		template<
			typename X0, typename Y0,
			typename X1, typename Y1,
			typename X2, typename Y2,
			typename X3, typename Y3>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			X0 x0, Y0 y0,
			X1 x1, Y1 y1,
			X2 x2, Y2 y2,
			X3 x3, Y3 y3);

		template<typename V1, typename V2, typename V3, typename V4>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			vec<2, V1> const& v1,
			vec<2, V2> const& v2,
			vec<2, V3> const& v3,
			vec<2, V4> const& v4);

		// -- Matrix conversions --

		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 2, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 3, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 4, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 3, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 2, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 4, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 3, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 4, T> const& x);

		// -- Unary arithmetic operators --

		template<typename U>
		GLM_FUNC_DECL mat<4, 2, T> & operator=(mat<4, 2, U> const& m);
		template<typename U>
		GLM_FUNC_DECL mat<4, 2, T> & operator+=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<4, 2, T> & operator+=(mat<4, 2, U> const& m);
		template<typename U>
		GLM_FUNC_DECL mat<4, 2, T> & operator-=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<4, 2, T> & operator-=(mat<4, 2, U> const& m);
		template<typename U>
		GLM_FUNC_DECL mat<4, 2, T> & operator*=(U s);
		template<typename U>
		GLM_FUNC_DECL mat<4, 2, T> & operator/=(U s);
	};

	// -- Unary operators --

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator+(mat<4, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator-(mat<4, 2, T> const& m);

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator+(mat<4, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator+(mat<4, 2, T> const& m1, mat<4, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator-(mat<4, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator-(mat<4, 2, T> const& m1,	mat<4, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator*(mat<4, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator*(T scalar, mat<4, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL typename mat<4, 2, T>::col_type operator*(mat<4, 2, T> const& m, typename mat<4, 2, T>::row_type const& v);

	template<typename T>
	GLM_FUNC_DECL typename mat<4, 2, T>::row_type operator*(typename mat<4, 2, T>::col_type const& v, mat<4, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator*(mat<4, 2, T> const& m1, mat<2, 4, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<3, 2, T> operator*(mat<4, 2, T> const& m1, mat<3, 4, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator*(mat<4, 2, T> const& m1, mat<4, 4, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator/(mat<4, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator/(T scalar, mat<4, 2, T> const& m);

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_DECL bool operator==(mat<4, 2, T> const& m1, mat<4, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL bool operator!=(mat<4, 2, T> const& m1, mat<4, 2, T> const& m2);
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat4x2.inl"
#endif
