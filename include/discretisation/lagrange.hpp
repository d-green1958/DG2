#ifndef DG2_LAGRANGE_HPP
#define DG2_LAGRANGE_HPP

#include "types/types.hpp"
#include "maths/vector.hpp"
#include "maths/matrix.hpp"


namespace DG2{

template<Index N>
void computeBaryWeights(Vector<Scalar, N>& weights, const Vector<Scalar, N>& points)
{
	for (Index j = 0; j < N; j++)
	{
		weights[j] = 1.0;
		for (Index m = 0; m < N; m++)
		{
			if (j == m) continue;
			weights[j] *= (points[j] - points[m]);
		}
		weights[j] = 1.0/weights[j];
	}
}
template<Index N>
void computeDerivMatrix(Matrix<Scalar, N, N>& derivMatrix, const Vector<Scalar, N>& points, const Vector<Scalar, N>& weights)
{
	// first compute the off diagonals
	for (Index i = 0; i < N; i++)
	{
		Scalar rowSum = 0.0;
		for (Index j = 0; j < N; j++)
		{
			if (i == j) continue;
			derivMatrix.at(i,j) = weights[j] / (weights[i] * (points[i] - points[j]));
			rowSum += derivMatrix.at(i,j);
		}
		
		// fill in diagonal
		derivMatrix.at(i,i) = -rowSum;
	}

}

} // end of DG2

#endif
