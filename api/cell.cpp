#include "cell.h"

Cell::Cell() : m_halfCell(false), m_coord(sf::Vector2i(-1, -1)), m_area(0), m_tide(Tide::MEDIUM_TIDE) {
    m_piece = nullptr;
}

Cell::Cell(sf::Vector2i coord, bool halfCell, unsigned int area) : m_halfCell(halfCell), m_coord(coord), m_area(area), m_tide(Tide::MEDIUM_TIDE) {
    m_piece = nullptr;
}

Cell::Cell(int x, int y, bool halfCell, unsigned int area) : m_halfCell(halfCell), m_coord(x, y), m_area(area), m_tide(Tide::MEDIUM_TIDE) {
    m_piece = nullptr;
}

bool Cell::isHalfCell() {
    return m_halfCell;
}

std::shared_ptr<Piece> Cell::getPiece() {
    return m_piece;
}

void Cell::setPiece(std::shared_ptr<Piece> piece) {
    assert(piece != nullptr);
    m_piece = piece;
}

bool Cell::isOccupied() const {
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

int Cell::getX() const {
    return m_coord.x;
}

int Cell::getY() const {
    return m_coord.y;
}

unsigned int Cell::getArea() {
    return m_area;
}

bool Cell::isPracticable(std::shared_ptr<Piece> piece) {
    assert(piece != nullptr);
    return (piece != nullptr) && !isHalfCell() && isPracticableCurrent(piece);
}

int Cell::getRangeBonus() {
    return 0;
}

void Cell::setTide(Tide tide)
{
    m_tide = tide;
}
