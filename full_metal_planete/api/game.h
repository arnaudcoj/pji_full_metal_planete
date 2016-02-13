#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include <string>

#include "hexagrid.h"
#include "player.h"
#include "tide.h"
#include "lowtide.h"
#include "hightide.h"
#include "mediumtide.h"

//contient les informations sur l'etat du jeu
//permet de retourner statiquement l'état des marais
class Game
{
    Hexagrid m_hexagrid;
    std::vector<Player> m_players;
    static std::list<std::shared_ptr<Tide>> m_tideList;
    void initTideList();
public:
    ~Game();
    Game();
    Game(const std::string& gridFile);
    Game(Hexagrid& grid);
    Hexagrid getHexagrid();
    static const std::list<std::shared_ptr<Tide>> getTideList(); //liste de pointeurs pour permettre le polymorphisme
};

std::list<std::shared_ptr<Tide>> Game::m_tideList;

#endif // GAME_H
