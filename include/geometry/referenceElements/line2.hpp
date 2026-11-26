#ifndef DG2_REFERENCELINE2_HPP
#define DG2_REFERENCELINE2_HPP

#include "types/types.hpp"

namespace DG2 {

struct Line2 {
    static constexpr Index dimension = 1;

    static constexpr Index nPoints = 2;

    static constexpr Index nFaces = 2;

    static constexpr Index pointsPerFace = 1;

    static constexpr Int facePoints[2][1] = {
        {0},
        {1}
    };

    static constexpr Scalar refCoords[2][1] = {
        {-1.0},
        {1.0}
    };

    // information about shape functions for mappings
    static inline void evaluate(const Scalar xi[dimension], Scalar N[nPoints])
    {
        N[0] = 0.5 * (1 - xi[0]);
        N[1] = 0.5 * (1 + xi[0]);
    }

    static inline void evaluateDerivative(const Scalar[dimension], Scalar dN[nPoints][dimension])
    {
        dN[0][0] = -0.5;
        dN[1][0] = 0.5;
    }

};

} // end of DG2


#endif