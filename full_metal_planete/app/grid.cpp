#include "grid.h"

Grid::Grid(Hexagrid hexagrid)
{
    for(int i = 0; i < hexagrid.getWidth(); i++)
    {
        for(int j = 0; j < hexagrid.getHeight(); j++)
        {
            std::shared_ptr<Cell> cell = hexagrid.getCell(i, j);
            Hexagon hexagon = Hexagon(cell, 50);

            float width = hexagon.getGlobalBounds().width;
            float height = hexagon.getGlobalBounds().height;

            hexagon.setOrigin(0, -(height / 2));

            if(cell->isHalfCell())
                hexagon.setFillColor(sf::Color(255, 255, 200, 200));
            else
                hexagon.setFillColor(sf::Color(255, 255, 255, 200));

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
    std::vector<Hexagon>::const_iterator hexagone;
    for(hexagone = m_grid.begin(); hexagone != m_grid.end(); ++hexagone)
    {
        target.draw(*hexagone, states);
    }
}
