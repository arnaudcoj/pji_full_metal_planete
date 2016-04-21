#include "crabpiece.h"

CrabPiece::CrabPiece() : Piece(Engine::Type::TERRESTRIAL_ENGINE, Weapon::Type::NO_WEAPON, Container::Type::CLASSIC_CONTAINER, 2)
{

}

bool CrabPiece::canBeCarried(Container container) const
{
    Container::Type containerType = container.getType();
    switch(containerType) {
        case Container::Type::BIG_CONTAINER:
            return true;
        default:
            return false;
    }
}

std::string CrabPiece::getType() {
    return "crab";
}
