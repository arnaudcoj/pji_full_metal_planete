#include "game.h"

Game::Game(const std::string &gridFile) : mGrid(generateGridFromFile(gridFile))
{

}

Hexagrid Game::generateGridFromFile(const std::string& gridFile) {
    YAML::Node gridInfo = YAML::LoadFile(gridFile);
    return Hexagrid();
}
