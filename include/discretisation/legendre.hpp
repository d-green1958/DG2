#ifndef DG2_LEGENDRE_HPP
#define DG2_LEGENDRE_HPP

#include "types/types.hpp"

namespace DG2 {

void legendrePolynomial(Scalar& out, Scalar& outPrev, const Int N, const Scalar x)
{
    out = x;
    outPrev = 1;
    
    // some better naming
    Scalar& prev = outPrev;
    Scalar& curr = out;

    // base cases
    if (N == 0)
    {
        outPrev = LARGE_SCALAR;
        out = 1;
        return;
    }

    if (N == 1)
    {
        return;
    }
    
    Scalar next; 
    for (Int n = 1; n < N; n++)
    {
        next = ((2*n+1) * x * curr - n*prev) / (n+1);
        prev = curr;
        curr = next;
    }
    return;
}

} // end of DG2

#endif
