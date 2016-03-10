#include "swampcell.h"

SwampCell::SwampCell() : Cell() { }

SwampCell::SwampCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) { }

SwampCell::SwampCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) { }


bool SwampCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide tide) {
    switch(tide) {
    case Tide::LOW_TIDE:
        return piece->isTerrestrial();
    case Tide::MEDIUM_TIDE:
        return piece->isTerrestrial();
    case Tide::HIGH_TIDE:
        return piece->isMarine();
    }
    return false;
}

std::string SwampCell::getType() {
    return m_type;
}