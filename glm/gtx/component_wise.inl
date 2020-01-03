/// @ref gtx_component_wise

#include <limits>
#include "../detail/setup.hpp"

namespace glm{
namespace detail
{
	template<length_t L, typename T, typename floatType, bool isInteger, bool signedType>
	struct compute_compNormalize
	{};

	template<length_t L, typename T, typename floatType>
	struct compute_compNormalize<L, T, floatType, true, true>
	{
		GLM_FUNC_QUALIFIER static vec<L, floatType> call(vec<L, T> const& v)
		{
			floatType const Min = static_cast<floatType>(std::numeric_limits<T>::min());
			floatType const Max = static_cast<floatType>(std::numeric_limits<T>::max());
			return (vec<L, floatType>(v) - Min) / (Max - Min) * static_cast<floatType>(2) - static_cast<floatType>(1);
		}
	};

	template<length_t L, typename T, typename floatType>
	struct compute_compNormalize<L, T, floatType, true, false>
	{
		GLM_FUNC_QUALIFIER static vec<L, floatType> call(vec<L, T> const& v)
		{
			return vec<L, floatType>(v) / static_cast<floatType>(std::numeric_limits<T>::max());
		}
	};

	template<length_t L, typename T, typename floatType>
	struct compute_compNormalize<L, T, floatType, false, true>
	{
		GLM_FUNC_QUALIFIER static vec<L, floatType> call(vec<L, T> const& v)
		{
			return v;
		}
	};

	template<length_t L, typename T, typename floatType, bool isInteger, bool signedType>
	struct compute_compScale
	{};

	template<length_t L, typename T, typename floatType>
	struct compute_compScale<L, T, floatType, true, true>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, floatType> const& v)
		{
			floatType const Max = static_cast<floatType>(std::numeric_limits<T>::max()) + static_cast<floatType>(0.5);
			vec<L, floatType> const Scaled(v * Max);
			vec<L, T> const Result(Scaled - static_cast<floatType>(0.5));
			return Result;
		}
	};

	template<length_t L, typename T, typename floatType>
	struct compute_compScale<L, T, floatType, true, false>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, floatType> const& v)
		{
			return vec<L, T>(vec<L, floatType>(v) * static_cast<floatType>(std::numeric_limits<T>::max()));
		}
	};

	template<length_t L, typename T, typename floatType>
	struct compute_compScale<L, T, floatType, false, true>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, floatType> const& v)
		{
			return v;
		}
	};
}//namespace detail

	template<typename floatType, length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, floatType> compNormalize(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<floatType>::is_iec559, "'compNormalize' accepts only floating-point types for 'floatType' template parameter");

		return detail::compute_compNormalize<L, T, floatType, std::numeric_limits<T>::is_integer, std::numeric_limits<T>::is_signed>::call(v);
	}

	template<typename T, length_t L, typename floatType>
	GLM_FUNC_QUALIFIER vec<L, T> compScale(vec<L, floatType> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<floatType>::is_iec559, "'compScale' accepts only floating-point types for 'floatType' template parameter");

		return detail::compute_compScale<L, T, floatType, std::numeric_limits<T>::is_integer, std::numeric_limits<T>::is_signed>::call(v);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER T compAdd(vec<L, T> const& v)
	{
		T Result(0);
		for(length_t i = 0, n = v.length(); i < n; ++i)
			Result += v[i];
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER T compMul(vec<L, T> const& v)
	{
		T Result(1);
		for(length_t i = 0, n = v.length(); i < n; ++i)
			Result *= v[i];
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER T compMin(vec<L, T> const& v)
	{
		T Result(v[0]);
		for(length_t i = 1, n = v.length(); i < n; ++i)
			Result = min(Result, v[i]);
		return Result;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER T compMax(vec<L, T> const& v)
	{
		T Result(v[0]);
		for(length_t i = 1, n = v.length(); i < n; ++i)
			Result = max(Result, v[i]);
		return Result;
	}
}//namespace glm
