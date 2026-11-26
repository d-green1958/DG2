#ifndef DG2_BOUNDARYINFO_HPP
#define DG2_BOUNDARYINFO_HPP

#include "field/field.hpp"
#include "types/types.hpp"

namespace DG2 {


template<Index dim, FieldType Layout, typename Allocator, Index NBoundaries>
class BoundaryInfo
{
public:
	BoundaryInfo(Index NBoundaryFaces)
	: faceIDs_(NBoundaryFaces, 1)
	{}

	Field<Layout, Index, Allocator>& faceIDs() {return faceIDs_;}
	const Field<Layout, Index, Allocator>& faceIDs() const {return faceIDs_;}

	Index& offset(Index iB) {return offsets_[iB];}
	const Index& offset(Index iB) const {return offsets_[iB];}

private:

	// list of faces that belong to each boundary
	Field<Layout, Index, Allocator> faceIDs_;

	Index offsets_[NBoundaries]{};

};

}

#endif
