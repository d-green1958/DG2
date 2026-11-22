#ifndef DG2_EULER_HPP
#define DG2_EULER_HPP

/*
updates the equation 
	du/dt = f(u,x,t)
like so
	u^n+1 = u^n + f(u^n, x, t^n) * deltaT.
This can be done in place so required no additional storage.
*/

#include "types/types.hpp"

namespace DG2 {

template<typename TSolver>
class EulerIntegrator {
private:


public:
	void update(Scalar deltaT);

	void init();
};

}

#include "euler.tpp"

#endif
