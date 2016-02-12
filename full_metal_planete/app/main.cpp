#include <SFML/Graphics.hpp>

#include "game.h"
#include "grid.h"


using namespace std;

int main()
{
    // if the width of the hexagrid is <= 1,
    // there will be an error because we are hidding 1 cell
    // the width of the window will be <= 0
    Hexagrid hexagrid = Hexagrid(10, 10);
    Game game = Game(hexagrid);

    Player player;
    player.move(std::make_shared<Piece>(), hexagrid.getCell(1, 2));

    float size = 100;

    float width = size * (game.getHexagrid().getWidth() - 1) * 3/4;
    float height = sqrt(3)/2 * size * (game.getHexagrid().getHeight() - 0.5);

    // float size = width / (game.getHexagrid().getWidth() - 1) / 3/4

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
