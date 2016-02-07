#include "game.h"

Game::Game(const std::string& gridFile) : m_grid(gridFile)
{

}

Game::Game(Hexagrid& grid) : m_grid(grid) {

}
