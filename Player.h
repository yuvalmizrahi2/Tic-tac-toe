#pragma once
#include "Coordinate.hpp"
#include "Board.h"

class Player{
    public:
        char myChar;
        virtual const string name() const{return "";}
        virtual const Coordinate play(const Board& board){return{0,0};}
        char getChar() const {return myChar;}
};