#include "player.h"

Player::Player()
{

}

bool Player::move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell) {
    if(cell->isOccupied()) {
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

    return true;
}
