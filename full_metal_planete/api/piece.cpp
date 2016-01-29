#include "piece.h"

Piece::Piece() : m_cell(nullptr)
{

}


Cell* Piece::getCell() {
    return m_cell;
}

void Piece::setCell(Cell *cell) {
    m_cell = cell;
}
