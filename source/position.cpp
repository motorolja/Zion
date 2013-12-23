#include "position.h"

Position::Position(int _x, int _y): x(_x), y(_y)
{}

Position::~Position()
{}

Position Position::operator+(Position& pos)
{
  Position temp;
  temp.x = x + pos.x;
  temp.y = y + pos.y;
  return temp;
}

Position Position::operator-(Position& pos)
{
  Position temp;
  temp.x = x - pos.x;
  temp.y = y - pos.y;
  return temp;
}

bool Position::operator==(const Position& pos) const
{
  if( pos.x == x && pos.y == y )
    return true;
  return false;
}

bool Position::operator<(const Position& pos) const
{
  if( pos.x < x || ( pos.x == x && pos.y < y ) ) 
    return true;
  return false;
}

bool Position::operator>(const Position& pos) const
{
  if( pos.x > x || ( pos.x == x && pos.y > y ) )
    return true;
  return false;
}
