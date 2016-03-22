#include "pawn.h"

Pawn::Pawn(std::shared_ptr<Piece> const& piece)
    : m_piece(piece)
    , m_sprite()
    , m_size(0, 0)
    , m_animator(m_sprite)
{
    int nbSprites = 1;

    if(m_piece->getType() == "tank") {
        m_size = sf::Vector2i(30, 38);
    } else if(m_piece->getType() == "big_tank") {
        m_size = sf::Vector2i(32, 48);
    } else if(m_piece->getType() == "boat") {
        m_size = sf::Vector2i(27, 52);
    } else if(m_piece->getType() == "crab") {
        m_size = sf::Vector2i(56, 54);
    } else if(m_piece->getType() == "barge") {
        m_size = sf::Vector2i(40, 101);
    } else if(m_piece->getType() == "pontoon") {
        m_size = sf::Vector2i(32, 52);
    } else if(m_piece->getType() == "weather_layer") {
        m_size = sf::Vector2i(56, 56);
    }

    m_sprite.setOrigin(m_size.x / 2, m_size.y / 2);
    m_sprite.setScale(1.5, 1.5);

    auto& animation = m_animator.CreateAnimation(m_piece->getType(), m_piece->getType(), sf::seconds(0.2), true);
    animation.AddFrames(sf::Vector2i(0, 0), m_size, nbSprites);
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

sf::Sprite& Pawn::getSprite()
{
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
    if(m_piece->getCell() != nullptr) {
        states.transform.translate(PawnToPix(m_piece->getCell()->getX(), m_piece->getCell()->getY()));

        target.draw(m_sprite, states);
    }
}
