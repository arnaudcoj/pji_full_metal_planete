#include "piece.h"
#include "cell.h"

Piece::Piece(Engine engine) : m_cell(), m_engine(engine)
{
    initSprite();
}

bool Piece::isOnCell() {
    return !m_cell.expired();
}

std::shared_ptr<Cell> Piece::getCell() {
    return m_cell.lock();
}

void Piece::setCell(std::shared_ptr<Cell> cell) {
    m_cell = cell;
}

bool Piece::removeCell() {
    if(!isOnCell())
        return false;

    m_cell.reset();

    return true;
}


bool Piece::isTerrestrial() {
    return m_engine != Engine::MARINE_ENGINE;
}

bool Piece::isMarine() {
    return m_engine == Engine::MARINE_ENGINE;
}

bool Piece::canClimb() {
    return m_engine == Engine::TERRESTRIAL_ENGINE;
}

void Piece::initSprite()
{
    m_texture = AssetManager::GetTexture("../../media/textures/char.png");

    m_sprite = sf::Sprite(m_texture);

    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

// updates the pion
void Piece::update() {

}

// draws the pion
void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
}
