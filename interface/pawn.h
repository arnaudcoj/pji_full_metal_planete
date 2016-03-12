#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "piece.h"
#include "animator.h"
#include "hexagon.h"

class Pawn
{
private:
    std::shared_ptr<Piece> m_piece;

    sf::Sprite m_sprite;
    sf::Vector2i m_size;
    Animator m_animator;

public:
    Pawn(std::shared_ptr<Piece> const& piece);
    sf::Sprite& getSprite();
    void update(sf::Time const& deltaTime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    void initSprite();
    sf::Vector2f PawnToPix(int xCell, int yCell) const;
};

#endif // PAWN_H
