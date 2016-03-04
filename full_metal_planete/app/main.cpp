#include <SFML/Graphics.hpp>

#include "game.h"

using namespace std;

int main()
{
    // Creating the game objects
    Hexagrid hexagrid = Hexagrid("../../media/grids/first.yaml");
    //Hexagrid hexagrid = Hexagrid(10, 10);
    Game game = Game(hexagrid);
    Player player;

    std::shared_ptr<Piece> piece = std::make_shared<Piece>();
    player.move(piece, hexagrid.getCell(1, 1), Tide::MEDIUM_TIDE); // put a piece on the grid

    std::shared_ptr<Piece> piece2 = std::make_shared<Piece>();

    player.move(piece2, hexagrid.getCell(2, 2), Tide::MEDIUM_TIDE); // put a piece on the grid

    // calculate the window dimensions
    float width = Cell::WIDTH * (game.getHexagrid().getWidth() - 1) * 3/4;
    float height = Cell::HEIGHT * (game.getHexagrid().getHeight() - 0.5);

    // Creating the window
    sf::RenderWindow window(sf::VideoMode(width, height), "Full Metal Planete");
    //window.setFramerateLimit(60); // Set target Frames per second

    std::shared_ptr<Piece> selectedPiece = nullptr;

    switch (game.getGameState().getTide()) {
    case Tide::LOW_TIDE :
        std::cout << "Low" << std::endl;
        break;
    case Tide::MEDIUM_TIDE :
        std::cout << "Medium" << std::endl;
        break;
    case Tide::HIGH_TIDE :
        std::cout << "High" << std::endl;
        break;
    default:
        break;
    }

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
                case sf::Keyboard::Key:: Space:
                {
                    game.getGameState().nextTurn();

                    switch (game.getGameState().getTide()) {
                    case Tide::LOW_TIDE :
                        std::cout << "Low" << std::endl;
                        break;
                    case Tide::MEDIUM_TIDE :
                        std::cout << "Medium" << std::endl;
                        break;
                    case Tide::HIGH_TIDE :
                        std::cout << "High" << std::endl;
                        break;
                    default:
                        break;
                    }
                    break;
                }
                case sf::Keyboard::Key::Escape:
                    window.close();
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::MouseButtonReleased:
            {
                sf::Vector2f vector = hexagrid.PixToCell(event.mouseButton.x, event.mouseButton.y);
                std::shared_ptr<Cell> cell = hexagrid.getCell(vector.x, vector.y);
                if(selectedPiece != nullptr) {
                    // When we click on a cell: Move the selected piece to the cell
                    player.move(selectedPiece, cell, game.getGameState().getTide());
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

        hexagrid.update();

        // Render frame
        window.clear(sf::Color::White);

        window.draw(hexagrid); // drawing the grid

        window.display();
    }

    return 0;
}
