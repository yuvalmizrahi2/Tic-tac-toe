#pragma once
#include <iostream>
#include "IllegalCoordinateException.hpp"
#include "IllegalCharException.hpp"
#include "Cell.hpp"
#include <fstream>
#include "Rgb.hpp"
using namespace std;

class Board{
    private:
        /* Variable */
        Cell** board;
        int rowcolumn;
    public:
        string namefile;
        /* Constructor */
        Board();
        Board(int);
        Board(const Board&);
        /* Destructor */
        ~Board();
        /* IOstream */
        friend ostream& operator<<(ostream&, Board const&);
        friend istream& operator>>(istream& input, Board&);
        /* Subscript */
        Cell& operator[](Coordinate);
        Cell operator[](Coordinate) const;
        /* Assignment */
        Board& operator=(char c);
        Board& operator=(const Board&);
        /* Get */
        int size() const;
        /* Drow */
        void draw(int);
        void drawboard(RGB** , int);
        void drawX(RGB** , int , int , int);
        void drawO(RGB** , int , int , int);
};