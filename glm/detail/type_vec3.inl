/// @ref core

#include "compute_vector_relational.hpp"

namespace glm
{
	// -- Implicit basic constructors --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec()
#			if GLM_CONFIG_CTOR_INIT != GLM_CTOR_INIT_DISABLE
				: x(0), y(0), z(0)
#			endif
		{}

		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec(vec<3, T> const& v)
			: x(v.x), y(v.y), z(v.z)
		{}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar)
	{}

	template <typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec(T _x, T _y, T _z)
		: x(_x), y(_y), z(_z)
	{}

	// -- Conversion vector constructors --

	template<typename T>
	template<typename A, typename B>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec(vec<2, A> const& _xy, B _z)
		: x(static_cast<T>(_xy.x))
		, y(static_cast<T>(_xy.y))
		, z(static_cast<T>(_z))
	{}

	template<typename T>
	template<typename A, typename B>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec(A _x, vec<2, B> const& _yz)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_yz.x))
		, z(static_cast<T>(_yz.y))
	{}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec(vec<3, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z))
	{}

	template<typename T>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>::vec(vec<4, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z))
	{}

	// -- Component accesses --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T & vec<3, T>::operator[](typename vec<3, T>::length_type i)
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
		}
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T const& vec<3, T>::operator[](typename vec<3, T>::length_type i) const
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
		}
	}

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T>& vec<3, T>::operator=(vec<3, T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}
#	endif

	template<typename T>
	
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator+=(T scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator+=(vec<3, T> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator-=(T scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>	
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator-=(vec<3, T> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator*=(T  scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>	
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator*=(vec<3, T> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator/=(T v)
	{
		this->x /= static_cast<T>(v);
		this->y /= static_cast<T>(v);
		this->z /= static_cast<T>(v);
		return *this;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> & vec<3, T>::operator/=(vec<3, T> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		return *this;
	}

	// -- Unary arithmetic operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v)
	{
		return v;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v)
	{
		return vec<3, T>(
			-v.x,
			-v.y,
			-v.z);
	}

	// -- Binary arithmetic operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x + scalar,
			v.y + scalar,
			v.z + scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x + scalar.x,
			v.y + scalar.x,
			v.z + scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator+(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar + v.x,
			scalar + v.y,
			scalar + v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator+(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x + v.x,
			scalar.x + v.y,
			scalar.x + v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x - scalar,
			v.y - scalar,
			v.z - scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x - scalar.x,
			v.y - scalar.x,
			v.z - scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator-(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar - v.x,
			scalar - v.y,
			scalar - v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator-(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x - v.x,
			scalar.x - v.y,
			scalar.x - v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x * scalar.x,
			v.y * scalar.x,
			v.z * scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator*(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar * v.x,
			scalar * v.y,
			scalar * v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator*(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x * v.x,
			scalar.x * v.y,
			scalar.x * v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x / scalar.x,
			v.y / scalar.x,
			v.z / scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator/(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar / v.x,
			scalar / v.y,
			scalar / v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator/(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x / v.x,
			scalar.x / v.y,
			scalar.x / v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z);
	}

	// -- Binary bit operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x % scalar,
			v.y % scalar,
			v.z % scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x % scalar.x,
			v.y % scalar.x,
			v.z % scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator%(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar % v.x,
			scalar % v.y,
			scalar % v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator%(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x % v.x,
			scalar.x % v.y,
			scalar.x % v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x % v2.x,
			v1.y % v2.y,
			v1.z % v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x & scalar,
			v.y & scalar,
			v.z & scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x & scalar.x,
			v.y & scalar.x,
			v.z & scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator&(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar & v.x,
			scalar & v.y,
			scalar & v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator&(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x & v.x,
			scalar.x & v.y,
			scalar.x & v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x & v2.x,
			v1.y & v2.y,
			v1.z & v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x | scalar,
			v.y | scalar,
			v.z | scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x | scalar.x,
			v.y | scalar.x,
			v.z | scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator|(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar | v.x,
			scalar | v.y,
			scalar | v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator|(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x | v.x,
			scalar.x | v.y,
			scalar.x | v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x | v2.x,
			v1.y | v2.y,
			v1.z | v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x ^ scalar,
			v.y ^ scalar,
			v.z ^ scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x ^ scalar.x,
			v.y ^ scalar.x,
			v.z ^ scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator^(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar ^ v.x,
			scalar ^ v.y,
			scalar ^ v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator^(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x ^ v.x,
			scalar.x ^ v.y,
			scalar.x ^ v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x ^ v2.x,
			v1.y ^ v2.y,
			v1.z ^ v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x << scalar,
			v.y << scalar,
			v.z << scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x << scalar.x,
			v.y << scalar.x,
			v.z << scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator<<(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar << v.x,
			scalar << v.y,
			scalar << v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator<<(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x << v.x,
			scalar.x << v.y,
			scalar.x << v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x << v2.x,
			v1.y << v2.y,
			v1.z << v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(
			v.x >> scalar,
			v.y >> scalar,
			v.z >> scalar);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(
			v.x >> scalar.x,
			v.y >> scalar.x,
			v.z >> scalar.x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator>>(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar >> v.x,
			scalar >> v.y,
			scalar >> v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator>>(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(
			scalar.x >> v.x,
			scalar.x >> v.y,
			scalar.x >> v.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(
			v1.x >> v2.x,
			v1.y >> v2.y,
			v1.z >> v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T> operator~(vec<3, T> const& v)
	{
		return vec<3, T>(
			~v.x,
			~v.y,
			~v.z);
	}

	// -- Boolean operators --

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.y, v2.y) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.z, v2.z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return !(v1 == v2);
	}

	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, bool> operator&&(vec<3, bool> const& v1, vec<3, bool> const& v2)
	{
		return vec<3, bool>(v1.x && v2.x, v1.y && v2.y, v1.z && v2.z);
	}

	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, bool> operator||(vec<3, bool> const& v1, vec<3, bool> const& v2)
	{
		return vec<3, bool>(v1.x || v2.x, v1.y || v2.y, v1.z || v2.z);
	}
}//namespace glm
