#pragma once
#include <iostream>
#include "IllegalCoordinateException.hpp"
#include "IllegalCharException.hpp"
#include "GameBoard.hpp"
using namespace std;

class Board{
    private:
        GameBoard* game;
    public:
    /* Constructor */
    Board(int);
    Board(const Board&);
    /* Destructor */
    ~Board();
    /* IOstream */
    friend ostream& operator<<(ostream&, Board const&);
    /* Subscript */
    GameBoard& operator[](Pair);
    /* Assignment */
    Board& operator=(char c);
    Board& operator=(const Board&);
};