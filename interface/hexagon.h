#ifndef HEXAGON_H
#define HEXAGON_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "cell.h"
#include "pawn.h"
#include "assetmanager.h"

class Hexagon
{
private:
    std::shared_ptr<Cell> m_cell;
    sf::ConvexShape m_sprite;

public:
    static const float SIZE;
    static const float WIDTH;
    static const float HEIGHT;

    Hexagon(std::shared_ptr<Cell> cell);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    void initSprite();
    sf::Vector2f CellToPix(int xCell, int yCell) const;
};

#endif // HEXAGON_H
