#include "pawn.h"

Pawn::Pawn()
    : m_sprite(AssetManager::GetTexture("char"))
    , m_animator(m_sprite)
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
    m_sprite.setScale(2, 2);
    m_animator.CreateAnimation("tank", "tank", sf::seconds(0.2), true);
    sf::Vector2i spriteSize(30, 38);
    std::cout << "Pawn" << std::endl;
}

// updates the pion
void Pawn::update(sf::Time const& deltaTime)
{
    sf::Vector2i spriteSize(30, 38);
    //m_animator.FindAnimation("tank")->AddFrames(sf::Vector2i(0, 0), spriteSize, 2);
    //animation.AddFrames(sf::Vector2i(0, 0), spriteSize, 2);
    m_animator.Update(deltaTime);
}

// draws the pion
void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}
