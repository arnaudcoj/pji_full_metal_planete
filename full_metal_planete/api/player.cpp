#include "player.h"

Player::Player()
{

}

bool Player::move(Piece& piece, Cell& cell) {
    if(cell.isOccupied()) {
        return false;
    }

    cell.setPiece(piece);

    if(cell.getPiece().isOnCell())
        cell.getPiece().getCell().removePiece();
    cell.getPiece().setCell(cell);

    return true;
}
