#include "Cell.hpp"
/* Constructor */
Cell::Cell(char c)
{
    cell = c;
}
Cell::Cell()
{
    cell = '.';
}
/* IOstream */
ostream& operator<<(ostream& os, Cell const& obj)
{
    os << obj.cell;
    return os;
}
/* Assignment */
Cell& Cell::operator=(char c)
{
    if(c != 'X' && c != 'O')
        throw IllegalCharException(c);
    cell = c;
    return *this;
}
Cell& Cell::operator=(const Cell& c)
{
    cell = c.cell;
    return *this;
}
bool operator==(const Cell c1 , const char c2)
{
    return c1.cell == c2;
}
Cell::operator char()
{
    return cell;
}