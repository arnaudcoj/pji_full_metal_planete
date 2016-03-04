#ifndef MOUNTAINCELL_H
#define MOUNTAINCELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <cassert>
#include "piece.h"
#include "gamestate.h"
#include "cell.h"

class MountainCell : public Cell
{
public:
    MountainCell();
    MountainCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    MountainCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece, Tide);
    virtual int getRangeBonus();
};

#endif // MOUNTAINCELL_H
