#include "reefcell.h"

ReefCell::ReefCell() : Cell() { }

ReefCell::ReefCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) { }

ReefCell::ReefCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) { }


bool ReefCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide tide) {
    switch(tide) {
    case Tide::LOW_TIDE:
        return piece->isTerrestrial();
    case Tide::MEDIUM_TIDE:
        return piece->isMarine();
    case Tide::HIGH_TIDE:
        return piece->isMarine();
    }
    return false;
}
