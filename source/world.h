#ifndef WORLD_H
#define WORLD_H

#include <map>
#include "position.h"
#include "room.h"

class World
{
 public:
  World( std::string& world_name, std::string& world_description, Position pos = {0,0});
  ~World();

  Position startInWorld() const; // returns the start position in map
  std::map<Position, Room> getWorld() const; // returns the world
  std::string getName() const; // gets world_name
  std::string getDescription() const; // gets world_description

  bool addRoom(std::string&, std::string&, Position); // adds a room
  bool removeRoom(Position); // removes based on pos
  bool removeRoom(std::string&); // removes based on room_name

 private:
  std::map<Position, Room> m_game_world;
  std::string m_world_name;
  std::string m_world_description;
  Position m_start_pos;
}

#endif
