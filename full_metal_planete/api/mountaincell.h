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
private:
    std::string m_type = "mountain";

public:
    MountainCell();
    MountainCell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    MountainCell(int x, int y, bool halfCell = false, unsigned int area = 0);
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece, Tide);
<<<<<<< HEAD
    virtual std::string getType();
=======
    virtual int getRangeBonus();
>>>>>>> 58567d508f0aef1a67a1884e10627bd86dc81651
};

#endif // MOUNTAINCELL_H
