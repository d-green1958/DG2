#ifndef DG2_OFFSETS_HPP
#define DG2_OFFSETS_HPP

#include "types/types.hpp"
#include <cassert>

namespace DG2 {

template<Index rank>
struct Offsets {
    Index dims[rank]{};

    constexpr Index& operator[](Index i) {
        assert(i<rank);
        return dims[i];
    }
    constexpr const Index& operator[](Index i) const {
        assert(i<rank);
        return dims[i];
    }
};


}

#endif