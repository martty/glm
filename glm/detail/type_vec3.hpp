/// @ref core
/// @file glm/detail/type_vec3.hpp

#pragma once

#include "setup.hpp"
#if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
#	include "_swizzle.hpp"
#elif GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_FUNCTION
#	include "_swizzle_func.hpp"
#endif
#include <cstddef>

namespace glm
{
	template<length_t L, typename T> struct vec;
	template<typename T>
	struct vec<3, T>
	{
		// -- Implementation detail --

		typedef T value_type;
		typedef vec<3, T> type;
		typedef vec<3, bool> bool_type;

		// -- Data --

#		if GLM_SILENT_WARNINGS == GLM_ENABLE
#			if GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic push
#				pragma GCC diagnostic ignored "-Wpedantic"
#			elif GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic push
#				pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#				pragma clang diagnostic ignored "-Wnested-anon-types"
#			elif GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(push)
#				pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union
#				if GLM_CONFIG_ALIGNED_GENTYPES == GLM_ENABLE
#					pragma warning(disable: 4324)  // structure was padded due to alignment specifier
#				endif
#			endif
#		endif

#		if GLM_CONFIG_XYZW_ONLY
			T x, y, z;
#		elif GLM_CONFIG_ANONYMOUS_STRUCT == GLM_ENABLE
			union
			{
				struct{ T x, y, z; };
				struct{ T r, g, b; };
				struct{ T s, t, p; };

				typename detail::storage<3, T, detail::is_aligned<Q>::value>::type data;

#				if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
					GLM_SWIZZLE3_2_MEMBERS(T, x, y, z)
					GLM_SWIZZLE3_2_MEMBERS(T, r, g, b)
					GLM_SWIZZLE3_2_MEMBERS(T, s, t, p)
					GLM_SWIZZLE3_3_MEMBERS(T, x, y, z)
					GLM_SWIZZLE3_3_MEMBERS(T, r, g, b)
					GLM_SWIZZLE3_3_MEMBERS(T, s, t, p)
					GLM_SWIZZLE3_4_MEMBERS(T, x, y, z)
					GLM_SWIZZLE3_4_MEMBERS(T, r, g, b)
					GLM_SWIZZLE3_4_MEMBERS(T, s, t, p)
#				endif
			};
#		else
			union { T x, r, s; };
			union { T y, g, t; };
			union { T z, b, p; };

#			if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_FUNCTION
				GLM_SWIZZLE_GEN_VEC_FROM_VEC3(T)
#			endif//GLM_CONFIG_SWIZZLE
#		endif//GLM_LANG

#		if GLM_SILENT_WARNINGS == GLM_ENABLE
#			if GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic pop
#			elif GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic pop
#			elif GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(pop)
#			endif
#		endif

		// -- Component accesses --

		/// Return the count of components of the vector
		typedef length_t length_type;
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length(){return 3;}

		GLM_FUNC_DECL GLM_CONSTEXPR T & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR T const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR vec() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec const& v) GLM_DEFAULT;

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR explicit vec(T scalar);
		GLM_FUNC_DECL GLM_CONSTEXPR vec(T a, T b, T c);

		// -- Conversion vector constructors --

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A> const& _xy, B _z);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<2, B> const& _yz);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT vec(vec<4, U> const& v);

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT vec(vec<3, U> const& v);

		// -- Swizzle constructors --
#		if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
			template<int E0, int E1, int E2>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(detail::_swizzle<3, T, Q, E0, E1, E2, -1> const& that)
			{
				*this = that();
			}

			template<int E0, int E1>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v, T const& scalar)
			{
				*this = vec(v(), scalar);
			}

			template<int E0, int E1>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(T const& scalar, detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v)
			{
				*this = vec(scalar, v());
			}
#		endif//GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T>& operator=(vec<3, T> const& v) GLM_DEFAULT;
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator+=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator+=(vec<3, T> const& v);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator-=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator-=(vec<3, T> const& v);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator*=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator*=(vec<3, T> const& v);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator/=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> & operator/=(vec<3, T> const& v);
	};

	// -- Unary operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v);

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, T scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator+(T scalar, vec<3, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, T scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator-(T scalar, vec<3, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, T scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator*(T scalar, vec<3, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, T scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator/(T scalar, vec<3, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const& v2);

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2);


	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, bool> operator&&(vec<3, bool> const& v1, vec<3, bool> const& v2);

	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, bool> operator||(vec<3, bool> const& v1, vec<3, bool> const& v2);
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_vec3.inl"
#endif//GLM_EXTERNAL_TEMPLATE
