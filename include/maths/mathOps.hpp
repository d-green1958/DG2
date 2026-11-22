#ifndef DG2_MATHOPS_HPP
#define DG2_MATHOPS_HPP

#include "maths/vector.hpp"
#include "maths/matrix.hpp"
#include "maths/vectorView.hpp"
#include "maths/matrixView.hpp"

#include<cassert>


namespace DG2 {

namespace mathOps {

// define vector-vector operations
// + (already have this below) but define as a operator
// - (already have this below) but define as an operator

// define scalar-vector operations
// *
// /

// define matrix matrix operations
// + 
// -

// define vector


template<typename TVectorL, typename TVectorR>
constexpr auto addVec(const TVectorL& l, const TVectorR& r)
{
	assert(l.rank == 1);
	assert(r.rank == 1);
	assert(l.rows == r.rows);

	using T = decltype(l[0] * r[0]);
	Vector<T, l.rank> result;
	
	for (Index i = 0; i<l.size; i++)
	{
		result[i] = l[i] + r[i];
	}
	return result;
} 

template<typename TVectorL, typename TVectorR>
constexpr auto subVec(const TVectorL& l, const TVectorR& r)
{
	assert(l.rank == 1);
	assert(r.rank == 1);
	assert(l.rows == r.rows);

	using T = decltype(l[0] * r[0]);
	Vector<T, l.rank> result;
	
	for (Index i = 0; i<l.size; i++)
	{
		result[i] = l[i] - r[i];
	}
	return result;
} 

template<typename TVectorL, typename TVectorR>
constexpr auto dot(const TVectorL& l, const TVectorR& r)
{
	assert(l.rank == 1);
	assert(r.rank == 1);
	assert(l.rows == r.rows);

	using T = decltype(l[0] * r[0]);
	T result{};
	
	for (Index i = 0; i<l.size; i++)
	{
		result += l[i] * r[i];
	}
	return result;
} 

template<typename TMatrix, typename TVector>
constexpr auto matVec(const TMatrix& m, const TVector& v)
{
	assert(m.rank == 2);
	assert(v.rank == 1);
	assert(m.columns == v.rows);

	using T = decltype(m[0] * v[0]);
	Vector<T, TMatrix::rows> result{};

	for (Index i=0; i<m.rows; i++)
	{
		for (Index j=0; j<m.columns; j++)
		{
			result.at(i) += m.at(i,j) * v.at(j);
		}
	}
	return result;
}

template<typename TMatrix>
constexpr auto transposeMat(const TMatrix& m)
{
	Matrix<typename TMatrix::value_type, TMatrix::columns, TMatrix::rows> result;
	for (Index i=0; i<m.columns; i++)
	{
		for (Index j=0; j<m.rows; j++)
		{
			result.at(i,j) = m.at(j,i);
		}
	}
	return result;
}

template<typename TMatrix>
constexpr auto traceMat(const TMatrix& m)
{
	assert(TMatrix::rows == TMatrix::columns);

	using TVal = typename TMatrix::type_val;
	TVal result{};
	
	for (Index i=0; i<TMatrix::rows; i++)
	{
		result += m.at(i,i);
	}
	return result;
}

} 
} // end DG2

#endif
