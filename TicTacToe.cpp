#include "TicTacToe.h"

TicTacToe::TicTacToe(int num)
{
    game = new Board(num);
    size = num;
}
TicTacToe::~TicTacToe()
{
    delete game;
}
Board TicTacToe::board() const
{
    return *game;
}
Player& TicTacToe::winner() const
{
    return *win;
}
void TicTacToe::play(Player& xPlayer, Player& oPlayer)
{
    *game = '.';
    xPlayer.myChar = 'X';
    oPlayer.myChar = 'O';
    int i =0;
    Coordinate temp;
    win = &oPlayer;
    while(i < size*size)
    {
        try{
        temp = xPlayer.play(*game);
        }
        catch(...)
        {
            win = &oPlayer;
            break;
        }
        if((*game)[temp] != '.')
        {
            win = &oPlayer;
            break;
        }
        (*game)[temp] = 'X';
        if(checkwin(temp,(*game)))
        {
            win = &xPlayer;
            break;
        }
        i++;
        if(i != size*size)
        {
            try{
            temp = oPlayer.play(*game);
            }
            catch(...)
            {
                win = &xPlayer;
                break;
            }
            if((*game)[temp] != '.')
            {
                win = &xPlayer;
                break;
            }
            (*game)[temp] = 'O';
            if(checkwin(temp,(*game)))
            {
                win = &oPlayer;
                break;
            }
            i++;
        }
    }
}
bool TicTacToe::checkwin(Coordinate cor ,Board& game)
{
    char symbole = game[cor];
    for(int i = 0; i < size ; i++)
    {
        if(game[{cor.x,i}] != symbole)
            break;
        else if(i == size - 1)
            return true;
    }
    for(int i = 0; i < size ; i++)
    {
        if(game[{i,cor.y}] != symbole)
            break;
        else if(i == size - 1)
            return true;
    }
    for(int i = 0; i < size ; i++)
    {
        if(game[{i,i}] != symbole)
            break;
        else if(i == size - 1)
            return true;
    }
    for(int i = 0; i < size ; i++)
    {
        if(game[{i,size-i-1}] != symbole)
            break;
        if(i == size - 1)
            return true;
    }
    return false;
}