#include "discretisation/discretisation.hpp"

namespace DG2 {

template<Index dim, Index order>
Discretisation<dim, order>::Discretisation()
{
	findGLLPointsAndWeights(
		quadPoints_,
		quadWeights_
	);

	// populate the 1D mass matrix
	for (Index i = 0; i < N1DQuadPoints; i++)
	{
		for (Index j = 0; j < N1DQuadPoints; j++)
		{
			if (i == j)
			{
				M_.at(i,j) = quadWeights_.at(i);
				invM_.at(i,j) = 1.0/quadWeights_.at(i);
			}
			else
			{
				M_.at(i,j) = 0.0;
				invM_.at(i,j) = 0.0;
			}
		}
	}

	// now compute the 1D derivative matrix
	Vector<Scalar, N1DQuadPoints> baryWeights;
	computeBaryWeights(baryWeights, quadPoints_);
	computeDerivMatrix(D_, quadPoints_, baryWeights);
}


} // end of DG2
