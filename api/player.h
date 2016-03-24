#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <cassert>
#include <SFML/System/Vector2.hpp>
#include "piece.h"
#include "cell.h"
#include "tide.h"

class Player
{
    int m_action_points;
    int m_number;
    
public:
    Player(int number);
    
    int getNumber() const;
    int getActionPoints() const;
    bool useActionPoints(int points = 1);
    bool canMove(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell);
    bool move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell);
    bool removePiece(std::shared_ptr<Piece> piece);

};

#endif // PLAYER_H
