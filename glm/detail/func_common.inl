/// @ref core
/// @file glm/detail/func_common.inl

#include "../vector_relational.hpp"
#include "compute_common.hpp"
#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include "_vectorize.hpp"
#include <limits>

#ifdef GLM_IMPL
#undef GLM_FUNC_QUALIFIER
#define GLM_FUNC_QUALIFIER
#define GLM_FUNC_ALWAYS_INLINE inline
#else
#define GLM_FUNC_ALWAYS_INLINE
#endif

namespace glm
{
	// min
	template<typename genType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR genType min(genType x, genType y)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559 || std::numeric_limits<genType>::is_integer, "'min' only accept floating-point or integer inputs");
		return (y < x) ? y : x;
	}

	// max
	template<typename genType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR genType max(genType x, genType y)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559 || std::numeric_limits<genType>::is_integer, "'max' only accept floating-point or integer inputs");

		return (x < y) ? y : x;
	}

	// abs
	template<>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR int abs(int x)
	{
		int const y = x >> (sizeof(int) * 8 - 1);
		return (x ^ y) - y;
	}

	// round
#	if GLM_HAS_CXX11_STL
		using ::std::round;
#	else
		template<typename genType>
		GLM_FUNC_QUALIFIER genType round(genType x)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'round' only accept floating-point inputs");

			return x < static_cast<genType>(0) ? static_cast<genType>(int(x - static_cast<genType>(0.5))) : static_cast<genType>(int(x + static_cast<genType>(0.5)));
		}
#	endif

	// trunc
#	if GLM_HAS_CXX11_STL
		using ::std::trunc;
#	else
		template<typename genType>
		GLM_FUNC_QUALIFIER genType trunc(genType x)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'trunc' only accept floating-point inputs");

			return x < static_cast<genType>(0) ? -std::floor(-x) : std::floor(x);
		}
#	endif

}//namespace glm

namespace glm{
namespace detail
{
	template<length_t L, typename T, bool Aligned>
	struct compute_abs_vector
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<L, T> call(vec<L, T> const& x)
		{
			return detail::functor1<vec, L, T, T>::call(abs, x);
		}
	};

	template<length_t L, typename T, typename U, bool Aligned>
	struct compute_mix_vector
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, vec<L, T> const& y, vec<L, U> const& a)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<U>::is_iec559 || GLM_CONFIG_UNRESTRICTED_GENTYPE, "'mix' only accept floating-point inputs for the interpolator a");

			return vec<L, T>(vec<L, U>(x) * (static_cast<U>(1) - a) + vec<L, U>(y) * a);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_mix_vector<L, T, bool, Aligned>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, vec<L, T> const& y, vec<L, bool> const& a)
		{
			vec<L, T> Result;
			for(length_t i = 0; i < x.length(); ++i)
				Result[i] = a[i] ? y[i] : x[i];
			return Result;
		}
	};

	template<length_t L, typename T, typename U, bool Aligned>
	struct compute_mix_scalar
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, vec<L, T> const& y, U const& a)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<U>::is_iec559 || GLM_CONFIG_UNRESTRICTED_GENTYPE, "'mix' only accept floating-point inputs for the interpolator a");

			return vec<L, T>(vec<L, U>(x) * (static_cast<U>(1) - a) + vec<L, U>(y) * a);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_mix_scalar<L, T, bool, Aligned>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, vec<L, T> const& y, bool const& a)
		{
			return a ? y : x;
		}
	};

	template<typename T, typename U>
	struct compute_mix
	{
		GLM_FUNC_QUALIFIER static T call(T const& x, T const& y, U const& a)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<U>::is_iec559 || GLM_CONFIG_UNRESTRICTED_GENTYPE, "'mix' only accept floating-point inputs for the interpolator a");

			return static_cast<T>(static_cast<U>(x) * (static_cast<U>(1) - a) + static_cast<U>(y) * a);
		}
	};

	template<typename T>
	struct compute_mix<T, bool>
	{
		GLM_FUNC_QUALIFIER static T call(T const& x, T const& y, bool const& a)
		{
			return a ? y : x;
		}
	};

	template<length_t L, typename T, bool isFloat, bool Aligned>
	struct compute_sign
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return vec<L, T>(glm::lessThan(vec<L, T>(0), x)) - vec<L, T>(glm::lessThan(x, vec<L, T>(0)));
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_floor
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return detail::functor1<vec, L, T, T>::call(std::floor, x);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_ceil
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return detail::functor1<vec, L, T, T>::call(std::ceil, x);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_fract
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return x - floor(x);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_trunc
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return detail::functor1<vec, L, T, T>::call(trunc, x);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_round
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x)
		{
			return detail::functor1<vec, L, T, T>::call(round, x);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_mod
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'mod' only accept floating-point inputs. Include <glm/gtc/integer.hpp> for integer inputs.");
			return a - b * floor(a / b);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_min_vector
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, vec<L, T> const& y)
		{
			return detail::functor2<vec, L, T>::call(min, x, y);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_max_vector
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, vec<L, T> const& y)
		{
			return detail::functor2<vec, L, T>::call(max, x, y);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_clamp_vector
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, vec<L, T> const& minVal, vec<L, T> const& maxVal)
		{
			return min(max(x, minVal), maxVal);
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_step_vector
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& edge, vec<L, T> const& x)
		{
			return mix(vec<L, T>(1), vec<L, T>(0), glm::lessThan(x, edge));
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_smoothstep_vector
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& edge0, vec<L, T> const& edge1, vec<L, T> const& x)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_GENTYPE, "'smoothstep' only accept floating-point inputs");
			vec<L, T> const tmp(clamp((x - edge0) / (edge1 - edge0), static_cast<T>(0), static_cast<T>(1)));
			return tmp * tmp * (static_cast<T>(3) - static_cast<T>(2) * tmp);
		}
	};
}//namespace detail

	template<typename genFIType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR genFIType abs(genFIType x)
	{
		return detail::compute_abs<genFIType, std::numeric_limits<genFIType>::is_signed>::call(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> abs(vec<L, T> const& x)
	{
		return detail::compute_abs_vector<L, T, false>::call(x);
	}

	// sign
	// fast and works for any type
	template<typename genFIType>
	GLM_FUNC_QUALIFIER genFIType sign(genFIType x)
	{
		GLM_STATIC_ASSERT(
			std::numeric_limits<genFIType>::is_iec559 || (std::numeric_limits<genFIType>::is_signed && std::numeric_limits<genFIType>::is_integer),
			"'sign' only accept signed inputs");
		return (genFIType(0) < x) - (x < genFIType(0));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> sign(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(
			std::numeric_limits<T>::is_iec559 || (std::numeric_limits<T>::is_signed && std::numeric_limits<T>::is_integer),
			"'sign' only accept signed inputs");

		return detail::compute_sign<L, T, std::numeric_limits<T>::is_iec559, false>::call(x);
	}

	// floor
	//using ::std::floor;
	template<typename genType>
	GLM_FUNC_DECL genType floor(genType x) 
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'floor' only accept floating-point inputs.");
		return ::std::floor(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> floor(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'floor' only accept floating-point inputs.");
		return detail::compute_floor<L, T, false>::call(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> trunc(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'trunc' only accept floating-point inputs");
		return detail::compute_trunc<L, T, false>::call(x);
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType round(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'round' only accept floating-point inputs");
		return ::std::round(x);
	}


	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> round(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'round' only accept floating-point inputs");
		return detail::compute_round<L, T, false>::call(x);
	}

/*
	// roundEven
	template<typename genType>
	GLM_FUNC_QUALIFIER genType roundEven(genType const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'roundEven' only accept floating-point inputs");

		return genType(int(x + genType(int(x) % 2)));
	}
*/

	// roundEven
	template<typename genType>
	GLM_FUNC_QUALIFIER genType roundEven(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'roundEven' only accept floating-point inputs");

		int Integer = static_cast<int>(x);
		genType IntegerPart = static_cast<genType>(Integer);
		genType FractionalPart = fract(x);

		if(FractionalPart > static_cast<genType>(0.5) || FractionalPart < static_cast<genType>(0.5))
		{
			return round(x);
		}
		else if((Integer % 2) == 0)
		{
			return IntegerPart;
		}
		else if(x <= static_cast<genType>(0)) // Work around...
		{
			return IntegerPart - static_cast<genType>(1);
		}
		else
		{
			return IntegerPart + static_cast<genType>(1);
		}
		//else // Bug on MinGW 4.5.2
		//{
		//	return mix(IntegerPart + genType(-1), IntegerPart + genType(1), x <= genType(0));
		//}
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> roundEven(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'roundEven' only accept floating-point inputs");
		return detail::functor1<vec, L, T, T>::call(roundEven, x);
	}

	// ceil
	using ::std::ceil;
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> ceil(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'ceil' only accept floating-point inputs");
		return detail::compute_ceil<L, T, false>::call(x);
	}

	// fract
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fract(genType x)
	{
		return x - floor(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> fract(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'fract' only accept floating-point inputs");
		return detail::compute_fract<L, T, false>::call(x);
	}

	// mod
	template<typename genType>
	GLM_FUNC_QUALIFIER genType mod(genType x, genType y)
	{
#		if GLM_COMPILER & GLM_COMPILER_CUDA
			// Another Cuda compiler bug https://github.com/g-truc/glm/issues/530
			vec<1, genType> Result(mod(vec<1, genType>(x), y));
			return Result.x;
#		else
			return x - y * floor(x / y);
#		endif
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> mod(vec<L, T> const& x, T y)
	{
		return detail::compute_mod<L, T, false>::call(x, vec<L, T>(y));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> mod(vec<L, T> const& x, vec<L, T> const& y)
	{
		return detail::compute_mod<L, T, false>::call(x, y);
	}

	// modf
	template<typename genType>
	GLM_FUNC_QUALIFIER genType modf(genType x, genType & i)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'modf' only accept floating-point inputs");
		return std::modf(x, &i);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T> modf(vec<2, T> const& x, vec<2, T> & i)
	{
		return vec<2, T>(
			modf(x.x, i.x),
			modf(x.y, i.y));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> modf(vec<3, T> const& x, vec<3, T> & i)
	{
		return vec<3, T>(
			modf(x.x, i.x),
			modf(x.y, i.y),
			modf(x.z, i.z));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<4, T> modf(vec<4, T> const& x, vec<4, T> & i)
	{
		return vec<4, T>(
			modf(x.x, i.x),
			modf(x.y, i.y),
			modf(x.z, i.z),
			modf(x.w, i.w));
	}

	//// Only valid if (INT_MIN <= x-y <= INT_MAX)
	//// min(x,y)
	//r = y + ((x - y) & ((x - y) >> (sizeof(int) *
	//CHAR_BIT - 1)));
	//// max(x,y)
	//r = x - ((x - y) & ((x - y) >> (sizeof(int) *
	//CHAR_BIT - 1)));

	// min
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> min(vec<L, T> const& a, T b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "'min' only accept floating-point or integer inputs");
		return detail::compute_min_vector<L, T, false>::call(a, vec<L, T>(b));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> min(vec<L, T> const& a, vec<L, T> const& b)
	{
		return detail::compute_min_vector<L, T, false>::call(a, b);
	}

	// max
	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> max(vec<L, T> const& a, T b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "'max' only accept floating-point or integer inputs");
		return detail::compute_max_vector<L, T, false>::call(a, vec<L, T>(b));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> max(vec<L, T> const& a, vec<L, T> const& b)
	{
		return detail::compute_max_vector<L, T, false>::call(a, b);
	}

	// clamp
	template<typename genType>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR genType clamp(genType x, genType minVal, genType maxVal)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559 || std::numeric_limits<genType>::is_integer, "'clamp' only accept floating-point or integer inputs");
		return min(max(x, minVal), maxVal);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> clamp(vec<L, T> const& x, T minVal, T maxVal)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "'clamp' only accept floating-point or integer inputs");
		return detail::compute_clamp_vector<L, T, false>::call(x, vec<L, T>(minVal), vec<L, T>(maxVal));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T> clamp(vec<L, T> const& x, vec<L, T> const& minVal, vec<L, T> const& maxVal)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "'clamp' only accept floating-point or integer inputs");
		return detail::compute_clamp_vector<L, T, false>::call(x, minVal, maxVal);
	}

	template<typename genTypeT, typename genTypeU>
	GLM_FUNC_QUALIFIER genTypeT mix(genTypeT x, genTypeT y, genTypeU a)
	{
		return detail::compute_mix<genTypeT, genTypeU>::call(x, y, a);
	}

	template<length_t L, typename T, typename U>
	GLM_FUNC_QUALIFIER vec<L, T> mix(vec<L, T> const& x, vec<L, T> const& y, U a)
	{
		return detail::compute_mix_scalar<L, T, U, false>::call(x, y, a);
	}

	template<length_t L, typename T, typename U>
	GLM_FUNC_QUALIFIER vec<L, T> mix(vec<L, T> const& x, vec<L, T> const& y, vec<L, U> const& a)
	{
		return detail::compute_mix_vector<L, T, U, false>::call(x, y, a);
	}

	// step
	template<typename genType>
	GLM_FUNC_QUALIFIER genType step(genType edge, genType x)
	{
		return mix(static_cast<genType>(1), static_cast<genType>(0), x < edge);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> step(T edge, vec<L, T> const& x)
	{
		return detail::compute_step_vector<L, T, false>::call(vec<L, T>(edge), x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> step(vec<L, T> const& edge, vec<L, T> const& x)
	{
		return detail::compute_step_vector<L, T, false>::call(edge, x);
	}

	// smoothstep
	template<typename genType>
	GLM_FUNC_QUALIFIER genType smoothstep(genType edge0, genType edge1, genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_GENTYPE, "'smoothstep' only accept floating-point inputs");

		genType const tmp(clamp((x - edge0) / (edge1 - edge0), genType(0), genType(1)));
		return tmp * tmp * (genType(3) - genType(2) * tmp);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> smoothstep(T edge0, T edge1, vec<L, T> const& x)
	{
		return detail::compute_smoothstep_vector<L, T, false>::call(vec<L, T>(edge0), vec<L, T>(edge1), x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> smoothstep(vec<L, T> const& edge0, vec<L, T> const& edge1, vec<L, T> const& x)
	{
		return detail::compute_smoothstep_vector<L, T, false>::call(edge0, edge1, x);
	}

#	if GLM_HAS_CXX11_STL
		//using std::isnan;
#	else
		template<typename genType>
		GLM_FUNC_QUALIFIER bool isnan(genType x)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'isnan' only accept floating-point inputs");

#			if GLM_HAS_CXX11_STL
				return std::isnan(x);
#			elif GLM_COMPILER & GLM_COMPILER_VC
				return _isnan(x) != 0;
#			elif GLM_COMPILER & GLM_COMPILER_INTEL
#				if GLM_PLATFORM & GLM_PLATFORM_WINDOWS
					return _isnan(x) != 0;
#				else
					return ::isnan(x) != 0;
#				endif
#			elif (GLM_COMPILER & (GLM_COMPILER_GCC | GLM_COMPILER_CLANG)) && (GLM_PLATFORM & GLM_PLATFORM_ANDROID) && __cplusplus < 201103L
				return _isnan(x) != 0;
#			elif GLM_COMPILER & GLM_COMPILER_CUDA
				return ::isnan(x) != 0;
#			else
				return std::isnan(x);
#			endif
		}
#	endif

	template<typename genType>
	GLM_FUNC_QUALIFIER bool isnan(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'isnan' only accept floating-point inputs");
		return std::isnan(x);
	}


	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> isnan(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnan' only accept floating-point inputs");

		vec<L, bool> Result;
		for (length_t l = 0; l < v.length(); ++l)
			Result[l] = glm::isnan(v[l]);
		return Result;
	}

#	if GLM_HAS_CXX11_STL
		//using std::isinf;
#	else
		template<typename genType>
		GLM_FUNC_QUALIFIER bool isinf(genType x)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'isinf' only accept floating-point inputs");

#			if GLM_HAS_CXX11_STL
				return std::isinf(x);
#			elif GLM_COMPILER & (GLM_COMPILER_INTEL | GLM_COMPILER_VC)
#				if(GLM_PLATFORM & GLM_PLATFORM_WINDOWS)
					return _fpclass(x) == _FPCLASS_NINF || _fpclass(x) == _FPCLASS_PINF;
#				else
					return ::isinf(x);
#				endif
#			elif GLM_COMPILER & (GLM_COMPILER_GCC | GLM_COMPILER_CLANG)
#				if(GLM_PLATFORM & GLM_PLATFORM_ANDROID && __cplusplus < 201103L)
					return _isinf(x) != 0;
#				else
					return std::isinf(x);
#				endif
#			elif GLM_COMPILER & GLM_COMPILER_CUDA
				// http://developer.download.nvidia.com/compute/cuda/4_2/rel/toolkit/docs/online/group__CUDA__MATH__DOUBLE_g13431dd2b40b51f9139cbb7f50c18fab.html#g13431dd2b40b51f9139cbb7f50c18fab
				return ::isinf(double(x)) != 0;
#			else
				return std::isinf(x);
#			endif
	}
#	endif

	template<typename genType>
	GLM_FUNC_QUALIFIER bool isinf(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'isinf' only accept floating-point inputs");
		return std::isinf(x);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, bool> isinf(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isinf' only accept floating-point inputs");

		vec<L, bool> Result;
		for (length_t l = 0; l < v.length(); ++l)
			Result[l] = glm::isinf(v[l]);
		return Result;
	}

	GLM_FUNC_QUALIFIER GLM_FUNC_ALWAYS_INLINE int floatBitsToInt(float const& v)
	{
		union
		{
			float in;
			int out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, int> floatBitsToInt(vec<L, float> const& v)
	{
		return reinterpret_cast<vec<L, int>&>(const_cast<vec<L, float>&>(v));
	}

	GLM_FUNC_QUALIFIER GLM_FUNC_ALWAYS_INLINE uint floatBitsToUint(float const& v)
	{
		union
		{
			float in;
			uint out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, uint> floatBitsToUint(vec<L, float> const& v)
	{
		return reinterpret_cast<vec<L, uint>&>(const_cast<vec<L, float>&>(v));
	}

	GLM_FUNC_QUALIFIER GLM_FUNC_ALWAYS_INLINE float intBitsToFloat(int const& v)
	{
		union
		{
			int in;
			float out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, float> intBitsToFloat(vec<L, int> const& v)
	{
		return reinterpret_cast<vec<L, float>&>(const_cast<vec<L, int>&>(v));
	}

	GLM_FUNC_QUALIFIER GLM_FUNC_ALWAYS_INLINE float uintBitsToFloat(uint const& v)
	{
		union
		{
			uint in;
			float out;
		} u;

		u.in = v;

		return u.out;
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, float> uintBitsToFloat(vec<L, uint> const& v)
	{
		return reinterpret_cast<vec<L, float>&>(const_cast<vec<L, uint>&>(v));
	}

#	if GLM_HAS_CXX11_STL
		using std::fma;
#	else
		template<typename genType>
		GLM_FUNC_QUALIFIER genType fma(genType const& a, genType const& b, genType const& c)
		{
			return a * b + c;
		}
#	endif

	template<typename genType>
	GLM_FUNC_QUALIFIER genType frexp(genType x, int& exp)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'frexp' only accept floating-point inputs");

		return std::frexp(x, &exp);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> frexp(vec<L, T> const& v, vec<L, int>& exp)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'frexp' only accept floating-point inputs");

		vec<L, T> Result;
		for (length_t l = 0; l < v.length(); ++l)
			Result[l] = std::frexp(v[l], &exp[l]);
		return Result;
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType ldexp(genType const& x, int const& exp)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'ldexp' only accept floating-point inputs");

		return std::ldexp(x, exp);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> ldexp(vec<L, T> const& v, vec<L, int> const& exp)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'ldexp' only accept floating-point inputs");

		vec<L, T> Result;
		for (length_t l = 0; l < v.length(); ++l)
			Result[l] = std::ldexp(v[l], exp[l]);
		return Result;
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "func_common_simd.inl"
#endif
