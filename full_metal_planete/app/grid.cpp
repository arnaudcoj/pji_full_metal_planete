#include "grid.h"

Grid::Grid(Hexagrid hexagrid)
{
    Hexagon hexagon = Hexagon(0, 0, 50);
    hexagon.setFillColor(sf::Color(255, 255, 255, 200));

    float width = hexagon.getGlobalBounds().width;
    float height = hexagon.getGlobalBounds().height;

    for(int i = 0; i < hexagrid.getWidth(); i++)
    {
        for(int j = 0; j < hexagrid.getHeight(); j++)
        {
            if(i % 2 == 0)
                hexagon.setPosition(i * width * 3/4, j * height);
            else
                hexagon.setPosition(i * width * 3/4, j * height - height * 0.5);
            m_grid.push_back(hexagon);
        }
    }
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::vector<sf::ConvexShape>::const_iterator hexagone;
    for(hexagone = m_grid.begin(); hexagone != m_grid.end(); ++hexagone)
    {
        target.draw(*hexagone, states);
    }
}
