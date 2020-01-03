/// @ref gtx_dual_quaternion

#include "../geometric.hpp"
#include <limits>

namespace glm
{
	// -- Component accesses --

	template<typename T>
	GLM_FUNC_QUALIFIER typename tdualquat<T>::part_type & tdualquat<T>::operator[](typename tdualquat<T>::length_type i)
	{
		assert(i >= 0 && i < this->length());
		return (&real)[i];
	}

	template<typename T>
	GLM_FUNC_QUALIFIER typename tdualquat<T>::part_type const& tdualquat<T>::operator[](typename tdualquat<T>::length_type i) const
	{
		assert(i >= 0 && i < this->length());
		return (&real)[i];
	}

	// -- Implicit basic constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T>::tdualquat()
#			if GLM_CONFIG_DEFAULTED_FUNCTIONS != GLM_DISABLE
			: real(qua<T>())
			, dual(qua<T>(0, 0, 0, 0))
#			endif
		{}

		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T>::tdualquat(tdualquat<T> const& d)
			: real(d.real)
			, dual(d.dual)
		{}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T>::tdualquat(qua<T> const& r)
		: real(r), dual(qua<T>(0, 0, 0, 0))
	{}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T>::tdualquat(qua<T> const& q, vec<3, T> const& p)
		: real(q), dual(
			T(-0.5) * ( p.x*q.x + p.y*q.y + p.z*q.z),
			T(+0.5) * ( p.x*q.w + p.y*q.z - p.z*q.y),
			T(+0.5) * (-p.x*q.z + p.y*q.w + p.z*q.x),
			T(+0.5) * ( p.x*q.y - p.y*q.x + p.z*q.w))
	{}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T>::tdualquat(qua<T> const& r, qua<T> const& d)
		: real(r), dual(d)
	{}

	// -- Conversion constructors --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T>::tdualquat(mat<2, 4, T> const& m)
	{
		*this = dualquat_cast(m);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tdualquat<T>::tdualquat(mat<3, 4, T> const& m)
	{
		*this = dualquat_cast(m);
	}

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER tdualquat<T> & tdualquat<T>::operator=(tdualquat<T> const& q)
		{
			this->real = q.real;
			this->dual = q.dual;
			return *this;
		}
#	endif

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER tdualquat<T> & tdualquat<T>::operator=(tdualquat<U> const& q)
	{
		this->real = q.real;
		this->dual = q.dual;
		return *this;
	}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER tdualquat<T> & tdualquat<T>::operator*=(U s)
	{
		this->real *= static_cast<T>(s);
		this->dual *= static_cast<T>(s);
		return *this;
	}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER tdualquat<T> & tdualquat<T>::operator/=(U s)
	{
		this->real /= static_cast<T>(s);
		this->dual /= static_cast<T>(s);
		return *this;
	}

	// -- Unary bit operators --

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> operator+(tdualquat<T> const& q)
	{
		return q;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> operator-(tdualquat<T> const& q)
	{
		return tdualquat<T>(-q.real, -q.dual);
	}

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> operator+(tdualquat<T> const& q, tdualquat<T> const& p)
	{
		return tdualquat<T>(q.real + p.real,q.dual + p.dual);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> operator*(tdualquat<T> const& p, tdualquat<T> const& o)
	{
		return tdualquat<T>(p.real * o.real,p.real * o.dual + p.dual * o.real);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> operator*(tdualquat<T> const& q, vec<3, T> const& v)
	{
		vec<3, T> const real_v3(q.real.x,q.real.y,q.real.z);
		vec<3, T> const dual_v3(q.dual.x,q.dual.y,q.dual.z);
		return (cross(real_v3, cross(real_v3,v) + v * q.real.w + dual_v3) + dual_v3 * q.real.w - real_v3 * q.dual.w) * T(2) + v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> operator*(vec<3, T> const& v,	tdualquat<T> const& q)
	{
		return glm::inverse(q) * v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, T> operator*(tdualquat<T> const& q, vec<4, T> const& v)
	{
		return vec<4, T>(q * vec<3, T>(v), v.w);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, T> operator*(vec<4, T> const& v,	tdualquat<T> const& q)
	{
		return glm::inverse(q) * v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> operator*(tdualquat<T> const& q, T const& s)
	{
		return tdualquat<T>(q.real * s, q.dual * s);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> operator*(T const& s, tdualquat<T> const& q)
	{
		return q * s;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> operator/(tdualquat<T> const& q,	T const& s)
	{
		return tdualquat<T>(q.real / s, q.dual / s);
	}

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_QUALIFIER bool operator==(tdualquat<T> const& q1, tdualquat<T> const& q2)
	{
		return (q1.real == q2.real) && (q1.dual == q2.dual);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER bool operator!=(tdualquat<T> const& q1, tdualquat<T> const& q2)
	{
		return (q1.real != q2.real) || (q1.dual != q2.dual);
	}

	// -- Operations --

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> dual_quat_identity()
	{
		return tdualquat<T>(
			qua<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)),
			qua<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> normalize(tdualquat<T> const& q)
	{
		return q / length(q.real);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> lerp(tdualquat<T> const& x, tdualquat<T> const& y, T const& a)
	{
		// Dual Quaternion Linear blend aka DLB:
		// Lerp is only defined in [0, 1]
		assert(a >= static_cast<T>(0));
		assert(a <= static_cast<T>(1));
		T const k = dot(x.real,y.real) < static_cast<T>(0) ? -a : a;
		T const one(1);
		return tdualquat<T>(x * (one - a) + y * k);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> inverse(tdualquat<T> const& q)
	{
		const glm::qua<T> real = conjugate(q.real);
		const glm::qua<T> dual = conjugate(q.dual);
		return tdualquat<T>(real, dual + (real * (-2.0f * dot(real,dual))));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<2, 4, T> mat2x4_cast(tdualquat<T> const& x)
	{
		return mat<2, 4, T>( x[0].x, x[0].y, x[0].z, x[0].w, x[1].x, x[1].y, x[1].z, x[1].w );
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<3, 4, T> mat3x4_cast(tdualquat<T> const& x)
	{
		qua<T> r = x.real / length2(x.real);

		qua<T> const rr(r.w * x.real.w, r.x * x.real.x, r.y * x.real.y, r.z * x.real.z);
		r *= static_cast<T>(2);

		T const xy = r.x * x.real.y;
		T const xz = r.x * x.real.z;
		T const yz = r.y * x.real.z;
		T const wx = r.w * x.real.x;
		T const wy = r.w * x.real.y;
		T const wz = r.w * x.real.z;

		vec<4, T> const a(
			rr.w + rr.x - rr.y - rr.z,
			xy - wz,
			xz + wy,
			-(x.dual.w * r.x - x.dual.x * r.w + x.dual.y * r.z - x.dual.z * r.y));

		vec<4, T> const b(
			xy + wz,
			rr.w + rr.y - rr.x - rr.z,
			yz - wx,
			-(x.dual.w * r.y - x.dual.x * r.z - x.dual.y * r.w + x.dual.z * r.x));

		vec<4, T> const c(
			xz - wy,
			yz + wx,
			rr.w + rr.z - rr.x - rr.y,
			-(x.dual.w * r.z + x.dual.x * r.y - x.dual.y * r.x - x.dual.z * r.w));

		return mat<3, 4, T>(a, b, c);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> dualquat_cast(mat<2, 4, T> const& x)
	{
		return tdualquat<T>(
			qua<T>( x[0].w, x[0].x, x[0].y, x[0].z ),
			qua<T>( x[1].w, x[1].x, x[1].y, x[1].z ));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER tdualquat<T> dualquat_cast(mat<3, 4, T> const& x)
	{
		qua<T> real;

		T const trace = x[0].x + x[1].y + x[2].z;
		if(trace > static_cast<T>(0))
		{
			T const r = sqrt(T(1) + trace);
			T const invr = static_cast<T>(0.5) / r;
			real.w = static_cast<T>(0.5) * r;
			real.x = (x[2].y - x[1].z) * invr;
			real.y = (x[0].z - x[2].x) * invr;
			real.z = (x[1].x - x[0].y) * invr;
		}
		else if(x[0].x > x[1].y && x[0].x > x[2].z)
		{
			T const r = sqrt(T(1) + x[0].x - x[1].y - x[2].z);
			T const invr = static_cast<T>(0.5) / r;
			real.x = static_cast<T>(0.5)*r;
			real.y = (x[1].x + x[0].y) * invr;
			real.z = (x[0].z + x[2].x) * invr;
			real.w = (x[2].y - x[1].z) * invr;
		}
		else if(x[1].y > x[2].z)
		{
			T const r = sqrt(T(1) + x[1].y - x[0].x - x[2].z);
			T const invr = static_cast<T>(0.5) / r;
			real.x = (x[1].x + x[0].y) * invr;
			real.y = static_cast<T>(0.5) * r;
			real.z = (x[2].y + x[1].z) * invr;
			real.w = (x[0].z - x[2].x) * invr;
		}
		else
		{
			T const r = sqrt(T(1) + x[2].z - x[0].x - x[1].y);
			T const invr = static_cast<T>(0.5) / r;
			real.x = (x[0].z + x[2].x) * invr;
			real.y = (x[2].y + x[1].z) * invr;
			real.z = static_cast<T>(0.5) * r;
			real.w = (x[1].x - x[0].y) * invr;
		}

		qua<T> dual;
		dual.x =  static_cast<T>(0.5) * ( x[0].w * real.w + x[1].w * real.z - x[2].w * real.y);
		dual.y =  static_cast<T>(0.5) * (-x[0].w * real.z + x[1].w * real.w + x[2].w * real.x);
		dual.z =  static_cast<T>(0.5) * ( x[0].w * real.y - x[1].w * real.x + x[2].w * real.w);
		dual.w = -static_cast<T>(0.5) * ( x[0].w * real.x + x[1].w * real.y + x[2].w * real.z);
		return tdualquat<T>(real, dual);
	}
}//namespace glm
