#include "pawn.h"

Pawn::Pawn(std::shared_ptr<Piece> const& piece)
    : m_piece(piece)
    , m_sprite()
    , m_size(30, 38)
    , m_animator(m_sprite)
{
    m_sprite.setOrigin(m_size.x / 2, m_size.y / 2);
    m_sprite.setScale(3, 3);

    auto& animation = m_animator.CreateAnimation("tank", "tank", sf::seconds(0.2), true);
    animation.AddFrames(sf::Vector2i(0, 0), m_size, 2);
}

sf::Vector2f Pawn::PawnToPix(int xCell, int yCell) const
{
    float x;
    float y;

    // setting the position of the pawn
    if(xCell % 2 == 0) {
        x = xCell * Hexagon::WIDTH * 3 / 4;
        y = yCell * Hexagon::HEIGHT;
    } else {
        x = xCell * Hexagon::WIDTH * 3 / 4;
        y = (yCell - 0.5) * Hexagon::HEIGHT; // above the previous one
    }

    y += Hexagon::HEIGHT / 2; // adding an offset

    return sf::Vector2f(x, y);
}

sf::Sprite& Pawn::getSprite() {
    return m_sprite;
}

// updates the pion
void Pawn::update(sf::Time const& deltaTime)
{
    m_animator.Update(deltaTime);
}

// draws the pion
void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.translate(PawnToPix(m_piece->getCell()->getX(), m_piece->getCell()->getY()));

    target.draw(m_sprite, states);
}
