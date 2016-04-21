#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <cassert>
#include <SFML/System/Vector2.hpp>
#include "hexagrid.h"
#include "piece.h"
#include "cell.h"
#include "tide.h"
#include "piecestock.h"

class Player
{
    int m_action_points;
    int m_number;
    PieceStock m_pieceStock;

public:
    Player(int number);

    int getNumber() const;
    int getActionPoints() const;
    bool useActionPoints(int points = 1);
    bool canMove(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell);
    bool canCarry(std::shared_ptr<Piece> transporter, std::shared_ptr<Piece> targetPiece, Hexagrid& grid);
    bool move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell);
    bool pickPiece(std::shared_ptr<Piece> transporter, std::shared_ptr<Piece> targetPiece, Hexagrid& grid);
    bool removePiece(std::shared_ptr<Piece> piece);
    PieceStock& getPieceStock();
    
    
    // gets the cells where a piece can move
    std::unordered_set<std::shared_ptr<Cell> > getAccessibleCells(Hexagrid& grid, std::shared_ptr<Piece> piece);

};

#endif // PLAYER_H
