#include "game.h"

using namespace std;

Game::Game()
    : m_hexagrid(Hexagrid())
    , m_gameState()
    , m_pieceStock()
{
    m_players.resize(1);
    m_players[0] = Player();
}

Game::Game(const std::string& gridFile)
    : m_hexagrid(gridFile)
    , m_gameState()
    , m_pieceStock()
{
}

Game::Game(Hexagrid grid)
    : m_hexagrid(grid)
    , m_gameState()
    , m_pieceStock()
{
}

Hexagrid& Game::getHexagrid()
{
    return m_hexagrid;
}

GameState& Game::getGameState()
{
    return m_gameState;
}

PieceStock& Game::getPieceStock()
{
    return m_pieceStock;
}
