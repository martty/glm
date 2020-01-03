/// @ref core
/// @file glm/detail/type_quat.hpp

#pragma once

// Dependency:
#include "../detail/type_mat3x3.hpp"
#include "../detail/type_mat4x4.hpp"
#include "../detail/type_vec3.hpp"
#include "../detail/type_vec4.hpp"
#include "../ext/vector_relational.hpp"
#include "../ext/quaternion_relational.hpp"
#include "../gtc/constants.hpp"
#include "../gtc/matrix_transform.hpp"

namespace glm
{
	template<typename T>
	struct qua
	{
		// -- Implementation detail --

		typedef qua<T> type;
		typedef T value_type;

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

#		if GLM_LANG & GLM_LANG_CXXMS_FLAG & false
			union
			{
				struct { T x, y, z, w;};

				typename detail::storage<4, T, false>::type data;
			};
#		else
			T x, y, z, w;
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

		/// Return the count of components of a quaternion
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length(){return 4;}

		GLM_FUNC_DECL GLM_CONSTEXPR T & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR T const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR qua() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR qua(qua<T> const& q) GLM_DEFAULT;

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR qua(T s, vec<3, T> const& v);
		GLM_FUNC_DECL GLM_CONSTEXPR qua(T w, T x, T y, T z);

		/// Explicit conversion operators
#		if GLM_HAS_EXPLICIT_CONVERSION_OPERATORS
			GLM_FUNC_DECL explicit operator mat<3, 3, T>() const;
			GLM_FUNC_DECL explicit operator mat<4, 4, T>() const;
#		endif

		/// Create a quaternion from two normalized axis
		///
		/// @param u A first normalized axis
		/// @param v A second normalized axis
		/// @see gtc_quaternion
		/// @see http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
		GLM_FUNC_DECL qua(vec<3, T> const& u, vec<3, T> const& v);

		/// Build a quaternion from euler angles (pitch, yaw, roll), in radians.
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT qua(vec<3, T> const& eulerAngles);
		GLM_FUNC_DECL GLM_EXPLICIT qua(mat<3, 3, T> const& q);
		GLM_FUNC_DECL GLM_EXPLICIT qua(mat<4, 4, T> const& q);

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL GLM_CONSTEXPR qua<T>& operator=(qua<T> const& q) GLM_DEFAULT;

		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR qua<T>& operator=(qua<U> const& q);
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR qua<T>& operator+=(qua<U> const& q);
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR qua<T>& operator-=(qua<U> const& q);
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR qua<T>& operator*=(qua<U> const& q);
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR qua<T>& operator*=(U s);
		template<typename U>
		GLM_FUNC_DECL GLM_CONSTEXPR qua<T>& operator/=(U s);
	};

	// -- Unary bit operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator+(qua<T> const& q);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator-(qua<T> const& q);

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator+(qua<T> const& q, qua<T> const& p);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator-(qua<T> const& q, qua<T> const& p);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator*(qua<T> const& q, qua<T> const& p);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator*(qua<T> const& q, vec<3, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, qua<T> const& q);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator*(qua<T> const& q, vec<4, T> const& v);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v, qua<T> const& q);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator*(qua<T> const& q, T const& s);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator*(T const& s, qua<T> const& q);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T> operator/(qua<T> const& q, T const& s);

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(qua<T> const& q1, qua<T> const& q2);

	template<typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(qua<T> const& q1, qua<T> const& q2);
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_quat.inl"
#endif//GLM_EXTERNAL_TEMPLATE
