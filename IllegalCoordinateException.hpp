#pragma once

#include <exception>
#include "Pair.hpp"
#include <sstream>
using namespace std;

class IllegalCoordinateException
{
    private:
        Pair* pair;
    public:
        IllegalCoordinateException(const Pair&);
        string theCoordinate() const;
};