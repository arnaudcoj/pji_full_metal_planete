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
    std::vector<Piece> mPieces;

public:
    PieceStock(int nbPieces = 0);

    Piece takePiece();
    void addPiece(Piece &piece);
    size_t size();
};

#endif // PIECESTOCK_H
