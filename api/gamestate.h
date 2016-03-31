#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <list>
#include <random>
#include <algorithm>
#include "tide.h"

typedef std::mt19937 RNG;

class GameState
{
    int m_maxTurns;
    int m_turn;

    RNG m_RNG;

    std::vector<Tide> m_tideVector;
    void initTideVector();

public:
    GameState();
    std::vector<Tide>& getTides();

    int getTurn();
    int getMaxTurns();
    void nextTurn();
    void nextTide();

    Tide& getTide();
};

#endif // GAMESTATE_H
