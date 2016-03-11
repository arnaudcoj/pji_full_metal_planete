#ifndef HEXGRID_HPP
#define HEXGRID_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "hexagrid.h"
#include "hexagon.h"

class Grid : public sf::Drawable
{
private:
    std::vector<std::shared_ptr<Hexagon>> m_grid;

public:
    Grid(Hexagrid hexagrid);
    sf::Vector2f PixToCell(int xCursor, int yCursor);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // HEXGRID_HPP
