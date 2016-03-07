#ifndef SWAMPCELL_H
#define SWAMPCELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <cassert>
#include "piece.h"
#include "gamestate.h"
#include "cell.h"

class SwampCell : public Cell
{
private:
    std::string m_type = "swamp";

public:
    SwampCell();
    SwampCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    SwampCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece, Tide tide);
    virtual std::string getType();
};

#endif // SWAMPCELL_H
