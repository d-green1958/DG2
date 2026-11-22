#ifndef DG2_FIELD_HPP
#define DG2_FIELD_HPP


#include "types/types.hpp"
#include "allocators/CPUAllocator.hpp"
#include "maths/vectorView.hpp"
#include "maths/matrixView.hpp"
#include<iostream>
#include<cassert>

namespace DG2 {

enum class FieldType {
	StructOfArrays,
	ArrayOfStructs
};

template <FieldType Layout, typename T, typename Allocator>
class Field {

	public:
		// RULE OF 5:
		// 1. destructor
		~Field();

		// 2. constructor
		Field(Index count, Index dim);

		// 3. copy assignment (deleted)
		Field& operator=(const Field& other) = delete;
		Field(const Field<Layout, T, Allocator>& other) = delete;
		
		// 4. move constructor 
		Field(Field<Layout, T, Allocator>&& other) noexcept;
		
		// 5. move assignment 
		Field& operator=(Field&& other) noexcept;

		// expose template
		static constexpr FieldType layout = Layout;
		using value_type = T;
		using allocator_type = Allocator;

		// const access to dim
		const Index& dim() const {return dim_;}
	
		// const access to size
		const Index& size() const {return size_;}

		// const access to max index
		const Index& count() const {return count_;}

		// start of data
		T* start() const {return data_;}

		// access to flattened data
		T& operator[](const Index idx) {
			assert(data_ != nullptr);
			assert(idx < size_);				
			return data_[idx];
		}

		// const access to flattened data
		const T& operator[](const Index idx) const {
			assert(data_ != nullptr);
			assert(idx < size_);				
			return data_[idx];
		}

		// access to organised data
		T& at(const Index idx, const Index cmpt);

		// const access to organised data
		const T& at(const Index idx, const Index cmpt) const;

		// access to organised data
		T& operator()(const Index idx, const Index cmpt) {return at(idx, cmpt);}

		// const access to organised data
		const T& operator()(const Index idx, const Index cmpt) const {return at(idx, cmpt);}

		template<Index N>
		VectorView<T, N> vector(Index n);

		template<Index N, Index M>
		MatrixView<T, N, M> matrix(Index n);

		Index indexAt(const Index idx, const Index cmpt) const;

	private:
	
		// dimension of data [size, dim]
		Index dim_;
		
		// max index giving total number of elements
		Index count_;
		
		// number of vectors of size dim stored
		Index size_;
	
		// pointer to data
		T* data_ = nullptr;
		
		// init the storage
		void initialise();

};

} // end of DG2

#include "field.tpp"

#endif
