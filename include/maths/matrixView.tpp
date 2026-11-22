#include "maths/matrixView.hpp"

namespace DG2 {

template <typename T, Index N, Index M>
template<typename U>
void MatrixView<T, N, M>::set(const U val)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] = val;
	}
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator+=(const MatrixView<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] += rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator-=(const MatrixView<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] -= rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator*=(const MatrixView<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] *= rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator/=(const MatrixView<U, N, M>& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] /= rhs[i];
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator+=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] += rhs;
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator-=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] -= rhs;
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator*=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] *= rhs;
	}
	return *this;
}

template <typename T, Index N, Index M>
template<typename U>
MatrixView<T, N, M>& MatrixView<T, N, M>::operator/=(const U& rhs)
{
	for (Index i = 0; i < size; i++)
	{
		start_[offsets_[i]] /= rhs;
	}
	return *this;
}

} // end of DG
