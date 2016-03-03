#ifndef PION_H
#define PION_H

#include <SFML/Graphics.hpp>

class Pawn : public sf::CircleShape
{

public:
    static constexpr float SIZE = 25;

    Pawn();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PION_H
