/// @ref core

#include "compute_vector_relational.hpp"

namespace glm{
namespace detail
{
	template<typename T, bool Aligned>
	struct compute_vec4_add
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
		}
	};

	template<typename T, bool Aligned>
	struct compute_vec4_sub
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
		}
	};

	template<typename T, bool Aligned>
	struct compute_vec4_mul
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
		}
	};

	template<typename T, bool Aligned>
	struct compute_vec4_div
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
		}
	};

	template<typename T, bool Aligned>
	struct compute_vec4_mod
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_and
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_or
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_xor
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_shift_left
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x << b.x, a.y << b.y, a.z << b.z, a.w << b.w);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_shift_right
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(a.x >> b.x, a.y >> b.y, a.z >> b.z, a.w >> b.w);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_equal
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static bool call(vec<4, T> const& v1, vec<4, T> const& v2)
		{
			return
				detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x) &&
				detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.y, v2.y) &&
				detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.z, v2.z) &&
				detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.w, v2.w);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_nequal
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static bool call(vec<4, T> const& v1, vec<4, T> const& v2)
		{
			return !compute_vec4_equal<T, detail::is_int<T>::value, sizeof(T) * 8, false>::call(v1, v2);
		}
	};

	template<typename T, int IsInt, std::size_t Size, bool Aligned>
	struct compute_vec4_bitwise_not
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T> call(vec<4, T> const& v)
		{
			return vec<4, T>(~v.x, ~v.y, ~v.z, ~v.w);
		}
	};
}//namespace detail

	// -- Implicit basic constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec()
#			if GLM_CONFIG_CTOR_INIT != GLM_CTOR_INIT_DISABLE
				: x(0), y(0), z(0), w(0)
#			endif
		{}

		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(vec<4, T> const& v)
			: x(v.x), y(v.y), z(v.z), w(v.w)
		{}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar), w(scalar)
	{}

	template <typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(T _x, T _y, T _z, T _w)
		: x(_x), y(_y), z(_z), w(_w)
	{}

	// -- Conversion vector constructors --

	template<typename T>
	template<typename A, typename B, typename C>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(vec<2, A> const& _xy, B _z, C _w)
		: x(static_cast<T>(_xy.x))
		, y(static_cast<T>(_xy.y))
		, z(static_cast<T>(_z))
		, w(static_cast<T>(_w))
	{}

	template<typename T>
	template<typename A, typename B, typename C>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(A _x, vec<2, B> const& _yz, C _w)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_yz.x))
		, z(static_cast<T>(_yz.y))
		, w(static_cast<T>(_w))
	{}

	template<typename T>
	template<typename A, typename B, typename C>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(A _x, B _y, vec<2, C> const& _zw)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_zw.x))
		, w(static_cast<T>(_zw.y))
	{}

	template<typename T>
	template<typename A, typename B>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(vec<3, A> const& _xyz, B _w)
		: x(static_cast<T>(_xyz.x))
		, y(static_cast<T>(_xyz.y))
		, z(static_cast<T>(_xyz.z))
		, w(static_cast<T>(_w))
	{}

	template<typename T>
	template<typename A, typename B>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(A _x, vec<3, B> const& _yzw)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_yzw.x))
		, z(static_cast<T>(_yzw.y))
		, w(static_cast<T>(_yzw.z))
	{}

	template<typename T>
	template<typename A, typename B>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(vec<2, A> const& _xy, vec<2, B> const& _zw)
		: x(static_cast<T>(_xy.x))
		, y(static_cast<T>(_xy.y))
		, z(static_cast<T>(_zw.x))
		, w(static_cast<T>(_zw.y))
	{}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>::vec(vec<4, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z))
		, w(static_cast<T>(v.w))
	{}

	// -- Component accesses --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T& vec<4, T>::operator[](typename vec<4, T>::length_type i)
	{
		assert(i >= 0 && i < this->length());
		switch(i)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		}
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T const& vec<4, T>::operator[](typename vec<4, T>::length_type i) const
	{
		assert(i >= 0 && i < this->length());
		switch(i)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		}
	}

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T>& vec<4, T>::operator=(vec<4, T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
			return *this;
		}
#	endif

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator+=(T scalar)
	{
		return (*this = detail::compute_vec4_add<T, false>::call(*this, vec<4, T>(scalar)));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator+=(vec<4, T> const& v)
	{
		return (*this = detail::compute_vec4_add<T, false>::call(*this, vec<4, T>(v)));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator-=(T scalar)
	{
		return (*this = detail::compute_vec4_sub<T, false>::call(*this, vec<4, T>(scalar)));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator-=(vec<4, T> const& v)
	{
		return (*this = detail::compute_vec4_sub<T, false>::call(*this, vec<4, T>(v)));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator*=(T scalar)
	{
		return (*this = detail::compute_vec4_mul<T, false>::call(*this, vec<4, T>(scalar)));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator*=(vec<4, T> const& v)
	{
		return (*this = detail::compute_vec4_mul<T, false>::call(*this, vec<4, T>(v)));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator/=(T scalar)
	{
		return (*this = detail::compute_vec4_div<T, false>::call(*this, vec<4, T>(scalar)));
	}

	
	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> & vec<4, T>::operator/=(vec<4, T> const& v)
	{
		return (*this = detail::compute_vec4_div<T, false>::call(*this, vec<4, T>(v)));
	}

	// -- Unary constant operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v)
	{
		return v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v)
	{
		return vec<4, T>(0) -= v;
	}

	// -- Binary arithmetic operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v, T const & scalar)
	{
		return vec<4, T>(v) += scalar;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator+(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(v) += scalar;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator+(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) += v2;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v, T const & scalar)
	{
		return vec<4, T>(v) -= scalar;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator-(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) -= v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator-(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) -= v2;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v, T const & scalar)
	{
		return vec<4, T>(v) *= scalar;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator*(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(v) *= scalar;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator*(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) *= v2;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v, T const & scalar)
	{
		return vec<4, T>(v) /= scalar;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator/(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) /= v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T> operator/(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) /= v2;
	}

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return detail::compute_vec4_equal<T, detail::is_int<T>::value, sizeof(T) * 8, false>::call(v1, v2);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return detail::compute_vec4_nequal<T, detail::is_int<T>::value, sizeof(T) * 8, false>::call(v1, v2);
	}

	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, bool> operator&&(vec<4, bool> const& v1, vec<4, bool> const& v2)
	{
		return vec<4, bool>(v1.x && v2.x, v1.y && v2.y, v1.z && v2.z, v1.w && v2.w);
	}

	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, bool> operator||(vec<4, bool> const& v1, vec<4, bool> const& v2)
	{
		return vec<4, bool>(v1.x || v2.x, v1.y || v2.y, v1.z || v2.z, v1.w || v2.w);
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "type_vec4_simd.inl"
#endif
