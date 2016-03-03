#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.hpp>
#include "hexagon.h"
#include <cmath>

namespace Tools
{
sf::Vector2f HexToPix(int xCell, int yCell);
sf::Vector2f PixToHex(int xCursor, int yCursor);
}

#endif // TOOLS_H
