#ifndef PLAYER_H
#define PLAYER_H

#include "piece.h"
#include "cell.h"

class Player
{
public:
    Player();
    bool move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell);
    bool removePiece(std::shared_ptr<Piece> piece);
};

#endif // PLAYER_H
