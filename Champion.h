#pragma once
#include "Coordinate.hpp"
#include "Player.hpp"
#include "Board.h"

class Champion: public Player {
public:
	bool reverse = false;
	const string name() const override { return "Yuval Mizrahi"; }
	const Coordinate play(const Board& board) override;
};