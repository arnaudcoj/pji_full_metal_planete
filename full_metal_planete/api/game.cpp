#include "game.h"

#include <iostream>

using namespace std;

Game::Game() : m_hexagrid(Hexagrid())
{
    m_players.resize(1);
    m_players[0] = Player();
}

void Game::start() {
    std::shared_ptr<Piece> piece = std::make_shared<Piece>();
    std::shared_ptr<Cell> cell = std::make_shared<Cell>();
    m_players[0].move(piece, cell);
}
