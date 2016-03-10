#include "piece.h"
#include "cell.h"

Piece::Piece(Engine engine) : m_cell(), m_engine(engine)
{ }

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