#ifndef PIECESTOCK_H
#define PIECESTOCK_H

#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>

#include "piece.h"

//NOTE: cas où il n'y a qu'un seul type de piece, surement différent quand plusieurs types
class PieceStock
{
    std::vector<std::shared_ptr<Piece>> mPieces;

public:
    PieceStock(int nbPieces = 0);

    std::shared_ptr<Piece> takePiece();
    std::shared_ptr<Piece> getPiece(int i) const;
    void addPiece(std::shared_ptr<Piece> piece);
    size_t size() const;
};

#endif // PIECESTOCK_H
