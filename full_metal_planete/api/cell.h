#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
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

    sf::ConvexShape m_sprite;

protected:
    sf::Texture m_texture;

public:
    static const float SIZE;
    static const float WIDTH;
    static const float HEIGHT;

    Cell();
    Cell(sf::Vector2i coord, bool halfCell = false, unsigned int area = 0);
    Cell(int x, int y, bool halfCell = false, unsigned int area = 0);
    bool isHalfCell();
    std::shared_ptr<Piece> getPiece();
    void setPiece(std::shared_ptr<Piece> piece);
    bool isOccupied() const;
    bool removePiece();
    sf::Vector2i getCoord();
    int getX() const;
    int getY() const;
    unsigned int getArea();
    bool isPracticable(std::shared_ptr<Piece> piece, Tide tide);

    sf::Vector2f CellToPix(int xCell, int yCell) const;
    void initSprite();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    virtual bool isPracticableCurrent(std::shared_ptr<Piece> piece, Tide tide) = 0;
};

#endif // CELL_H
