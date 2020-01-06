/// @ref gtc_integer

namespace glm{
namespace detail
{
	template<length_t L, typename T, bool isFloat, bool Aligned>
	struct compute_log2;

	template<length_t L, typename T, bool Aligned>
	struct compute_log2<L, T, false, Aligned>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& v)
		{
			//Equivalent to return findMSB(vec); but save one function call in ASM with VC
			//return findMSB(vec);
			return vec<L, T>(detail::compute_findMSB_vec<L, T, sizeof(T) * 8>::call(v));
		}
	};

#	if GLM_HAS_BITSCAN_WINDOWS
		template<qualifier Q, bool Aligned>
		struct compute_log2<4, int, false, Aligned>
		{
			GLM_FUNC_QUALIFIER static vec<4, int> call(vec<4, int> const& v)
			{
				vec<4, int> Result;
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result.x), v.x);
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result.y), v.y);
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result.z), v.z);
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result.w), v.w);
				return Result;
			}
		};
#	endif//GLM_HAS_BITSCAN_WINDOWS
}//namespace detail
	template<typename genType>
	GLM_FUNC_QUALIFIER int iround(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'iround' only accept floating-point inputs");
		assert(static_cast<genType>(0.0) <= x);

		return static_cast<int>(x + static_cast<genType>(0.5));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, int> iround(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'iround' only accept floating-point inputs");
		assert(all(lessThanEqual(vec<L, T>(0), x)));

		return vec<L, int>(x + static_cast<T>(0.5));
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER uint uround(genType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'uround' only accept floating-point inputs");
		assert(static_cast<genType>(0.0) <= x);

		return static_cast<uint>(x + static_cast<genType>(0.5));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, uint> uround(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'uround' only accept floating-point inputs");
		assert(all(lessThanEqual(vec<L, T>(0), x)));

		return vec<L, uint>(x + static_cast<T>(0.5));
	}
}//namespace glm
