#ifndef MESH_HPP
#define MESH_HPP

#include "types/types.hpp"
#include "topology/faceInfo.hpp"
#include "topology/elementInfo.hpp"
#include "logging/logging.hpp"
#include "allocators/CPUAllocator.hpp"
#include "field/field.hpp"
#include "topology/boundaryInfo.hpp"

namespace DG2 {

template<Index dim, FieldType Layout, typename Allocator, Index NBoundaries>
class Mesh {
    public:
		Mesh(
			Index NPoints,
			Index NElements, 
			Index NFaces, 
			Index NBoundaryFaces, 
			Index NPointsPerElement, 
			Index NPointsPerFace,
			Index NFacesPerElement
		)
		 : pointPositions_(NPoints, dim),
		 elementInfo_(NElements, NPointsPerElement, NFacesPerElement),
		 faceInfo_(NFaces, NPointsPerFace, NBoundaryFaces, NBoundaries),
		 boundaryInfo_(NBoundaryFaces)
		 {}


		FaceInfo<dim, Layout, Allocator>& faceInfo() {return faceInfo_;}
		const FaceInfo<dim, Layout, Allocator>& faceInfo() const {return faceInfo_;}
		
		ElementInfo<dim, Layout, Allocator>& elementInfo() {return elementInfo_;}
		const ElementInfo<dim, Layout, Allocator>& elementInfo() const {return elementInfo_;}

		BoundaryInfo<dim, Layout, Allocator, NBoundaries>& boundaryInfo() {return boundaryInfo_;}
		const BoundaryInfo<dim, Layout, Allocator, NBoundaries>& boundaryInfo() const {return boundaryInfo_;}

		const Index& dimension() const {return dim;}

		const Index& NPoints() const {return pointPositions_.count();}

		Field<Layout, Scalar, Allocator>& pointPositions() {return pointPositions_;}
	
	
	private:
		// nodal positions 
		Field<Layout, Scalar, Allocator> pointPositions_;

		// object owning information about elements
		ElementInfo<dim, Layout, Allocator> elementInfo_;
		
		// object owning information about faces
		FaceInfo<dim, Layout, Allocator> faceInfo_;

		// object owning information about boundary info
		BoundaryInfo<dim, Layout, Allocator, NBoundaries> boundaryInfo_;


};

} // end of DG2


#endif
