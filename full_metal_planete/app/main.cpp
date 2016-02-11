#include <SFML/Graphics.hpp>
#include "game.h"
#include<iostream>

using namespace std;

int main()
{
#include <SFML/Graphics.hpp>

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape hexagon(100, 6);
    hexagon.setFillColor(sf::Color(255, 255, 255, 255));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(hexagon);
        window.display();
    }

    Game game = Game();
    game.start();
    return 0;
}
