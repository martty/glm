/// @ref core

#include "_vectorize.hpp"
#if(GLM_ARCH & GLM_ARCH_X86 && GLM_COMPILER & GLM_COMPILER_VC)
#	include <intrin.h>
#	pragma intrinsic(_BitScanReverse)
#endif//(GLM_ARCH & GLM_ARCH_X86 && GLM_COMPILER & GLM_COMPILER_VC)
#include <limits>

#if !GLM_HAS_EXTENDED_INTEGER_TYPE
#	if GLM_COMPILER & GLM_COMPILER_GCC
#		pragma GCC diagnostic ignored "-Wlong-long"
#	endif
#	if (GLM_COMPILER & GLM_COMPILER_CLANG)
#		pragma clang diagnostic ignored "-Wc++11-long-long"
#	endif
#endif

namespace glm{
namespace detail
{
	template<typename T>
	GLM_FUNC_QUALIFIER T mask(T Bits)
	{
		return Bits >= static_cast<T>(sizeof(T) * 8) ? ~static_cast<T>(0) : (static_cast<T>(1) << Bits) - static_cast<T>(1);
	}

	template<length_t L, typename T, bool Aligned, bool EXEC>
	struct compute_bitfieldReverseStep
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& v, T, T)
		{
			return v;
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_bitfieldReverseStep<L, T, Aligned, true>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& v, T Mask, T Shift)
		{
			return (v & Mask) << Shift | (v & (~Mask)) >> Shift;
		}
	};

	template<length_t L, typename T, bool Aligned, bool EXEC>
	struct compute_bitfieldBitCountStep
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& v, T, T)
		{
			return v;
		}
	};

	template<length_t L, typename T, bool Aligned>
	struct compute_bitfieldBitCountStep<L, T, Aligned, true>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& v, T Mask, T Shift)
		{
			return (v & Mask) + ((v >> Shift) & Mask);
		}
	};

	template<typename genIUType, size_t Bits>
	struct compute_findLSB
	{
		GLM_FUNC_QUALIFIER static int call(genIUType Value)
		{
			if(Value == 0)
				return -1;

			return glm::bitCount(~Value & (Value - static_cast<genIUType>(1)));
		}
	};

#	if GLM_HAS_BITSCAN_WINDOWS
		template<typename genIUType>
		struct compute_findLSB<genIUType, 32>
		{
			GLM_FUNC_QUALIFIER static int call(genIUType Value)
			{
				unsigned long Result(0);
				unsigned char IsNotNull = _BitScanForward(&Result, *reinterpret_cast<unsigned long*>(&Value));
				return IsNotNull ? int(Result) : -1;
			}
		};

#		if !((GLM_COMPILER & GLM_COMPILER_VC) && (GLM_MODEL == GLM_MODEL_32))
		template<typename genIUType>
		struct compute_findLSB<genIUType, 64>
		{
			GLM_FUNC_QUALIFIER static int call(genIUType Value)
			{
				unsigned long Result(0);
				unsigned char IsNotNull = _BitScanForward64(&Result, *reinterpret_cast<unsigned __int64*>(&Value));
				return IsNotNull ? int(Result) : -1;
			}
		};
#		endif
#	endif//GLM_HAS_BITSCAN_WINDOWS

	template<length_t L, typename T, bool EXEC = true>
	struct compute_findMSB_step_vec
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, T Shift)
		{
			return x | (x >> Shift);
		}
	};

	template<length_t L, typename T>
	struct compute_findMSB_step_vec<L, T, false>
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& x, T)
		{
			return x;
		}
	};

	template<length_t L, typename T, int>
	struct compute_findMSB_vec
	{
		GLM_FUNC_QUALIFIER static vec<L, int> call(vec<L, T> const& v)
		{
			vec<L, T> x(v);
			x = compute_findMSB_step_vec<L, T, sizeof(T) * 8 >=  8>::call(x, static_cast<T>( 1));
			x = compute_findMSB_step_vec<L, T, sizeof(T) * 8 >=  8>::call(x, static_cast<T>( 2));
			x = compute_findMSB_step_vec<L, T, sizeof(T) * 8 >=  8>::call(x, static_cast<T>( 4));
			x = compute_findMSB_step_vec<L, T, sizeof(T) * 8 >= 16>::call(x, static_cast<T>( 8));
			x = compute_findMSB_step_vec<L, T, sizeof(T) * 8 >= 32>::call(x, static_cast<T>(16));
			x = compute_findMSB_step_vec<L, T, sizeof(T) * 8 >= 64>::call(x, static_cast<T>(32));
			return vec<L, int>(sizeof(T) * 8 - 1) - glm::bitCount(~x);
		}
	};

#	if GLM_HAS_BITSCAN_WINDOWS
		template<typename genIUType>
		GLM_FUNC_QUALIFIER int compute_findMSB_32(genIUType Value)
		{
			unsigned long Result(0);
			unsigned char IsNotNull = _BitScanReverse(&Result, *reinterpret_cast<unsigned long*>(&Value));
			return IsNotNull ? int(Result) : -1;
		}

		template<length_t L, typename T>
		struct compute_findMSB_vec<L, T, 32>
		{
			GLM_FUNC_QUALIFIER static vec<L, int> call(vec<L, T> const& x)
			{
				return detail::functor1<vec, L, int, T>::call(compute_findMSB_32, x);
			}
		};

#		if !((GLM_COMPILER & GLM_COMPILER_VC) && (GLM_MODEL == GLM_MODEL_32))
		template<typename genIUType>
		GLM_FUNC_QUALIFIER int compute_findMSB_64(genIUType Value)
		{
			unsigned long Result(0);
			unsigned char IsNotNull = _BitScanReverse64(&Result, *reinterpret_cast<unsigned __int64*>(&Value));
			return IsNotNull ? int(Result) : -1;
		}

		template<length_t L, typename T>
		struct compute_findMSB_vec<L, T, 64>
		{
			GLM_FUNC_QUALIFIER static vec<L, int> call(vec<L, T> const& x)
			{
				return detail::functor1<vec, L, int, T>::call(compute_findMSB_64, x);
			}
		};
#		endif
#	endif//GLM_HAS_BITSCAN_WINDOWS
}//namespace detail

	// uaddCarry
	GLM_FUNC_QUALIFIER uint uaddCarry(uint const& x, uint const& y, uint & Carry)
	{
		detail::uint64 const Value64(static_cast<detail::uint64>(x) + static_cast<detail::uint64>(y));
		detail::uint64 const Max32((static_cast<detail::uint64>(1) << static_cast<detail::uint64>(32)) - static_cast<detail::uint64>(1));
		Carry = Value64 > Max32 ? 1u : 0u;
		return static_cast<uint>(Value64 % (Max32 + static_cast<detail::uint64>(1)));
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, uint> uaddCarry(vec<L, uint> const& x, vec<L, uint> const& y, vec<L, uint>& Carry)
	{
		vec<L, detail::uint64> Value64(vec<L, detail::uint64>(x) + vec<L, detail::uint64>(y));
		vec<L, detail::uint64> Max32((static_cast<detail::uint64>(1) << static_cast<detail::uint64>(32)) - static_cast<detail::uint64>(1));
		Carry = mix(vec<L, uint>(0), vec<L, uint>(1), greaterThan(Value64, Max32));
		return vec<L, uint>(Value64 % (Max32 + static_cast<detail::uint64>(1)));
	}

	// usubBorrow
	GLM_FUNC_QUALIFIER uint usubBorrow(uint const& x, uint const& y, uint & Borrow)
	{
		Borrow = x >= y ? static_cast<uint>(0) : static_cast<uint>(1);
		if(y >= x)
			return y - x;
		else
			return static_cast<uint>((static_cast<detail::int64>(1) << static_cast<detail::int64>(32)) + (static_cast<detail::int64>(y) - static_cast<detail::int64>(x)));
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER vec<L, uint> usubBorrow(vec<L, uint> const& x, vec<L, uint> const& y, vec<L, uint>& Borrow)
	{
		Borrow = mix(vec<L, uint>(1), vec<L, uint>(0), greaterThanEqual(x, y));
		vec<L, uint> const YgeX(y - x);
		vec<L, uint> const XgeY(vec<L, uint>((static_cast<detail::int64>(1) << static_cast<detail::int64>(32)) + (vec<L, detail::int64>(y) - vec<L, detail::int64>(x))));
		return mix(XgeY, YgeX, greaterThanEqual(y, x));
	}

	// umulExtended
	GLM_FUNC_QUALIFIER void umulExtended(uint const& x, uint const& y, uint & msb, uint & lsb)
	{
		detail::uint64 Value64 = static_cast<detail::uint64>(x) * static_cast<detail::uint64>(y);
		msb = static_cast<uint>(Value64 >> static_cast<detail::uint64>(32));
		lsb = static_cast<uint>(Value64);
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER void umulExtended(vec<L, uint> const& x, vec<L, uint> const& y, vec<L, uint>& msb, vec<L, uint>& lsb)
	{
		vec<L, detail::uint64> Value64(vec<L, detail::uint64>(x) * vec<L, detail::uint64>(y));
		msb = vec<L, uint>(Value64 >> static_cast<detail::uint64>(32));
		lsb = vec<L, uint>(Value64);
	}

	// imulExtended
	GLM_FUNC_QUALIFIER void imulExtended(int x, int y, int& msb, int& lsb)
	{
		detail::int64 Value64 = static_cast<detail::int64>(x) * static_cast<detail::int64>(y);
		msb = static_cast<int>(Value64 >> static_cast<detail::int64>(32));
		lsb = static_cast<int>(Value64);
	}

	template<length_t L>
	GLM_FUNC_QUALIFIER void imulExtended(vec<L, int> const& x, vec<L, int> const& y, vec<L, int>& msb, vec<L, int>& lsb)
	{
		vec<L, detail::int64> Value64(vec<L, detail::int64>(x) * vec<L, detail::int64>(y));
		lsb = vec<L, int>(Value64 & static_cast<detail::int64>(0xFFFFFFFF));
		msb = vec<L, int>((Value64 >> static_cast<detail::int64>(32)) & static_cast<detail::int64>(0xFFFFFFFF));
	}

	// bitfieldExtract
	template<typename genIUType>
	GLM_FUNC_QUALIFIER genIUType bitfieldExtract(genIUType Value, int Offset, int Bits)
	{
		return (Value >> static_cast<genIUType>(Offset)) & static_cast<genIUType>(detail::mask(Bits));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> bitfieldExtract(vec<L, T> const& Value, int Offset, int Bits)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldExtract' only accept integer inputs");

		return (Value >> static_cast<T>(Offset)) & static_cast<T>(detail::mask(Bits));
	}

	// bitfieldInsert
	template<typename genIUType>
	GLM_FUNC_QUALIFIER genIUType bitfieldInsert(genIUType const& Base, genIUType const& Insert, int Offset, int Bits)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'bitfieldInsert' only accept integer values");
		
		genIUType const Mask = static_cast<genIUType>(detail::mask(Bits) << Offset);
		return (Base & ~Mask) | ((Insert << static_cast<genIUType>(Offset)) & Mask);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> bitfieldInsert(vec<L, T> const& Base, vec<L, T> const& Insert, int Offset, int Bits)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldInsert' only accept integer values");

		T const Mask = static_cast<T>(detail::mask(Bits) << Offset);
		return (Base & ~Mask) | ((Insert << static_cast<T>(Offset)) & Mask);
	}

	// bitfieldReverse
	template<typename genIUType>
	GLM_FUNC_QUALIFIER genIUType bitfieldReverse(genIUType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'bitfieldReverse' only accept integer values");

		return bitfieldReverse(glm::vec<1, genIUType>(x)).x;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> bitfieldReverse(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldReverse' only accept integer values");

		vec<L, T> x(v);
		x = detail::compute_bitfieldReverseStep<L, T, false, sizeof(T) * 8>=  2>::call(x, static_cast<T>(0x5555555555555555ull), static_cast<T>( 1));
		x = detail::compute_bitfieldReverseStep<L, T, false, sizeof(T) * 8>=  4>::call(x, static_cast<T>(0x3333333333333333ull), static_cast<T>( 2));
		x = detail::compute_bitfieldReverseStep<L, T, false, sizeof(T) * 8>=  8>::call(x, static_cast<T>(0x0F0F0F0F0F0F0F0Full), static_cast<T>( 4));
		x = detail::compute_bitfieldReverseStep<L, T, false, sizeof(T) * 8>= 16>::call(x, static_cast<T>(0x00FF00FF00FF00FFull), static_cast<T>( 8));
		x = detail::compute_bitfieldReverseStep<L, T, false, sizeof(T) * 8>= 32>::call(x, static_cast<T>(0x0000FFFF0000FFFFull), static_cast<T>(16));
		x = detail::compute_bitfieldReverseStep<L, T, false, sizeof(T) * 8>= 64>::call(x, static_cast<T>(0x00000000FFFFFFFFull), static_cast<T>(32));
		return x;
	}

	// bitCount
	template<typename genIUType>
	GLM_FUNC_QUALIFIER int bitCount(genIUType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'bitCount' only accept integer values");

		return bitCount(glm::vec<1, genIUType>(x)).x;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, int> bitCount(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitCount' only accept integer values");

#		if GLM_COMPILER & GLM_COMPILER_VC
#			pragma warning(push)
#			pragma warning(disable : 4310) //cast truncates constant value
#		endif

		vec<L, typename detail::make_unsigned<T>::type> x(*reinterpret_cast<vec<L, typename detail::make_unsigned<T>::type> const *>(&v));
		x = detail::compute_bitfieldBitCountStep<L, typename detail::make_unsigned<T>::type, false, sizeof(T) * 8>=  2>::call(x, typename detail::make_unsigned<T>::type(0x5555555555555555ull), typename detail::make_unsigned<T>::type( 1));
		x = detail::compute_bitfieldBitCountStep<L, typename detail::make_unsigned<T>::type, false, sizeof(T) * 8>=  4>::call(x, typename detail::make_unsigned<T>::type(0x3333333333333333ull), typename detail::make_unsigned<T>::type( 2));
		x = detail::compute_bitfieldBitCountStep<L, typename detail::make_unsigned<T>::type, false, sizeof(T) * 8>=  8>::call(x, typename detail::make_unsigned<T>::type(0x0F0F0F0F0F0F0F0Full), typename detail::make_unsigned<T>::type( 4));
		x = detail::compute_bitfieldBitCountStep<L, typename detail::make_unsigned<T>::type, false, sizeof(T) * 8>= 16>::call(x, typename detail::make_unsigned<T>::type(0x00FF00FF00FF00FFull), typename detail::make_unsigned<T>::type( 8));
		x = detail::compute_bitfieldBitCountStep<L, typename detail::make_unsigned<T>::type, false, sizeof(T) * 8>= 32>::call(x, typename detail::make_unsigned<T>::type(0x0000FFFF0000FFFFull), typename detail::make_unsigned<T>::type(16));
		x = detail::compute_bitfieldBitCountStep<L, typename detail::make_unsigned<T>::type, false, sizeof(T) * 8>= 64>::call(x, typename detail::make_unsigned<T>::type(0x00000000FFFFFFFFull), typename detail::make_unsigned<T>::type(32));
		return vec<L, int>(x);

#		if GLM_COMPILER & GLM_COMPILER_VC
#			pragma warning(pop)
#		endif
	}

	// findLSB
	template<typename genIUType>
	GLM_FUNC_QUALIFIER int findLSB(genIUType Value)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findLSB' only accept integer values");

		return detail::compute_findLSB<genIUType, sizeof(genIUType) * 8>::call(Value);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, int> findLSB(vec<L, T> const& x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'findLSB' only accept integer values");

		return detail::functor1<vec, L, int, T>::call(findLSB, x);
	}

	// findMSB
	template<typename genIUType>
	GLM_FUNC_QUALIFIER int findMSB(genIUType v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findMSB' only accept integer values");

		return findMSB(vec<1, genIUType>(v)).x;
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, int> findMSB(vec<L, T> const& v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'findMSB' only accept integer values");

		return detail::compute_findMSB_vec<L, T, sizeof(T) * 8>::call(v);
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "func_integer_simd.inl"
#endif

