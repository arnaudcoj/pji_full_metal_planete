#include "container.h"

Container::Container(Container::Type type) : m_type(type), m_MaxCapacity(0), m_carriedPieces()
{
    //TODO vérifier valeurs
    switch(type) {
    case Type::CLASSIC_CONTAINER:
        m_MaxCapacity = 2;
        break;
    case Type::BIG_CONTAINER:
        m_MaxCapacity = 4;
    default:
        break;
    }
}

int Container::getMaxCapacity() const {
    return m_MaxCapacity;
}

int Container::getCapacity() const {
    //TODO to be implemented (list.size)
    return 0;
}

std::list< std::shared_ptr<Piece> > Container::getCarriedPieces() const {
    return m_carriedPieces;
}

bool Container::canCarry(std::shared_ptr<Piece> piece) const {
    assert(piece != nullptr);

    //Type pieceType = piece->getContainer.getType();

    return false;
    //TODO to be implemented
}

Container::Type Container::getType() const {
    return m_type;
}

void Container::takePiece(std::shared_ptr<Piece> piece) {
    if(canCarry(piece)) {
            m_carriedPieces.push_back(piece);
    }
}

