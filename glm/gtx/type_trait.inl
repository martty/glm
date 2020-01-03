/// @ref gtx_type_trait

namespace glm
{
	template<typename T>
	bool const type<T>::is_vec;
	template<typename T>
	bool const type<T>::is_mat;
	template<typename T>
	bool const type<T>::is_quat;
	template<typename T>
	length_t const type<T>::components;
	template<typename T>
	length_t const type<T>::cols;
	template<typename T>
	length_t const type<T>::rows;

	// vec
	template<length_t L, typename T>
	bool const type<vec<L, T> >::is_vec;
	template<length_t L, typename T>
	bool const type<vec<L, T> >::is_mat;
	template<length_t L, typename T>
	bool const type<vec<L, T> >::is_quat;
	template<length_t L, typename T>
	length_t const type<vec<L, T> >::components;

	// mat
	template<length_t C, length_t R, typename T>
	bool const type<mat<C, R, T> >::is_vec;
	template<length_t C, length_t R, typename T>
	bool const type<mat<C, R, T> >::is_mat;
	template<length_t C, length_t R, typename T>
	bool const type<mat<C, R, T> >::is_quat;
	template<length_t C, length_t R, typename T>
	length_t const type<mat<C, R, T> >::components;
	template<length_t C, length_t R, typename T>
	length_t const type<mat<C, R, T> >::cols;
	template<length_t C, length_t R, typename T>
	length_t const type<mat<C, R, T> >::rows;

	// tquat
	template<typename T>
	bool const type<qua<T> >::is_vec;
	template<typename T>
	bool const type<qua<T> >::is_mat;
	template<typename T>
	bool const type<qua<T> >::is_quat;
	template<typename T>
	length_t const type<qua<T> >::components;

	// tdualquat
	template<typename T>
	bool const type<tdualquat<T> >::is_vec;
	template<typename T>
	bool const type<tdualquat<T> >::is_mat;
	template<typename T>
	bool const type<tdualquat<T> >::is_quat;
	template<typename T>
	length_t const type<tdualquat<T> >::components;
}//namespace glm
