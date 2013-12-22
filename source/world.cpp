#include "world.h"

World::World( std::string& world_name, std::string& world_description, Position pos)
  : m_world_name(world_name), m_world_description(world_description), m_start_pos(pos)
{

}

World::~World()
{

}

Position World::startInWorld() const
{
  return m_start_pos;
}

std::string World::getName() const
{
  return m_world_name;
}

std::string World::getDescription() const
{
  return m_world_description;
}

bool World::addRoom(std::string& name, std::string& description, Position pos)
{
  if( m_game_world.find(pos) != m_game_world.end() )
    {
      Room r(name,description);
      m_game_world[pos,r];
      return true;
    }
  return false;
}

bool World::removeRoom(Position pos)
{
  if( m_game_world.find(pos) != m_game_world.end() )
    {
      m_game_world.erase(pos);
      return true;
    }
  return false;
}

bool World::removeRoom(std::string& name)
{
  for( auto i = m_game_world.begin(), i != m_game_world.end(), ++i)
    {
      if( m_game_world.at(i) == name)
	{
	  m_game_world.erase(i);
	  return true;
	}
    }
  return false;
}
