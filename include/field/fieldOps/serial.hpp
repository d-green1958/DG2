#ifndef DG2_FIELDOPS_SERIAL_HPP
#define DG2_FIELDOPS_SERIAL_HPP

#include "field/field.hpp"
#include "types/types.hpp"

namespace DG2 {
namespace fieldOps {
namespace serial {

// set all values in f to val
template <typename TField, typename TVal>
void set(TField& f, TVal val)
{
	const Index size = f.size();
	for (Index i = 0; i < size; i++)
	{
		f[i] = val;
	}	
}

// inplace addition (f += val)
template <typename TField, typename TVal>
void add(TField& f, TVal val)
{
	const Index size = f.size();
	for (Index i = 0; i < size; i++)
	{
		f[i] += val;
	}
}

// inplace addition (f += val)
template <typename TField, typename TVal>
void subtract(TField& f, TVal val)
{
	const Index size = f.size();
	for (Index i = 0; i < size; i++)
	{
		f[i] -= val;
	}
}

// inplace multiplication (f *= val)
template <typename TField, typename TVal>
void multiply(TField& f, TVal val)
{
	const Index size = f.size();
	for (Index i = 0; i < size; i++)
	{
		f[i] *= val;
	}	
}

// inplace multiplication (f *= val)
template <typename TField, typename TVal>
void divide(TField& f, TVal val)
{
	const Index size = f.size();
	for (Index i = 0; i < size; i++)
	{
		f[i] /= val;
	}	
}

// template for fields with same type
template<FieldType Layout, typename T, typename Allocator>
void dot(Field< Layout, T, Allocator>& f1, Field< Layout, T, Allocator>& f2, Field< Layout, T, Allocator>& fout)
{
	assert(f1.count() == f2.count());
	assert(fout.count() == f2.count());

	assert(f1.dim() == f2.dim());
	assert(fout.dim() == 1);

	const Index count = f1.count();
	const Index dim = f1.dim();

	if constexpr (Layout == FieldType::ArrayOfStructs)
	{
		for (Index i = 0; i <  count; i++)
		{
			for (Index j = 0; j < dim; j++)
			{
				fout.at(i, 0) += f1.at(i, j) 
									* f2.at(i, j);
			}
		}
	}
	else
	{
		for (Index j = 0; j < dim; j++)
		{
			for (Index i = 0; i < count; i++)
			{
				fout.at(i, 0) += f1.at(i, j) 
									* f2.at(i, j);
			}
		}

	}
}

// copy f to fOut
template<FieldType Layout, typename T, typename Allocator>
void copy(const Field< Layout, T, Allocator>& f, Field< Layout, T, Allocator>& fOut)
{
	assert(f.dim() == fOut.dim());
	assert(f.count() == fOut.count());

	const Index size = f.size();

	for (Index i = 0; i < size; i++)
	{
		fOut[i] = f[i];
	}
}

} // end of serial
} // end of fieldOps
} // end of DG2


#endif
