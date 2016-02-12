#include "piece.h"
#include "cell.h"

Piece::Piece() : m_cell()
{

}

bool Piece::isOnCell() {
    return !m_cell.expired();
}

std::shared_ptr<Cell> Piece::getCell() {
    return m_cell.lock();
}

void Piece::setCell(std::shared_ptr<Cell> cell) {
    m_cell = cell;
}

bool Piece::removeCell() {
    if(!isOnCell())
        return false;

    m_cell.reset();
/*    std::shared_ptr<Cell> cell = m_cell.lock();
    cell->removePiece();
    cell = nullptr;
    */
    return true;
}
