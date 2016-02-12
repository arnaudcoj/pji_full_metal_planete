#include "hexagon.h"

sf::Vector2f hex_corner(float x, float y, float size, int i) {
    int angle_deg = 60 * i;
    float angle_rad = M_PI / 180 * angle_deg;
    return sf::Vector2f(x + size * cos(angle_rad), y + size * sin(angle_rad));
}

Hexagon::Hexagon(float x, float y, float size)
{
    setPointCount(6);

    for (int i = 0; i < 6; ++i) {
        setPoint(i, hex_corner(x, y, size, i));
    }

    setOutlineThickness(-2);
    setOutlineColor(sf::Color(0, 100, 0, 255));
}
