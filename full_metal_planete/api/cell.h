#ifndef CELL_H
#define CELL_H

#include <SFML/System/Vector2.hpp>

class Cell {

    bool m_halfCell;
//    Piece m_piece;
    sf::Vector2i m_coord;

    public:
        Cell(sf::Vector2i coord, bool halfCell = false);
        Cell(int x, int y, bool halfCell = false);
        bool isHalfCell();
  //      Piece getPiece();
  //      bool isOccupied();
  //      void removePiece();
  //      bool placePiece(Piece& piece);
        sf::Vector2i getCoord();
};

#endif // CELL_H
