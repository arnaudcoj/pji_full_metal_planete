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
}

// draws the hexagon the the entities inside of it
void Hexagon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // drawing the hexagon on the target
    // needed to cast so that it does not call the Hexagon draw() method (this one) but the ConvexShape one
    target.draw((ConvexShape)*this, states);

    // if the cell is occupied
    if (m_cell->isOccupied()) {
        Pion pion; // creating a pion

        pion.setFillColor(sf::Color(0, 0, 250)); // setting blue color

        // setting the origin of the pion so that it is centered.
        pion.setOrigin(SIZE / 2, SIZE / 2 - (this->getGlobalBounds().height / 2));
        // setting the position of the pion in the middle of the hexagon
        pion.setPosition(this->getPosition());

        // drawing the pion on the target
        target.draw(pion, states);
    }
}
