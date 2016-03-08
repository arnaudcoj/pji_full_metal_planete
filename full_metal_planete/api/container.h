#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>
#include <list>
#include <cassert>

class Piece;

class Container
{
public:
    enum class Type : char { NO_CONTAINER, CLASSIC_CONTAINER, BIG_CONTAINER };

    Container(Type type = Type::NO_CONTAINER);

    int getMaxCapacity() const;
    int getCapacity() const;
    std::list< std::shared_ptr<Piece> > getCarriedPieces() const;
    bool canCarry(std::shared_ptr<Piece> piece) const;
    void takePiece(std::shared_ptr<Piece> piece);
    Type getType() const;

private:
    Type m_type;
    int m_MaxCapacity;
    std::list< std::shared_ptr<Piece> > m_carriedPieces;
};

#include "piece.h"

#endif // CONTAINER_H
