#ifndef DG2_BOUNDARYCONDITIONS_HPP
#define DG2_BOUNDARYCONDITIONS_HPP

#include "types/types.hpp"

namespace DG2 {

template <typename BC>
struct BoundaryCondition
{
    Index boundaryID;
    BC condition;
};

} // end of DG2

#endif