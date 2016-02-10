#include "piece.h"
#include "cell.h"

Piece::Piece() : m_cell(nullptr)
{

}

bool Piece::isOnCell() {
    return m_cell != nullptr;
}

Cell Piece::getCell() {
    return *m_cell;
}

void Piece::setCell(Cell &cell) {
    m_cell = std::make_shared<Cell>(cell);
}

bool Piece::removeCell() {
    if(m_cell == nullptr)
        return false;

    m_cell->removePiece();
    m_cell = nullptr;
    return true;
}
