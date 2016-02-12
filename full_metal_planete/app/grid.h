#ifndef HEXGRID_HPP
#define HEXGRID_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "hexagon.h"
#include "hexagrid.h"

class Grid : public sf::Drawable
{
    private:
        std::vector<sf::ConvexShape> m_grid;

    public:
        Grid(Hexagrid hexagrid);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // HEXGRID_HPP
