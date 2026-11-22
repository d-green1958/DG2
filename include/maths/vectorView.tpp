#include "maths/vectorView.hpp"

namespace DG2 {

template <typename T, Index N>
template<typename U>
void VectorView<T, N>::set(const U val)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] = val;
	}
}

template <typename T, Index N>
template<typename U>
VectorView<T, N>& VectorView<T, N>::operator+=(const VectorView<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] += rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template<typename U>
VectorView<T, N>& VectorView<T, N>::operator-=(const VectorView<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] -= rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template<typename U>
VectorView<T, N>& VectorView<T, N>::operator*=(const VectorView<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] *= rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template<typename U>
VectorView<T, N>& VectorView<T, N>::operator/=(const VectorView<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] /= rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
VectorView<T, N>& VectorView<T, N>::operator+=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] += rhs;
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
VectorView<T, N>& VectorView<T, N>::operator-=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] -= rhs;
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
VectorView<T, N>& VectorView<T, N>::operator*=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] *= rhs;
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
VectorView<T, N>& VectorView<T, N>::operator/=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] /= rhs;
	}
	return *this;
}


} // end of DG
