#include "piece.h"
#include "cell.h"

Piece::Piece() : m_cell()
{

}

bool Piece::isOnCell() {
    return !m_cell.expired();
}

Cell& Piece::getCell() {
    return *(m_cell.lock());
}

void Piece::setCell(Cell &cell) {
    m_cell = std::make_shared<Cell>(cell);
}

bool Piece::removeCell() {
    if(!isOnCell())
        return false;

    std::shared_ptr<Cell> cell = m_cell.lock();
    cell->removePiece();
    cell = nullptr;
    return true;
}
