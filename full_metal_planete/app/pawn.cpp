#include "pawn.h"

Pawn::Pawn() : sf::CircleShape(SIZE)
{
    this->setFillColor(sf::Color(0, 0, 250)); // setting blue color
    this->setOrigin(SIZE, SIZE);
}

// updates the pion
void Pawn::update() {

}

// draws the pion
void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw((sf::CircleShape)*this, states);
}
