#include "piecestock.h"

PieceStock::PieceStock()
    : mPieces()
{
}

std::shared_ptr<Piece> PieceStock::takePiece(std::string id)
{
    auto found = mPieces.find(id);
    if(found == mPieces.end())
        return nullptr;

    std::shared_ptr<Piece> p = found->second;
    
    mPieces.erase(found);
    return p;
}

std::shared_ptr<Piece> PieceStock::takeBargePiece()
{
    return takePiece("barge");
}

std::shared_ptr<Piece> PieceStock::takeBigTankPiece()
{
    return takePiece("big_tank");
}

std::shared_ptr<Piece> PieceStock::takeCrabPiece()
{
    return takePiece("crab");
}

std::shared_ptr<Piece> PieceStock::takeMineralPiece()
{
    return takePiece("mineral");
}

std::shared_ptr<Piece> PieceStock::takePatrolBoatPiece()
{
    return takePiece("boat");
}

std::shared_ptr<Piece> PieceStock::takePontoonPiece()
{
    return takePiece("pontoon");
}

std::shared_ptr<Piece> PieceStock::takeTankPiece()
{
    return takePiece("tank");
}

std::shared_ptr<Piece> PieceStock::takeWeatherLayerPiece()
{
    return takePiece("weather_layer");
}

void PieceStock::addPiece(std::shared_ptr<Piece> piece)
{
    assert(piece != nullptr);
    mPieces.insert(std::make_pair(piece->getType(), piece));
}

std::list<std::shared_ptr<Piece> > PieceStock::getAllPieces() const
{
    std::list<std::shared_ptr<Piece> > res;
    for(std::pair<std::string, std::shared_ptr<Piece> > piece : mPieces)
        res.push_back(piece.second);
    return res;
}
