/// @ref core
/// @file glm/detail/type_mat2x2.hpp

#pragma once

#include "type_vec2.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template<typename T>
	struct mat<2, 2, T>
	{
		typedef vec<2, T> col_type;
		typedef vec<2, T> row_type;
		typedef mat<2, 2, T> type;
		typedef mat<2, 2, T> transpose_type;
		typedef T value_type;

	private:
		col_type value[2];

	public:
		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length() { return 2; }

		GLM_FUNC_DECL col_type & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR col_type const& operator[](length_type i) const;

		// -- Constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR mat() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR mat(mat<2, 2, T> const& m);

		GLM_FUNC_DECL explicit GLM_CONSTEXPR mat(T scalar);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			T const& x1, T const& y1,
			T const& x2, T const& y2);
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			col_type const& v1,
			col_type const& v2);

		// -- Conversions --

		template<typename U, typename V, typename M, typename N>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			U const& x1, V const& y1,
			M const& x2, N const& y2);

		template<typename U, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR mat(
			vec<2, U> const& v1,
			vec<2, V> const& v2);

		// -- Matrix conversions --

		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 3, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 4, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 3, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 2, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<2, 4, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 2, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<3, 4, T> const& x);
		GLM_FUNC_DECL GLM_EXPLICIT GLM_CONSTEXPR mat(mat<4, 3, T> const& x);

		// -- Unary arithmetic operators --

		
		GLM_FUNC_DECL mat<2, 2, T> & operator=(mat const& m);
		GLM_FUNC_DECL mat<2, 2, T> & operator+=(T s);
		GLM_FUNC_DECL mat<2, 2, T> & operator+=(mat const& m);
		GLM_FUNC_DECL mat<2, 2, T> & operator-=(T s);
		GLM_FUNC_DECL mat<2, 2, T> & operator-=(mat const& m);
		GLM_FUNC_DECL mat<2, 2, T> & operator*=(T s);
		GLM_FUNC_DECL mat<2, 2, T> & operator*=(mat const& m);
		GLM_FUNC_DECL mat<2, 2, T> & operator/=(T s);
		GLM_FUNC_DECL mat<2, 2, T> & operator/=(mat const& m);
	};

	// -- Unary operators --

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator+(mat<2, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator-(mat<2, 2, T> const& m);

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator+(mat<2, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator+(T scalar, mat<2, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator+(mat<2, 2, T> const& m1, mat<2, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator-(mat<2, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator-(T scalar, mat<2, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator-(mat<2, 2, T> const& m1, mat<2, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator*(mat<2, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator*(T scalar, mat<2, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL typename mat<2, 2, T>::col_type operator*(mat<2, 2, T> const& m, typename mat<2, 2, T>::row_type const& v);

	template<typename T>
	GLM_FUNC_DECL typename mat<2, 2, T>::row_type operator*(typename mat<2, 2, T>::col_type const& v, mat<2, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator*(mat<2, 2, T> const& m1, mat<2, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<3, 2, T> operator*(mat<2, 2, T> const& m1, mat<3, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<4, 2, T> operator*(mat<2, 2, T> const& m1, mat<4, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator/(mat<2, 2, T> const& m, T scalar);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator/(T scalar, mat<2, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL typename mat<2, 2, T>::col_type operator/(mat<2, 2, T> const& m, typename mat<2, 2, T>::row_type const& v);

	template<typename T>
	GLM_FUNC_DECL typename mat<2, 2, T>::row_type operator/(typename mat<2, 2, T>::col_type const& v, mat<2, 2, T> const& m);

	template<typename T>
	GLM_FUNC_DECL mat<2, 2, T> operator/(mat<2, 2, T> const& m1, mat<2, 2, T> const& m2);

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_DECL bool operator==(mat<2, 2, T> const& m1, mat<2, 2, T> const& m2);

	template<typename T>
	GLM_FUNC_DECL bool operator!=(mat<2, 2, T> const& m1, mat<2, 2, T> const& m2);
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat2x2.inl"
#endif
