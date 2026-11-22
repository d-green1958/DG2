#ifndef DG2_DISCRETISATION_HPP
#define DG2_DISCRETISATION_HPP

#include "types/types.hpp"
#include "discretisation/GLLPoints.hpp"
#include "discretisation/lagrange.hpp"
#include "discretisation/legendre.hpp"

#include "maths/vector.hpp"
#include "maths/matrix.hpp"

// recursive power calculator so NPoints_ can be computed
// at compile time
constexpr int ipow(int base, int exp)
{
    return exp == 0 ? 1 : base * ipow(base, exp - 1);
}


namespace DG2{

template<Index dim, Index order>
class Discretisation
{
public:
	// the number of quad points in the element
	static constexpr Index NQuadPoints = ipow(order + 1, dim);

	// the number of quad points in a single dimension
	static constexpr Index N1DQuadPoints = order + 1;

	// constructor
	Discretisation();

	const Vector<Scalar, N1DQuadPoints>& quadPoints() const {return quadPoints_;}
	
	const Vector<Scalar, N1DQuadPoints>& quadWeights() const {return quadWeights_;}

	const Matrix<Scalar, N1DQuadPoints, N1DQuadPoints>& D() const {return D_;}

	const Matrix<Scalar, N1DQuadPoints, N1DQuadPoints>& M() const {return M_;}

	const Matrix<Scalar, N1DQuadPoints, N1DQuadPoints>& invM() const {return invM_;}

private:
	// 1D quad points
	Vector<Scalar, N1DQuadPoints> quadPoints_;

	// 1D quad weights
	Vector<Scalar, N1DQuadPoints> quadWeights_;

	// 1D differentiation matrix
	Matrix<Scalar, N1DQuadPoints, N1DQuadPoints> D_;

	// the 1D mass matrix
	Matrix<Scalar, N1DQuadPoints, N1DQuadPoints> M_;
	Matrix<Scalar, N1DQuadPoints, N1DQuadPoints> invM_;
};

} // end of DG2

#include "discretisation/discretisation.tpp"

#endif
