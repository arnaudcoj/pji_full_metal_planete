#ifndef HEXAGON_H
#define HEXAGON_H

#include <SFML/Graphics.hpp>
#include <math.h>

class Hexagon : public sf::ConvexShape
{

public:
    Hexagon(float x, float y, float size);
};

#endif // HEXAGON_H
