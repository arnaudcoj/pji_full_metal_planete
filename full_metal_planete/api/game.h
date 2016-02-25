#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include <string>

#include "hexagrid.h"
#include "gamestate.h"
#include "player.h"
#include "tide.h"

//contient les informations sur l'etat du jeu
class Game
{
    Hexagrid m_hexagrid;
    std::vector<Player> m_players;
    GameState m_gameState;

public:

    Game();
    Game(const std::string& gridFile);
    Game(Hexagrid grid);
    Hexagrid& getHexagrid();
    GameState& getGameState();
};

#endif // GAME_H
