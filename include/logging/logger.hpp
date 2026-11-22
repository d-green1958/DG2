#ifndef DG2_LOGGER_HPP
#define DG2_LOGGER_HPP

#include <ostream>

namespace DG2 {

struct flush_t {};
extern flush_t flush;

struct nl_t {};
extern nl_t nl;

struct tab_t {};
extern tab_t tab;

class Logger
{
public: 
    explicit Logger(std::ostream& out, const char* prefix = "", const bool autoFlush = false)
    : out_(out),
    prefix_(prefix)
    {}
    
    template<typename T>
    Logger& operator<<(const T& value);
    
    Logger& operator<<(flush_t) {
        out_.flush();
        return *this;
    }
    
    Logger& operator<<(nl_t) {
        *this << "\n";
        atLineStart_ = true;
        out_.flush();
        return *this;
    }

    Logger& operator<<(tab_t) {
        *this << "\t";
        out_.flush();
        return *this;
    }
    
    Logger& flush() {
        out_.flush();
        return *this;
    }
    
    void newLine() {
        *this << "\n";
    }

private:
    std::ostream& out_;
    const char* prefix_;
    bool atLineStart_ = true;
};
    
} // end of DG2

#include "logger.tpp"

#endif
