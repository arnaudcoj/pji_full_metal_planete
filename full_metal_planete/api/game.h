#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#include "hexagrid.h"
#include "player.h"

class Game
{
    Hexagrid m_hexagrid;
    std::vector<Player> m_players;
public:
    Game();
    Game(const std::string& gridFile);
    Game(Hexagrid& grid);
    void start();

};

#endif // GAME_H
