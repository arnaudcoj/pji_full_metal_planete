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
    Game game = Game("../../assets/maps/first.yaml");
    Grid grid(game.getHexagrid());
    Player player;
    PieceStock stock = game.getPieceStock();
    Pawns pawns(stock);

    player.move(stock.takePiece(), game.getHexagrid().getCell(1, 1), Tide::MEDIUM_TIDE);
    // player.move(stock.takePiece(), game.getHexagrid().getCell(6, 4), Tide::MEDIUM_TIDE);
    // std::cout << stock.takePiece()->getType() << std::endl;
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

    sf::Clock clock;

    std::shared_ptr<Piece> selectedPiece = nullptr;
    std::stack<std::shared_ptr<Cell> > path;
    std::unordered_set<std::shared_ptr<Cell> > accessibleCells;
    std::shared_ptr<Cell> destination_cell = nullptr;

    bool travelling = false;

    bool rotating = false;
    float angle = 0;
    int direction = 0;

    bool moving = false;
    float distance;
    float progress = 0;

    std::shared_ptr<Cell> previous_cell = nullptr;

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

                // std::cout << vector.x << " " << vector.y << std::endl;

                if(selectedPiece != nullptr && !rotating && !moving) {
                    sf::ConvexShape& sprite_hexagon = grid.getHexagon(selectedPiece->getCell())->getSprite();
                    sprite_hexagon.setOutlineColor(sf::Color::Black);
                    sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 25);

                    if(accessibleCells.count(cell) == 1) {
                        path = game.getHexagrid().getPath_Astar(
                            selectedPiece->getCell(), cell, selectedPiece, game.getGameState().getTide());

                        path.pop();

                        sf::Sprite& sprite_pawn = pawns.getPawn(selectedPiece)->getSprite();

                        sf::ConvexShape& sprite_hexagon = grid.getHexagon(previous_cell)->getSprite();
                        sprite_hexagon.setOutlineColor(sf::Color::Black);
                        sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 25);

                        travelling = true;
                    } else {
                        selectedPiece = nullptr;
                        sf::ConvexShape& sprite_destination = grid.getHexagon(cell)->getSprite();
                        sprite_destination.setOutlineColor(sf::Color::Black);
                        sprite_destination.setOutlineThickness(-Hexagon::SIZE / 25);
                    }
                } else if(cell->isOccupied() && !rotating && !moving) {
                    selectedPiece = cell->getPiece();
                    accessibleCells =
                        game.getHexagrid().getAccessibleCells(player, game.getGameState().getTide(), selectedPiece);
                    sf::ConvexShape& sprite_hexagon = grid.getHexagon(cell)->getSprite();
                    sprite_hexagon.setOutlineColor(sf::Color(0, 128, 128));
                    sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 10);
                }
            } break;
            case sf::Event::MouseMoved: {
                if(selectedPiece != nullptr && !rotating && !moving) {
                    sf::Vector2f vector = grid.PixToCell(event.mouseMove.x, event.mouseMove.y);

                    if(event.mouseMove.x >= 0 && event.mouseMove.y >= 0 && event.mouseMove.x <= window.getSize().x &&
                        event.mouseMove.y <= window.getSize().y) {
                        if(previous_cell != nullptr) {
                            sf::ConvexShape& sprite_hexagon = grid.getHexagon(previous_cell)->getSprite();
                            sprite_hexagon.setOutlineColor(sf::Color::Black);
                            sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 25);
                        }

                        std::shared_ptr<Cell> cell = game.getHexagrid().getCell(vector.x, vector.y);
                        if(cell->getPiece() != selectedPiece) {
                            sf::ConvexShape& sprite_hexagon = grid.getHexagon(cell)->getSprite();
                            if(accessibleCells.count(cell) == 1 &&
                                player.canMove(selectedPiece, cell, game.getGameState().getTide())) {
                                sprite_hexagon.setOutlineColor(sf::Color::Green);
                                sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 10);
                            } else {
                                sprite_hexagon.setOutlineColor(sf::Color::Red);
                                sprite_hexagon.setOutlineThickness(-Hexagon::SIZE / 10);
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

        if(travelling && !rotating && !moving) {
            sf::Vector2f v1(Hexagon::CellToPix(selectedPiece->getCell()->getX(), selectedPiece->getCell()->getY()));
            sf::Vector2f v2(Hexagon::CellToPix(path.top()->getX(), path.top()->getY()));

            sf::Sprite& sprite_pawn = pawns.getPawn(selectedPiece)->getSprite();

            if(v1.x == v2.x && v1.y == v2.y) {
                angle = sprite_pawn.getRotation();
            } else {

                distance = sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2));

                if(v1.x == v2.x) {
                    angle = (v1.y > v2.y) ? 0 : 180;
                } else if(v1.x < v2.x) {
                    angle = (v1.y > v2.y) ? 60 : 120;
                } else {
                    angle = (v1.y > v2.y) ? 300 : 240;
                }

                if(sprite_pawn.getRotation() < 180) {
                    if(angle > sprite_pawn.getRotation() && angle <= sprite_pawn.getRotation() + 180) {
                        direction = 1;
                    } else {
                        direction = -1;
                    }
                } else {
                    if(angle > (int)(sprite_pawn.getRotation()) % 180 &&
                        angle <= (int)(sprite_pawn.getRotation()) % 180 + 180) {
                        direction = -1;
                    } else {
                        direction = 1;
                    }
                }
            }

            destination_cell = path.top();
            rotating = true;
        }

        if(selectedPiece != nullptr) {
            sf::Sprite& sprite_pawn = pawns.getPawn(selectedPiece)->getSprite();
            if(rotating && sprite_pawn.getRotation() != angle) {
                sprite_pawn.rotate(direction);
            } else if(rotating) {
                rotating = false;
                moving = true;
            } else if(moving && progress < distance) {
                // pawns.getPawn(selectedPiece)->getAnimator().setFrames...
                sprite_pawn.move(cos((90 - angle) * M_PI / 180.0), -sin((90 - angle) * M_PI / 180.0));
                progress++;
            } else if(moving) {
                moving = false;
                progress = 0;
                distance = 0;

                // Move the selected piece to the cell
                player.move(selectedPiece, path.top(), game.getGameState().getTide());
                sprite_pawn.setPosition(0, 0);

                path.pop();

                if(path.empty()) {
                    selectedPiece = nullptr;
                    travelling = false;
                }
            }
        }
        grid.update(tide);
        pawns.update(deltaTime);

        // Render frame
        window.clear(sf::Color::Black);

        window.draw(grid); // drawing the grid
        window.draw(pawns);

        window.display();
    }

    return 0;
}
