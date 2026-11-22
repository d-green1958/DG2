#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstddef>
#include <string>
#include <cstdint>

namespace DG2 {

using Scalar = double;
using Index = std::size_t;
using Int = int;
using Bool = bool;
using String = std::string;

constexpr size_t INVALID_ID = SIZE_MAX;
constexpr Scalar LARGE_SCALAR = 1e30;

} // end of DG2

#endif
