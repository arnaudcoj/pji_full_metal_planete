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

    // create the player
    Player player;
    player.move(std::make_shared<Piece>(), hexagrid.getCell(1, 2)); // put a piece on the grid at (1, 2)

    // calculate the window dimensions
    float width = Hexagon::WIDTH * (game.getHexagrid().getWidth() - 1) * 3/4;
    // sqrt(3)/2 * Hexagon::WIDTH is the height of a hexagon. It can't be a const of Hexagon because of sqrt()
    float height = sqrt(3)/2 * Hexagon::WIDTH * (game.getHexagrid().getHeight() - 0.5);

    // float size = width / (game.getHexagrid().getWidth() - 1) / 3/4

    sf::RenderWindow window(sf::VideoMode(width, height), "Full Metal Planete"); // creating the window
    Grid grid = Grid(game.getHexagrid()); // creating the grid using the hexagrid of the game

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(grid); // drawing the grid
        window.display();
    }

    return 0;
}
