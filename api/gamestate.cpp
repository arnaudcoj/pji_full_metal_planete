#include "gamestate.h"

GameState::GameState()
    : m_RNG()
    , m_maxTurns(25)
    , m_turn(0)
    , m_tideVector()
{
    m_RNG.seed(std::random_device()());
    initTideVector();
}

std::vector<Tide> GameState::getTides() const
{
    return m_tideVector;
}

Tide GameState::getTide() const
{
    return m_tideVector.back();
}

int GameState::getTurn() const
{
    return m_turn;
}

int GameState::getMaxTurns() const
{
    return m_maxTurns;
}

void GameState::nextTurn()
{
    if(m_turn <= m_maxTurns) {
        m_turn++;
    }
}

void GameState::nextTide()
{
    m_tideVector.pop_back();
    if(m_tideVector.size() <= 0)
        initTideVector();
}

void GameState::initTideVector()
{

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
