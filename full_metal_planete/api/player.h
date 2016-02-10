#ifndef PLAYER_H
#define PLAYER_H

#include "piece.h"
#include "cell.h"

class Player
{
public:
    Player();
    bool move(Piece &piece, Cell &cell);
};

#endif // PLAYER_H
