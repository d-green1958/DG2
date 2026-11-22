#include "maths/vector.hpp"

namespace DG2 {

template <typename T, Index N>
template<typename U>
void Vector<T, N>::set(const U val)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] = val;
	}
}

template <typename T, Index N>
template<typename U>
Vector<T, N>& Vector<T, N>::operator+=(const Vector<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] += rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template<typename U>
Vector<T, N>& Vector<T, N>::operator-=(const Vector<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] -= rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template<typename U>
Vector<T, N>& Vector<T, N>::operator*=(const Vector<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] *= rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template<typename U>
Vector<T, N>& Vector<T, N>::operator/=(const Vector<U, N>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] /= rhs[i];
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
Vector<T, N>& Vector<T, N>::operator+=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] += rhs;
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
Vector<T, N>& Vector<T, N>::operator-=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] -= rhs;
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
Vector<T, N>& Vector<T, N>::operator*=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] *= rhs;
	}
	return *this;
}

template <typename T, Index N>
template <typename U>
Vector<T, N>& Vector<T, N>::operator/=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] /= rhs;
	}
	return *this;
}


} // end of DG
