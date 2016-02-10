#include "game.h"

#include <iostream>

using namespace std;

Game::Game() : m_hexagrid(Hexagrid())
{
    m_players.resize(1);
    m_players[0] = Player();
}
    
Game::Game(const std::string& gridFile) : m_hexagrid(gridFile)
{

}

Game::Game(Hexagrid& grid) : m_hexagrid(grid) {

}

void Game::start() {
    Piece piece;
    Cell cell;
    m_players[0].move(piece, cell);
}
