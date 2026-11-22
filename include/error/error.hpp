#ifndef DG2_ERROR_HPP
#define DG2_ERROR_HPP

#include <stdexcept>
#include <string>

namespace DG2 {

class Error : public std::runtime_error
{
public:
    explicit Error(const std::string& message)
    : std::runtime_error(message) {}
};

} // end of DG2

#endif
