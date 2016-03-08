#include "gamestate.h"


GameState::GameState() : m_maxTurns(25), m_nbTurns(m_maxTurns), m_tideVector()
{
    m_RNG.seed(std::random_device()());
    initTideVector();
}

std::vector<Tide> &GameState::getTides() {
    return m_tideVector;
}

Tide& GameState::getTide() {
    return m_tideVector.back();
}

int GameState::getNbTurns() {
    return m_nbTurns;
}

int GameState::getMaxTurns() {
    return m_maxTurns;
}

void GameState::nextTurn() {
    if(m_nbTurns < 0) {
    //  comportement à déterminer
        return;
    }
    m_nbTurns--;
    m_tideVector.pop_back();
    if(m_tideVector.size() <= 0)
        initTideVector();
}

void GameState::initTideVector() {

    m_tideVector.clear();

    for(int i = 0; i < 5; i++)
        m_tideVector.push_back(Tide::LOW_TIDE);
    for(int i = 0; i < 5; i++)
        m_tideVector.push_back(Tide::MEDIUM_TIDE);
    for(int i = 0; i < 5; i++)
        m_tideVector.push_back(Tide::HIGH_TIDE);

    std::shuffle(m_tideVector.begin(), m_tideVector.end(), m_RNG);

    for(int i = 0; i < 6; i++)
        m_tideVector.pop_back();

}
