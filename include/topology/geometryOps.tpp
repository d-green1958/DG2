#include "topology/referenceElements/line2.hpp"
#include "error/error.hpp"
#include "field/field.hpp"
#include "topology/mesh.hpp"
#include "error/error.hpp"
#include "maths/mathOps.hpp"

namespace DG2 {
namespace geometryOps {

template <typename MeshType, typename ReferenceElementType>
void computeJacobian(MeshType& mesh)
{
	auto& jacobian = mesh.elementInfo().jacobians();
	auto& pointPositions = mesh.pointPositions();

    Index numElements = mesh.elementInfo().nElements();
	

    constexpr Index dim = ReferenceElementType::dimension;
    constexpr Index nPoints = ReferenceElementType::nPoints;  

    // Evaluate reference shape function derivatives once (since assuming affine elements)
    Scalar xi[dim] = {}; // since position within the element doesnt matter
    Scalar dN[nPoints][dim];

    ReferenceElementType::evaluateDerivative(xi, dN);

    for (Index elementID = 0; elementID < numElements; elementID++)
    {
        // for each element
        for (Index i = 0; i < dim; i++)
        {
            for (Index j = 0; j < dim; j++)
            {   
                jacobian.at(elementID, i * dim +  j) = 0.0;
            }   
        } 

        for (Index pointNum = 0; pointNum < nPoints; pointNum++)
        {
            // get pointID
            const Index pointID = mesh.elementInfo().pointIDs().at(elementID, pointNum);
                        
            for (Index i = 0; i < dim; i++)
            {
                // fetch the real point position
                const Scalar xReal = pointPositions.at(pointID, i);  

                for (Index j = 0; j < dim; j++)
                {   
                    jacobian.at(elementID, i * dim +  j) += xReal * dN[pointNum][j];
                }   
            } 
        }
    }
	
}

template<FieldType Layout, typename Allocator>
Mesh<1, Layout, Allocator, 2> create1DMesh(Index NElements, Scalar xL, Scalar xR)
{
    Index NPoints = NElements + 1;
    Index NFaces = NElements + 1;
    Index NBoundaryFaces = 2;
    Index NPointsPerFace = 1;
    Index NFacesPerElement = 2;
    Index NPointsPerElement = 2;
    
    Mesh<1, Layout, Allocator, 2> mesh(NPoints, NElements, NFaces, NBoundaryFaces, NPointsPerElement, NPointsPerFace, NFacesPerElement);


    Scalar dx = (xR - xL) / NElements;
    for(Index i = 0; i < NPoints; i++)
    {
        mesh.pointPositions().at(i,0) = xL + i*dx;
    }


    for (Index n = 0; n < NElements; n++)
    {
        // define left and right points
		mesh.elementInfo().pointIDs().at(n,0) = n;
		mesh.elementInfo().pointIDs().at(n,1) = n + 1;

        // as points are faces can set these
		mesh.elementInfo().faceIDs().at(n,0) = n;
		mesh.elementInfo().faceIDs().at(n,1) = n+1;

		mesh.elementInfo().volumes().at(n,0) = dx;
        mesh.elementInfo().centres().at(n,0) = (n+0.5)*dx + xL;
    }

	for (Index f = 0; f < NFaces; f++)
    {
        mesh.faceInfo().pointIDs().at(f,0) = f;

        if (f > 0)
        {
            mesh.faceInfo().neighbourElementIDs().at(f,0) = f-1;
        }
        else
        {
            mesh.faceInfo().neighbourElementIDs().at(f,0) = INVALID_ID;
        }

        if (f < NFaces - 1)
        {
            mesh.faceInfo().neighbourElementIDs().at(f,1) = f;
        }
        else
        {
            mesh.faceInfo().neighbourElementIDs().at(f,1) = INVALID_ID;
        }
    }

    mesh.faceInfo().boundaryIDs().at(0,0) = 0;
    mesh.faceInfo().boundaryIDs().at(1,0) = 1;

    for (Index f = 0; f < NFaces; f++)
    {
        // since this is a 1D case the normals must be +x
        mesh.faceInfo().normals().at(f,0) = 1.0;
    
        // also set the faceSizes to unity
        mesh.faceInfo().areas().at(f,0) = 1.0;
    }

    mesh.boundaryInfo().faceIDs().at(0,0) = 0;
    mesh.boundaryInfo().faceIDs().at(1,0) = NFaces - 1;

    mesh.boundaryInfo().offset(0) = 0;
    mesh.boundaryInfo().offset(1) = 1;

    // finally compute jacobians
    computeJacobian<Mesh<1, Layout, Allocator, 2>, Line2>(mesh);
    

    return mesh;
}

template<Index dim, typename TJacobian, typename TXi, typename TOrigin>
constexpr Vector<Scalar, dim> affineMap(TJacobian J, TXi xi, TOrigin o)
{
    return mathOps::addVec(mathOps::matVec(J, xi), o);
}


}// end of DG2::geometryOps
} // end of DG2
