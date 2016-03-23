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
    Game game = Game("../../assets/maps/fmp.yaml");
    Grid grid(game.getHexagrid());
    Player player;
    PieceStock stock = game.getPieceStock();
    Pawns pawns(stock);

    player.move(stock.takePiece(), game.getHexagrid().getCell(1, 1), Tide::MEDIUM_TIDE);
    // player.move(stock.takePiece(), game.getHexagrid().getCell(6, 4), Tide::MEDIUM_TIDE);
    // std::cout << stock.takePiece()->getType() << std::endl; // Pontoon
    stock.takePiece();
    player.move(stock.takePiece(), game.getHexagrid().getCell(5, 4), Tide::MEDIUM_TIDE);
    player.move(stock.takePiece(), game.getHexagrid().getCell(1, 3), Tide::MEDIUM_TIDE);
    player.move(stock.takePiece(), game.getHexagrid().getCell(5, 5), Tide::MEDIUM_TIDE);
    player.move(stock.takePiece(), game.getHexagrid().getCell(2, 2), Tide::MEDIUM_TIDE);
    player.move(stock.takePiece(), game.getHexagrid().getCell(2, 3), Tide::MEDIUM_TIDE);

    // calculate the window dimensions
    float width = Hexagon::WIDTH * (game.getHexagrid().getWidth() - 1) * 3 / 4;
    float height = Hexagon::HEIGHT * (game.getHexagrid().getHeight() - 0.5);

    // Creating the window
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(width, height), "Full Metal Planete", style);
    window.setFramerateLimit(60); // Set target Frames per second

    string tide = "";

    switch(game.getGameState().getTide()) {
    case Tide::LOW_TIDE:
        tide = "low";
        break;
    case Tide::MEDIUM_TIDE:
        tide = "medium";
        break;
    case Tide::HIGH_TIDE:
        tide = "high";
        break;
    default:
        break;
    }

    cout << tide << endl;

    sf::Clock clock;

    std::shared_ptr<Piece> selectedPiece = nullptr;
    std::stack<std::shared_ptr<Cell> > path;
    std::unordered_set<std::shared_ptr<Cell> > accessibleCells;

    std::shared_ptr<Cell> previous_cell = nullptr;

    bool travelling = false;

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
                    if(!travelling) {
                        game.getGameState().nextTurn();

                        switch(game.getGameState().getTide()) {
                        case Tide::LOW_TIDE:
                            tide = "low";
                            break;
                        case Tide::MEDIUM_TIDE:
                            tide = "medium";
                            break;
                        case Tide::HIGH_TIDE:
                            tide = "high";
                            break;
                        default:
                            break;
                        }

                        cout << tide << endl;
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
                std::shared_ptr<Cell> cell = game.getHexagrid().getCell(vector.x, vector.y);

                if(selectedPiece != nullptr && !travelling) {
                    grid.getHexagon(selectedPiece->getCell())->setSelected(false);
                    grid.getHexagon(cell)->setFocused(false);

                    if(accessibleCells.count(cell) == 1 &&
                        player.canMove(selectedPiece, cell, game.getGameState().getTide())) {
                        path = game.getHexagrid().getPath_Astar(
                            selectedPiece->getCell(), cell, selectedPiece, game.getGameState().getTide());

                        path.pop();
                        pawns.getPawn(selectedPiece)->travelTo(path.top());

                        travelling = true;
                    } else {
                        selectedPiece = nullptr;
                    }
                } else if(cell->isOccupied() && !travelling) {
                    selectedPiece = cell->getPiece();
                    accessibleCells =
                        game.getHexagrid().getAccessibleCells(player, game.getGameState().getTide(), selectedPiece);
                    grid.getHexagon(cell)->setSelected(true);
                }
            } break;
            case sf::Event::MouseMoved: {
                if(selectedPiece != nullptr && !travelling) {
                    sf::Vector2f vector = grid.PixToCell(event.mouseMove.x, event.mouseMove.y);

                    if(event.mouseMove.x >= 0 && event.mouseMove.y >= 0 && event.mouseMove.x <= window.getSize().x &&
                        event.mouseMove.y <= window.getSize().y) {
                        if(previous_cell != nullptr) {
                            grid.getHexagon(previous_cell)->setFocused(false);
                        }

                        std::shared_ptr<Cell> cell = game.getHexagrid().getCell(vector.x, vector.y);
                        if(cell->getPiece() != selectedPiece) {
                            std::shared_ptr<Hexagon> hexagon = grid.getHexagon(cell);
                            hexagon->setFocused(true);
                            if(accessibleCells.count(cell) == 1 &&
                                player.canMove(selectedPiece, cell, game.getGameState().getTide())) {
                                hexagon->setAccessible(true);

                            } else {
                                hexagon->setAccessible(false);
                            }
                            previous_cell = cell;
                        } else {
                            previous_cell = nullptr;
                        }
                    }
                }
            } break;
            default:
                break;
            }
        }

        // Update frame
        grid.update(tide);
        pawns.update(deltaTime);

        if(travelling && !pawns.getPawn(selectedPiece)->isTravelling()) {
            // Move the selected piece to the cell

            player.move(selectedPiece, path.top(), game.getGameState().getTide());
            path.pop();

            if(path.empty()) {
                selectedPiece = nullptr;
                travelling = false;
            } else {
                pawns.getPawn(selectedPiece)->travelTo(path.top());
            }
        }

        // Render frame
        window.clear(sf::Color::Black);

        window.draw(grid); // drawing the grid
        window.draw(pawns);

        window.display();
    }

    return 0;
}
