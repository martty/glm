/// @ref gtc_color_space

namespace glm{
namespace detail
{
	template<length_t L, typename T>
	struct compute_rgbToSrgb
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& ColorRGB, T GammaCorrection)
		{
			vec<L, T> const ClampedColor(clamp(ColorRGB, static_cast<T>(0), static_cast<T>(1)));

			return mix(
				pow(ClampedColor, vec<L, T>(GammaCorrection)) * static_cast<T>(1.055) - static_cast<T>(0.055),
				ClampedColor * static_cast<T>(12.92),
				lessThan(ClampedColor, vec<L, T>(static_cast<T>(0.0031308))));
		}
	};

	template<typename T>
	struct compute_rgbToSrgb<4, T>
	{
		GLM_FUNC_QUALIFIER static vec<4, T> call(vec<4, T> const& ColorRGB, T GammaCorrection)
		{
			return vec<4, T>(compute_rgbToSrgb<3, T>::call(vec<3, T>(ColorRGB), GammaCorrection), ColorRGB.w);
		}
	};

	template<length_t L, typename T>
	struct compute_srgbToRgb
	{
		GLM_FUNC_QUALIFIER static vec<L, T> call(vec<L, T> const& ColorSRGB, T Gamma)
		{
			return mix(
				pow((ColorSRGB + static_cast<T>(0.055)) * static_cast<T>(0.94786729857819905213270142180095), vec<L, T>(Gamma)),
				ColorSRGB * static_cast<T>(0.07739938080495356037151702786378),
				lessThanEqual(ColorSRGB, vec<L, T>(static_cast<T>(0.04045))));
		}
	};

	template<typename T>
	struct compute_srgbToRgb<4, T>
	{
		GLM_FUNC_QUALIFIER static vec<4, T> call(vec<4, T> const& ColorSRGB, T Gamma)
		{
			return vec<4, T>(compute_srgbToRgb<3, T>::call(vec<3, T>(ColorSRGB), Gamma), ColorSRGB.w);
		}
	};
}//namespace detail

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> convertLinearToSRGB(vec<L, T> const& ColorLinear)
	{
		return detail::compute_rgbToSrgb<L, T>::call(ColorLinear, static_cast<T>(0.41666));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> convertLinearToSRGB(vec<L, T> const& ColorLinear, T Gamma)
	{
		return detail::compute_rgbToSrgb<L, T>::call(ColorLinear, static_cast<T>(1) / Gamma);
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> convertSRGBToLinear(vec<L, T> const& ColorSRGB)
	{
		return detail::compute_srgbToRgb<L, T>::call(ColorSRGB, static_cast<T>(2.4));
	}

	template<length_t L, typename T>
	GLM_FUNC_QUALIFIER vec<L, T> convertSRGBToLinear(vec<L, T> const& ColorSRGB, T Gamma)
	{
		return detail::compute_srgbToRgb<L, T>::call(ColorSRGB, Gamma);
	}
}//namespace glm
