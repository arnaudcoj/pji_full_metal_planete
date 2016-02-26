#ifndef SEACELL_H
#define SEACELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <cassert>
#include "piece.h"
#include "gamestate.h"
#include "cell.h"

class SeaCell: public Cell
{
public:
    SeaCell();
    SeaCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    SeaCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece, Tide);
};

#endif // SEACELL_H
