#ifndef GAME_H
#define GAME_H

#include <string>
#include <yaml-cpp/yaml.h>
#include <hexagrid.h>

class Game
{
    Hexagrid m_grid;

public:
    Game(const std::string& gridFile);
    Game(Hexagrid& grid);

private:
    Hexagrid generateGridFromFile(const std::string &gridFile);

};

#endif // GAME_H
