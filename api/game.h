#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include <iterator>
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
    std::list<Player> m_players;
    std::list<Player>::iterator m_currentPlayer;
    GameState m_gameState;
    PieceStock m_pieceStock;

public:

    Game(int nbPlayer = 1);
    Game(const std::string& gridFile, int nbPlayer = 1);
    Game(Hexagrid grid, int nbPlayer = 1);
    
    void passTurn();
    
    std::list<Player> getPlayers() const;
    Player& getCurrentPlayer() ;
    Hexagrid& getHexagrid() ;
    GameState& getGameState() ;
    PieceStock& getPieceStock() ;
};

#endif // GAME_H
