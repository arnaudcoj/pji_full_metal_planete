#include "piece.h"

Piece::Piece() : m_cell(nullptr)
{

}

bool Piece::isOnCell() {
    return m_cell != nullptr;
}

std::shared_ptr<Cell> Piece::getCell() {
    return m_cell;
}

void Piece::setCell(std::shared_ptr<Cell> cell) {
    m_cell = cell;
}
