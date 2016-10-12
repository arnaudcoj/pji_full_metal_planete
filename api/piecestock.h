#ifndef PIECESTOCK_H
#define PIECESTOCK_H

#include <cassert>
#include <unordered_map>
#include <algorithm>
#include <exception>
#include <stdexcept>

#include "piece.h"

class PieceStock
{
    std::unordered_multimap<std::string, std::shared_ptr<Piece>> mPieces;
    
    std::shared_ptr<Piece> takePiece(std::string id);
    
public:
    PieceStock();

    std::shared_ptr<Piece> takeBargePiece();
    std::shared_ptr<Piece> takeBigTankPiece();
    std::shared_ptr<Piece> takeCrabPiece();
    std::shared_ptr<Piece> takeMineralPiece();
    std::shared_ptr<Piece> takePatrolBoatPiece();
    std::shared_ptr<Piece> takePontoonPiece();
    std::shared_ptr<Piece> takeTankPiece();
    std::shared_ptr<Piece> takeWeatherLayerPiece();
    
    std::list<std::shared_ptr<Piece> > getAllPieces() const;
    
    void addPiece(std::shared_ptr<Piece> piece);
    
};

#endif // PIECESTOCK_H
