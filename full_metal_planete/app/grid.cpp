#include "grid.h"

Grid::Grid(Hexagrid hexagrid)
{
    // for each cell of the hexagrid
    for(int i = 0; i < hexagrid.getWidth(); i++)
    {
        for(int j = 0; j < hexagrid.getHeight(); j++)
        {
            Hexagon hexagon = Hexagon(hexagrid.getCell(i, j));

            hexagon.setPosition(Tools::HexToPix(i, j));

            m_grid.push_back(hexagon);
        }
    }
}

// updates the grid
void Grid::update()
{
    std::vector<Hexagon>::iterator hexagone;
    for(hexagone = m_grid.begin(); hexagone != m_grid.end(); ++hexagone)
    {
        hexagone->update();
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
