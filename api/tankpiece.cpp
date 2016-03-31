#include "tankpiece.h"

TankPiece::TankPiece() : Piece(Engine::Type::TERRESTRIAL_ENGINE, Weapon::Type::CLASSIC_WEAPON, Container::Type::NO_CONTAINER, 1)
{

}

bool TankPiece::canBeCarried(Container::Type containerType) const
{
    switch(containerType) {
        case Container::Type::BIG_CONTAINER:
            return true;
        case Container::Type::CLASSIC_CONTAINER:
            return true;
        default:
            return false;
    }
}

std::string TankPiece::getType() {
    return "tank";
}
