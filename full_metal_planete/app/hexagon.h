#ifndef HEXAGON_H
#define HEXAGON_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include <memory>

#include "cell.h"

class Hexagon : public sf::ConvexShape
{
    std::shared_ptr<Cell> m_cell;

public:
    Hexagon(std::shared_ptr<Cell> cell, float size);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // HEXAGON_H
