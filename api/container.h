#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>
#include <vector>
#include <cassert>

class Piece;

class Container
{
public:
    enum class Type : char { NO_CONTAINER, MINERAL_CONTAINER, CLASSIC_CONTAINER, BIG_CONTAINER };

    Container(Type type = Type::NO_CONTAINER);

    int getMaxCapacity() const;
    int getWeight() const;
    std::vector< std::shared_ptr<Piece> > getCarriedPieces() const;
    bool canCarry(std::shared_ptr<Piece> piece) const;
    bool takePiece(std::shared_ptr<Piece> piece);
    std::shared_ptr<Piece> deployPiece(int pieceID);
    Type getType() const;

private:
    Type m_type;
    int m_MaxCapacity;
    std::vector< std::shared_ptr<Piece> > m_carriedPieces;
};

#endif // CONTAINER_H
