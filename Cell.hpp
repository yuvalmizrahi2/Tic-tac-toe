#pragma once
#include "Coordinate.hpp"
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
        /* Comparison operators */
        friend bool operator==(const Cell c1 , const char c2);
        operator char();
};