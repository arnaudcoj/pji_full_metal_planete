#include "grid.h"

Grid::Grid(Hexagrid hexagrid)
{
    // for each cell of the hexagrid
    for(int i = 0; i < hexagrid.getWidth(); i++)
    {
        for(int j = 0; j < hexagrid.getHeight(); j++)
        {
            Hexagon hexagon = Hexagon(hexagrid.getCell(i, j));

            float width = hexagon.getGlobalBounds().width;
            float height = hexagon.getGlobalBounds().height;

            hexagon.setOrigin(0, -height / 2);

            // setting the position of the hexagon
            if(i % 2 == 0)
                hexagon.setPosition(i * width * 3/4, j * height);
            else
                hexagon.setPosition(i * width * 3/4, (j - 0.5) * height); // above the previous one
            m_grid.push_back(hexagon);
        }
    }
}

// calls the draw function of each hexagon of the grid
void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::vector<Hexagon>::const_iterator hexagone;
    for(hexagone = m_grid.begin(); hexagone != m_grid.end(); ++hexagone)
    {
        target.draw(*hexagone, states);
    }
}
