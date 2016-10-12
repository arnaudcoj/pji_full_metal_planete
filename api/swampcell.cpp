#include "swampcell.h"

SwampCell::SwampCell()
    : Cell()
{
}

SwampCell::SwampCell(sf::Vector2i coord, bool halfCell, unsigned int area)
    : Cell(coord, halfCell, area)
{
}

SwampCell::SwampCell(int x, int y, bool halfCell, unsigned int area)
    : Cell(x, y, halfCell, area)
{
}

bool SwampCell::isPracticableCurrent(std::shared_ptr<Piece> piece)
{
    switch(m_tide) {
    case Tide::LOW_TIDE:
        return piece->getEngine().isTerrestrial();
    case Tide::MEDIUM_TIDE:
        return piece->getEngine().isTerrestrial();
    case Tide::HIGH_TIDE:
        return piece->getEngine().isMarine();
    }
    return false;
}

std::string SwampCell::getType()
{
    switch(m_tide) {
    case Tide::LOW_TIDE:
        return m_type + "_low";
    case Tide::HIGH_TIDE:
        return m_type + "_high";
    default:
        return m_type + "_medium";
    }
}

bool SwampCell::canContainPod()
{
    return true;
}
