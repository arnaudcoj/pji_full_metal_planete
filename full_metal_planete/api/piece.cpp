#include "piece.h"
#include "cell.h"

Piece::Piece(Engine::Type engineType, Weapon::Type weaponType) : m_cell(), m_engine(engineType), m_weapon(weaponType)
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

Weapon& Piece::getWeapon() {
    return m_weapon;
}
