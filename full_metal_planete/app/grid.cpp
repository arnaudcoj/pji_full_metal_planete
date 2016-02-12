#include "grid.h"

Grid::Grid(Hexagrid hexagrid)
{
    for(int i = 0; i < hexagrid.getWidth(); i++)
    {
        for(int j = 0; j < hexagrid.getHeight(); j++)
        {
            Hexagon hexagon = Hexagon(0, (sqrt(3)/2 * 100) / 2, 50);

            if(hexagrid.getCell(i, j)->isHalfCell())
                hexagon.setFillColor(sf::Color(255, 255, 200, 200));
            else
                hexagon.setFillColor(sf::Color(255, 255, 255, 200));

            if(hexagrid.getCell(i, j)->getPiece() != nullptr)
                hexagon.setFillColor(sf::Color(255, 0, 0, 200));

            float width = hexagon.getGlobalBounds().width;
            float height = hexagon.getGlobalBounds().height;

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
