#include <SFML/Graphics.hpp>

#include "game.h"
#include "grid.h"


using namespace std;

int main()
{
    Hexagrid hexagrid = Hexagrid(16, 16);
    Game game = Game(hexagrid);

    float size = 100;
    float width = size * (game.getHexagrid().getWidth() / 2);
    width += size * (game.getHexagrid().getWidth() / 2) / 2;
    if (game.getHexagrid().getWidth() % 2 == 0)
        width -= size * 3/4;
    float height = sqrt(3)/2 * size * (game.getHexagrid().getHeight() - 1);

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
