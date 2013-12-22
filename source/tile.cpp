#include "tile.h"
#include <algorithm>

Tile::Tile(Position pos, bool door, eDirection dir)
  : m_pos(pos), m_door(door), m_direction(dir)
{
  m_open = false;
}

Tile::~Tile()
{

}

void Tile::addDoor(eDirection dir)
{
  if( std::find(m_directions.cbegin(), m_directions.cend(), dir ) == std::vector::end() )
    m_directions.push_back(dir);
}

bool Tile::openDoor(eDirection dir) const
{
  if( dir != none && dir == m_direction )
    return m_open;
  return false;
}

void Tile::interactDoor(eDirection dir)
{
  if( dir != none && dir == m_direction )
    m_open = !m_open;
}
