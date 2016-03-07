#include "pawn.h"

Pawn::Pawn() {
    initSprite();
}

void Pawn::initSprite()
{
    m_sprite = sf::Sprite(AssetManager::GetTexture("char"));

    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);

    m_sprite.setScale(1.5, 1.5);
}

// updates the pion
void Pawn::update() {

}

// draws the pion
void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
}
