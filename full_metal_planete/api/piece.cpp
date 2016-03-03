#include "piece.h"
#include "cell.h"

Piece::Piece(Engine::Type engineType) : m_cell(), m_engine(engineType)
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

Engine& Piece::getEngine() {
    return m_engine;
}


void Piece::initSprite()
{
    m_sprite = sf::CircleShape(SIZE);
    m_sprite.setFillColor(sf::Color(0, 0, 250)); // setting blue color
    m_sprite.setOrigin(SIZE, SIZE);
}

// updates the pion
void Piece::update() {

}

// draws the pion
void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
}
