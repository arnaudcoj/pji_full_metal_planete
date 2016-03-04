#include "mountaincell.h"

MountainCell::MountainCell() : Cell() { }

MountainCell::MountainCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) { }

MountainCell::MountainCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) { }


bool MountainCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->getEngine().canClimb();
}

int MountainCell::getRangeBonus() {
    return 1;
}
