#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "piece.h"
#include "assetmanager.h"

class Pawn
{
private:
    Piece m_piece;

    sf::Sprite m_sprite;

public:
    Pawn();
    void initSprite();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PAWN_H
