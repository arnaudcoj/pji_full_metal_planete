#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <iostream>

class Hexagrid {

  bool **mgrid;
  int mwidth;
  int mheight;

 public:
  
  Hexagrid(int width = 10, int height = 10);
  void printAdjacents(int x, int y);
  void printCell(int x, int y);
  void toString();
  void toStringCoord();  
  
};

int main (void);

#endif //HEXAGRID_H
