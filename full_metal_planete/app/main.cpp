#include <SFML/Graphics.hpp>

#include "game.h"
#include "grid.h"


using namespace std;

int main()
{
    Game game = Game();

    float width = 100 * (game.getHexagrid().getWidth() - 3) - 25;
    float height = sqrt(3)/2 * 100 * (game.getHexagrid().getHeight() - 1);

    sf::RenderWindow window(sf::VideoMode(width, height), "Full Metal Planete");
    Grid grid = Grid(game.getHexagrid());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(grid);
        window.display();
    }

    return 0;
}
