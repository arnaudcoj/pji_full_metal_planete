#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "piece.h"
#include "assetmanager.h"
#include "animator.h"

class Pawn
{
private:
    Piece m_piece;

    sf::Sprite m_sprite;
    Animator m_animator;

public:
    Pawn();
    void initSprite();
    void update(sf::Time const& deltaTime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PAWN_H
