#include <SFML/Graphics.hpp>

#include "game.h"
#include "grid.h"
#include "tools.h"

using namespace std;

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
                sf::Vector2f vector = Tools::PixToHex(event.mouseButton.x, event.mouseButton.y);
                std::shared_ptr<Cell> cell = hexagrid.getCell(vector.x, vector.y);
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
