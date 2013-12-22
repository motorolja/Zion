#ifndef TILE_H
#define TILE_H

#include "position.h"
#include "direction.h"
#include <vector>

class Tile
{
 public:
  Tile(Position pos = {0,0}, bool door = false, eDirection dir = none);
  ~Tile();

  void addDoor(eDirection); // adds a door in the direction if it does not exits
  bool openDoor(eDirection) const; // true if there is a open door
  void interactDoor(eDirection); // if there is a door, close or open it

 private:
  Position m_pos;
  bool m_door;
  bool m_open;
  std::vector<eDirection> m_directions;
};

#endif
