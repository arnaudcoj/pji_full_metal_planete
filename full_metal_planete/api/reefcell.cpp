#include "reefcell.h"

ReefCell::ReefCell() : Cell() { }

ReefCell::ReefCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) { }

ReefCell::ReefCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) { }


bool ReefCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide tide) {
    switch(tide) {
    case Tide::LOW_TIDE:
        return piece->getEngine().isTerrestrial();
    case Tide::MEDIUM_TIDE:
        return piece->getEngine().isMarine();
    case Tide::HIGH_TIDE:
        return piece->getEngine().isMarine();
    }
    return false;
}

std::string ReefCell::getType() {
    return m_type;
}
