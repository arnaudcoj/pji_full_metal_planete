#include "piecestock.h"

PieceStock::PieceStock(int nbPieces) : mPieces()
{
    for(int i = 0; i < nbPieces; i++)
        mPieces.emplace_back();
}

Piece PieceStock::takePiece() {
    if(mPieces.empty())
        throw std::logic_error("PieceStock is empty");
    Piece p = mPieces.back();
    mPieces.pop_back();
    return p;
}

void PieceStock::addPiece(Piece &piece) {
    mPieces.push_back(piece);
}

size_t PieceStock::size() {
    return mPieces.size();
}
