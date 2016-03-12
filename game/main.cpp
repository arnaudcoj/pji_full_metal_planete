#include <SFML/Graphics.hpp>

#include "game.h"

#include "assetmanager.h"
#include "animator.h"
#include "grid.h"
#include <iostream>
#include "pawns.h"

#include <cmath>

using namespace std;

int main()
{
    AssetManager manager;

    // Creating the game objects
    Hexagrid hexagrid("../../assets/maps/first.yaml");
    Grid grid(hexagrid);
    Game game = Game(hexagrid);
    Player player;
    PieceStock stock = game.getPieceStock();
    Pawns pawns(stock);

    player.move(stock.takePiece(), hexagrid.getCell(1, 1), Tide::MEDIUM_TIDE); // put a piece on the grid
    player.move(stock.takePiece(), hexagrid.getCell(2, 2), Tide::MEDIUM_TIDE);

    // calculate the window dimensions
    float width = Hexagon::WIDTH * (game.getHexagrid().getWidth() - 1) * 3 / 4;
    float height = Hexagon::HEIGHT * (game.getHexagrid().getHeight() - 0.5);

    // Creating the window
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(width, height), "Full Metal Planete", style);
    window.setFramerateLimit(60); // Set target Frames per second

    std::shared_ptr<Piece> selectedPiece = nullptr;

    switch(game.getGameState().getTide()) {
    case Tide::LOW_TIDE:
        std::cout << "Low" << std::endl;
        break;
    case Tide::MEDIUM_TIDE:
        std::cout << "Medium" << std::endl;
        break;
    case Tide::HIGH_TIDE:
        std::cout << "High" << std::endl;
        break;
    default:
        break;
    }

    sf::Clock clock;
    
    int angle = 0;
    bool rotation = false;

    // Game loop
    while(window.isOpen()) {
        // Returns the elapsed time and restarts the clock
        sf::Time deltaTime = clock.restart();

        // Handle Input
        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                switch(event.key.code) {
                case sf::Keyboard::Key::Space: {
                    game.getGameState().nextTurn();

                    switch(game.getGameState().getTide()) {
                    case Tide::LOW_TIDE:
                        std::cout << "Low" << std::endl;
                        break;
                    case Tide::MEDIUM_TIDE:
                        std::cout << "Medium" << std::endl;
                        break;
                    case Tide::HIGH_TIDE:
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
            case sf::Event::MouseButtonReleased: {
                sf::Vector2f vector = grid.PixToCell(event.mouseButton.x, event.mouseButton.y);
                std::shared_ptr<Cell> cell = hexagrid.getCell(vector.x, vector.y);

                if(selectedPiece != nullptr) {
                    sf::ConvexShape& sprite_hexagon = grid.getHexagon(selectedPiece->getCell())->getSprite();
                    sprite_hexagon.setOutlineColor(sf::Color::Black);
                    sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 25);

                    sf::Sprite& sprite_pawn = pawns.getPawn(selectedPiece)->getSprite();
                    float angle;

                    sf::Vector2f v1(
                        Hexagon::CellToPix(selectedPiece->getCell()->getX(), selectedPiece->getCell()->getY()));
                    sf::Vector2f v2(Hexagon::CellToPix(cell->getX(), cell->getY()));
                    
                    if(v1.x == v2.x && v1.y == v2.y) {
                        angle = sprite_pawn.getRotation();
                    } else {

                        float distance = sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2));

                        int alphaX = 1;
                        int alphaY;

                        if(v1.x == v2.x) {
                            alphaY = (v1.y > v2.y) ? 0 : 180;
                        } else if(v1.x < v2.x) {
                            alphaY = (v1.y > v2.y) ? 60 : 120;
                        } else {
                            alphaY = (v1.y > v2.y) ? 300 : 240;
                        }

                        angle = alphaY * alphaX;
                    }

                    std::cout << angle << std::endl;

                    while(sprite_pawn.getRotation() != angle) {
                        std::cout << sprite_pawn.getRotation() << std::endl;
                        sprite_pawn.rotate(-1);
                    }

                    // When we click on a cell: Move the selected piece to the cell
                    player.move(selectedPiece, cell, game.getGameState().getTide());
                    selectedPiece = nullptr;
                } else if(cell->isOccupied()) {
                    selectedPiece = cell->getPiece();
                    sf::ConvexShape& sprite_hexagon = grid.getHexagon(cell)->getSprite();
                    sprite_hexagon.setOutlineColor(sf::Color(0, 128, 128));
                    sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 10);
                }
            } break;
            default:
                break;
            }
        }

        // Update frame
        /*if(rotation && sprite_pawn.getRotation() != angle) {            
            sprite_pawn.rotate(-1);
        }*/
        grid.update();
        pawns.update(deltaTime);

        // Render frame
        window.clear(sf::Color::Black);

        window.draw(grid); // drawing the grid
        window.draw(pawns);

        window.display();
    }

    return 0;
}
