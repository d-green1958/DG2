#ifndef DG2_GLLPOINTS_HPP
#define DH2_GLLPOINTS_HPP

#include "types/types.hpp"
#include "discretisation/legendre.hpp"
#include "constants/constants.hpp"
#include "maths/vector.hpp"

#include <math.h>

namespace DG2 {

template<Index N>
void findGLLPointsAndWeights(Vector<Scalar, N>& points, Vector<Scalar, N>& weights, Int maxIter = 100, Scalar relTol = 1e-6, Scalar absTol = 1e-10)
{
    // N is the number of points
    // (so indices go from 0,...,N-1)

    // to have N roots we need 2 from the exterior 
    // and then N-2 from the iterior
    // this means we use Legendre polys the order 
    
    const Index order = N-1;
    if (N < 2)
    {
        throw Error("GLL Requires at least 2 points");
    }

    // set exterior points and weights
    points[0] = -1;
    points[N-1] = 1; 

    Scalar weightArg1 = 2.0 / (N * (N-1));
    weights[0] = weightArg1;
    weights[N-1] = weightArg1;

    // use symmetry of nodes and account for middle point being zero
    const Index numInteriorPoints = N-2;
    const Index numInteriorPointsToFind = numInteriorPoints / 2;
    
    if (numInteriorPoints%2 == 1)
    {
        points[numInteriorPoints/2 + 1] = 0.0;

        Scalar Pn, Pnm1;
        legendrePolynomial(Pn, Pnm1, order, 0.0);
        weights[numInteriorPoints/2 + 1] = weightArg1 /  (Pn*Pn);
    }

    for (Index i = 0; i < numInteriorPointsToFind; i++)
    {        
        // create scalar x
        Scalar x, xPrev, relChange, absChange, Pn, Pnm1, Pprime, Pprimeprime;

        // set initial guess using chebyshev
        // (i+1 to account for exterior node)
        x = cos(PI*(i+1)/(N-1));

        for (Int iter = 0; iter < maxIter; iter++)
        {
            legendrePolynomial(Pn, Pnm1, order, x);
            
            Pprime = N * (Pnm1 - x * Pn);
            Pprimeprime = (2*x*Pprime - order*(order+1)*Pn) / (1-x*x);
            
            xPrev = x;
            x = x - Pprime/Pprimeprime;

            absChange = abs(x - xPrev);
            relChange = absChange / x;

            if ((absChange < absTol) || (relChange < relTol))
            {
                // now use symmetry to set the values
                points[i+1] = -x;
                points[N - 1 - i - 1] = x;

                weights[i+1] = weightArg1 /  (Pn*Pn);
                weights[N - 1 - i - 1] = weightArg1 /  (Pn*Pn);
                break;
            }
        }
    }
}

} // end of DG2::Numerics

#endif
