#include "IllegalCoordinateException.hpp"

IllegalCoordinateException::IllegalCoordinateException(const Pair& illegalpair)
{
    pair = new Pair(illegalpair);
}
string IllegalCoordinateException::theCoordinate() const
{
    ostringstream os;
    os << pair->x << "," << pair->y;
    return os.str();
}
