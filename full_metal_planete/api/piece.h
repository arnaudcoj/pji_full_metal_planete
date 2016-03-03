#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>

class Cell;

enum class Engine {TERRESTRIAL_ENGINE, HEAVY_TERRESTRIAL_ENGINE, MARINE_ENGINE};

class Piece
{
    std::weak_ptr<Cell> m_cell;
    Engine m_engine;

    sf::CircleShape m_sprite;

public:
    static constexpr float SIZE = 25;

    Piece(Engine engine = Engine::TERRESTRIAL_ENGINE);
    bool isOnCell();
    std::shared_ptr<Cell> getCell();
    void setCell(std::shared_ptr<Cell> cell);
    bool removeCell();

    bool isTerrestrial();
    bool isMarine();
    bool canClimb();

    void initSprite();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PIECE_H
