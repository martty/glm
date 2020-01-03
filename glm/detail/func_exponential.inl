/// @ref core
/// @file glm/detail/func_exponential.inl

#include "../vector_relational.hpp"
#include "_vectorize.hpp"
#include <limits>
#include <cmath>
#include <cassert>

namespace glm{
namespace detail
{
#	if GLM_HAS_CXX11_STL
		using std::log2;
#	else
		template<typename genType>
		genType log2(genType Value)
		{
			return std::log(Value) * static_cast<genType>(1.4426950408889634073599246810019);
		}
#	endif

	template<length_t L, typename T, bool isFloat, bool Aligned>
	struct compute_log2
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& v)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'log2' only accept floating-point inputs. Include <glm/gtc/integer.hpp> for integer inputs.");

			return detail::functor1<vec, L, T, T>::call(log2, v);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_sqrt
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return detail::functor1<vec, L, T, T>::call(std::sqrt, x);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_inversesqrt
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return static_cast<T>(1) / sqrt(x);
		}
	};
}//namespace detail

	// pow
	using std::pow;
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> pow(vec<L, T> const& base, vec<L, T> const& exponent)
	{
		return detail::functor2<vec, L, T>::call(pow, base, exponent);
	}

	// exp
	using std::exp;
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> exp(vec<L, T> const& x)
	{
		return detail::functor1<vec, L, T, T>::call(exp, x);
	}

	// log
	using std::log;
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> log(vec<L, T> const& x)
	{
		return detail::functor1<vec, L, T, T>::call(log, x);
	}

#   if GLM_HAS_CXX11_STL
    using std::exp2;
#   else
	//exp2, ln2 = 0.69314718055994530941723212145818f
	template<typename genType>
	GLM_FUNC_QUALIFIER genType exp2(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'exp2' only accept floating-point inputs");

		return std::exp(static_cast<genType>(0.69314718055994530941723212145818) * x);
	}
#   endif

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> exp2(vec<L, T> const& x)
	{
		return detail::functor1<vec, L, T, T>::call(exp2, x);
	}

	// log2, ln2 = 0.69314718055994530941723212145818f
	template<typename genType>
	GLM_FUNC_QUALIFIER genType log2(genType x)
	{
		return std::log2(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> log2(vec<L, T> const& x)
	{
		return detail::compute_log2<L, T, std::numeric_limits<T>::is_iec559, false>::call(x);
	}

	// sqrt
	using std::sqrt;
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> sqrt(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'sqrt' only accept floating-point inputs");
		return detail::compute_sqrt<L, T, false>::call(x);
	}

	// inversesqrt
	template<typename genType>
	GLM_FUNC_QUALIFIER genType inversesqrt(genType x)
	{
		return static_cast<genType>(1) / sqrt(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> inversesqrt(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'inversesqrt' only accept floating-point inputs");
		return detail::compute_inversesqrt<L, T, false>::call(x);
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "func_exponential_simd.inl"
#endif

