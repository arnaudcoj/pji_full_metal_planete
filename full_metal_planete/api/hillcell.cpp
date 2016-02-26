#include "hillcell.h"

HillCell::HillCell() : Cell() { }

HillCell::HillCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) { }

HillCell::HillCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) { }


bool HillCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->isTerrestrial();
}
