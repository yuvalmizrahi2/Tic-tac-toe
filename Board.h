#pragma once
#include <iostream>
#include "IllegalCoordinateException.hpp"
#include "IllegalCharException.hpp"
#include "Cell.hpp"
using namespace std;

class Board{
    private:
        /* Variable */
        Cell** board;
        int rowcolumn;
    public:
        /* Constructor */
        Board(int);
        Board(const Board&);
        /* Destructor */
        ~Board();
        /* IOstream */
        friend ostream& operator<<(ostream&, Board const&);
        /* Subscript */
        Cell& operator[](Coordinate);
        /* Assignment */
        Board& operator=(char c);
        Board& operator=(const Board&);
        /* Get */
        const int size();
};