#include "bargepiece.h"

BargePiece::BargePiece() : Piece(Engine::Type::MARINE_ENGINE, Weapon::Type::NO_WEAPON, Container::Type::BIG_CONTAINER, 2)
{

}

std::string BargePiece::getType() {
    return m_type;
}
