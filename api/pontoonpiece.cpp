#include "pontoonpiece.h"

PontoonPiece::PontoonPiece() : Piece(Engine::Type::NO_ENGINE, Weapon::Type::NO_WEAPON, Container::Type::NO_CONTAINER, 1)
{

}

bool PontoonPiece::canBeCarried(Container container) const
{
    Container::Type containerType = container.getType();
    switch(containerType) {
        case Container::Type::BIG_CONTAINER:
            return true;
        case Container::Type::CLASSIC_CONTAINER:
            return true;
        default:
            return false;
    }
}

std::string PontoonPiece::getType() {
    return "pontoon";
}
