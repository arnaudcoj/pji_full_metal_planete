#include "plaincell.h"

PlainCell::PlainCell() : Cell() { }

PlainCell::PlainCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) { }

PlainCell::PlainCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) { }


bool PlainCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->getEngine().isTerrestrial();
}
