#ifndef HILLCELL_H
#define HILLCELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <cassert>
#include "piece.h"
#include "gamestate.h"
#include "cell.h"

class HillCell : public Cell
{
public:
    HillCell();
    HillCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    HillCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece, GameState);
};

#endif // HILLCELL_H
