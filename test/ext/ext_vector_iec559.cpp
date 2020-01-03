#include <glm/gtc/constants.hpp>
#include <glm/ext/scalar_relational.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/vector_double2.hpp>
#include <glm/ext/vector_double3.hpp>
#include <glm/ext/vector_double4.hpp>
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>

template <typename genType>
static int test_operators()
{
	typedef typename genType::value_type valType;
	
	int Error = 0;

	{
		genType const A(1);
		genType const B(1);

		genType const C = A + B;
		Error += glm::all(glm::equal(C, genType(2), glm::epsilon<valType>())) ? 0 : 1;

		genType const D = A - B;
		Error += glm::all(glm::equal(D, genType(0), glm::epsilon<valType>())) ? 0 : 1;

		genType const E = A * B;
		Error += glm::all(glm::equal(E, genType(1), glm::epsilon<valType>())) ? 0 : 1;

		genType const F = A / B;
		Error += glm::all(glm::equal(F, genType(1), glm::epsilon<valType>())) ? 0 : 1;
	}

	return Error;
}

template <typename genType>
static int test_ctor()
{
	typedef typename genType::value_type T;
	
	int Error = 0;

	glm::vec<1, T> const A = genType(1);

	glm::vec<1, T> const E(genType(1));
	Error += glm::all(glm::equal(A, E, glm::epsilon<T>())) ? 0 : 1;

	glm::vec<1, T> const F(E);
	Error += glm::all(glm::equal(A, F, glm::epsilon<T>())) ? 0 : 1;

	genType const B = genType(1);
	genType const G(glm::vec<2, T>(1));
	Error += glm::all(glm::equal(B, G, glm::epsilon<T>())) ? 0 : 1;

	genType const H(glm::vec<3, T>(1));
	Error += glm::all(glm::equal(B, H, glm::epsilon<T>())) ? 0 : 1;

	genType const I(glm::vec<4, T>(1));
	Error += glm::all(glm::equal(B, I, glm::epsilon<T>())) ? 0 : 1;

	return Error;
}

template <typename genType>
static int test_size()
{
	typedef typename genType::value_type T;
	
	int Error = 0;

	Error += sizeof(glm::vec<1, T>) == sizeof(genType) ? 0 : 1;
	Error += genType().length() == 1 ? 0 : 1;
	Error += genType::length() == 1 ? 0 : 1;

	return Error;
}

template <typename genType>
static int test_relational()
{
	typedef typename genType::value_type valType;
	
	int Error = 0;

	genType const A(1);
	genType const B(1);
	genType const C(0);

	Error += all(equal(A, B, glm::epsilon<valType>())) ? 0 : 1;
	Error += any(notEqual(A, C, glm::epsilon<valType>())) ? 0 : 1;

	return Error;
}

template <typename genType>
static int test_constexpr()
{
#	if GLM_CONFIG_CONSTEXP == GLM_ENABLE
		static_assert(genType::length() == 1, "GLM: Failed constexpr");
#	endif

	return 0;
}

int main()
{
	int Error = 0;

	
	return Error;
}
