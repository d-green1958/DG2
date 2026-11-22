#ifndef DG2_APPLYBOUNDARYCONDITION_HPP
#define DG2_APPLYBOUNDARYCONDITION_HPP

#include "types/types.hpp"
#include "topology/mesh.hpp"
#include "boundaryConditions/boundaryCondition.hpp"

namespace DG2 {

template<typename MeshType, typename StateType, typename ResidualType, typename BC>
void applyBoundaryCondition(const MeshType& mesh, const StateType& state, ResidualType& residual, BC& bc)
{
    Index bID = bc.boundaryID;

    // then apply the boundary condition
    // i.e compute the exterior contribution to the residuals given state
    
}

}

#endif
