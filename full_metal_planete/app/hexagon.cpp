#include "hexagon.h"
#include <iostream>

sf::Vector2f hex_corner(float size, int i) {
    int angle_deg = 60 * i;
    float angle_rad = M_PI / 180 * angle_deg;
    return sf::Vector2f(size * cos(angle_rad), size * sin(angle_rad));
}

Hexagon::Hexagon(std::shared_ptr<Cell> cell, float size) : m_cell(cell)
{
    setPointCount(6);

    for (int i = 0; i < 6; ++i) {
        setPoint(i, hex_corner(size, i));
    }

    setOutlineThickness(-2);
    setOutlineColor(sf::Color(0, 100, 0, 255));
}

void Hexagon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw((ConvexShape)*this, states);

    if (m_cell->isOccupied()) {
        sf::CircleShape pion(25);
        pion.setFillColor(sf::Color(100, 250, 50));
        pion.setOrigin(25, 25 - (this->getGlobalBounds().height / 2));
        pion.setPosition(this->getPosition());

        target.draw(pion, states);
    }
}
