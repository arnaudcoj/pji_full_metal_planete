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
    
    for(int i = 0; i < m_MaxCapacity; i++)
        m_carriedPieces.push_back(nullptr);
}

int Container::getMaxCapacity() const {
    return m_MaxCapacity;
}

int Container::getWeight() const {
    int size = 0;
    for(std::shared_ptr<Piece> piece : m_carriedPieces)
        if(piece != nullptr)
            size = piece->getWeight();
    return size;
}

Container::Type Container::getType() const {
    return m_type;
}

//contient des nullptr
std::vector< std::shared_ptr<Piece> > Container::getCarriedPieces() const {
    return m_carriedPieces;
}

bool Container::canCarry(std::shared_ptr<Piece> piece) const {
    assert(piece != nullptr);
    
    if(!piece->canBeCarried(m_type)) 
        return false;
        
    if(contains(piece))
        return false;
        
    return getWeight() + piece->getWeight() <= getMaxCapacity();
}

int Container::getFirstEmptyPlaceIndex() const {
    for(int i =0; i < m_carriedPieces.size(); i++)
        if(m_carriedPieces[i] == nullptr)
            return i;
    return -1;
}

int Container::getIndex(std::shared_ptr<Piece> piece) const {
    for(int i = 0; i < m_carriedPieces.size(); i++)
        if(m_carriedPieces[i] == piece)
            return i;
    return -1;
}

bool Container::contains(std::shared_ptr<Piece> piece) const {
    for(int i = 0; i < m_carriedPieces.size(); i++)
        if(m_carriedPieces[i] == piece)
            return true;
    return false;
}

bool Container::takePiece(std::shared_ptr<Piece> piece) {
    if(canCarry(piece)) {
        int index = getFirstEmptyPlaceIndex();
        if(index != -1) {
            m_carriedPieces[index] = piece;
            return true;
        }
    }
    return false;
}

bool Container::removePiece(std::shared_ptr<Piece> piece)
{
    int index = getIndex(piece);
    if(index == -1)
        return false;
    m_carriedPieces[index] = nullptr;
    return true;
}
