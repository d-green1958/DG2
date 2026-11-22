#ifndef DG2_VECTOR_HPP
#define DG2_VECTOR_HPP

#include<iostream>
#include "types/types.hpp"

namespace DG2 {

template <typename T, Index N>
class Vector {
public:
    using value_type = T;
    static constexpr Index rank = 1; 
    static constexpr Index size = N;
    static constexpr Index rows = N;

	// access to flattened data (consistent with other classes)
    T& operator[](Index idx) { return data_[idx]; }
    const T& operator[](Index idx) const { return data_[idx]; }

	// access to organised data (consistent with other classes)
    T& at(Index cmpt) { return data_[cmpt]; }
    const T& at(Index cmpt) const { return data_[cmpt]; }

    Vector() = default;

    Vector(const Vector&) = default;
    Vector(Vector&&) = default;
    Vector& operator=(const Vector&) = default;
    Vector& operator=(Vector&&) = default;

    // set all values
    template<typename U>
    void set(const U val);

    // vector operators
    template<typename U>
    Vector& operator+=(const Vector<U, N>& rhs);
    template<typename U>
    Vector& operator-=(const Vector<U, N>& rhs);
    template<typename U>
    Vector& operator/=(const Vector<U, N>& rhs);
    template<typename U>
    Vector& operator*=(const Vector<U, N>& rhs);

    // scalar operators
    template<typename U>
    Vector& operator+=(const U& rhs);
    template<typename U>
    Vector& operator-=(const U& rhs);
    template<typename U>
    Vector& operator*=(const U& rhs);
    template<typename U>
    Vector& operator/=(const U& rhs);


private:

	T data_[N]; // heap allocated since small
};

} // end of DG2

#include "vector.tpp"

#endif
