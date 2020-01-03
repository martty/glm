/// @file glm/ext.hpp
///
/// @ref core (Dependence)

#include "detail/setup.hpp"

#pragma once

#include "glm.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_MESSAGE_EXT_INCLUDED_DISPLAYED)
#	define GLM_MESSAGE_EXT_INCLUDED_DISPLAYED
#	pragma message("GLM: All extensions included (not recommended)")
#endif//GLM_MESSAGES

#include "./ext/matrix_double2x2.hpp"
#include "./ext/matrix_double2x3.hpp"
#include "./ext/matrix_double2x4.hpp"
#include "./ext/matrix_double3x2.hpp"
#include "./ext/matrix_double3x3.hpp"
#include "./ext/matrix_double3x4.hpp"
#include "./ext/matrix_double4x2.hpp"
#include "./ext/matrix_double4x3.hpp"
#include "./ext/matrix_double4x4.hpp"

#include "./ext/matrix_float2x2.hpp"
#include "./ext/matrix_float2x3.hpp"
#include "./ext/matrix_float2x4.hpp"
#include "./ext/matrix_float3x2.hpp"
#include "./ext/matrix_float3x3.hpp"
#include "./ext/matrix_float3x4.hpp"
#include "./ext/matrix_float4x2.hpp"
#include "./ext/matrix_float4x3.hpp"
#include "./ext/matrix_float4x4.hpp"

#include "./ext/matrix_relational.hpp"

#include "./ext/quaternion_double.hpp"
#include "./ext/quaternion_float.hpp"
#include "./ext/quaternion_geometric.hpp"
#include "./ext/quaternion_relational.hpp"

#include "./ext/scalar_constants.hpp"
#include "./ext/scalar_int_sized.hpp"
#include "./ext/scalar_relational.hpp"

#include "./ext/vector_bool2.hpp"
#include "./ext/vector_bool3.hpp"
#include "./ext/vector_bool4.hpp"

#include "./ext/vector_double2.hpp"
#include "./ext/vector_double3.hpp"
#include "./ext/vector_double4.hpp"

#include "./ext/vector_float2.hpp"
#include "./ext/vector_float3.hpp"
#include "./ext/vector_float4.hpp"

#include "./ext/vector_int2.hpp"
#include "./ext/vector_int3.hpp"
#include "./ext/vector_int4.hpp"

#include "./ext/vector_relational.hpp"

#include "./ext/vector_uint2.hpp"
#include "./ext/vector_uint3.hpp"
#include "./ext/vector_uint4.hpp"

#include "./gtc/bitfield.hpp"
#include "./gtc/color_space.hpp"
#include "./gtc/constants.hpp"
#include "./gtc/epsilon.hpp"
#include "./gtc/integer.hpp"
#include "./gtc/matrix_access.hpp"
#include "./gtc/matrix_integer.hpp"
#include "./gtc/matrix_inverse.hpp"
#include "./gtc/matrix_transform.hpp"
#include "./gtc/noise.hpp"
#include "./gtc/packing.hpp"
#include "./gtc/quaternion.hpp"
#include "./gtc/random.hpp"
#include "./gtc/reciprocal.hpp"
#include "./gtc/round.hpp"
#include "./gtc/type_ptr.hpp"
#include "./gtc/ulp.hpp"
#if GLM_CONFIG_ALIGNED_GENTYPES == GLM_ENABLE
#	include "./gtc/type_aligned.hpp"
#endif

#ifdef GLM_ENABLE_EXPERIMENTAL
#include "./gtx/associated_min_max.hpp"
#include "./gtx/bit.hpp"
#include "./gtx/closest_point.hpp"
#include "./gtx/color_encoding.hpp"
#include "./gtx/color_space.hpp"
#include "./gtx/color_space_YCoCg.hpp"
#include "./gtx/compatibility.hpp"
#include "./gtx/component_wise.hpp"
#include "./gtx/dual_quaternion.hpp"
#include "./gtx/euler_angles.hpp"
#include "./gtx/extend.hpp"
#include "./gtx/extended_min_max.hpp"
#include "./gtx/fast_exponential.hpp"
#include "./gtx/fast_square_root.hpp"
#include "./gtx/fast_trigonometry.hpp"
#include "./gtx/functions.hpp"
#include "./gtx/gradient_paint.hpp"
#include "./gtx/handed_coordinate_space.hpp"
#include "./gtx/integer.hpp"
#include "./gtx/intersect.hpp"
#include "./gtx/log_base.hpp"
#include "./gtx/matrix_cross_product.hpp"
#include "./gtx/matrix_interpolation.hpp"
#include "./gtx/matrix_major_storage.hpp"
#include "./gtx/matrix_operation.hpp"
#include "./gtx/matrix_query.hpp"
#include "./gtx/mixed_product.hpp"
#include "./gtx/norm.hpp"
#include "./gtx/normal.hpp"
#include "./gtx/normalize_dot.hpp"
#include "./gtx/number_precision.hpp"
#include "./gtx/optimum_pow.hpp"
#include "./gtx/orthonormalize.hpp"
#include "./gtx/perpendicular.hpp"
#include "./gtx/polar_coordinates.hpp"
#include "./gtx/projection.hpp"
#include "./gtx/quaternion.hpp"
#include "./gtx/raw_data.hpp"
#include "./gtx/rotate_vector.hpp"
#include "./gtx/spline.hpp"
#include "./gtx/std_based_type.hpp"
#if !(GLM_COMPILER & GLM_COMPILER_CUDA)
#	include "./gtx/string_cast.hpp"
#endif
#include "./gtx/transform.hpp"
#include "./gtx/transform2.hpp"
#include "./gtx/vec_swizzle.hpp"
#include "./gtx/vector_angle.hpp"
#include "./gtx/vector_query.hpp"
#include "./gtx/wrap.hpp"

#if GLM_HAS_TEMPLATE_ALIASES
#	include "./gtx/scalar_multiplication.hpp"
#endif

#if GLM_HAS_RANGE_FOR
#	include "./gtx/range.hpp"
#endif
#endif//GLM_ENABLE_EXPERIMENTAL
