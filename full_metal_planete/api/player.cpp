#include "player.h"

Player::Player() : m_action_points(100)
{

}

int Player::getActionPoints() {
    return m_action_points;
}

bool Player::useActionPoints(int points) {
    if (points < 0)
        return false;
    if (m_action_points - points < 0)
        return false;
    m_action_points -= points;
    return true;
}

bool Player::move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell, Tide tide) {
    if(cell->isOccupied() || !cell->isPracticable(piece, tide)) {
        return false;
    }

    cell->setPiece(piece);

    if(piece->isOnCell())
        piece->getCell()->removePiece();

    piece->setCell(cell);

    return true;
}

bool Player::removePiece(std::shared_ptr<Piece> piece) {
    if(!piece->isOnCell()) {
        return false;
    }

    piece->getCell()->removePiece();
    piece->removeCell();

    return false;
}
