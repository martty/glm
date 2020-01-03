/// @ref gtx_vec_swizzle
/// @file glm/gtx/vec_swizzle.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_vec_swizzle GLM_GTX_vec_swizzle
/// @ingroup gtx
///
/// Include <glm/gtx/vec_swizzle.hpp> to use the features of this extension.
///
/// Functions to perform swizzle operation.

#pragma once

#include "../glm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_vec_swizzle is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_vec_swizzle extension included")
#	endif
#endif

namespace glm {
	// xx

	template<typename T>
	GLM_INLINE glm::vec<2, T> xx(const glm::vec<2, T> &v) {
		return glm::vec<2, T>(v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> xx(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> xx(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.x, v.x);
	}

	// xy
	template<typename T>
	GLM_INLINE glm::vec<2, T> xy(const glm::vec<2, T> &v) {
		return glm::vec<2, T>(v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> xy(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> xy(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.x, v.y);
	}

	// xz
	template<typename T>
	GLM_INLINE glm::vec<2, T> xz(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> xz(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.x, v.z);
	}

	// xw
	template<typename T>
	GLM_INLINE glm::vec<2, T> xw(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.x, v.w);
	}

	// yx
	template<typename T>
	GLM_INLINE glm::vec<2, T> yx(const glm::vec<2, T> &v) {
		return glm::vec<2, T>(v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> yx(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> yx(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.y, v.x);
	}

	// yy
	template<typename T>
	GLM_INLINE glm::vec<2, T> yy(const glm::vec<2, T> &v) {
		return glm::vec<2, T>(v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> yy(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> yy(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.y, v.y);
	}

	// yz
	template<typename T>
	GLM_INLINE glm::vec<2, T> yz(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> yz(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.y, v.z);
	}

	// yw
	template<typename T>
	GLM_INLINE glm::vec<2, T> yw(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.y, v.w);
	}

	// zx
	template<typename T>
	GLM_INLINE glm::vec<2, T> zx(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> zx(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.z, v.x);
	}

	// zy
	template<typename T>
	GLM_INLINE glm::vec<2, T> zy(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> zy(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.z, v.y);
	}

	// zz
	template<typename T>
	GLM_INLINE glm::vec<2, T> zz(const glm::vec<3, T> &v) {
		return glm::vec<2, T>(v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<2, T> zz(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.z, v.z);
	}

	// zw
	template<typename T>
	GLM_INLINE glm::vec<2, T> zw(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.z, v.w);
	}

	// wx
	template<typename T>
	GLM_INLINE glm::vec<2, T> wx(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.w, v.x);
	}

	// wy
	template<typename T>
	GLM_INLINE glm::vec<2, T> wy(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.w, v.y);
	}

	// wz
	template<typename T>
	GLM_INLINE glm::vec<2, T> wz(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.w, v.z);
	}

	// ww
	template<typename T>
	GLM_INLINE glm::vec<2, T> ww(const glm::vec<4, T> &v) {
		return glm::vec<2, T>(v.w, v.w);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xxx(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xxx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xxx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.x);
	}

	// xxy
	template<typename T>
	GLM_INLINE glm::vec<3, T> xxy(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xxy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xxy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.y);
	}

	// xxz
	template<typename T>
	GLM_INLINE glm::vec<3, T> xxz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xxz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.z);
	}

	// xxw
	template<typename T>
	GLM_INLINE glm::vec<3, T> xxw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.x, v.w);
	}

	// xyx
	template<typename T>
	GLM_INLINE glm::vec<3, T> xyx(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xyx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xyx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.x);
	}

	// xyy
	template<typename T>
	GLM_INLINE glm::vec<3, T> xyy(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xyy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xyy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.y);
	}

	// xyz
	template<typename T>
	GLM_INLINE glm::vec<3, T> xyz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xyz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.z);
	}

	// xyw
	template<typename T>
	GLM_INLINE glm::vec<3, T> xyw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.y, v.w);
	}

	// xzx
	template<typename T>
	GLM_INLINE glm::vec<3, T> xzx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xzx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.z, v.x);
	}

	// xzy
	template<typename T>
	GLM_INLINE glm::vec<3, T> xzy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xzy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.z, v.y);
	}

	// xzz
	template<typename T>
	GLM_INLINE glm::vec<3, T> xzz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.x, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> xzz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.z, v.z);
	}

	// xzw
	template<typename T>
	GLM_INLINE glm::vec<3, T> xzw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.z, v.w);
	}

	// xwx
	template<typename T>
	GLM_INLINE glm::vec<3, T> xwx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.w, v.x);
	}

	// xwy
	template<typename T>
	GLM_INLINE glm::vec<3, T> xwy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.w, v.y);
	}

	// xwz
	template<typename T>
	GLM_INLINE glm::vec<3, T> xwz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.w, v.z);
	}

	// xww
	template<typename T>
	GLM_INLINE glm::vec<3, T> xww(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.x, v.w, v.w);
	}

	// yxx
	template<typename T>
	GLM_INLINE glm::vec<3, T> yxx(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yxx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yxx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.x);
	}

	// yxy
	template<typename T>
	GLM_INLINE glm::vec<3, T> yxy(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yxy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yxy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.y);
	}

	// yxz
	template<typename T>
	GLM_INLINE glm::vec<3, T> yxz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yxz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.z);
	}

	// yxw
	template<typename T>
	GLM_INLINE glm::vec<3, T> yxw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.x, v.w);
	}

	// yyx
	template<typename T>
	GLM_INLINE glm::vec<3, T> yyx(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yyx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yyx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.x);
	}

	// yyy
	template<typename T>
	GLM_INLINE glm::vec<3, T> yyy(const glm::vec<2, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yyy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yyy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.y);
	}

	// yyz
	template<typename T>
	GLM_INLINE glm::vec<3, T> yyz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yyz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.z);
	}

	// yyw
	template<typename T>
	GLM_INLINE glm::vec<3, T> yyw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.y, v.w);
	}

	// yzx
	template<typename T>
	GLM_INLINE glm::vec<3, T> yzx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yzx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.z, v.x);
	}

	// yzy
	template<typename T>
	GLM_INLINE glm::vec<3, T> yzy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yzy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.z, v.y);
	}

	// yzz
	template<typename T>
	GLM_INLINE glm::vec<3, T> yzz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.y, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> yzz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.z, v.z);
	}

	// yzw
	template<typename T>
	GLM_INLINE glm::vec<3, T> yzw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.z, v.w);
	}

	// ywx
	template<typename T>
	GLM_INLINE glm::vec<3, T> ywx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.w, v.x);
	}

	// ywy
	template<typename T>
	GLM_INLINE glm::vec<3, T> ywy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.w, v.y);
	}

	// ywz
	template<typename T>
	GLM_INLINE glm::vec<3, T> ywz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.w, v.z);
	}

	// yww
	template<typename T>
	GLM_INLINE glm::vec<3, T> yww(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.y, v.w, v.w);
	}

	// zxx
	template<typename T>
	GLM_INLINE glm::vec<3, T> zxx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zxx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.x, v.x);
	}

	// zxy
	template<typename T>
	GLM_INLINE glm::vec<3, T> zxy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zxy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.x, v.y);
	}

	// zxz
	template<typename T>
	GLM_INLINE glm::vec<3, T> zxz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zxz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.x, v.z);
	}

	// zxw
	template<typename T>
	GLM_INLINE glm::vec<3, T> zxw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.x, v.w);
	}

	// zyx
	template<typename T>
	GLM_INLINE glm::vec<3, T> zyx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zyx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.y, v.x);
	}

	// zyy
	template<typename T>
	GLM_INLINE glm::vec<3, T> zyy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zyy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.y, v.y);
	}

	// zyz
	template<typename T>
	GLM_INLINE glm::vec<3, T> zyz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zyz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.y, v.z);
	}

	// zyw
	template<typename T>
	GLM_INLINE glm::vec<3, T> zyw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.y, v.w);
	}

	// zzx
	template<typename T>
	GLM_INLINE glm::vec<3, T> zzx(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zzx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.z, v.x);
	}

	// zzy
	template<typename T>
	GLM_INLINE glm::vec<3, T> zzy(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zzy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.z, v.y);
	}

	// zzz
	template<typename T>
	GLM_INLINE glm::vec<3, T> zzz(const glm::vec<3, T> &v) {
		return glm::vec<3, T>(v.z, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<3, T> zzz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.z, v.z);
	}

	// zzw
	template<typename T>
	GLM_INLINE glm::vec<3, T> zzw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.z, v.w);
	}

	// zwx
	template<typename T>
	GLM_INLINE glm::vec<3, T> zwx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.w, v.x);
	}

	// zwy
	template<typename T>
	GLM_INLINE glm::vec<3, T> zwy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.w, v.y);
	}

	// zwz
	template<typename T>
	GLM_INLINE glm::vec<3, T> zwz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.w, v.z);
	}

	// zww
	template<typename T>
	GLM_INLINE glm::vec<3, T> zww(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.z, v.w, v.w);
	}

	// wxx
	template<typename T>
	GLM_INLINE glm::vec<3, T> wxx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.x, v.x);
	}

	// wxy
	template<typename T>
	GLM_INLINE glm::vec<3, T> wxy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.x, v.y);
	}

	// wxz
	template<typename T>
	GLM_INLINE glm::vec<3, T> wxz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.x, v.z);
	}

	// wxw
	template<typename T>
	GLM_INLINE glm::vec<3, T> wxw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.x, v.w);
	}

	// wyx
	template<typename T>
	GLM_INLINE glm::vec<3, T> wyx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.y, v.x);
	}

	// wyy
	template<typename T>
	GLM_INLINE glm::vec<3, T> wyy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.y, v.y);
	}

	// wyz
	template<typename T>
	GLM_INLINE glm::vec<3, T> wyz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.y, v.z);
	}

	// wyw
	template<typename T>
	GLM_INLINE glm::vec<3, T> wyw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.y, v.w);
	}

	// wzx
	template<typename T>
	GLM_INLINE glm::vec<3, T> wzx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.z, v.x);
	}

	// wzy
	template<typename T>
	GLM_INLINE glm::vec<3, T> wzy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.z, v.y);
	}

	// wzz
	template<typename T>
	GLM_INLINE glm::vec<3, T> wzz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.z, v.z);
	}

	// wzw
	template<typename T>
	GLM_INLINE glm::vec<3, T> wzw(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.z, v.w);
	}

	// wwx
	template<typename T>
	GLM_INLINE glm::vec<3, T> wwx(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.w, v.x);
	}

	// wwy
	template<typename T>
	GLM_INLINE glm::vec<3, T> wwy(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.w, v.y);
	}

	// wwz
	template<typename T>
	GLM_INLINE glm::vec<3, T> wwz(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.w, v.z);
	}

	// www
	template<typename T>
	GLM_INLINE glm::vec<3, T> www(const glm::vec<4, T> &v) {
		return glm::vec<3, T>(v.w, v.w, v.w);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.x);
	}

	// xxxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.y);
	}

	// xxxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.z);
	}

	// xxxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.x, v.w);
	}

	// xxyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.x);
	}

	// xxyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.y);
	}

	// xxyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.z);
	}

	// xxyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.y, v.w);
	}

	// xxzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.z, v.x);
	}

	// xxzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.z, v.y);
	}

	// xxzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xxzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.z, v.z);
	}

	// xxzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.z, v.w);
	}

	// xxwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.w, v.x);
	}

	// xxwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.w, v.y);
	}

	// xxwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.w, v.z);
	}

	// xxww
	template<typename T>
	GLM_INLINE glm::vec<4, T> xxww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.x, v.w, v.w);
	}

	// xyxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.x);
	}

	// xyxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.y);
	}

	// xyxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.z);
	}

	// xyxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.x, v.w);
	}

	// xyyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.x);
	}

	// xyyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.y);
	}

	// xyyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.z);
	}

	// xyyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.y, v.w);
	}

	// xyzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.z, v.x);
	}

	// xyzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.z, v.y);
	}

	// xyzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xyzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.z, v.z);
	}

	// xyzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.z, v.w);
	}

	// xywx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xywx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.w, v.x);
	}

	// xywy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xywy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.w, v.y);
	}

	// xywz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xywz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.w, v.z);
	}

	// xyww
	template<typename T>
	GLM_INLINE glm::vec<4, T> xyww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.y, v.w, v.w);
	}

	// xzxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.x, v.x);
	}

	// xzxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.x, v.y);
	}

	// xzxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.x, v.z);
	}

	// xzxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.x, v.w);
	}

	// xzyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.y, v.x);
	}

	// xzyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.y, v.y);
	}

	// xzyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.y, v.z);
	}

	// xzyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.y, v.w);
	}

	// xzzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.z, v.x);
	}

	// xzzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.z, v.y);
	}

	// xzzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> xzzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.z, v.z);
	}

	// xzzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.z, v.w);
	}

	// xzwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.w, v.x);
	}

	// xzwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.w, v.y);
	}

	// xzwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.w, v.z);
	}

	// xzww
	template<typename T>
	GLM_INLINE glm::vec<4, T> xzww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.z, v.w, v.w);
	}

	// xwxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.x, v.x);
	}

	// xwxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.x, v.y);
	}

	// xwxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.x, v.z);
	}

	// xwxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.x, v.w);
	}

	// xwyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.y, v.x);
	}

	// xwyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.y, v.y);
	}

	// xwyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.y, v.z);
	}

	// xwyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.y, v.w);
	}

	// xwzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.z, v.x);
	}

	// xwzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.z, v.y);
	}

	// xwzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.z, v.z);
	}

	// xwzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.z, v.w);
	}

	// xwwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.w, v.x);
	}

	// xwwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.w, v.y);
	}

	// xwwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.w, v.z);
	}

	// xwww
	template<typename T>
	GLM_INLINE glm::vec<4, T> xwww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.x, v.w, v.w, v.w);
	}

	// yxxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.x);
	}

	// yxxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.y);
	}

	// yxxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.z);
	}

	// yxxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.x, v.w);
	}

	// yxyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.x);
	}

	// yxyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.y);
	}

	// yxyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.z);
	}

	// yxyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.y, v.w);
	}

	// yxzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.z, v.x);
	}

	// yxzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.z, v.y);
	}

	// yxzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yxzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.z, v.z);
	}

	// yxzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.z, v.w);
	}

	// yxwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.w, v.x);
	}

	// yxwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.w, v.y);
	}

	// yxwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.w, v.z);
	}

	// yxww
	template<typename T>
	GLM_INLINE glm::vec<4, T> yxww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.x, v.w, v.w);
	}

	// yyxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.x);
	}

	// yyxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.y);
	}

	// yyxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.z);
	}

	// yyxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.x, v.w);
	}

	// yyyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyx(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.x);
	}

	// yyyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyy(const glm::vec<2, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.y);
	}

	// yyyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.z);
	}

	// yyyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.y, v.w);
	}

	// yyzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.z, v.x);
	}

	// yyzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.z, v.y);
	}

	// yyzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yyzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.z, v.z);
	}

	// yyzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.z, v.w);
	}

	// yywx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yywx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.w, v.x);
	}

	// yywy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yywy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.w, v.y);
	}

	// yywz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yywz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.w, v.z);
	}

	// yyww
	template<typename T>
	GLM_INLINE glm::vec<4, T> yyww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.y, v.w, v.w);
	}

	// yzxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.x, v.x);
	}

	// yzxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.x, v.y);
	}

	// yzxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.x, v.z);
	}

	// yzxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.x, v.w);
	}

	// yzyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.y, v.x);
	}

	// yzyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.y, v.y);
	}

	// yzyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.y, v.z);
	}

	// yzyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.y, v.w);
	}

	// yzzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.z, v.x);
	}

	// yzzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.z, v.y);
	}

	// yzzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> yzzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.z, v.z);
	}

	// yzzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.z, v.w);
	}

	// yzwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.w, v.x);
	}

	// yzwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.w, v.y);
	}

	// yzwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.w, v.z);
	}

	// yzww
	template<typename T>
	GLM_INLINE glm::vec<4, T> yzww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.z, v.w, v.w);
	}

	// ywxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.x, v.x);
	}

	// ywxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.x, v.y);
	}

	// ywxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.x, v.z);
	}

	// ywxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.x, v.w);
	}

	// ywyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.y, v.x);
	}

	// ywyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.y, v.y);
	}

	// ywyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.y, v.z);
	}

	// ywyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.y, v.w);
	}

	// ywzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.z, v.x);
	}

	// ywzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.z, v.y);
	}

	// ywzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.z, v.z);
	}

	// ywzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.z, v.w);
	}

	// ywwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.w, v.x);
	}

	// ywwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.w, v.y);
	}

	// ywwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.w, v.z);
	}

	// ywww
	template<typename T>
	GLM_INLINE glm::vec<4, T> ywww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.y, v.w, v.w, v.w);
	}

	// zxxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.x, v.x);
	}

	// zxxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.x, v.y);
	}

	// zxxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.x, v.z);
	}

	// zxxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.x, v.w);
	}

	// zxyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.y, v.x);
	}

	// zxyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.y, v.y);
	}

	// zxyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.y, v.z);
	}

	// zxyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.y, v.w);
	}

	// zxzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.z, v.x);
	}

	// zxzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.z, v.y);
	}

	// zxzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zxzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.z, v.z);
	}

	// zxzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.z, v.w);
	}

	// zxwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.w, v.x);
	}

	// zxwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.w, v.y);
	}

	// zxwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.w, v.z);
	}

	// zxww
	template<typename T>
	GLM_INLINE glm::vec<4, T> zxww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.x, v.w, v.w);
	}

	// zyxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.x, v.x);
	}

	// zyxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.x, v.y);
	}

	// zyxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.x, v.z);
	}

	// zyxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.x, v.w);
	}

	// zyyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.y, v.x);
	}

	// zyyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.y, v.y);
	}

	// zyyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.y, v.z);
	}

	// zyyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.y, v.w);
	}

	// zyzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.z, v.x);
	}

	// zyzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.z, v.y);
	}

	// zyzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zyzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.z, v.z);
	}

	// zyzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.z, v.w);
	}

	// zywx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zywx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.w, v.x);
	}

	// zywy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zywy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.w, v.y);
	}

	// zywz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zywz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.w, v.z);
	}

	// zyww
	template<typename T>
	GLM_INLINE glm::vec<4, T> zyww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.y, v.w, v.w);
	}

	// zzxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzxx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.x, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.x, v.x);
	}

	// zzxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzxy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.x, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.x, v.y);
	}

	// zzxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzxz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.x, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.x, v.z);
	}

	// zzxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.x, v.w);
	}

	// zzyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzyx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.y, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.y, v.x);
	}

	// zzyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzyy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.y, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.y, v.y);
	}

	// zzyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzyz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.y, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.y, v.z);
	}

	// zzyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.y, v.w);
	}

	// zzzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzzx(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.z, v.x);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.z, v.x);
	}

	// zzzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzzy(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.z, v.y);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.z, v.y);
	}

	// zzzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzzz(const glm::vec<3, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.z, v.z);
	}

	template<typename T>
	GLM_INLINE glm::vec<4, T> zzzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.z, v.z);
	}

	// zzzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.z, v.w);
	}

	// zzwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.w, v.x);
	}

	// zzwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.w, v.y);
	}

	// zzwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.w, v.z);
	}

	// zzww
	template<typename T>
	GLM_INLINE glm::vec<4, T> zzww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.z, v.w, v.w);
	}

	// zwxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.x, v.x);
	}

	// zwxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.x, v.y);
	}

	// zwxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.x, v.z);
	}

	// zwxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.x, v.w);
	}

	// zwyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.y, v.x);
	}

	// zwyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.y, v.y);
	}

	// zwyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.y, v.z);
	}

	// zwyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.y, v.w);
	}

	// zwzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.z, v.x);
	}

	// zwzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.z, v.y);
	}

	// zwzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.z, v.z);
	}

	// zwzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.z, v.w);
	}

	// zwwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.w, v.x);
	}

	// zwwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.w, v.y);
	}

	// zwwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.w, v.z);
	}

	// zwww
	template<typename T>
	GLM_INLINE glm::vec<4, T> zwww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.z, v.w, v.w, v.w);
	}

	// wxxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.x, v.x);
	}

	// wxxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.x, v.y);
	}

	// wxxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.x, v.z);
	}

	// wxxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.x, v.w);
	}

	// wxyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.y, v.x);
	}

	// wxyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.y, v.y);
	}

	// wxyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.y, v.z);
	}

	// wxyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.y, v.w);
	}

	// wxzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.z, v.x);
	}

	// wxzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.z, v.y);
	}

	// wxzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.z, v.z);
	}

	// wxzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.z, v.w);
	}

	// wxwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.w, v.x);
	}

	// wxwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.w, v.y);
	}

	// wxwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.w, v.z);
	}

	// wxww
	template<typename T>
	GLM_INLINE glm::vec<4, T> wxww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.x, v.w, v.w);
	}

	// wyxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.x, v.x);
	}

	// wyxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.x, v.y);
	}

	// wyxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.x, v.z);
	}

	// wyxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.x, v.w);
	}

	// wyyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.y, v.x);
	}

	// wyyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.y, v.y);
	}

	// wyyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.y, v.z);
	}

	// wyyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.y, v.w);
	}

	// wyzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.z, v.x);
	}

	// wyzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.z, v.y);
	}

	// wyzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.z, v.z);
	}

	// wyzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.z, v.w);
	}

	// wywx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wywx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.w, v.x);
	}

	// wywy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wywy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.w, v.y);
	}

	// wywz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wywz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.w, v.z);
	}

	// wyww
	template<typename T>
	GLM_INLINE glm::vec<4, T> wyww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.y, v.w, v.w);
	}

	// wzxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.x, v.x);
	}

	// wzxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.x, v.y);
	}

	// wzxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.x, v.z);
	}

	// wzxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.x, v.w);
	}

	// wzyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.y, v.x);
	}

	// wzyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.y, v.y);
	}

	// wzyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.y, v.z);
	}

	// wzyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.y, v.w);
	}

	// wzzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.z, v.x);
	}

	// wzzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.z, v.y);
	}

	// wzzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.z, v.z);
	}

	// wzzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.z, v.w);
	}

	// wzwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.w, v.x);
	}

	// wzwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.w, v.y);
	}

	// wzwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.w, v.z);
	}

	// wzww
	template<typename T>
	GLM_INLINE glm::vec<4, T> wzww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.z, v.w, v.w);
	}

	// wwxx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwxx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.x, v.x);
	}

	// wwxy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwxy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.x, v.y);
	}

	// wwxz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwxz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.x, v.z);
	}

	// wwxw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwxw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.x, v.w);
	}

	// wwyx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwyx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.y, v.x);
	}

	// wwyy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwyy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.y, v.y);
	}

	// wwyz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwyz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.y, v.z);
	}

	// wwyw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwyw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.y, v.w);
	}

	// wwzx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwzx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.z, v.x);
	}

	// wwzy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwzy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.z, v.y);
	}

	// wwzz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwzz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.z, v.z);
	}

	// wwzw
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwzw(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.z, v.w);
	}

	// wwwx
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwwx(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.w, v.x);
	}

	// wwwy
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwwy(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.w, v.y);
	}

	// wwwz
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwwz(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.w, v.z);
	}

	// wwww
	template<typename T>
	GLM_INLINE glm::vec<4, T> wwww(const glm::vec<4, T> &v) {
		return glm::vec<4, T>(v.w, v.w, v.w, v.w);
	}

}
