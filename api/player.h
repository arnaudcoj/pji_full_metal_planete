#ifndef PLAYER_H
#define PLAYER_H

#include <cassert>

#include "piece.h"
#include "cell.h"
#include "tide.h"

class Player
{
    int m_action_points;
public:
    Player();
    int getActionPoints();
    bool useActionPoints(int points = 1);
    bool move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell, Tide tide);
    bool removePiece(std::shared_ptr<Piece> piece);
};

#endif // PLAYER_H
