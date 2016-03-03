#include "hexagon.h"

// returns a point of the hexagon thanks to its center, its size and the point's identifier
sf::Vector2f hex_corner(float x, float y, float size, int i) {
    int angle_deg = 60 * i;
    float angle_rad = M_PI / 180 * angle_deg;
    return sf::Vector2f(x + size * cos(angle_rad), y + size * sin(angle_rad));
}

Hexagon::Hexagon(std::shared_ptr<Cell> cell) : m_cell(cell)
{
    setPointCount(6); // the number of points

    // creating each point of the hexagon
    for (int i = 0; i < 6; ++i) {
        setPoint(i, hex_corner(X, Y, SIZE, i));
    }

    // creating a black border inside the hexagon
    setOutlineThickness(-2);
    setOutlineColor(sf::Color(0, 0, 0, 255));

    // setting the color of the hexagon depending of if it's a half cell or not
    if(m_cell->isHalfCell())
        setFillColor(sf::Color(255, 255, 255, 200));
    else
        setFillColor(sf::Color(255, 255, 255));

    setOrigin(-SIZE, -HEIGHT / 2);
}

// updates the hexagon
void Hexagon::update() {
    if (m_cell->isOccupied()) {
        setOutlineColor(sf::Color::Red);
        setOutlineThickness(-5);
    } else {
        setOutlineColor(sf::Color::Black);
        setOutlineThickness(-2);
    }
}

// draws the hexagon the the entities inside of it
void Hexagon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // drawing the hexagon on the target
    // needed to cast so that it does not call the Hexagon draw() method (this one) but the ConvexShape one
    target.draw((ConvexShape)*this, states);

    // if the cell is occupied
    if (m_cell->isOccupied()) {
        Pawn pion; // creating a pion

        // setting the position of the pion in the middle of the hexagon
        pion.setPosition(this->getPosition().x + SIZE, this->getPosition().y + HEIGHT / 2);

        // drawing the pion on the target
        target.draw(pion, states);
    }
}
