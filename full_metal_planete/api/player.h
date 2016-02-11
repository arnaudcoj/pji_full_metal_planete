#ifndef PLAYER_H
#define PLAYER_H

#include "piece.h"
#include "cell.h"

class Player
{
    int m_action_points;
public:
    Player();
    int getActionPoints();
    bool useActionPoints(int points = 1);
    bool move(Piece &piece, Cell &cell);
};

#endif // PLAYER_H
