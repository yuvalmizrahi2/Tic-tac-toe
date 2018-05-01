#pragma once
#include "Pair.hpp"
#include <iostream>
#include "IllegalCharException.hpp"
using namespace std;

class Cell{
    public:
        /* Variable */
        char cell;
        /* Constructor */
        Cell(char);
        Cell();
        /* IOstream */
        friend ostream& operator<<(ostream& os, Cell const& obj);
        /* Assignment */
        Cell& operator=(char c);
        Cell& operator=(const Cell& c);
};