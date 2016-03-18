#include "patrolboatpiece.h"

PatrolBoatPiece::PatrolBoatPiece() : Piece(Engine::Type::MARINE_ENGINE, Weapon::Type::CLASSIC_WEAPON, Container::Type::NO_CONTAINER, 1)
{

}

std::string PatrolBoatPiece::getType() {
    return m_type;
}
