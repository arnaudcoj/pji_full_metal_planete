#include "player.h"

Player::Player()
{

}

bool Player::move(Piece& piece, Cell& cell) {
    if(cell.isOccupied()) {
        return false;
    }

    cell.setPiece(piece);

    if(piece.isOnCell())
        piece.getCell().removePiece();

    piece.setCell(cell);

    return true;
}
