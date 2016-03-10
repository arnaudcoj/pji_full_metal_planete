#include "container.h"
#include "piece.h"

Container::Container(Container::Type type) : m_type(type), m_MaxCapacity(0), m_carriedPieces()
{
    switch(type) {
    case Type::MINERAL_CONTAINER:
        m_MaxCapacity = 1;
        break;
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

int Container::getWeight() const {
    int size = 0;
    for(std::shared_ptr<Piece> piece : m_carriedPieces)
        size = piece->getWeight();
    return size;
}

std::vector< std::shared_ptr<Piece> > Container::getCarriedPieces() const {
    return m_carriedPieces;
}

bool Container::canCarry(std::shared_ptr<Piece> piece) const {
    assert(piece != nullptr);
    
    if(piece->canBeCarried(m_type)) 
        return getWeight() + piece->getWeight() <= getMaxCapacity();

    return false;
}

Container::Type Container::getType() const {
    return m_type;
}

bool Container::takePiece(std::shared_ptr<Piece> piece) {
    if(canCarry(piece)) {
            m_carriedPieces.push_back(piece);
            return true;
    }
    return false;
}

std::shared_ptr<Piece> Container::deployPiece(int pieceID)
{
    if(0 > pieceID || pieceID >= m_carriedPieces.size())
        return nullptr;
    return m_carriedPieces[pieceID];
}
