#ifndef DG2_WALL_HPP
#define DG2_WALL_HPP

#include "types/types.hpp"

namespace DG2 {

struct wall {

	Scalar operator()(Scalar U, Scalar, Scalar) 
	{
		return -U;
	}

};

}

#endif
