#include "player.h"

Player::Player()
{

}

bool Player::move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell) {
    if(cell->isOccupied()) {
        return false;
    }

    if(cell == nullptr || piece == nullptr)
        return false;

    cell->setPiece(piece);

    if(cell->getPiece()->isOnCell())
        cell->getPiece()->getCell()->removePiece();
    cell->getPiece()->setCell(cell);

    return true;
}
