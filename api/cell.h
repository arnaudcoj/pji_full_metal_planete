#ifndef CELL_H
#define CELL_H

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <cassert>
#include "piece.h"
#include "tide.h"
#include <cmath>

class Cell
{
    bool m_halfCell;
    std::shared_ptr<Piece> m_piece;
    sf::Vector2i m_coord;
    unsigned int m_area;

protected:
    Tide m_tide;

public:
    Cell();
    Cell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    Cell(int x, int y, bool halfCell = false, unsigned int area = 0);
    bool isHalfCell();
    std::shared_ptr<Piece> getPiece();
    void setPiece(std::shared_ptr<Piece> piece);
    bool isOccupied() const;
    bool removePiece();

    void setTide(Tide tide);

    sf::Vector2i getCoord();
    int getX() const;
    int getY() const;
    unsigned int getArea();
    bool isPracticable(std::shared_ptr<Piece> piece);

    virtual std::string getType() = 0;

    virtual int getRangeBonus();

private:
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece) = 0;
};

#endif // CELL_H
