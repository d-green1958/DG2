#ifndef DG2_CENTRALFLUX_HPP
#define DG2_CENTRALFLUX_HPP

#include "types/types.hpp"

namespace DG2 {

namespace numericalFlux {

class CentralFlux 
{
	public:
		Scalar operator() (Scalar fL, Scalar fR) {return 0.5 * (fL + fR);}

};


}

} // end of DG2

#endif
