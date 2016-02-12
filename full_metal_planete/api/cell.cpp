#include "cell.h"

Cell::Cell() : m_halfCell(false), m_coord(sf::Vector2i(-1, -1)), m_area(0) {
    m_piece = nullptr;
}

Cell::Cell(sf::Vector2i coord, bool halfCell, unsigned int area) : m_halfCell(halfCell), m_coord(coord), m_area(area) {
    m_piece = nullptr;
}

Cell::Cell(int x, int y, bool halfCell, unsigned int area) : m_halfCell(halfCell), m_coord(x, y), m_area(area) {
    m_piece = nullptr;
}

bool Cell::isHalfCell() {
    return m_halfCell;
}

std::shared_ptr<Piece> Cell::getPiece() {
    return m_piece;
}

void Cell::setPiece(std::shared_ptr<Piece> piece) {
    m_piece = piece;
}

bool Cell::isOccupied() {
    return m_piece != nullptr;
}

bool Cell::removePiece() {
    if(m_piece == nullptr)
        return false;

    m_piece = nullptr;
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

unsigned int Cell::getArea() {
    return m_area;
}
