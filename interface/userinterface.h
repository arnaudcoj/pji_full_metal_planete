#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <SFML/Graphics.hpp>

#include "game.h"
#include "hexagon.h"
#include "assetmanager.h"
#include <string> 

class UserInterface : public sf::Drawable
{
private:
    sf::RenderWindow& m_window;
    sf::View m_view;
    Game& m_game;
    sf::Text m_turn;
    sf::Text m_player;
    sf::Text m_actions;
    sf::Text m_tide;

public:
    UserInterface(Game& game, sf::RenderWindow& window);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // USERINTERFACE_H
