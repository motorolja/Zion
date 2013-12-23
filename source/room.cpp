#include "Room.h"

Room::Room(std::string& name, std::string description)
  : m_name(name), m_description(description)
{
  // maybe initiate a tile with pos (0,0)
  tile t(pos); // is (0,0) if not initiated with any values 
  m_tiles.push_back(t);
}

Room::~Room()
{}

std::string Room::getName() const
{
  return m_name;
}

std::string Room::getDescription() const
{
  return m_description;
}

bool Room::addTile(Position pos)
{
  if( m_tiles.find(pos) == std::map::end() )
    {
      m_tiles[pos];
      return true;
    }
  return false;
}

bool Room::removeTile(Position pos)
{
  if( m_tiles.find(pos) != std::map::end() )
    {
      m_tiles.erase(pos);
      return true;
    }
  return false;
}

void Room::clearRoom()
{
  m_tiles.clear();
}

std::map<Position,Tile> Room::getTiles() const
{
  return m_tiles;
}

bool Room::empty()
{
  return m_tiles.empty();
}
