#ifndef PLAYER_H
#define PLAYER_H

#include "status.h"
#include "item.h"
#include "position.h"
#include "inventory.h"
#include <vector>

class Player
{
 public:
  Player(int health = 100, Position pos);
  ~Player();

  void setHealth(int&); // sets the player health to a given value
  void addHealth(int&); // adds the given health to the total player health
  int getHealth() const; // returns the players health
  
  void addStatus(Status); // adds a status to the player
  std::vector<Status> getStatuses() const; // returns all statuses
  void removeStatus(Status); // removes the given status
  void clearStatuses(); // removes all statuses

  void setPosition(Position); // sets the position of the player in the current room
  Position getPosition() const; // returns the player position
  
  void addItem(Item*); // adds a item to the inventory
  std::vector<Item*> getInventory() const; // returns the inventory
  void clearInventory(); // empties the inventory

 private:
  int m_health;
  Position m_position;
  std::vector<Status> m_statuses;
  std::vector<Item*> m_inventory;
};

#endif
