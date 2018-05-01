#include "IllegalCharException.hpp"
/* Constructor */
IllegalCharException::IllegalCharException(const char illegalchar)
{
    ilchar = illegalchar;
}
/* Functions */
string IllegalCharException::theChar() const
{
    ostringstream os;
    os << ilchar;
    return os.str();
}
