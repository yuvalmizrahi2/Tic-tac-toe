#pragma once
#include "Pair.hpp"
#include <iostream>
#include "IllegalCharException.hpp"
using namespace std;

class GameBoard{
    public:
        int num;
        char** gameboard;
        Pair* index;
        GameBoard(int);
        GameBoard(const GameBoard&);
        ~GameBoard();
        GameBoard& operator=(char c);
};