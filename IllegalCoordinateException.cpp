#include "IllegalCoordinateException.hpp"
/* Constructor */
IllegalCoordinateException::IllegalCoordinateException(const Coordinate& illegalpair)
{
    pair = new Coordinate(illegalpair);
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
