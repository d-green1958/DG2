#ifndef DG2_VectorViewVIEW_HPP
#define DG2_VectorViewVIEW_HPP

#include "types/types.hpp"
#include "maths/offsets.hpp"

namespace DG2 {

template <typename T, Index N>
class VectorView {
public:
    using value_type = T;
    static constexpr Index rank = 1; 
    static constexpr Index size = N;
    static constexpr Index rows = N;

    Index offset(const Index i) const {return offsets_[i];}

	// access to flattened data (consistent with other classes)
    T& operator[](Index idx) { return start_[offsets_[idx]]; }
    const T& operator[](Index idx) const { return start_[offsets_[idx]]; }

	// access to organised data (consistent with other classes)
    T& at(Index cmpt) { return start_[offsets_[cmpt]]; }
    const T& at(Index cmpt) const { return start_[offsets_[cmpt]]; }

    VectorView() = default;
    VectorView(T* start, Offsets<N> offsets)
    : start_(start), offsets_(offsets) {}

    VectorView(const VectorView&) = default;
    VectorView(VectorView&&) = default;
    VectorView& operator=(const VectorView&) = default;
    VectorView& operator=(VectorView&&) = default;

    // set all values
    template<typename U>
    void set(const U val);

    // VectorView operators
    template<typename U>
    VectorView& operator+=(const VectorView<U, N>& rhs);
    template<typename U>
    VectorView& operator-=(const VectorView<U, N>& rhs);
    template<typename U>
    VectorView& operator/=(const VectorView<U, N>& rhs);
    template<typename U>
    VectorView& operator*=(const VectorView<U, N>& rhs);

    // scalar operators
    template<typename U>
    VectorView& operator+=(const U& rhs);
    template<typename U>
    VectorView& operator-=(const U& rhs);
    template<typename U>
    VectorView& operator*=(const U& rhs);
    template<typename U>
    VectorView& operator/=(const U& rhs);


private:

	T* start_;
    Offsets<N> offsets_;

};

}

#include "maths/vectorView.tpp"

#endif