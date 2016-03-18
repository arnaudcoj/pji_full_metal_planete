#include "MineralPiece.h"

MineralPiece::MineralPiece() : Piece(Engine::Type::NO_ENGINE, Weapon::Type::NO_WEAPON, Container::Type::NO_CONTAINER, 1)
{
}

bool MineralPiece::canBeCarried(Container::Type containerType) const
{
    switch(containerType) {
        case Container::Type::NO_CONTAINER:
            return false;
        default:
            return true;
    }
}

std::string MineralPiece::getType() {
    return m_type;
}