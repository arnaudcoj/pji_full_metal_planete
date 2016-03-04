#ifndef WEAPON_H
#define WEAPON_H

#include <memory>
#include <list>
#include <cassert>

class Hexagrid;
class Cell;

class Weapon
{
public:
    enum class Type : char { CLASSIC_WEAPON, LONG_WEAPON, NO_WEAPON };
    Weapon(Type type = Type::NO_WEAPON);

    std::list<std::shared_ptr<Cell>> getRange(Hexagrid& grid, std::shared_ptr<Cell> cell);

private:
    Type m_type;
};

#endif // WEAPON_H
