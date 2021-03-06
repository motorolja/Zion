#ifndef TILE_H
#define TILE_H

#include "position.h"
#include "direction.h"
#include <vector>
#include <utility>

class Tile
{
 public:
  Tile(bool door = false, eDirection dir = none);
  ~Tile();

  void addDoor(eDirection); // adds a door in the direction if it does not exits
  bool openDoor(eDirection) const; // true if there is a open door
  void interactDoor(eDirection); // if there is a door, close or open it

 private:
  bool m_door;
  std::vector< std::pair<eDirection,bool> > m_directions;
};

#endif

