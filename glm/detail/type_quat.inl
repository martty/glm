#include "../trigonometric.hpp"
#include "../exponential.hpp"
#include "../ext/quaternion_geometric.hpp"
#include <limits>
#include "setup.hpp"

namespace glm{
namespace detail
{
	template <typename T>
	struct genTypeTrait<qua<T>>
	{
		static const genTypeEnum GENTYPE = GENTYPE_QUAT;
	};

	template<typename V, typename T, bool Aligned>
	struct compute_dot{};

	template<typename T, bool Aligned>
	struct compute_dot<qua<T>, T, Aligned>	
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static T call(qua<T> const& a, qua<T> const& b)
		{
			vec<4, T> tmp(a.w * b.w, a.x * b.x, a.y * b.y, a.z * b.z);
			return (tmp.x + tmp.y) + (tmp.z + tmp.w);
		}
	};

	template<typename T, bool Aligned>
	struct compute_quat_add
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T> call(qua<T> const& q, qua<T> const& p)
		{
			return qua<T>(q.w + p.w, q.x + p.x, q.y + p.y, q.z + p.z);
		}
	};

	template<typename T, bool Aligned>
	struct compute_quat_sub
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T> call(qua<T> const& q, qua<T> const& p)
		{
			return qua<T>(q.w - p.w, q.x - p.x, q.y - p.y, q.z - p.z);
		}
	};

	template<typename T, bool Aligned>
	struct compute_quat_mul_scalar
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T> call(qua<T> const& q, T s)
		{
			return qua<T>(q.w * s, q.x * s, q.y * s, q.z * s);
		}
	};

	template<typename T, bool Aligned>
	struct compute_quat_div_scalar
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static qua<T> call(qua<T> const& q, T s)
		{
			return qua<T>(q.w / s, q.x / s, q.y / s, q.z / s);
		}
	};

	template<typename T, bool Aligned>
	struct compute_quat_mul_vec4
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(qua<T> const& q, vec<4, T> const& v)
		{
			return vec<4, T>(q * vec<3, T>(v), v.w);
		}
	};
}//namespace detail

	// -- Component accesses --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T & qua<T>::operator[](typename qua<T>::length_type i)
	{
		assert(i >= 0 && i < this->length());
		return (&x)[i];
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T const& qua<T>::operator[](typename qua<T>::length_type i) const
	{
		assert(i >= 0 && i < this->length());
		return (&x)[i];
	}

	// -- Implicit basic constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T>::qua()
#			if GLM_CONFIG_CTOR_INIT != GLM_CTOR_INIT_DISABLE
			: x(0), y(0), z(0), w(1)
#			endif
		{}

		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T>::qua(qua<T> const& q)
			: x(q.x), y(q.y), z(q.z), w(q.w)
		{}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T>::qua(T s, vec<3, T> const& v)
		: x(v.x), y(v.y), z(v.z), w(s)
	{}

	template <typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T>::qua(T _w, T _x, T _y, T _z)
		: x(_x), y(_y), z(_z), w(_w)
	{}

	// -- Conversion constructors --

	//template<typename valType>
	//GLM_FUNC_QUALIFIER qua<valType>::qua
	//(
	//	valType const& pitch,
	//	valType const& yaw,
	//	valType const& roll
	//)
	//{
	//	vec<3, valType> eulerAngle(pitch * valType(0.5), yaw * valType(0.5), roll * valType(0.5));
	//	vec<3, valType> c = glm::cos(eulerAngle * valType(0.5));
	//	vec<3, valType> s = glm::sin(eulerAngle * valType(0.5));
	//
	//	this->w = c.x * c.y * c.z + s.x * s.y * s.z;
	//	this->x = s.x * c.y * c.z - c.x * s.y * s.z;
	//	this->y = c.x * s.y * c.z + s.x * c.y * s.z;
	//	this->z = c.x * c.y * s.z - s.x * s.y * c.z;
	//}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T>::qua(vec<3, T> const& u, vec<3, T> const& v)
	{
		T norm_u_norm_v = sqrt(dot(u, u) * dot(v, v));
		T real_part = norm_u_norm_v + dot(u, v);
		vec<3, T> t;

		if(real_part < static_cast<T>(1.e-6f) * norm_u_norm_v)
		{
			// If u and v are exactly opposite, rotate 180 degrees
			// around an arbitrary orthogonal axis. Axis normalisation
			// can happen later, when we normalise the quaternion.
			real_part = static_cast<T>(0);
			t = abs(u.x) > abs(u.z) ? vec<3, T>(-u.y, u.x, static_cast<T>(0)) : vec<3, T>(static_cast<T>(0), -u.z, u.y);
		}
		else
		{
			// Otherwise, build quaternion the standard way.
			t = cross(u, v);
		}

		*this = normalize(qua<T>(real_part, t.x, t.y, t.z));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T>::qua(vec<3, T> const& eulerAngle)
	{
		vec<3, T> c = glm::cos(eulerAngle * T(0.5));
		vec<3, T> s = glm::sin(eulerAngle * T(0.5));

		this->w = c.x * c.y * c.z + s.x * s.y * s.z;
		this->x = s.x * c.y * c.z - c.x * s.y * s.z;
		this->y = c.x * s.y * c.z + s.x * c.y * s.z;
		this->z = c.x * c.y * s.z - s.x * s.y * c.z;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T>::qua(mat<3, 3, T> const& m)
	{
		*this = quat_cast(m);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T>::qua(mat<4, 4, T> const& m)
	{
		*this = quat_cast(m);
	}

#	if GLM_HAS_EXPLICIT_CONVERSION_OPERATORS
	template<typename T>
	GLM_FUNC_QUALIFIER qua<T>::operator mat<3, 3, T>() const
	{
		return mat3_cast(*this);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER qua<T>::operator mat<4, 4, T>() const
	{
		return mat4_cast(*this);
	}
#	endif//GLM_HAS_EXPLICIT_CONVERSION_OPERATORS

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> & qua<T>::operator=(qua<T> const& q)
		{
			this->w = q.w;
			this->x = q.x;
			this->y = q.y;
			this->z = q.z;
			return *this;
		}
#	endif

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> & qua<T>::operator=(qua<U> const& q)
	{
		this->w = static_cast<T>(q.w);
		this->x = static_cast<T>(q.x);
		this->y = static_cast<T>(q.y);
		this->z = static_cast<T>(q.z);
		return *this;
	}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> & qua<T>::operator+=(qua<U> const& q)
	{
		return (*this = detail::compute_quat_add<T, false>::call(*this, qua<T>(q)));
	}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> & qua<T>::operator-=(qua<U> const& q)
	{
		return (*this = detail::compute_quat_sub<T, false>::call(*this, qua<T>(q)));
	}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> & qua<T>::operator*=(qua<U> const& r)
	{
		qua<T> const p(*this);
		qua<T> const q(r);

		this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
		this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
		this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
		this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
		return *this;
	}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> & qua<T>::operator*=(U s)
	{
		return (*this = detail::compute_quat_mul_scalar<T, false>::call(*this, static_cast<U>(s)));
	}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> & qua<T>::operator/=(U s)
	{
		return (*this = detail::compute_quat_div_scalar<T, false>::call(*this, static_cast<U>(s)));
	}

	// -- Unary bit operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator+(qua<T> const& q)
	{
		return q;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator-(qua<T> const& q)
	{
		return qua<T>(-q.w, -q.x, -q.y, -q.z);
	}

	// -- Binary operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator+(qua<T> const& q, qua<T> const& p)
	{
		return qua<T>(q) += p;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator-(qua<T> const& q, qua<T> const& p)
	{
		return qua<T>(q) -= p;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator*(qua<T> const& q, qua<T> const& p)
	{
		return qua<T>(q) *= p;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator*(qua<T> const& q, vec<3, T> const& v)
	{
		vec<3, T> const QuatVector(q.x, q.y, q.z);
		vec<3, T> const uv(glm::cross(QuatVector, v));
		vec<3, T> const uuv(glm::cross(QuatVector, uv));

		return v + ((uv * q.w) + uuv) * static_cast<T>(2);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, qua<T> const& q)
	{
		return glm::inverse(q) * v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator*(qua<T> const& q, vec<4, T> const& v)
	{
		return detail::compute_quat_mul_vec4<T, false>::call(q, v);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v, qua<T> const& q)
	{
		return glm::inverse(q) * v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator*(qua<T> const& q, T const& s)
	{
		return qua<T>(
			q.w * s, q.x * s, q.y * s, q.z * s);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator*(T const& s, qua<T> const& q)
	{
		return q * s;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR qua<T> operator/(qua<T> const& q, T const& s)
	{
		return qua<T>(
			q.w / s, q.x / s, q.y / s, q.z / s);
	}

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(qua<T> const& q1, qua<T> const& q2)
	{
		return q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(qua<T> const& q1, qua<T> const& q2)
	{
		return q1.x != q2.x || q1.y != q2.y || q1.z != q2.z || q1.w != q2.w;
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "type_quat_simd.inl"
#endif

