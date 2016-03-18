#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include <string>

#include "hexagrid.h"
#include "gamestate.h"
#include "player.h"
#include "tide.h"
#include "piecestock.h"

#include "tankpiece.h"
#include "bigtankpiece.h"
#include "bargepiece.h"
#include "crabpiece.h"
#include "patrolboatpiece.h"
#include "pontoonpiece.h"
#include "weatherlayerpiece.h"

//contient les informations sur l'etat du jeu
class Game
{
    Hexagrid m_hexagrid;
    std::vector<Player> m_players;
    GameState m_gameState;
    PieceStock m_pieceStock;

public:

    Game();
    Game(const std::string& gridFile);
    Game(Hexagrid grid);
    Hexagrid& getHexagrid();
    GameState& getGameState();
    PieceStock& getPieceStock();
};

#endif // GAME_H
