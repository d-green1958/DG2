#ifndef DG2_ELEMENTINFO_HPP
#define DG2_ELEMENTINFO_HPP

#include "types/types.hpp"
#include "allocators/CPUAllocator.hpp"
#include "field/field.hpp"

namespace DG2
{
    
template<Index dim, FieldType Layout, typename Allocator>
class ElementInfo
{

public:

    ElementInfo(
        Index NElements,
        Index NPointsPerElement, 
        Index NFacesPerElement
    )
     : pointIDs_(NElements, NPointsPerElement),
     faceIDs_(NElements, NFacesPerElement),
     elementVolumes_(NElements, 1),
     elementJacobians_(NElements, dim*dim),
     elementCentres_(NElements, dim)
    {}

	Field<Layout, Index, Allocator>& pointIDs() {return pointIDs_;}
    
	Field<Layout, Index, Allocator>& faceIDs() {return faceIDs_;}
    
	Field<Layout, Scalar, Allocator>& jacobians() {return elementJacobians_;}
	
	Field<Layout, Scalar, Allocator>& volumes() {return elementVolumes_;}

    Field<Layout, Scalar, Allocator>& centres() {return elementCentres_;}

    const Index& dimension() const {return dim;}
    
    const Index& nElements() const {return pointIDs_.count();}
    
    const Index& pointsPerElement() const {return pointIDs_.dim();}

    const Index& facesPerElement() const {return faceIDs_.dim();}


private:
    // list of point ids arranged by [NElement, NPoint]
    Field<Layout, Index, Allocator> pointIDs_;

    // list of face ids arranged by [NElement, NFace]
    Field<Layout, Index, Allocator> faceIDs_;

    // list of element volumes [NElement, 1] 
    Field<Layout, Scalar, Allocator> elementVolumes_;

    // list of element jacobians [NElement, dim*dim]
    Field<Layout, Scalar, Allocator> elementJacobians_;

    // list of element jacobians [NElement, dim*dim]
    Field<Layout, Scalar, Allocator> elementCentres_;

};

} // end of DG2

#endif
