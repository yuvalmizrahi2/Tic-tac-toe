#pragma once

#include "Board.h"
#include <iostream>
#include "Player.h"

class TicTacToe {
public:
    /* Variable */
    int size;
    Board* game;
    Player* win;
	/* Constructor */
        TicTacToe(int);
    /* Destructor */
        ~TicTacToe();
    /* Functions */
        Board board() const;
        Player& winner() const;
        void play(Player&, Player&);
        bool checkwin(Coordinate , Board&);
};
