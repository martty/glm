#define GLM_IMPL

#include "detail/setup.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "mat3x3.hpp"
#include "mat4x4.hpp"

#define LIST_OF_TYPES \
	X(glm::vec2)  \
	X(glm::ivec2) \
	X(glm::uvec2) \
	X(glm::vec3)  \
	X(glm::ivec3) \
    X(glm::uvec3) \
    X(glm::vec4)  \
    X(glm::ivec4) \
    X(glm::uvec4) \
    X(glm::mat3)  \
    X(glm::mat4)

#define VEC        \
    X(2, double)   \
    X(2, float)    \
    X(2, int)      \
    X(2, unsigned) \
    X(3, double)   \
    X(3, float)    \
    X(3, int)      \
    X(3, unsigned) \
    X(4, double)   \
    X(4, float)    \
    X(4, int)      \
    X(4, unsigned) 

#define VEC_FLOAT  \
    X(2, double)   \
    X(2, float)    \
    X(3, double)   \
    X(3, float)    \
    X(4, double)   \
    X(4, float)    


#include "detail/func_vector_relational.inl"
namespace glm {
#define X(len, type) \
    template vec<len, bool> lessThan(vec<len, type>const &, vec<len, type>const &); \
    template vec<len, bool> lessThanEqual(vec<len, type>const &, vec<len, type>const &); \
    template vec<len, bool> greaterThan(vec<len, type>const &, vec<len, type>const &); \
    template vec<len, bool> greaterThanEqual(vec<len, type>const &, vec<len, type>const &); \
    template vec<len, bool> equal(vec<len, type>const &, vec<len, type>const &); \
    template vec<len, bool> notEqual(vec<len, type>const &, vec<len, type>const &); \
    template bool any(vec<len, bool>const &); \
    template bool all(vec<len, bool>const &); \
    template vec<len, bool> not_(vec<len, bool>const &);
	VEC
#undef X
}
#include "detail/func_geometric.inl"
namespace glm {
#define X(len, type) \
    template type length(vec<len, type>const&); \
    template type distance(vec<len, type>const&, vec<len, type>const&); \
    template vec<3, type> cross(vec<3, type>const&, vec<3, type>const&); \
    template vec<len, type> normalize(vec<len, type>const&); \
    template vec<len, type> faceforward(vec<len, type>const&, vec<len, type>const&, vec<len, type>const&); \
    template vec<len, type> reflect(vec<len, type>const&, vec<len, type>const&); \
    template vec<len, type> refract(vec<len, type>const&, vec<len, type>const&, type);
	VEC_FLOAT
#undef X
}

#include "detail/func_common.inl"
namespace glm {
#define X(len, type) \
template type abs(type x);	\
template vec<len, type> abs(vec<len, type> const& x);	\
template type min(type x, type y);	\
template vec<len, type> min(vec<len, type> const& x, type y);	\
template vec<len, type> min(vec<len, type> const& x, vec<len, type> const& y);	\
template type max(type x, type y);	\
template vec<len, type> max(vec<len, type> const& x, type y);	\
template vec<len, type> max(vec<len, type> const& x, vec<len, type> const& y);	\
template type clamp(type x, type minVal, type maxVal);	\
template vec<len, type> clamp(vec<len, type> const& x, type minVal, type maxVal);	\
template vec<len, type> clamp(vec<len, type> const& x, vec<len, type> const& minVal, vec<len, type> const& maxVal);	\
template type step(type edge, type x);	\
template vec<len, type> step(type edge, vec<len, type> const& x);	\
template vec<len, type> step(vec<len, type> const& edge, vec<len, type> const& x);	\
template vec<len, int> floatBitsToInt(vec<len, float> const& v);	\
template vec<len, uint> floatBitsToUint(vec<len, float> const& v);	\
template vec<len, float> intBitsToFloat(vec<len , int> const& v);	\
template vec<len, float> uintBitsToFloat(vec<len, uint> const& v);	\
template type fma(type const& a, type const& b, type const& c);
    VEC
#undef X
#define X(len, type) \
template vec<len, type> sign(vec<len, type> const& x);	\
template vec<len, type> floor(vec<len, type> const& x);	\
template vec<len, type> trunc(vec<len, type> const& x);	\
template vec<len, type> round(vec<len, type> const& x);	\
template type roundEven(type x);	\
template vec<len, type> roundEven(vec<len, type> const& x);	\
template vec<len, type> ceil(vec<len, type> const& x);	\
template type fract(type x);	\
template vec<len, type> fract(vec<len, type> const& x);	\
template vec<len, type> mod(vec<len, type> const& x, type y);	\
template vec<len, type> mod(vec<len, type> const& x, vec<len, type> const& y);	\
template type modf<type>(type x, type& i);	\
template vec<len, type> modf<type>(vec<len, type> const& x, vec<len, type>& i);	\
template vec<len, bool> isnan(vec<len, type> const& x);	\
template vec<len, bool> isinf(vec<len, type> const& x);	\
template type frexp(type x, int& exp);	\
template vec<len, type> frexp(vec<len, type> const& v, vec<len, int>& exp);	\
template type ldexp(type const& x, int const& exp);	\
template vec<len, type> ldexp(vec<len, type> const& v, vec<len, int> const& exp);\
template type smoothstep(type edge0, type edge1, type x);	\
template vec<len, type> smoothstep(type edge0, type edge1, vec<len, type> const& x);	\
template vec<len, type> smoothstep(vec<len, type> const& edge0, vec<len, type> const& edge1, vec<len, type> const& x);	\
template type mod(type x, type y);	\
template type mix(type x, type y, type a);	\
template vec<len, type> mix(vec<len, type> const& x, vec<len, type> const& y, vec<len, type> const& a);	\
template vec<len, type> mix(vec<len, type> const& x, vec<len, type> const& y, type a);
    VEC_FLOAT
#undef X
}

#include "detail/func_exponential.inl"
namespace glm {

#define X(len, type) \template vec<len, type> pow(vec<len, type> const& base, vec<len, type> const& exponent); \template vec<len, type> exp(vec<len, type> const& v); \template vec<len, type> log(vec<len, type> const& v); \template vec<len, type> exp2(vec<len, type> const& v); \
template vec<len, type> log2(vec<len, type> const& v); \template vec<len, type> sqrt(vec<len, type> const& v); \template vec<len, type> inversesqrt(vec<len, type> const& v); \
template type pow(type base, type exponent); \
template type exp(type v); \
template type log(type v); \
template type exp2(type v); \
template type log2(type v); \
template type sqrt(type v); \
template type inversesqrt(type v);
    VEC_FLOAT
#undef X

}
