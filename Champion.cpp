#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
	if(reverse)
    {
        for (int x=board.size() - 1; x>=0; --x)
        {
            Coordinate c{x,board.size()-x - 1};
            if (board[c]=='.') {
                reverse = !reverse;
				return c;
			}
        }
    }
    else
    {
        for (int x=0; x<board.size(); ++x)
        {
            Coordinate c{x,board.size()-x-1};
            if (board[c]=='.') {
                reverse = !reverse;
				return c;
			}
        }
    }
	return {0,0};
}