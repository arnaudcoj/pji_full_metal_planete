#include "grid.h"
#include <SFML/System/Vector2.hpp>

sf::Vector2f HexToPix(std::shared_ptr<Cell> cell) {
    float x;
    float y;
    float width = Hexagon::WIDTH;
    float height = Hexagon::HEIGHT;
    int xCell = cell->getX();
    int yCell = cell->getY();

    // setting the position of the hexagon
    if(xCell % 2 == 0) {
        x = xCell * width * 3/4;
        y = yCell * height;
    } else {
        x = xCell * width * 3/4;
        y = (yCell - 0.5) * height; // above the previous one
    }

    x -= width / 2; // adding an offset

    return sf::Vector2f(x, y);
}

Grid::Grid(Hexagrid hexagrid)
{
    // for each cell of the hexagrid
    for(int i = 0; i < hexagrid.getWidth(); i++)
    {
        for(int j = 0; j < hexagrid.getHeight(); j++)
        {
            Hexagon hexagon = Hexagon(hexagrid.getCell(i, j));

            hexagon.setPosition(HexToPix(hexagrid.getCell(i, j)));

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
