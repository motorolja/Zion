#ifndef ROOM_H
#define ROOM_H

#include "position.h"
#include "tile.h"
#include <vector>

class Room
{
 public:
  explicit Room(std::string&,std::string&);
  Room() = delete; // no default constructor
  ~Room();

  //functions
  std::string getName() const; // returns the roomname
  std::string getDescription() const; // returns the description

  bool addTile(Position); // adds a tile in the room if true
  bool removeTile(Position); // removes a tile in the room if true
  void clearRoom(); // empties the room
  std::vector<Tile> getTiles() const; // returns all the tiles
  bool empty(); // returns true if the room has no tiles


 private:
  std::string m_name;
  std::string m_description;
  std::vector<Tile> m_tiles;
};

#endif
