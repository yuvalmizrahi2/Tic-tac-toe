#pragma once
#include <exception>
#include "Pair.hpp"
#include <sstream>
using namespace std;

class IllegalCoordinateException
{
    private:
        /* Variable */
        Pair* pair;
    public:
        /* Constructor */
        IllegalCoordinateException(const Pair&);
        /* Destructor */
        ~IllegalCoordinateException();
        /* Funtions */
        string theCoordinate() const;
};