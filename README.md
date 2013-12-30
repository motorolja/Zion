Zion
====
Class diagram ( not finished )

  Zion:
    Engine:
      Player
        Position:
        Item:
          Property:
        Status:
      World:
        Position:
        Room:
          Position:
          Tile:
            Position:
            Item:
              Property:
    Input:
    Output:
  
Module description ( not finished )
  
  Zion:
    The main module that is in charge of running the program through the use of Engine, Input and Output.
  
  Engine:
    Handles the game physics by using Player and World.
  
  Player:
    Includes the player and the inventory with the players health, position and status
  
    Status:
  
  Item:
    Contains a container with properties, name, description and a bool if it is stackable or not.
    
  World:
    Contains a map<Position,Room>, name, description and functions to create and remove rooms.
    
  Room:
    A room in the world, contains a map<Position, Tile>, name, description and functions to add and remove tiles.
    
  Tile
    A Tile in the room, contains a container with a pair<eDirection,bool> where the bool tells if the door in that direction is open.
  
  Input:
  Output:
  
Other data-types

  Position:
    Contains x- and y-coordinates. Also operators that makes it easier for other modules to handle it.
    
  Property:
    An enumeration of diffrent properties
    
  Status:
    An enumeration of diffrent statuses
