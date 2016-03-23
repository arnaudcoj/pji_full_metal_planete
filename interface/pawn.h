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

    bool m_travelling;
    bool m_rotating;
    bool m_moving;

    int m_direction;
    float m_speed;
    float m_angle;
    float m_distance;
    float m_progress;

public:
    Pawn(std::shared_ptr<Piece> const& piece);
    void setSelected(bool selected);
    bool isTravelling();
    void travelTo(std::shared_ptr<Cell> destination);
    void update(sf::Time const& deltaTime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Vector2f PawnToPix(int xCell, int yCell) const;
};

#endif // PAWN_H
