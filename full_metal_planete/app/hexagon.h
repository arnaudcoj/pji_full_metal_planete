#ifndef HEXAGON_H
#define HEXAGON_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include <memory>

#include "cell.h"
#include "pawn.h"

class Hexagon : public sf::ConvexShape
{
    std::shared_ptr<Cell> m_cell;
    const float X = 0;
    const float Y = 0;

public:
    static constexpr float SIZE = 50;
    static constexpr float HEIGHT = 86.6025;
    static constexpr float WIDTH = SIZE * 2;

    Hexagon(std::shared_ptr<Cell> cell);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // HEXAGON_H
