#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <iostream>
#include <SFML/System/Vector2.hpp>

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
  sf::Vector2i getTopCellCoord(int x, int y);
  sf::Vector2i getBottomCellCoord(int x, int y);
};


#endif //HEXAGRID_H
