#include "grid.h"

Grid::Grid(Hexagrid hexagrid)
{
    // for each cell of the hexagrid
    for(int i = 0; i < hexagrid.getWidth(); i++)
    {
        for(int j = 0; j < hexagrid.getHeight(); j++)
        {
            m_grid.push_back(Hexagon(hexagrid.getCell(i, j)));
        }
    }
}

sf::Vector2f Grid::PixToCell(int xCursor, int yCursor) {
    int x;
    int y;
    float size = Hexagon::SIZE;
    float width = Hexagon::WIDTH;
    float height = Hexagon::HEIGHT;
    float side = size * 3 / 2;;

    xCursor += width / 2;

    int ci = floor(xCursor / side);
    int cx = xCursor - side * ci;

    int ty = yCursor - (ci % 2) * height / 2;
    int cj = floor(ty / height);
    int cy = ty - height * cj;

    if (cx > std::abs(size / 2 - size * cy / height)) {
        x = ci;
        y = cj;
    } else {
        x = ci - 1;
        y = cj + (ci % 2) - ((cy < height / 2) ? 1 : 0);
    }

    if(x % 2)
        y++;

    // A COMMENTER !

    return sf::Vector2f(x, y);
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
        hexagone->draw(target, states);
    }
}