#include "Board.h"
/* Constructor */
Board::Board() : rowcolumn(0)
{
    board = NULL;
}
Board::Board(int number) : rowcolumn(number)
{
    board = new Cell*[rowcolumn];
    for(int i = 0 ; i < rowcolumn ; i++)
    {
        board[i] = new Cell[rowcolumn];
    }
}
Board::Board(const Board& b)
{
    rowcolumn = b.rowcolumn;
    board = new Cell*[rowcolumn];
    for(int i = 0 ; i < rowcolumn ; i++)
    {
        board[i] = new Cell[rowcolumn];
        for(int j = 0; j < rowcolumn; j++)
        {
            board[i][j] = b.board[i][j];
        }
    }
}
/* Destructor */
Board::~Board()
{
    for(int i = 0 ; i < rowcolumn ; i++)
        delete[] board[i];
    delete[] board;
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
istream& operator>>(istream& input, Board& obj)
{
    string line;
    cin >> line;
    obj.rowcolumn = line.size();
    obj.board= new Cell*[obj.rowcolumn];
    for(int i = 0 ; i < obj.rowcolumn ; i++)
    {
        obj.board[i] = new Cell[obj.rowcolumn];
        for(int j = 0; j < obj.rowcolumn; j++)
        {
            obj.board[i][j] = line[j];
        }
        if(i != obj.rowcolumn-1)
            cin >> line;
    }
    return input;
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
        Cell temp(c);
        for(int i = 0 ; i < rowcolumn; i++)
        {
            for(int j = 0; j < rowcolumn; j++)
            {
                board[i][j] = temp; 
            }
        }
    }
    else
        throw IllegalCharException(c);
    return *this;
}
Board& Board::operator=(const Board& c)
{
    this->~Board();
    rowcolumn = c.rowcolumn;
    board = new Cell*[rowcolumn];
    for(int i = 0 ; i < rowcolumn ; i++)
    {
        board[i] = new Cell[rowcolumn];
        for(int j = 0; j < rowcolumn; j++)
        {
            board[i][j] = c.board[i][j];
        }
    }
    return *this;
}
/* Get */
int Board::size() const
{
    return rowcolumn;
}
/* Drow */
string Board::draw(int sizearr)
{
    int numfile = 0;
    while(true)
    {
        ifstream f(to_string(numfile)+".ppm");
            if(!f.good())
                break;
            else
                numfile++;
    }
    namefile = to_string(numfile)+".ppm";
    const int size = sizearr;
    ofstream imageFile(namefile, ios::out | ios::binary);
    imageFile << "P6" << endl << size <<" " << size << endl << 255 << endl;
    RGB** image;
    image = new RGB*[size];
    for(int i = 0 ; i < size ; i++)
    {
        image[i] = new RGB[size];
        for (int j = 0; j < size; ++j)  {
            image[i][j].red = 255;
            image[i][j].green =255;
            image[i][j].blue =255;
        }
    }
    drawboard(image , size);
    for(int k = 0 ; k < rowcolumn ; k++)
    {
        for(int j = 0; j < rowcolumn ; j++)
        {
            if(board[k][j].cell == 'X')
            {
                drawX(image , size , k , j);
            }
            else if(board[k][j].cell == 'O')
            {
                drawO(image , size , k , j);
            }
        }
    }
    for(int i = 0 ; i < size ; i++)
    {
        for (int j = 0; j < size; ++j)  {
            imageFile.write(reinterpret_cast<char*>(&image[i][j]),3);
        }
    }
    imageFile.close();
    for(int i = 0 ; i < size ; i++)
        delete[] image[i];
    delete[] image;
    return namefile;
}
void Board::drawboard(RGB** image , int size)
{
    int cell = (size - 20*(rowcolumn-1))/rowcolumn;
    for (int i = 0; i < size; ++i){
        for(int k = 1 ; k <= rowcolumn ; k++){
            for (int j = cell*k+20*(k-1); j < cell*k+20*k && j < size; ++j){
                    image[j][i].red = 0;
                    image[j][i].green = 0;
                    image[j][i].blue = 0;
                    image[i][j].red = 0;
                    image[i][j].green = 0;
                    image[i][j].blue = 0;
            }
        }
    }
}
void Board::drawX(RGB** image , int size , int k , int j)
{
    int cell = (size - 20*(rowcolumn-1))/rowcolumn;
    for (int i = 0; i < cell; ++i)  
    {
        image[(cell+20)*k + i][(cell+20)*j + i].red = 255;
        image[(cell+20)*k + i][(cell+20)*j + i].green =0;
        image[(cell+20)*k + i][(cell+20)*j + i].blue =0;
        image[(cell+20)*k +cell-1-i][(cell+20)*j + i].red = 255;
        image[(cell+20)*k +cell-1-i][(cell+20)*j + i].green =0;
        image[(cell+20)*k +cell-1-i][(cell+20)*j + i].blue =0;
    }
}
void Board::drawO(RGB** image , int size , int k , int j)
{
    int cell = (size - 20*(rowcolumn-1))/rowcolumn;
    int r = cell/2 , x_centre = (cell+20)*k+r , y_centre = (cell+20)*j+r;
    int x = r, y = 0;
    image[x + x_centre][y + y_centre].red = 255;
    image[x + x_centre][y + y_centre].green = 0;
    image[x + x_centre][y + y_centre].blue = 0;
    if (r > 0)
    {
        image[x + x_centre][-y + y_centre].red = 255;
        image[x + x_centre][-y + y_centre].green = 0;
        image[x + x_centre][-y + y_centre].blue = 0;
        image[y + x_centre][x + y_centre].red = 255;
        image[y + x_centre][x + y_centre].green = 0;
        image[y + x_centre][x + y_centre].blue = 0;
        image[-y + x_centre][x + y_centre].red = 255;
        image[-y + x_centre][x + y_centre].green = 0;
        image[-y + x_centre][x + y_centre].blue = 0;
    }
    int P = 1 - r;
    while (x > y)
    {
        y++;
        if (P <= 0)
            P = P + 2*y + 1;
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }
        if (x < y)
            break;
        image[x + x_centre][y + y_centre].red = 255;
        image[x + x_centre][y + y_centre].green = 0;
        image[x + x_centre][y + y_centre].blue = 0;
        image[-x + x_centre][y + y_centre].red = 255;
        image[-x + x_centre][y + y_centre].green = 0;
        image[-x + x_centre][y + y_centre].blue = 0;
        image[x + x_centre][-y + y_centre].red = 255;
        image[x + x_centre][-y + y_centre].green = 0;
        image[x + x_centre][-y + y_centre].blue = 0;
        image[-x + x_centre][-y + y_centre].red = 255;
        image[-x + x_centre][-y + y_centre].green = 0;
        image[-x + x_centre][-y + y_centre].blue = 0;
        if (x != y)
        {
            image[y + x_centre][x + y_centre].red = 255;
            image[y + x_centre][x + y_centre].green = 0;
            image[y + x_centre][x + y_centre].blue = 0;
            image[-y + x_centre][x + y_centre].red = 255;
            image[-y + x_centre][x + y_centre].green = 0;
            image[-y + x_centre][x + y_centre].blue = 0;
            image[y + x_centre][-x + y_centre].red = 255;
            image[y + x_centre][-x + y_centre].green = 0;
            image[y + x_centre][-x + y_centre].blue = 0;
            image[-y + x_centre][-x + y_centre].red = 255;
            image[-y + x_centre][-x + y_centre].green = 0;
            image[-y + x_centre][-x + y_centre].blue = 0;
        }
    }
}
