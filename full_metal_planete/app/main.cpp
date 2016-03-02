#include <SFML/Graphics.hpp>

#include "game.h"
#include "grid.h"

#include <math.h>

using namespace std;

std::shared_ptr<Cell> PixToHex(int xCursor, int yCursor, Hexagrid grid) {
    int x;
    int y;
    float size = Hexagon::SIZE;
    float width = Hexagon::WIDTH;
    float height = Hexagon::HEIGHT;
    float side = size * 3 / 2;;

    xCursor += width / 2;

    int ci = floor(xCursor / side);
    int cx = xCursor - side * ci;

    int ty = yCursor - (ci % 2) * height / 2;
    int cj = floor(ty / height);
    int cy = ty - height * cj;

    if (cx > abs(size / 2 - size * cy / height)) {
        x = ci;
        y = cj;
    } else {
        x = ci - 1;
        y = cj + (ci % 2) - ((cy < height / 2) ? 1 : 0);
    }

    if(x % 2)
        y++;

    // A COMMENTER !

    return grid.getCell(x, y);
}

int main()
{
    // Creating the game objects
    Hexagrid hexagrid = Hexagrid(10, 10);
    Game game = Game(hexagrid);
    Player player;

    std::shared_ptr<Piece> piece = std::make_shared<Piece>();
    player.move(piece, hexagrid.getCell(1, 1)); // put a piece on the grid

    std::shared_ptr<Piece> piece2 = std::make_shared<Piece>();
    player.move(piece2, hexagrid.getCell(5, 5)); // put a piece on the grid
    
    // calculate the window dimensions
    float width = Hexagon::WIDTH * (game.getHexagrid().getWidth() - 1) * 3/4;
    float height = Hexagon::HEIGHT * (game.getHexagrid().getHeight() - 0.5);
    
    // Creating the window
    sf::RenderWindow window(sf::VideoMode(width, height), "Full Metal Planete");
    //window.setFramerateLimit(60); // Set target Frames per second

    // Creating the graphical objects
    Grid grid = Grid(game.getHexagrid()); // creating the grid using the hexagrid of the game
    std::shared_ptr<Piece> selectedPiece = nullptr;

    //Game loop
    while (window.isOpen())
    {
        //Handle Input
        sf::Event event;

        while(window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Key::Escape:
                    window.close();
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::MouseButtonReleased:
            {
                std::shared_ptr<Cell> cell = PixToHex(event.mouseButton.x, event.mouseButton.y, game.getHexagrid());
                if(selectedPiece != nullptr) {
                    // When we click on a cell: Move the selected piece to the cell
                    player.move(selectedPiece, cell);
                    selectedPiece = nullptr;
                } else if(cell->isOccupied()){
                    selectedPiece = cell->getPiece();
                }
                break;
            }
            default:
                break;
            }
        }

        //Update frame

        grid.update();

        // Render frame
        window.clear(sf::Color::Black);

        window.draw(grid); // drawing the grid

        window.display();
    }
    
    return 0;
}
