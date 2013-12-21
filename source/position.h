#ifndef POSITION_H
#define POSITION_H

class Position
{
 public:
  // if not initiated (0,0)
 Position(int x = 0, int y = 0) : m_x(x), m_y(y)
  {}
  ~Position();

  /*
    may need some operators for addition and substraction
   */

 private:
  // m stands for member
  int m_x;
  int m_y;

};

#endif
