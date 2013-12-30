#include "tile.h"
#include <algorithm>

Tile::Tile(bool door, eDirection dir)
  : m_door(door), m_direction(dir)
{
}

void Tile::addDoor(eDirection dir)
{
  if(!m_door)
    m_door == true;

  if( std::find(m_directions.cbegin(), m_directions.cend(), dir ) == std::vector::end() )
    m_directions.push_back( std::make_pair(dir,false) );
}

bool Tile::openDoor(eDirection dir) const
{
  for( int i = 0; i < m_directions.size(); ++i )
    {
      if( dir != none && dir == m_directions.at(i).first )
	return m_directions.at(i).second;
    }  
  return false;
}

void Tile::interactDoor(eDirection dir)
{
  for( int i = 0; i < m_directions.size(); ++i )
    {
      if( dir != none && dir == m_directions.at(i).first )
	m_directions.at(i).second != m_directions.at(i).second;
    }
}
