/// @ref gtx_polar_coordinates

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> polar
	(
		vec<3, T> const& euclidean
	)
	{
		T const Length(length(euclidean));
		vec<3, T> const tmp(euclidean / Length);
		T const xz_dist(sqrt(tmp.x * tmp.x + tmp.z * tmp.z));

		return vec<3, T>(
			asin(tmp.y),	// latitude
			atan(tmp.x, tmp.z),		// longitude
			xz_dist);				// xz distance
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T> euclidean
	(
		vec<2, T> const& polar
	)
	{
		T const latitude(polar.x);
		T const longitude(polar.y);

		return vec<3, T>(
			cos(latitude) * sin(longitude),
			sin(latitude),
			cos(latitude) * cos(longitude));
	}

}//namespace glm
