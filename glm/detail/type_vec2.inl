/// @ref core

#include "./compute_vector_relational.hpp"

namespace glm
{
	// -- Implicit basic constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T>::vec()
#			if GLM_CONFIG_CTOR_INIT != GLM_CTOR_INIT_DISABLE
				: x(0), y(0)
#			endif
		{}

		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T>::vec(vec<2, T> const& v)
			: x(v.x), y(v.y)
		{}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T>::vec(T scalar)
		: x(scalar), y(scalar)
	{}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T>::vec(T _x, T _y)
		: x(_x), y(_y)
	{}

	// -- Conversion vector constructors --

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T>::vec(vec<2, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
	{}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T>::vec(vec<3, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
	{}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T>::vec(vec<4, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
	{}

	// -- Component accesses --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T & vec<2, T>::operator[](typename vec<2, T>::length_type i)
	{
		assert(i >= 0 && i < this->length());
		switch(i)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		}
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T const& vec<2, T>::operator[](typename vec<2, T>::length_type i) const
	{
		assert(i >= 0 && i < this->length());
		switch(i)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		}
	}

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator=(vec<2, T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			return *this;
		}
#	endif

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator+=(T scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator+=(vec const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator-=(T scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator-=(vec const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator*=(T scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator*=(vec const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator/=(T scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		return *this;
	}

	
	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> & vec<2, T>::operator/=(vec const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}

	// -- Unary arithmetic operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v)
	{
		return v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v)
	{
		return vec<2, T>(
			-v.x,
			-v.y);
	}

	// -- Binary arithmetic operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x + scalar,
			v.y + scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator+(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar + v.x,
			scalar + v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator+(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x + v2.x,
			v1.x + v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x + v2.x,
			v1.y + v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x - scalar,
			v.y - scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator-(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar - v.x,
			scalar - v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x - v2.x,
			v1.y - v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x * scalar,
			v.y * scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator*(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar * v.x,
			scalar * v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator*(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x * v2.x,
			v1.x * v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x * v2.x,
			v1.y * v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x / scalar,
			v.y / scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator/(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar / v.x,
			scalar / v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x / v2.x,
			v1.y / v2.y);
	}

	// -- Binary bit operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x % scalar,
			v.y % scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(
			v1.x % v2.x,
			v1.y % v2.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator%(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar % v.x,
			scalar % v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x % v2.x,
			v1.y % v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x & scalar,
			v.y & scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator&(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar & v.x,
			scalar & v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x & v2.x,
			v1.y & v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x | scalar,
			v.y | scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator|(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar | v.x,
			scalar | v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x | v2.x,
			v1.y | v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x ^ scalar,
			v.y ^ scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator^(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar ^ v.x,
			scalar ^ v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x ^ v2.x,
			v1.y ^ v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x << scalar,
			v.y << scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator<<(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar << v.x,
			scalar << v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x << v2.x,
			v1.y << v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(
			v.x >> scalar,
			v.y >> scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator>>(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(
			scalar >> v.x,
			scalar >> v.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(
			v1.x >> v2.x,
			v1.y >> v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T> operator~(vec<2, T> const& v)
	{
		return vec<2, T>(
			~v.x,
			~v.y);
	}

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.y, v2.y);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return !(v1 == v2);
	}

	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, bool> operator&&(vec<2, bool> const& v1, vec<2, bool> const& v2)
	{
		return vec<2, bool>(v1.x && v2.x, v1.y && v2.y);
	}

	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, bool> operator||(vec<2, bool> const& v1, vec<2, bool> const& v2)
	{
		return vec<2, bool>(v1.x || v2.x, v1.y || v2.y);
	}
}//namespace glm
