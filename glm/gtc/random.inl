#include "../geometric.hpp"
#include "../exponential.hpp"
#include "../trigonometric.hpp"
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

namespace glm{
namespace detail
{
	template <length_t L, typename T>
	struct compute_rand
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call();
	};

	template<>
	struct compute_rand<1, uint8>
	{
		GLM_FUNC_QUALIFIER static uint8 call()
		{
			return std::rand() % std::numeric_limits<uint8>::max();
		}
	};
	
	template<>
	struct compute_rand<2, uint8>
	{
		GLM_FUNC_QUALIFIER static vec<2, uint8> call()
		{
			return vec<2, uint8>(
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max());
		}
	};

	template<>
	struct compute_rand<3, uint8>
	{
		GLM_FUNC_QUALIFIER static vec<3, uint8> call()
		{
			return vec<3, uint8>(
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max());
		}
	};

	template<>
	struct compute_rand<4, uint8>
	{
		GLM_FUNC_QUALIFIER static vec<4, uint8> call()
		{
			return vec<4, uint8>(
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max());
		}
	};

	template <length_t L>
	struct compute_rand<L, uint16>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint16> call()
		{
			return
				(vec<L, uint16>(compute_rand<L, uint8>::call()) << static_cast<uint16>(8)) |
				(vec<L, uint16>(compute_rand<L, uint8>::call()) << static_cast<uint16>(0));
		}
	};

	template <length_t L>
	struct compute_rand<L, uint32>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint32> call()
		{
			return
				(vec<L, uint32>(compute_rand<L, uint16>::call()) << static_cast<uint32>(16)) |
				(vec<L, uint32>(compute_rand<L, uint16>::call()) << static_cast<uint32>(0));
		}
	};

	template <length_t L>
	struct compute_rand<L, uint64>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint64> call()
		{
			return
				(vec<L, uint64>(compute_rand<L, uint32>::call()) << static_cast<uint64>(32)) |
				(vec<L, uint64>(compute_rand<L, uint32>::call()) << static_cast<uint64>(0));
		}
	};

	template <length_t L, typename T>
	struct compute_linearRand
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& Min, vec<L, T> const& Max);
	};

	template<length_t L>
	struct compute_linearRand<L, int8>
	{
		GLM_FUNC_QUALIFIER static vec<L, int8> call(vec<L, int8> const& Min, vec<L, int8> const& Max)
		{
			return (vec<L, int8>(compute_rand<L, uint8>::call() % vec<L, uint8>(Max + static_cast<int8>(1) - Min))) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, uint8>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint8> call(vec<L, uint8> const& Min, vec<L, uint8> const& Max)
		{
			return (compute_rand<L, uint8>::call() % (Max + static_cast<uint8>(1) - Min)) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, int16>
	{
		GLM_FUNC_QUALIFIER static vec<L, int16> call(vec<L, int16> const& Min, vec<L, int16> const& Max)
		{
			return (vec<L, int16>(compute_rand<L, uint16>::call() % vec<L, uint16>(Max + static_cast<int16>(1) - Min))) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, uint16>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint16> call(vec<L, uint16> const& Min, vec<L, uint16> const& Max)
		{
			return (compute_rand<L, uint16>::call() % (Max + static_cast<uint16>(1) - Min)) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, int32>
	{
		GLM_FUNC_QUALIFIER static vec<L, int32> call(vec<L, int32> const& Min, vec<L, int32> const& Max)
		{
			return (vec<L, int32>(compute_rand<L, uint32>::call() % vec<L, uint32>(Max + static_cast<int32>(1) - Min))) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, uint32>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint32> call(vec<L, uint32> const& Min, vec<L, uint32> const& Max)
		{
			return (compute_rand<L, uint32>::call() % (Max + static_cast<uint32>(1) - Min)) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, int64>
	{
		GLM_FUNC_QUALIFIER static vec<L, int64> call(vec<L, int64> const& Min, vec<L, int64> const& Max)
		{
			return (vec<L, int64>(compute_rand<L, uint64>::call() % vec<L, uint64>(Max + static_cast<int64>(1) - Min))) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, uint64>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint64> call(vec<L, uint64> const& Min, vec<L, uint64> const& Max)
		{
			return (compute_rand<L, uint64>::call() % (Max + static_cast<uint64>(1) - Min)) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, float>
	{
		GLM_FUNC_QUALIFIER static vec<L, float> call(vec<L, float> const& Min, vec<L, float> const& Max)
		{
			return vec<L, float>(compute_rand<L, uint32>::call()) / static_cast<float>(std::numeric_limits<uint32>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, double>
	{
		GLM_FUNC_QUALIFIER static vec<L, double> call(vec<L, double> const& Min, vec<L, double> const& Max)
		{
			return vec<L, double>(compute_rand<L, uint64>::call()) / static_cast<double>(std::numeric_limits<uint64>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, long double>
	{
		GLM_FUNC_QUALIFIER static vec<L, long double> call(vec<L, long double> const& Min, vec<L, long double> const& Max)
		{
			return vec<L, long double>(compute_rand<L, uint64>::call()) / static_cast<long double>(std::numeric_limits<uint64>::max()) * (Max - Min) + Min;
		}
	};
}//namespace detail

	template<typename T>
	GLM_FUNC_QUALIFIER T linearRand(T Min, T Max)
	{
		// TODO: fix
		(void)Max;
		return Min;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> linearRand(vec<L, T> const& Min, vec<L, T> const& Max)
	{
		return detail::compute_linearRand<L, T>::call(Min, Max);
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType gaussRand(genType Mean, genType Deviation)
	{
		genType w, x1, x2;

		do
		{
			x1 = linearRand(genType(-1), genType(1));
			x2 = linearRand(genType(-1), genType(1));

			w = x1 * x1 + x2 * x2;
		} while(w > genType(1));

		return static_cast<genType>(x2 * Deviation * Deviation * sqrt((genType(-2) * log(w)) / w) + Mean);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> gaussRand(vec<L, T> const& Mean, vec<L, T> const& Deviation)
	{
		return detail::functor2<vec, L, T>::call(gaussRand, Mean, Deviation);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T> diskRand(T Radius)
	{
		assert(Radius > static_cast<T>(0));

		vec<2, T> Result(T(0));
		T LenRadius(T(0));

		do
		{
			Result = linearRand(
				vec<2, T>(-Radius),
				vec<2, T>(Radius));
			LenRadius = length(Result);
		}
		while(LenRadius > Radius);

		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> ballRand(T Radius)
	{
		assert(Radius > static_cast<T>(0));

		vec<3, T> Result(T(0));
		T LenRadius(T(0));

		do
		{
			Result = linearRand(
				vec<3, T>(-Radius),
				vec<3, T>(Radius));
			LenRadius = length(Result);
		}
		while(LenRadius > Radius);

		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T> circularRand(T Radius)
	{
		assert(Radius > static_cast<T>(0));

		T a = linearRand(T(0), static_cast<T>(6.283185307179586476925286766559));
		return vec<2, T>(glm::cos(a), glm::sin(a)) * Radius;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> sphericalRand(T Radius)
	{
		assert(Radius > static_cast<T>(0));

		T theta = linearRand(T(0), T(6.283185307179586476925286766559f));
		T phi = std::acos(linearRand(T(-1.0f), T(1.0f)));

		T x = std::sin(phi) * std::cos(theta);
		T y = std::sin(phi) * std::sin(theta);
		T z = std::cos(phi);

		return vec<3, T>(x, y, z) * Radius;
	}
}//namespace glm
