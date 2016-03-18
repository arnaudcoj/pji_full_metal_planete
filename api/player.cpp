#include "player.h"

Player::Player(int actionPoints)
    : m_action_points(actionPoints)
{
}

int Player::getActionPoints()
{
    return m_action_points;
}

bool Player::useActionPoints(int points)
{
    if(points < 0)
        return false;
    if(m_action_points - points < 0)
        return false;
    m_action_points -= points;
    return true;
}

bool Player::canMove(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell, Tide tide)
{
    assert(cell != nullptr);

    return (!(cell->isOccupied() || !cell->isPracticable(piece, tide) ||
        (piece->getCell() != nullptr && !piece->getCell()->isPracticable(piece, tide))));
}

bool Player::move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell, Tide tide)
{
    assert(cell != nullptr);

    if(!canMove(piece, cell, tide)) {
        return false;
    }

    cell->setPiece(piece);

    if(piece->isOnCell())
        piece->getCell()->removePiece();

    piece->setCell(cell);

    return true;
}

bool Player::removePiece(std::shared_ptr<Piece> piece)
{
    if(!piece->isOnCell()) {
        return false;
    }

    piece->getCell()->removePiece();
    piece->removeCell();

    return false;
}

