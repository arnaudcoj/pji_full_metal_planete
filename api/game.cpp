#include "game.h"

using namespace std;

Game::Game(int nbPlayer)
    : m_hexagrid(Hexagrid())
    , m_gameState()
    , m_pieceStock()
    , m_players()
    , m_currentPlayer()
{
    init(nbPlayer);
}

Game::Game(const std::string& gridFile, int nbPlayer)
    : m_hexagrid(gridFile)
    , m_gameState()
    , m_pieceStock()
    , m_players()
    , m_currentPlayer()
{

    for(int i = 1; i <= nbPlayer; i++) {
        m_players.emplace_back(i);
    }
    m_currentPlayer = m_players.begin();

    populatePieceStock(nbPlayer);
}

Game::Game(Hexagrid grid, int nbPlayer)
    : m_hexagrid(grid)
    , m_gameState()
    , m_pieceStock()
    , m_players()
    , m_currentPlayer()
{
    init(nbPlayer);
}

void Game::init(int nbPlayer)
{

    for(int i = 1; i <= nbPlayer; i++) {
        m_players.emplace_back(i);
    }
    m_currentPlayer = m_players.begin();

    populatePieceStock(nbPlayer);
}

void Game::populatePieceStock(int nbPlayers)
{
    // Reserve commune
    for(int i = 0; i < 4 * nbPlayers; i++)
        m_pieceStock.addPiece(std::make_shared<TankPiece>());
    for(int i = 0; i < nbPlayers; i++) {
        m_pieceStock.addPiece(std::make_shared<CrabPiece>());
        m_pieceStock.addPiece(std::make_shared<PontoonPiece>());
    }

    // Reserve pour chaque player
    for(int i = 0; i < nbPlayers; i++) {
        m_pieceStock.addPiece(std::make_shared<PontoonPiece>());
        m_pieceStock.addPiece(std::make_shared<BigTankPiece>());
        m_pieceStock.addPiece(std::make_shared<BargePiece>());
        m_pieceStock.addPiece(std::make_shared<CrabPiece>());
        m_pieceStock.addPiece(std::make_shared<WeatherLayerPiece>());
        for(int j = 0; j < 4; j++)
            m_pieceStock.addPiece(std::make_shared<TankPiece>());
        for(int j = 0; j < 2; j++)
            m_pieceStock.addPiece(std::make_shared<PatrolBoatPiece>());
    }
}

void Game::distributeArmy()
{
    for(Player& player : m_players) {
        player.getPieceStock().addPiece(m_pieceStock.takePontoonPiece());
        player.getPieceStock().addPiece(m_pieceStock.takeBigTankPiece());
        player.getPieceStock().addPiece(m_pieceStock.takeBargePiece());
        player.getPieceStock().addPiece(m_pieceStock.takeCrabPiece());
        player.getPieceStock().addPiece(m_pieceStock.takeWeatherLayerPiece());
        for(int i = 0; i < 4; i++)
            player.getPieceStock().addPiece(m_pieceStock.takeTankPiece());
        for(int i = 0; i < 2; i++)
            player.getPieceStock().addPiece(m_pieceStock.takePatrolBoatPiece());
    }
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

bool Game::isStarted() const {
    return m_gameState.getTurn() != 0;
}

bool Game::isFinished() const {
    return m_gameState.getTurn() > 25;
}

void Game::startGame()
{
    distributeArmy();
    newTurn();
}

void Game::passTurn()
{
    if(m_gameState.getTurn() <= 0 || m_gameState.getTurn() > 25)
        return;

    m_currentPlayer++;
    if(m_currentPlayer == m_players.end()) {
        m_currentPlayer = m_players.begin();
        newTurn();
    }
}

void Game::newTurn()
{
    m_gameState.nextTurn();
    switch(m_gameState.getTurn()) {
    case 1:
        // choix de la zone d'aterrissage
        break;
    case 2:
        // deploiement
        break;
    case 3:
        // 5 points d'action
        m_gameState.nextTide();
        break;
    case 4:
        // 10 points d'action
        m_gameState.nextTide();
        break;
    case 21:
        // demande si veut rester
        // même comportement que pour default
        m_gameState.nextTide();
        break;
    case 25:
    // fin du jeu
    default:
        // tours 5 à 20, 22 à 24 -- 15 points d'action
        m_gameState.nextTide();
    }
    m_hexagrid.update(m_gameState.getTide());
}

void Game::placePiece(std::shared_ptr<Cell> cell, std::shared_ptr<Piece> piece)
{
    cell->setPiece(piece);
    piece->setCell(cell);
}
