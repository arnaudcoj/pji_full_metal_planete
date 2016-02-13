#include "pion.h"

Pion::Pion() : sf::CircleShape(SIZE)
{
    this->setFillColor(sf::Color(0, 0, 250)); // setting blue color
}

// draws the pion
void Pion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw((sf::CircleShape)*this, states);
}
