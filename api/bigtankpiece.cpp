#include "bigtankpiece.h"

BigTankPiece::BigTankPiece() : Piece(Engine::Type::HEAVY_TERRESTRIAL_ENGINE, Weapon::Type::LONG_WEAPON, Container::Type::NO_CONTAINER, 1)
{

}

bool BigTankPiece::canBeCarried(Container::Type containerType) const
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

std::string BigTankPiece::getType() {
    return m_type;
}
