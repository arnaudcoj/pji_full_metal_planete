#include "cell.h"

Cell::Cell() : m_halfCell(false), m_coord(sf::Vector2i(-1, -1)) {
    m_piece = nullptr;
}

Cell::Cell(sf::Vector2i coord, bool halfCell) : m_halfCell(halfCell), m_coord(coord) {
    m_piece = nullptr;
}

Cell::Cell(int x, int y, bool halfCell) : m_halfCell(halfCell), m_coord(x, y) {
    m_piece = nullptr;
}

bool Cell::isHalfCell() {
    return m_halfCell;
}

Piece* Cell::getPiece() {
    return m_piece;
}

bool Cell::isOccupied() {
    return m_piece != nullptr;
}

void Cell::removePiece() {
    m_piece = nullptr;
}

bool Cell::placePiece(Piece *piece) {
    if(isOccupied()) {
        return false;
    }
    m_piece = piece;
    m_piece->getCell()->removePiece();
    m_piece->setCell(this);
    return true;
}


sf::Vector2i Cell::getCoord() {
    return m_coord;
}

int Cell::getX() {
    return m_coord.x;
}

int Cell::getY() {
    return m_coord.y;
}
