#include "game.h"

using namespace std;

Game::Game()
    : m_hexagrid(Hexagrid())
    , m_gameState()
    , m_pieceStock()
{
    m_players.resize(1);
    m_players[0] = Player();
    
    m_pieceStock.addPiece(std::make_shared<Piece>());
    m_pieceStock.addPiece(std::make_shared<Piece>());
}

Game::Game(const std::string& gridFile)
    : m_hexagrid(gridFile)
    , m_gameState()
    , m_pieceStock()
{
    m_pieceStock.addPiece(std::make_shared<Piece>());
    m_pieceStock.addPiece(std::make_shared<Piece>());
}

Game::Game(Hexagrid grid)
    : m_hexagrid(grid)
    , m_gameState()
    , m_pieceStock()
{
    m_pieceStock.addPiece(std::make_shared<Piece>());
    m_pieceStock.addPiece(std::make_shared<Piece>());
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
