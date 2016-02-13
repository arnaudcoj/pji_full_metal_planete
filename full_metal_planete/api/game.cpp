#include "game.h"

using namespace std;

Game::Game() : m_hexagrid(Hexagrid()), m_nbTurns(MAX_TURNS)
{
    m_players.resize(1);
    m_players[0] = Player();

    initTideList();
}
    
Game::Game(const std::string& gridFile) : m_hexagrid(gridFile), m_nbTurns(MAX_TURNS)
{
    initTideList();
}

Game::Game(Hexagrid grid) : m_hexagrid(grid), m_nbTurns(MAX_TURNS) {
    initTideList();
}

Hexagrid Game::getHexagrid() {
    return m_hexagrid;
}

void Game::initTideList() {

    std::shared_ptr<HighTide> ht = std::make_shared<HighTide>();
    std::shared_ptr<MediumTide> mt = std::make_shared<MediumTide>();
    std::shared_ptr<LowTide> lt = std::make_shared<LowTide>();

    m_tideList.push_back(ht);
    m_tideList.push_back(mt);
    m_tideList.push_back(ht);
    m_tideList.push_back(lt);
    m_tideList.push_back(mt);
}

std::list<std::shared_ptr<Tide>> Game::getTideList() {
    return m_tideList;
}

int Game::getNbTurns() {
    return m_nbTurns;
}

int Game::getMaxTurns() {
    return MAX_TURNS;
}

void Game::nextTurn() {
    m_nbTurns--;
}

Game::~Game() {
    m_tideList.clear();
}
