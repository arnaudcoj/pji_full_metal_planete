#ifndef HEXAGON_H
#define HEXAGON_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "cell.h"
#include "pawn.h"
#include "assetmanager.h"

class Hexagon
{
private:
    std::shared_ptr<Cell> m_cell;
    sf::ConvexShape m_sprite;
    
    bool m_selected;
    bool m_focused;
    bool m_accessible;

public:
    static const float SIZE;
    static const float WIDTH;
    static const float HEIGHT;

    Hexagon(std::shared_ptr<Cell> cell);
    void setSelected(bool selected);
    void setFocused(bool focused);
    void setAccessible(bool accessible);
    void update(std::string tide);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    static sf::Vector2f CellToPix(int xCell, int yCell);
};

#endif // HEXAGON_H
