#ifndef CELL_H
#define CELL_H

#include <SFML/System/Vector2.hpp>
#include "piece.h"

class Cell {

    bool m_halfCell;
    Piece* m_piece;
    sf::Vector2i m_coord;

public:
    Cell();
    Cell(sf::Vector2i coord, bool halfCell = false);
    Cell(int x, int y, bool halfCell = false);
    bool isHalfCell();
    Piece* getPiece();
    bool isOccupied();
    void removePiece();
    bool placePiece(Piece* piece)   ;
    sf::Vector2i getCoord();
    int getX();
    int getY();
};

#endif // CELL_H
