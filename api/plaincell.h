#ifndef PLAINCELL_H
#define PLAINCELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <cassert>
#include "piece.h"
#include "gamestate.h"
#include "cell.h"

class PlainCell : public Cell
{  
private:
    std::string m_type = "plain";

public:
    PlainCell();
    PlainCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    PlainCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece);
    virtual std::string getType();
};

#endif // PLAINCELL_H
