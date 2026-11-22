#ifndef DG2_CPUALLOCATOR_HPP
#define DG2_CPUALLOCATOR_HPP

#include "types/types.hpp"

namespace DG2 {

struct CPUAllocator {
	template<typename T>
	static T* allocate(Index n)
	{
		return new T[n]();
	}

	template<typename T>
	static void deallocate(T* ptr)
	{
		delete[] ptr;
	}

};

}

#endif
