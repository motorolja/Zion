#include "Room.h"

Room::Room(std::string& name, std::string description)
  : m_name(name), m_description(description)
{
  // maybe initiate a tile with pos (0,0)
  Position pos; // is (0,0) if not initiated with any values 
  m_tiles.push_back(pos);
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
  return true;
}

bool Room::removeTile(Position pos)
{
  return true;
}

void Room::clearRoom()
{
  m_tiles.clear();
}

std::vector<Tile> Room::getTiles() const
{
  return m_tiles;
}

bool Room::empty()
{
  return m_tiles.empty();
}
