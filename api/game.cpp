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
    init(nbPlayer);
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
    assert(!isStarted());

    for(int i = 1; i <= nbPlayer; i++) {
        m_players.emplace_back(i);
    }
    m_currentPlayer = m_players.begin();

    populatePieceStock(nbPlayer);
}

void Game::populatePieceStock(int nbPlayers)
{
    assert(!isStarted());
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

    for(int i = 0; i < 100; i++) {
        m_pieceStock.addPiece(std::make_shared<MineralPiece>());
    }
}

void Game::placeMinerals(sf::Vector2i firstMineral)
{
    int firstX = firstMineral.x;
    int firstY = firstMineral.y;

    assert(0 <= firstX && firstX < 3);
    assert(0 <= firstY && firstY < 3);

    for(int i = firstX; i < m_hexagrid.getWidth(); i += 6) {

        for(int j = firstY; j < m_hexagrid.getHeight(); j += 3) {
            std::shared_ptr<Cell> cell = m_hexagrid.getCell(i, j);
            if(cell->canContainMineral())
                placePiece(cell, m_pieceStock.takeMineralPiece());
        }

        // decalage de 1 vers le haut
        if(i + 3 < m_hexagrid.getWidth())
            for(int j = firstY - 1; j < m_hexagrid.getHeight(); j += 3) {
                if(j >= 0) {
                    std::shared_ptr<Cell> cell = m_hexagrid.getCell(i + 3, j);
                    if(cell->canContainMineral())
                        placePiece(cell, m_pieceStock.takeMineralPiece());
                }
            }
    }
}

void Game::distributeArmy()
{
    assert(!isStarted());
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

bool Game::isStarted() const
{
    return m_gameState.getTurn() != 0;
}

bool Game::isFinished() const
{
    return m_gameState.getTurn() > 25;
}

void Game::startGame(sf::Vector2i firstMineral)
{
    assert(!isStarted());

    // generate x and y values for mineral placement
    if(firstMineral.x < 0 || firstMineral.x > 2 || firstMineral.y < 0 || firstMineral.y > 2) {
        RNG rng;
        rng.seed(std::random_device()());

        std::uniform_int_distribution<uint32_t> range(0, 2);

        firstMineral.x = range(rng);
        firstMineral.y = range(rng);
    }
    placeMinerals(firstMineral);

    distributeArmy();
    m_gameState.nextTurn();
}

void Game::passTurn()
{
    if(!isStarted() || isFinished())
        return;

    m_currentPlayer++;
    if(m_currentPlayer == m_players.end()) {
        m_currentPlayer = m_players.begin();
        newTurn();
    }
}

void Game::newTurn()
{
    assert(isStarted());
    assert(!isFinished());

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
    assert(cell != nullptr);
    assert(piece != nullptr);

    cell->setPiece(piece);
    piece->setCell(cell);
}
