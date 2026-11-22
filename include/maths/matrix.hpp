#ifndef DG2_MATRIX_HPP
#define DG2_MATRIX_HPP

#include<iostream>
#include<cassert>
#include "types/types.hpp"

namespace DG2 {

template <typename T, Index N, Index M>
class Matrix {
public:

    using value_type = T;
    static constexpr Index rank = 2; 
    static constexpr Index size= N*M;
    static constexpr Index rows = N;
    static constexpr Index columns = M;

	// access to flattened data (consistent with other classes)
    T& operator[](Index idx) {
        assert(idx < size);
        return data_[idx]; 
    }
    const T& operator[](Index idx) const {
        assert(idx < size);
        return data_[idx]; 
    }

	// access to organised data (consistent with other classes)
    T& at(Index i, Index j) {
        assert(i<N);
        assert(j<M);
        return data_[i*M + j]; 
    }
    const T& at(Index i, Index j) const {
        assert(i<N);
        assert(j<M);
        return data_[i*M + j];
    }

    Matrix() = default;

    Matrix(const Matrix&) = default;
    Matrix(Matrix&&) = default;
    Matrix& operator=(const Matrix&) = default;
    Matrix& operator=(Matrix&&) = default;

    template<typename U>
    void set(const U val);

    // matrix operators
    template<typename U>
    Matrix& operator+=(const Matrix<U,N,M>& rhs);
    template<typename U>
    Matrix& operator-=(const Matrix<U,N,M>& rhs);
    template<typename U>
    Matrix& operator/=(const Matrix<U,N,M>& rhs);
    template<typename U>
    Matrix& operator*=(const Matrix<U,N,M>& rhs);

    // scalar operators
    template<typename U>
    Matrix& operator+=(const U& rhs);
    template<typename U>
    Matrix& operator-=(const U& rhs);
    template<typename U>
    Matrix& operator*=(const U& rhs);
    template<typename U>
    Matrix& operator/=(const U& rhs);



private:

	T data_[N*M]; // heap allocated since small
};

} // end of DG2

#include "matrix.tpp"

#endif
