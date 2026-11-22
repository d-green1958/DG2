#ifndef DG2_CONSTANTVAL_HPP
#define DG2_CONSTANTVAL_HPP

#include "types/types.hpp"

namespace DG2 {

struct constantVal {

	Scalar val;

	void setVal(Scalar v) {val = v;}

	Scalar operator()(Scalar, Scalar, Scalar) 
	{
		return val;
	}

};

}

#endif
