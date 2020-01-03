/// @ref core
/// @file glm/detail/type_vec4.hpp

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
	template<typename T>
	struct vec<4, T>
	{
		// -- Implementation detail --

		typedef T value_type;
		typedef vec<4, T> type;
		typedef vec<4, bool> bool_type;

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
#			endif
#		endif

#		if GLM_CONFIG_XYZW_ONLY
			T x, y, z, w;
#		elif GLM_CONFIG_ANONYMOUS_STRUCT == GLM_ENABLE
			union
			{
				struct { T x, y, z, w; };
				struct { T r, g, b, a; };
				struct { T s, t, p, q; };

				typename detail::storage<4, T, detail::is_aligned<Q>::value>::type data;

#				if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
					GLM_SWIZZLE4_2_MEMBERS(T, Q, x, y, z, w)
					GLM_SWIZZLE4_2_MEMBERS(T, Q, r, g, b, a)
					GLM_SWIZZLE4_2_MEMBERS(T, Q, s, t, p, q)
					GLM_SWIZZLE4_3_MEMBERS(T, Q, x, y, z, w)
					GLM_SWIZZLE4_3_MEMBERS(T, Q, r, g, b, a)
					GLM_SWIZZLE4_3_MEMBERS(T, Q, s, t, p, q)
					GLM_SWIZZLE4_4_MEMBERS(T, Q, x, y, z, w)
					GLM_SWIZZLE4_4_MEMBERS(T, Q, r, g, b, a)
					GLM_SWIZZLE4_4_MEMBERS(T, Q, s, t, p, q)
#				endif
			};
#		else
			union { T x, r, s; };
			union { T y, g, t; };
			union { T z, b, p; };
			union { T w, a, q; };

#			if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_FUNCTION
				GLM_SWIZZLE_GEN_VEC_FROM_VEC4(T)
#			endif
#		endif

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

		typedef length_t length_type;

		/// Return the count of components of the vector
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length(){return 4;}

		GLM_FUNC_DECL GLM_CONSTEXPR T & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR T const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR vec() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<4, T> const& v) GLM_DEFAULT;

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR explicit vec(T scalar);
		GLM_FUNC_DECL GLM_CONSTEXPR vec(T x, T y, T z, T w);

		// -- Conversion vector constructors --

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B, typename C>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A> const& _xy, B _z, C _w);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B, typename C>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<2, B> const& _yz, C _w);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B, typename C>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, B _y, vec<2, C> const& _zw);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<3, A> const& _xyz, B _w);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<3, B> const& _yzw);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A> const& _xy, vec<2, B> const& _zw);

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT vec(vec<4, U> const& v);

		// -- Swizzle constructors --
#		if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
			template<int E0, int E1, int E2, int E3>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(detail::_swizzle<4, T, Q, E0, E1, E2, E3> const& that)
			{
				*this = that();
			}

			template<int E0, int E1, int F0, int F1>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v, detail::_swizzle<2, T, Q, F0, F1, -1, -2> const& u)
			{
				*this = vec<4, T>(v(), u());
			}

			template<int E0, int E1>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(T const& x, T const& y, detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v)
			{
				*this = vec<4, T>(x, y, v());
			}

			template<int E0, int E1>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(T const& x, detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v, T const& w)
			{
				*this = vec<4, T>(x, v(), w);
			}

			template<int E0, int E1>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v, T const& z, T const& w)
			{
				*this = vec<4, T>(v(), z, w);
			}

			template<int E0, int E1, int E2>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(detail::_swizzle<3, T, Q, E0, E1, E2, -1> const& v, T const& w)
			{
				*this = vec<4, T>(v(), w);
			}

			template<int E0, int E1, int E2>
			GLM_FUNC_DECL GLM_CONSTEXPR vec(T const& x, detail::_swizzle<3, T, Q, E0, E1, E2, -1> const& v)
			{
				*this = vec<4, T>(x, v());
			}
#		endif//GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator=(vec<4, T> const& v) GLM_DEFAULT;
	
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator+=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator+=(vec const& v);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator-=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator-=(vec const& v);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator*=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator*=(vec const& v);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator/=(T scalar);
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T>& operator/=(vec const& v);
	};

	// -- Unary operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v);

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v, T const & scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator+(T scalar, vec<4, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v, T const & scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator-(T scalar, vec<4, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v, T const & scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator*(T scalar, vec<4, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v, T const & scalar);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator/(T scalar, vec<4, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v1, vec<4, T> const& v2);

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(vec<4, T> const& v1, vec<4, T> const& v2);

	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, bool> operator&&(vec<4, bool> const& v1, vec<4, bool> const& v2);

	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, bool> operator||(vec<4, bool> const& v1, vec<4, bool> const& v2);
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_vec4.inl"
#endif//GLM_EXTERNAL_TEMPLATE
