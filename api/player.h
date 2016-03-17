#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <cassert>
#include <SFML/System/Vector2.hpp>
#include "hexagrid.h"
#include "piece.h"
#include "cell.h"
#include "tide.h"

class Player
{
  int m_action_points;

  public:
  Player();
  int getActionPoints();
  bool useActionPoints(int points = 1);
  bool move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell, Tide tide);
  bool removePiece(std::shared_ptr<Piece> piece);

  std::list<std::shared_ptr<Cell> > getAccessibleCells(Hexagrid& grid, Tide tide, std::shared_ptr<Piece> piece);

  private:
  std::list<std::shared_ptr<Cell> > getAccessibleCells_rec(Hexagrid& grid,
      Tide tide,
      std::shared_ptr<Piece> piece,
      std::list<std::shared_ptr<Cell> >& cells,
      std::shared_ptr<Cell> currentCell,
      std::vector<std::vector<bool> > alreadyVisited,
      int actionPoints);
};

#endif // PLAYER_H
