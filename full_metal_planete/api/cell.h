#ifndef CELL_H
#define CELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include "piece.h"

class Cell {
    bool m_halfCell;
    std::shared_ptr<Piece> m_piece;
    sf::Vector2i m_coord;
    unsigned int m_area;

public:
    Cell();
    Cell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    Cell(int x, int y, bool halfCell = false, unsigned int area = 0);
    bool isHalfCell();
    std::shared_ptr<Piece> getPiece();
    void setPiece(std::shared_ptr<Piece> piece);
    bool isOccupied();
    bool removePiece();
    sf::Vector2i getCoord();
    int getX();
    int getY();
    unsigned int getArea();
};

#endif // CELL_H
