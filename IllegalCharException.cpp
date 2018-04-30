#include "IllegalCharException.hpp"

IllegalCharException::IllegalCharException(const char illegalchar)
{
    ilchar = illegalchar;
}
string IllegalCharException::theChar() const
{
    ostringstream os;
    os << ilchar;
    return os.str();
}
