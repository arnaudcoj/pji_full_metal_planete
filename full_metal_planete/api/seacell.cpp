#include "seacell.h"

SeaCell::SeaCell() : Cell() { }

SeaCell::SeaCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) { }

SeaCell::SeaCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) { }

bool SeaCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->getEngine().isMarine();
}

std::string SeaCell::getType() {
    return m_type;
}
