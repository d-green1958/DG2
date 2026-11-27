#ifndef DG2_FACEINFO_HPP
#define DG2_FACEINFO_HPP

#include "types/types.hpp"
#include "allocators/CPUAllocator.hpp"
#include "field/field.hpp"

namespace DG2
{

template<Index dim, FieldType Layout, typename Allocator>
class FaceInfo
{

public:
    // constructor
    FaceInfo(
        Index NFaces,
        Index NPointsPerFace,
        Index NBoundaryFaces,
        Index NBoundaries
    )
     : pointIDs_(NFaces, NPointsPerFace),
    neighbourElementIDs_(NFaces, 2),
    faceAreas_(NFaces, 1),
    normals_(NFaces, dim),
    boundaryFaceIDs_(NBoundaryFaces, 1),
    boundaryIDs_(NBoundaryFaces, 1),
    nBoundaries_(NBoundaries)
    {}
    
    // check if faceID is internal or external
    Bool isOnBoundary(Index faceID) const
    {
	return (neighbourElementIDs_.at(faceID, 0) ==INVALID_ID) 
		|| (neighbourElementIDs_.at(faceID, 1) ==INVALID_ID);
    }

    Field<Layout, Scalar, Allocator>& areas() {return faceAreas_;}
	const Field<Layout, Scalar, Allocator>& areas() const {return faceAreas_;}

    Field<Layout, Scalar, Allocator>& normals() {return normals_;}
	const Field<Layout, Scalar, Allocator>& normals() const {return normals_;}

    Field<Layout, Index, Allocator>& neighbourElementIDs() {return neighbourElementIDs_;}
	const Field<Layout, Index, Allocator>& neighbourElementIDs() const {return neighbourElementIDs_;}
    
    Field<Layout, Index, Allocator>& pointIDs() {return pointIDs_;}
    const Field<Layout, Index, Allocator>& pointIDs() const {return pointIDs_;}

    Field<Layout, Index, Allocator>& boundaryIDs() {return boundaryIDs_;}
    const Field<Layout, Index, Allocator>& boundaryIDs() const {return boundaryIDs_;}
    
    const Index& nFaces() const {return pointIDs_.count();}

    const Index& pointsPerFace() const {return pointIDs_.dim();}
    
    const Index& dimension() const {return dim;}

	const Int& nBoundaries() const {return nBoundaries_;}

private:

	// array of pointIDs [nFaces * pointsPerFace]
	Field<Layout, Index, Allocator> pointIDs_;

    // array of elementIDs [nFaces, 2]
	Field<Layout, Index, Allocator> neighbourElementIDs_;

	// face areas
	Field<Layout, Scalar, Allocator> faceAreas_;

    // list of normal vectors [NFaces, dim]
	Field<Layout, Scalar, Allocator> normals_;

    // list of boundary faces [NBoundaryFaces, 1]
	Field<Layout, Index, Allocator> boundaryFaceIDs_;

    // list specifying which boundary a given face belongs to [NBoundaryFaces, 1]
	Field<Layout, Index, Allocator> boundaryIDs_;

	// the number of boundaries
	Int nBoundaries_; 

};

} // end of DG2

#endif
