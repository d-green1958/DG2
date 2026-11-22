#include "field/field.hpp"

namespace DG2 {

// RULE OF 5
// 1. destructor
template <FieldType Layout, typename T, typename Allocator>
Field<Layout, T, Allocator>::~Field()
{
    Allocator::template deallocate(data_);
}

// 2. constructor
template <FieldType Layout, typename T, typename Allocator>
Field<Layout, T, Allocator>::Field(Index count, Index dim)
    : dim_(dim),
      count_(count),
	  size_(count_*dim_)
{
	initialise();
}

// 3. copy assignment (deleted)

// 4. move constructor
template <FieldType Layout, typename T, typename Allocator>
Field<Layout, T, Allocator>::Field(Field<Layout, T, Allocator>&& other) noexcept
    : dim_(other.dim_),
    count_(other.count_),
    size_(other.size_),
    data_(other.data_) 
{
    // leave `other` in a valid empty state
    other.data_ = nullptr;
    other.dim_ = 0;
    other.count_ = 0;
    other.size_ = 0;
}

// 5. move assignment
template <FieldType Layout, typename T, typename Allocator>
Field<Layout, T, Allocator>& 
Field<Layout, T, Allocator>::operator=(Field<Layout, T, Allocator>&& other) noexcept
{
    if (this != &other)
    {
        Allocator::template deallocate<T>(data_);
        data_ = other.data_;
        dim_ = other.dim_;
        count_ = other.count_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.dim_ = 0;
        other.count_ = 0;
        other.size_ = 0;
    }
    return *this;
}


// get data at index idx and component cmpt
template <FieldType Layout, typename T, typename Allocator>
T& Field<Layout, T, Allocator>::at(const Index idx, const Index cmpt)
{
    assert(data_ != nullptr);
    assert(idx < count_);
    assert(cmpt < dim_);

    return data_[indexAt(idx, cmpt)];
}

template <FieldType Layout, typename T, typename Allocator>
const T& Field<Layout, T, Allocator>::at(const Index idx, const Index cmpt) const
{
    assert(data_ != nullptr);
    assert(idx < count_);
    assert(cmpt < dim_);

    return data_[indexAt(idx, cmpt)];
}


// init the storage
template <FieldType Layout, typename T, typename Allocator>
void Field<Layout, T, Allocator>::initialise()
{
    data_ = Allocator::template allocate<T>(size_);
}

template <FieldType Layout, typename T, typename Allocator>
Index Field<Layout, T, Allocator>::indexAt(const Index idx, const Index cmpt) const
{
    if constexpr (Layout == FieldType::ArrayOfStructs) {
        return idx * dim_ + cmpt;
    }
    else {
        return cmpt * count_ + idx;
    }
}

template <FieldType Layout, typename T, typename Allocator>
template<Index N>
VectorView<T, N> Field<Layout, T, Allocator>::vector(Index n)
{
    assert(N<=dim_);
    assert(n<count_);
    Offsets<N> offsets;

    for (Index i=0; i<N; i++)
    {
        offsets[i] = indexAt(n, i);
    }
    return VectorView<T, N>(start(), offsets);
}

template <FieldType Layout, typename T, typename Allocator>
template<Index N, Index M>
MatrixView<T, N, M> Field<Layout, T, Allocator>::matrix(Index n)
{
    assert(N*M<=dim_);
    assert(n<count_);
    Offsets<N*M> offsets;

    for (Index i=0; i<N; i++)
    {
        for(Index j=0; j<M; j++)
        {
            offsets[i*M+j] = indexAt(n, i*M+j);
        }
    }
    return MatrixView<T, N, M>(start(), offsets);
}



} // end of DG2
