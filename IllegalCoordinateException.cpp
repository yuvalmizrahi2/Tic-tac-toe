#include "IllegalCoordinateException.hpp"
/* Constructor */
IllegalCoordinateException::IllegalCoordinateException(const Pair& illegalpair)
{
    pair = new Pair(illegalpair);
}
/* Destructor */
IllegalCoordinateException::~IllegalCoordinateException()
{
    delete pair;
}
/* Funtions */
string IllegalCoordinateException::theCoordinate() const
{
    ostringstream os;
    os << pair->x << "," << pair->y;
    return os.str();
}
