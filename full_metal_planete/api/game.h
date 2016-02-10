#ifndef GAME_H
#define GAME_H

#include <vector>

#include "hexagrid.h"
#include "player.h"

class Game
{
    Hexagrid m_hexagrid;
    std::vector<Player> m_players;
public:
    Game();
    void start();
};

#endif // GAME_H
