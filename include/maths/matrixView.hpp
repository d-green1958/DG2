#ifndef DG2_MATRIXVIEW_HPP
#define DG2_MATRIXVIEW_HPP

#include<iostream>
#include<cassert>
#include "types/types.hpp"
#include "maths/offsets.hpp"


namespace DG2 {

template <typename T, Index N, Index M>
class MatrixView {
public:

    using value_type = T;
    static constexpr Index rank = 2; 
    static constexpr Index size= N*M;
    static constexpr Index rows = N;
    static constexpr Index columns = M;

    Index offset(const Index i, const Index j) const {return offsets_[i*M+j];}

	// access to flattened data (consistent with other classes)
    T& operator[](Index idx) {
        assert(idx<size);
        return start_[offsets_[idx]];
    }
    const T& operator[](Index idx) const {
        assert(idx<size);
        return start_[offsets_[idx]];
    }

	// access to organised data (consistent with other classes)
    T& at(Index i, Index j) {
        assert(i<N);
        assert(j<M);
        return start_[offsets_[i*M + j]]; 
    }
    const T& at(Index i, Index j) const {
        assert(i<N);
        assert(j<M);
        return start_[offsets_[i*M + j]];
    }

    MatrixView() = default;
    MatrixView(T* start, Offsets<N*M> offsets)
    : start_(start), offsets_(offsets) {}

    MatrixView(const MatrixView&) = default;
    MatrixView(MatrixView&&) = default;
    MatrixView& operator=(const MatrixView&) = default;
    MatrixView& operator=(MatrixView&&) = default;

    template<typename U>
    void set(const U val);

    // matrix operators
    template<typename U>
    MatrixView& operator+=(const MatrixView<U,N,M>& rhs);
    template<typename U>
    MatrixView& operator-=(const MatrixView<U,N,M>& rhs);
    template<typename U>
    MatrixView& operator/=(const MatrixView<U,N,M>& rhs);
    template<typename U>
    MatrixView& operator*=(const MatrixView<U,N,M>& rhs);

    // scalar operators
    template<typename U>
    MatrixView& operator+=(const U& rhs);
    template<typename U>
    MatrixView& operator-=(const U& rhs);
    template<typename U>
    MatrixView& operator*=(const U& rhs);
    template<typename U>
    MatrixView& operator/=(const U& rhs);



private:

	T* start_;
    Offsets<N*M> offsets_;
};

} // end of DG2

#include "maths/matrixView.tpp"

#endif
