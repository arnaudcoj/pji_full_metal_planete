#include "player.h"

Player::Player()
    : m_action_points(100)
{
}

int Player::getActionPoints()
{
    return m_action_points;
}

bool Player::useActionPoints(int points)
{
    if(points < 0)
        return false;
    if(m_action_points - points < 0)
        return false;
    m_action_points -= points;
    return true;
}

bool Player::move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell, Tide tide)
{
    assert(cell != nullptr);

    if(cell->isOccupied() || !cell->isPracticable(piece, tide) ||
        (piece->getCell() != nullptr && !piece->getCell()->isPracticable(piece, tide))) {
        return false;
    }

    cell->setPiece(piece);

    if(piece->isOnCell())
        piece->getCell()->removePiece();

    piece->setCell(cell);

    return true;
}

bool Player::removePiece(std::shared_ptr<Piece> piece)
{
    if(!piece->isOnCell()) {
        return false;
    }

    piece->getCell()->removePiece();
    piece->removeCell();

    return false;
}

std::list<std::shared_ptr<Cell> > Player::getAccessibleCells(Hexagrid& grid, Tide tide, std::shared_ptr<Piece> piece)
{
    std::vector<std::vector<bool> > alreadyVisited(grid.getWidth());
    for(int i = 0; i < grid.getWidth(); i++) {
        alreadyVisited[i] = std::vector<bool>(grid.getHeight(), false);
    }
    
    std::list<std::shared_ptr<Cell> > cells;
    
    return getAccessibleCells_rec(
        grid, tide, piece, cells, piece->getCell(), alreadyVisited, m_action_points);
}

std::list<std::shared_ptr<Cell> > Player::getAccessibleCells_rec(Hexagrid& grid,
    Tide tide,
    std::shared_ptr<Piece> piece,
    std::list<std::shared_ptr<Cell> >& cells,
    std::shared_ptr<Cell> currentCell,
    std::vector<std::vector<bool> > alreadyVisited,
    int actionPoints)
{
    if(actionPoints > 0) {
        for(std::shared_ptr<Cell> neighbour : grid.getDirectNeighbours(currentCell)) {
            sf::Vector2i coord = neighbour->getCoord();
            if(neighbour->isPracticable(piece, tide) && !alreadyVisited[coord.x][coord.y]) {
                alreadyVisited[coord.x][coord.y] = true;
                cells.push_back(neighbour);
                getAccessibleCells_rec(grid, tide, piece, cells, neighbour, alreadyVisited, actionPoints -1);
            }
        }
    }

    return cells;
}

/*
std::list<std::shared_ptr<Cell> > Player::getAccessibleCells(Hexagrid& grid, Tide tide, std::shared_ptr<Piece> piece)
{
  std::list<std::shared_ptr<Cell> > list = grid.getCellsInRange(piece->getCell(), m_action_points);

  list.remove_if([&](std::shared_ptr<Cell> cell) -> bool { return !cell->isPracticable(piece, tide);  });

  return list;
  }
*/