/// @ref gtx_color_space_YCoCg

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> rgb2YCoCg
	(
		vec<3, T> const& rgbColor
	)
	{
		vec<3, T> result;
		result.x/*Y */ =   rgbColor.r / T(4) + rgbColor.g / T(2) + rgbColor.b / T(4);
		result.y/*Co*/ =   rgbColor.r / T(2) + rgbColor.g * T(0) - rgbColor.b / T(2);
		result.z/*Cg*/ = - rgbColor.r / T(4) + rgbColor.g / T(2) - rgbColor.b / T(4);
		return result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> YCoCg2rgb
	(
		vec<3, T> const& YCoCgColor
	)
	{
		vec<3, T> result;
		result.r = YCoCgColor.x + YCoCgColor.y - YCoCgColor.z;
		result.g = YCoCgColor.x				   + YCoCgColor.z;
		result.b = YCoCgColor.x - YCoCgColor.y - YCoCgColor.z;
		return result;
	}

	template<typename T, bool isInteger>
	class compute_YCoCgR {
	public:
		static GLM_FUNC_QUALIFIER vec<3, T> rgb2YCoCgR
		(
			vec<3, T> const& rgbColor
		)
		{
			vec<3, T> result;
			result.x/*Y */ = rgbColor.g * static_cast<T>(0.5) + (rgbColor.r + rgbColor.b) * static_cast<T>(0.25);
			result.y/*Co*/ = rgbColor.r - rgbColor.b;
			result.z/*Cg*/ = rgbColor.g - (rgbColor.r + rgbColor.b) * static_cast<T>(0.5);
			return result;
		}

		static GLM_FUNC_QUALIFIER vec<3, T> YCoCgR2rgb
		(
			vec<3, T> const& YCoCgRColor
		)
		{
			vec<3, T> result;
			T tmp = YCoCgRColor.x - (YCoCgRColor.z * static_cast<T>(0.5));
			result.g = YCoCgRColor.z + tmp;
			result.b = tmp - (YCoCgRColor.y * static_cast<T>(0.5));
			result.r = result.b + YCoCgRColor.y;
			return result;
		}
	};

	template<typename T>
	class compute_YCoCgR<T, true> {
	public:
		static GLM_FUNC_QUALIFIER vec<3, T> rgb2YCoCgR
		(
			vec<3, T> const& rgbColor
		)
		{
			vec<3, T> result;
			result.y/*Co*/ = rgbColor.r - rgbColor.b;
			T tmp = rgbColor.b + (result.y >> 1);
			result.z/*Cg*/ = rgbColor.g - tmp;
			result.x/*Y */ = tmp + (result.z >> 1);
			return result;
		}

		static GLM_FUNC_QUALIFIER vec<3, T> YCoCgR2rgb
		(
			vec<3, T> const& YCoCgRColor
		)
		{
			vec<3, T> result;
			T tmp = YCoCgRColor.x - (YCoCgRColor.z >> 1);
			result.g = YCoCgRColor.z + tmp;
			result.b = tmp - (YCoCgRColor.y >> 1);
			result.r = result.b + YCoCgRColor.y;
			return result;
		}
	};

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> rgb2YCoCgR
	(
		vec<3, T> const& rgbColor
	)
	{
		return compute_YCoCgR<T, std::numeric_limits<T>::is_integer>::rgb2YCoCgR(rgbColor);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> YCoCgR2rgb
	(
		vec<3, T> const& YCoCgRColor
	)
	{
		return compute_YCoCgR<T, std::numeric_limits<T>::is_integer>::YCoCgR2rgb(YCoCgRColor);
	}
}//namespace glm
