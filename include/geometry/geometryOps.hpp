#ifndef DG2_JACOBIAN_HPP
#define DG2_JACOBIAN_HPP

#include "geometry/mesh.hpp"
#include "field/field.hpp"
#include "types/types.hpp"
#include "maths/vector.hpp"

namespace DG2 {
namespace geometryOps {

template <typename MeshType, typename ReferenceElementType>
void computeJacobian(MeshType& mesh);

template<FieldType Layout, typename Allocator>
Mesh<1, Layout, Allocator, 2> create1DMesh(Index NElements, Scalar xL, Scalar xR);

template<Index dim, typename TJacobian, typename TXi, typename TOrigin>
constexpr Vector<Scalar, dim> affineMap(const TJacobian j, const TXi xi, const TOrigin o);

} // end of Geometry

} // end of DG2

#include "geometry/geometryOps.tpp"

#endif
