#pragma once
#include <exception>
#include "Coordinate.hpp"
#include <sstream>
using namespace std;

class IllegalCoordinateException
{
    private:
        /* Variable */
        Coordinate* pair;
    public:
        /* Constructor */
        IllegalCoordinateException(const Coordinate&);
        /* Destructor */
        ~IllegalCoordinateException();
        /* Funtions */
        string theCoordinate() const;
};