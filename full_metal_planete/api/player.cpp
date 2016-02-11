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

bool Player::move(Piece& piece, Cell& cell) {
    if(cell.isOccupied()) {
        return false;
    }

    if(useActionPoints()) {
        cell.setPiece(piece);

        if(piece.isOnCell())
            piece.getCell().removePiece();

        piece.setCell(cell);
        return true;
    }

    return false;
}
