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
    std::map<std::shared_ptr<Cell>, std::shared_ptr<Hexagon> > m_map;

public:
    Grid(Hexagrid hexagrid);
    std::shared_ptr<Hexagon> getHexagon(std::shared_ptr<Cell> cell);
    sf::Vector2f PixToCell(float xCursor, float yCursor);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // HEXGRID_HPP
