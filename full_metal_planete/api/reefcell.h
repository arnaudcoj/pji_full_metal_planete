#ifndef REEFCELL_H
#define REEFCELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <cassert>
#include "piece.h"
#include "gamestate.h"
#include "cell.h"

class ReefCell : public Cell
{
public:
    ReefCell();
    ReefCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    ReefCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece, Tide tide);
};

#endif // REEFCELL_H
