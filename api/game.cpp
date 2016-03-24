#include "game.h"

using namespace std;

Game::Game(int nbPlayer)
    : m_hexagrid(Hexagrid())
    , m_gameState()
    , m_pieceStock()
    , m_players()
    , m_currentPlayer()
{
    for(int i = 1; i <= nbPlayer; i++) {
        m_players.emplace_back(i);
    }
    m_currentPlayer = m_players.begin();
}

Game::Game(const std::string& gridFile, int nbPlayer)
    : m_hexagrid(gridFile)
    , m_gameState()
    , m_pieceStock()
    , m_players()
    , m_currentPlayer()
{
    m_pieceStock.addPiece(std::make_shared<TankPiece>());
    m_pieceStock.addPiece(std::make_shared<BigTankPiece>());
    m_pieceStock.addPiece(std::make_shared<BargePiece>());
    m_pieceStock.addPiece(std::make_shared<CrabPiece>());
    m_pieceStock.addPiece(std::make_shared<PatrolBoatPiece>());
    m_pieceStock.addPiece(std::make_shared<PontoonPiece>());
    m_pieceStock.addPiece(std::make_shared<WeatherLayerPiece>());

    for(int i = 1; i <= nbPlayer; i++) {
        m_players.emplace_back(i);
    }
    m_currentPlayer = m_players.begin();
}

Game::Game(Hexagrid grid, int nbPlayer)
    : m_hexagrid(grid)
    , m_gameState()
    , m_pieceStock()
    , m_players()
    , m_currentPlayer()
{

    for(int i = 1; i <= nbPlayer; i++) {
        m_players.emplace_back(i);
    }
    m_currentPlayer = m_players.begin();
}

std::list<Player> Game::getPlayers() const
{
    return m_players;
}

Player& Game::getCurrentPlayer()
{
    return *m_currentPlayer;
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
void Game::passTurn()
{
    m_currentPlayer++;
    if(m_currentPlayer == m_players.end()) {
        m_currentPlayer = m_players.begin();
        m_gameState.nextTurn();
    }
}
