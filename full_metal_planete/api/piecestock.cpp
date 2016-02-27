#include "piecestock.h"

PieceStock::PieceStock(int nbPieces) : mPieces()
{
    for(int i = 0; i < nbPieces; i++)
        mPieces.push_back(std::make_shared<Piece>());
}

std::shared_ptr<Piece> PieceStock::takePiece() {
    if(mPieces.empty())
        throw std::logic_error("PieceStock is empty");
    std::shared_ptr<Piece> p = mPieces.back();
    mPieces.pop_back();
    return p;
}

void PieceStock::addPiece(std::shared_ptr<Piece> piece) {
    mPieces.push_back(piece);
}

size_t PieceStock::size() {
    return mPieces.size();
}
