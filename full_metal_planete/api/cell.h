#ifndef CELL_H
#define CELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include "piece.h"

class Cell {

    bool m_halfCell;
    std::shared_ptr<Piece> m_piece;
    sf::Vector2i m_coord;

public:
    Cell();
    Cell(sf::Vector2i coord, bool halfCell = false);
    Cell(int x, int y, bool halfCell = false);
    bool isHalfCell();
    std::shared_ptr<Piece> getPiece();
    bool setPiece(std::shared_ptr<Piece> piece);
    bool isOccupied();
    bool removePiece();
    bool placePiece(std::shared_ptr<Cell> cell, std::shared_ptr<Piece> piece);
    sf::Vector2i getCoord();
    int getX();
    int getY();
};

#endif // CELL_H
