#ifndef GAME_H
#define GAME_H

#include <string>
#include <yaml-cpp/yaml.h>
#include <hexagrid.h>

class Game
{

    Hexagrid mGrid;

public:
    Game(const std::string &gridFile);

private:
    Hexagrid generateGridFromFile(const std::string &gridFile);

};

#endif // GAME_H
