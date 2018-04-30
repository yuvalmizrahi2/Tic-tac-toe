#include "Board.hpp"
/* Constructor */
Board::Board(int number)
{
    game = new GameBoard(number);
}
Board::Board(const Board& b)
{
    game = new GameBoard(*b.game);
}
/* Destructor */
Board::~Board()
{
    delete game;
}
/* IOstream */
ostream& operator<<(ostream& os, Board const& obj)
{
    for(int i = 0 ; i < obj.game->num; i++)
    {
        for(int j = 0; j < obj.game->num; j++)
        {
            os << obj.game->gameboard[i][j];
        }
        os << "\n";
    }
    return os;
}
/* Subscript */
GameBoard& Board::operator[](Pair pair)
{
    if (pair.x >= game->num || pair.x < 0 || pair.y >= game->num || pair.y < 0)
        throw IllegalCoordinateException(pair);
    game->index = new Pair();
    game->index->x = pair.x;
    game->index->y = pair.y;
    return *game;
}
/* Assignment */
Board& Board::operator=(char c)
{
    if(c == '.')
    {
        for(int i = 0 ; i < game->num; i++)
        {
            for(int j = 0; j < game->num; j++)
            {
                game->gameboard[i][j] = '.';
            }
        }
    }
    else
        throw IllegalCharException(c);
    return *this;
}
Board& Board::operator=(const Board& c)
{
    for(int i = 0 ; i < c.game->num; i++)
    {
       for(int j = 0; j < c.game->num; j++)
        {
            game->gameboard[i][j] = c.game->gameboard[i][j];
        }
    }
    return *this;
}