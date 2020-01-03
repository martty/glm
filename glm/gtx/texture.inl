/// @ref gtx_texture

namespace glm
{
	template <length_t L, typename T>
	inline T levels(vec<L, T> const& Extent)
	{
		return glm::log2(compMax(Extent)) + static_cast<T>(1);
	}

	template <typename T>
	inline T levels(T Extent)
	{
		return vec<1, T>(Extent).x;
	}
}//namespace glm

