#pragma once
#include <exception>
#include <sstream>
using namespace std;

class IllegalCharException
{
    private:
        char ilchar;
    public:
        IllegalCharException(const char);
        string theChar() const;
};