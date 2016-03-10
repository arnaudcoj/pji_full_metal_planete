#include "crabpiece.h"

CrabPiece::CrabPiece() : Piece(Engine::Type::TERRESTRIAL_ENGINE, Weapon::Type::NO_WEAPON, Container::Type::CLASSIC_CONTAINER, 2)
{

}

bool CrabPiece::canBeCarried(Container::Type containerType) const
{
    switch(containerType) {
        case Container::Type::BIG_CONTAINER:
            return true;
        default:
            return false;
    }
}
