#ifndef POSITION_H
#define POSITION_H

class Position
{
 public:
  // if not initiated (0,0)
  Position(int _x = 0, int _y = 0);
  ~Position();
 
  Position operator+(Position&); // addition of Position from Position
  Position operator-(Position&); // subtraction of Position from Position
  
  // comperation operators
  bool operator==(const Position&) const;
  bool operator< (const Position&) const;
  bool operator> (const Position&) const;
  
  // public members
  int x; 
  int y;
};

#endif
