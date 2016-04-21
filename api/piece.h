#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>
#include <engine.h>
#include <weapon.h>
#include <container.h>

class Cell;
class Piece

{
private:
    std::weak_ptr<Cell> m_cell;
    Engine m_engine;
    Weapon m_weapon;
    Container m_container;
    int m_weight;

public:
    Piece(Engine::Type engineType = Engine::Type::TERRESTRIAL_ENGINE, Weapon::Type weaponType = Weapon::Type::NO_WEAPON, Container::Type container = Container::Type::NO_CONTAINER, int weight = 1);

    bool isOnCell();
    std::shared_ptr<Cell> getCell() const;
    void setCell(std::shared_ptr<Cell> cell);
    bool removeCell();
    int getWeight();
    
    virtual bool canBeCarried(Container container) const;
    virtual std::string getType() = 0;

    Engine& getEngine();
    Weapon& getWeapon();
    Container& getContainer();

};

#endif // PIECE_H
