#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>
#include <engine.h>
#include <weapon.h>

class Cell;

class Piece
{
    std::weak_ptr<Cell> m_cell;
    Engine m_engine;
    Weapon m_weapon;

    sf::CircleShape m_sprite;

public:
    static constexpr float SIZE = 25;

    Piece(Engine::Type engineType = Engine::Type::TERRESTRIAL_ENGINE, Weapon::Type weaponType = Weapon::Type::NO_WEAPON);
    bool isOnCell();
    std::shared_ptr<Cell> getCell();
    void setCell(std::shared_ptr<Cell> cell);
    bool removeCell();

    Engine& getEngine();
    Weapon& getWeapon();

    void initSprite();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PIECE_H
