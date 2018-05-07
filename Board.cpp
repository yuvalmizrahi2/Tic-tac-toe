#include "Board.h"
/* Constructor */
Board::Board(int number)
{
    rowcolumn = number;
    Cell** temp = new Cell*[rowcolumn];
    for(int i = 0 ; i < rowcolumn ; i++)
    {
        temp[i] = new Cell[rowcolumn];
    }
    board = temp;
}
Board::Board(const Board& b)
{
    rowcolumn = b.rowcolumn;
    Cell** temp = new Cell*[rowcolumn];
    for(int i = 0 ; i < rowcolumn ; i++)
    {
        temp[i] = new Cell[rowcolumn];
        for(int j = 0; j < rowcolumn; j++)
        {
            temp[i][j] = b.board[i][j];
        }
    }
    board = temp;
}
/* Destructor */
Board::~Board()
{
    for(int i = 0 ; i < rowcolumn ; i++)
        delete board[i];
    delete board;
}
/* IOstream */
ostream& operator<<(ostream& os, Board const& obj)
{
    for(int i = 0 ; i < obj.rowcolumn; i++)
    {
        for(int j = 0; j < obj.rowcolumn; j++)
        {
            os << obj.board[i][j];
        }
        os << "\n";
    }
    return os;
}
/* Subscript */
Cell& Board::operator[](Coordinate pair)
{
    if (pair.x >= rowcolumn || pair.x < 0 || pair.y >= rowcolumn || pair.y < 0)
        throw IllegalCoordinateException(pair);
    return board[pair.x][pair.y];
}
Cell Board::operator[](Coordinate pair) const
{
    if (pair.x >= rowcolumn || pair.x < 0 || pair.y >= rowcolumn || pair.y < 0)
        throw IllegalCoordinateException(pair);
    return board[pair.x][pair.y];
}
/* Assignment */
Board& Board::operator=(char c)
{
    if(c == '.')
    {
        for(int i = 0 ; i < rowcolumn; i++)
        {
            for(int j = 0; j < rowcolumn; j++)
            {
                board[i][j].cell = '.'; 
            }
        }
    }
    else
        throw IllegalCharException(c);
    return *this;
}
Board& Board::operator=(const Board& c)
{
    rowcolumn = c.rowcolumn;
    Cell** temp = new Cell*[rowcolumn];
    for(int i = 0 ; i < rowcolumn ; i++)
    {
        temp[i] = new Cell[rowcolumn];
        for(int j = 0; j < rowcolumn; j++)
        {
            temp[i][j] = c.board[i][j];
        }
    }
    for(int i = 0 ; i < rowcolumn ; i++)
        delete board[i];
    delete board;
    board = temp;
    return *this;
}
/* Get */
const int Board::size()
{
    return rowcolumn;
}