#include "GameBoard.hpp"

GameBoard::GameBoard(int number)
{
    num = number;
    char** temp = new char*[num];
    for(int i = 0 ; i < num ; i++)
    {
        temp[i] = new char[num];
        for(int j = 0; j < num; j++)
            temp[i][j] = '.';
    }
    gameboard = temp;
}
GameBoard::GameBoard(const GameBoard& g)
{
    num = g.num;
    char** temp = new char*[num];
    for(int i = 0 ; i < num ; i++)
    {
        temp[i] = new char[num];
        for(int j = 0; j < num; j++)
            temp[i][j] = g.gameboard[i][j];
    }
    gameboard = temp;
}
GameBoard::~GameBoard()
{
    for(int i = 0; i < num; ++i)
    {
        delete [] gameboard[i];
    }
    delete [] gameboard;
    if(index != nullptr)
        delete index;
}
GameBoard& GameBoard::operator=(char c)
{
    if(c != 'X' && c != 'O')
        throw IllegalCharException(c);
    gameboard[index->x][index->y] = c;
    return *this;
}