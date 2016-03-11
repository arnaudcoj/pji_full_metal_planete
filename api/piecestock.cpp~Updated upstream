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

std::shared_ptr<Piece> PieceStock::getPiece(int i) const{
    return mPieces[i];
}

void PieceStock::addPiece(std::shared_ptr<Piece> piece) {
    mPieces.push_back(piece);
}

size_t PieceStock::size() const {
    return mPieces.size();
}
