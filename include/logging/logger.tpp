#ifndef DG2_LOGGER_TPP
#define DG2_LOGGER_TPP

template<typename T>
DG2::Logger& DG2::Logger::operator<<(const T& value)
{
    if (atLineStart_)
    {
        out_ << prefix_;
        atLineStart_ = false;
    }
    out_ << value;
    flush();
    return *this;
}

#endif
