#pragma once
#include <exception>
#include <sstream>
using namespace std;

class IllegalCharException
{
    private:
        /* Variable */
        char ilchar;
    public:
        /* Constructor */
        IllegalCharException(const char);
        /* Functions */
        string theChar() const;
};