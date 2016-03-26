#include <SFML/Graphics.hpp>

#include "game.h"

#include "assetmanager.h"
#include "animator.h"
#include "grid.h"
#include <iostream>
#include "pawns.h"

#include <cmath>

using namespace std;

void centerView(sf::Vector2f worldPos, sf::Vector2f worldSize, sf::View& view)
{
    if(worldPos.x < view.getSize().x / 2) {
        worldPos.x = view.getSize().x / 2;
    } else if(worldPos.x > worldSize.x - view.getSize().x / 2) {
        worldPos.x = worldSize.x - view.getSize().x / 2;
    }

    if(worldPos.y < view.getSize().y / 2) {
        worldPos.y = view.getSize().y / 2;
    } else if(worldPos.y > worldSize.y - view.getSize().y / 2) {
        worldPos.y = worldSize.y - view.getSize().y / 2;
    }

    view.setCenter(worldPos.x, worldPos.y);
}

int main()
{
    AssetManager manager;

    // Creating the game objects
    Game game = Game("../../assets/maps/fmp.yaml", 1);
    Grid grid(game.getHexagrid());
    Player player = game.getCurrentPlayer();
    PieceStock stock = game.getPieceStock();
    Pawns pawns(stock);

    player.move(stock.takePiece(), game.getHexagrid().getCell(1, 1));
    // player.move(stock.takePiece(), game.getHexagrid().getCell(6, 4));
    // std::cout << stock.takePiece()->getType() << std::endl; // Pontoon

    stock.takePiece();
    player.move(stock.takePiece(), game.getHexagrid().getCell(7, 7)); // Boat
    player.move(stock.takePiece(), game.getHexagrid().getCell(1, 3));
    player.move(stock.takePiece(), game.getHexagrid().getCell(7, 6)); // Barge
    player.move(stock.takePiece(), game.getHexagrid().getCell(2, 2));
    player.move(stock.takePiece(), game.getHexagrid().getCell(2, 3));

    // Creating the window
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Full Metal Planete", style);
    window.setFramerateLimit(60); // Set target Frames per second

    auto wSize = window.getSize();
    sf::View view(sf::FloatRect(0, 0, wSize.x, wSize.y));
    window.setView(view);

    sf::Vector2f worldSize(Hexagon::WIDTH * (game.getHexagrid().getWidth() - 1) * 3 / 4,
        Hexagon::HEIGHT * (game.getHexagrid().getHeight() - 0.5));

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
                        game.passTurn();

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
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                case sf::Keyboard::Key::Up: {
                    if(view.getSize().x * 0.9 > wSize.x && view.getSize().y * 0.9 > wSize.y) {
                        view.zoom(0.9);
                        sf::Vector2f worldPos(view.getCenter());
                        centerView(worldPos, worldSize, view);
                        window.setView(view);
                    }
                } break;
                case sf::Keyboard::Key::Down: {
                    if(view.getSize().x * 1.1 < worldSize.x && view.getSize().y * 1.1 < worldSize.y) {
                        view.zoom(1.1);
                        sf::Vector2f worldPos(view.getCenter());
                        centerView(worldPos, worldSize, view);
                        window.setView(view);
                    }
                } break;
                default:
                    break;
                }
                break;
            case sf::Event::MouseButtonReleased: {
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

                // conversion en coordonnées "monde"
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                sf::Vector2f vector = grid.PixToCell(worldPos.x, worldPos.y);
                std::shared_ptr<Cell> cell = game.getHexagrid().getCell(vector.x, vector.y);

                if(cell != nullptr) {
                    if(selectedPiece != nullptr && !travelling) {
                        grid.getHexagon(selectedPiece->getCell())->setSelected(false);
                        grid.getHexagon(cell)->setFocused(false);

                        if(accessibleCells.count(cell) == 1 && player.canMove(selectedPiece, cell)) {
                            path = game.getHexagrid().getPath_Astar(selectedPiece->getCell(), cell, selectedPiece);

                            path.pop();
                            pawns.getPawn(selectedPiece)->travelTo(path.top());

                            travelling = true;
                        } else {
                            selectedPiece = nullptr;
                        }
                    } else if(cell->isOccupied() && !travelling) {
                        selectedPiece = cell->getPiece();

                        accessibleCells = game.getHexagrid().getAccessibleCells(player, selectedPiece);
                        grid.getHexagon(cell)->setSelected(true);
                        for(std::shared_ptr<Cell> cell : accessibleCells) {
                            // grid.getHexagon(cell)->setFocused(true);
                        }
                    } else {
                        centerView(worldPos, worldSize, view);
                        window.setView(view);
                    }
                }

            } break;
            case sf::Event::MouseMoved: {
                if(selectedPiece != nullptr && !travelling) {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

                    // conversion en coordonnées "monde"
                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                    sf::Vector2f vector = grid.PixToCell(worldPos.x, worldPos.y);
                    std::shared_ptr<Cell> cell = game.getHexagrid().getCell(vector.x, vector.y);

                    if(cell != nullptr) {

                        if(previous_cell != nullptr) {
                            grid.getHexagon(previous_cell)->setFocused(false);
                        }

                        if(cell->getPiece() != selectedPiece) {
                            std::shared_ptr<Hexagon> hexagon = grid.getHexagon(cell);
                            hexagon->setFocused(true);
                            if(accessibleCells.count(cell) == 1 && player.canMove(selectedPiece, cell)) {
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
        grid.update();
        pawns.update(deltaTime);

        if(selectedPiece != nullptr) {
            sf::Vector2f position = pawns.getPawn(selectedPiece)->m_sprite.getPosition();
            centerView(position, worldSize, view);
            window.setView(view);
        }

        if(travelling && !pawns.getPawn(selectedPiece)->isTravelling()) {
            // Move the selected piece to the cell

            player.move(selectedPiece, path.top());
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
