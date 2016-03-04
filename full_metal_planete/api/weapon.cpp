#include "weapon.h"

#include "hexagrid.h"
#include "cell.h"

Weapon::Weapon(Weapon::Type type) : m_type(type)
{

}

std::list<std::shared_ptr<Cell>> Weapon::getRange(Hexagrid& grid, std::shared_ptr<Cell> cell) {
    assert(cell != nullptr);

    switch(m_type) {
    case Type::CLASSIC_WEAPON :
        return grid.getCellsInRange(cell, 2);
    case Type::LONG_WEAPON :
        return grid.getCellsInRange(cell, 3 + cell->getRangeBonus());
    default:
        break;
    }

    return std::list<std::shared_ptr<Cell>>();
}
