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
private:
    std::string m_type = "reef";

public:
    ReefCell();
    ReefCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    ReefCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece);
    virtual std::string getType();
};

#endif // REEFCELL_H
