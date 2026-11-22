#include "maths/matrix.hpp"

namespace DG2 {

template <typename T, Index N, Index M>
template<typename U>
void Matrix<T, N, M>::set(const U val)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] = val;
	}
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator+=(const Matrix<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] += rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator-=(const Matrix<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] -= rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator*=(const Matrix<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] *= rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator/=(const Matrix<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] /= rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator+=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] += rhs;
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator-=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] -= rhs;
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator*=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] *= rhs;
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
Matrix<T, N, M>& Matrix<T, N, M>::operator/=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		data_[i] /= rhs;
	}
	return *this;
}

} // end of DG
