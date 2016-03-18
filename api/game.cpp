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
    m_pieceStock.addPiece(std::make_shared<TankPiece>());
    m_pieceStock.addPiece(std::make_shared<BigTankPiece>());
    m_pieceStock.addPiece(std::make_shared<BargePiece>());
    m_pieceStock.addPiece(std::make_shared<CrabPiece>());
    m_pieceStock.addPiece(std::make_shared<PatrolBoatPiece>());
    m_pieceStock.addPiece(std::make_shared<PontoonPiece>());
    m_pieceStock.addPiece(std::make_shared<WeatherLayerPiece>());
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
