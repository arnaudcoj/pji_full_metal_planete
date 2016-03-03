#include "hexagrid.h"

using namespace std;

std::shared_ptr<Cell> createCell(int i, int j, bool halfCell, int type, int area);

Hexagrid::Hexagrid(int width, int height) {
    int i, j;

    m_grid.resize(width);
    for (int i = 0; i < width; ++i)
      m_grid[i].resize(height);

    for(i = 1; i < width - 1; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = createCell(i, j, false, 0, 0);
    }

    //1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = createCell(0, j, true, 0, 0);

    //derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = createCell(width - 1, j, true, 0, 0);

    //premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, true, 0, 0);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, false, 0, 0);
    }

    //derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, false, 0, 0);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, true, 0, 0);
    }
}

//appelle Hexagrid(YAML::Node gridInfo) avec comme node le fichier yaml donné en paramètre
Hexagrid::Hexagrid(string gridFile) : Hexagrid(YAML::LoadFile(gridFile)) {

}

// a reproprer
Hexagrid::Hexagrid(YAML::Node gridInfo) {
    unsigned int i, j;
    size_t width, height;

    std::vector<std::vector<std::vector<int>>> yGrid = gridInfo["cells"].as<std::vector<std::vector<std::vector<int>>>>();

    //plus simple d'écrire ligne par ligne dans yaml mais nous on écrit colonnes par colonnes, donc inversons i, j, width et height
    width = yGrid[0].size();
    height = yGrid.size();

    m_grid.resize(width);
    for (i = 0; i < width; ++i)
      m_grid[i].resize(height);

    for(i = 1; i < width - 1; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = createCell(i, j, false, yGrid[j][i][0], yGrid[j][i][1]);
    }

    //1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = createCell(0, j, true, yGrid[j][0][0], yGrid[j][0][1]);

    //derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = createCell(width - 1, j, true, yGrid[j][width - 1][0], yGrid[j][width - 1][1]);

    //premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, true, yGrid[0][i][0], yGrid[0][i][1]);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, false, yGrid[0][i][0], yGrid[0][i][1]);
    }

    //derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, false, yGrid[height - 1][i][0], yGrid[height - 1][i][1]);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, true, yGrid[height - 1][i][0], yGrid[height - 1][i][1]);
    }
}

int Hexagrid::getWidth() {
    return m_grid.size();
}

int Hexagrid::getHeight() {
    return m_grid[0].size();
}

std::shared_ptr<Cell> Hexagrid::getCell(int x, int y) {
    int width = m_grid.size();
    int height = m_grid.front().size();

    if(0 <= x && x < width &&
            0 <= y && y < height)
        return m_grid[x][y];
    else
        return nullptr;
}

std::shared_ptr<Cell> Hexagrid::getTopCell(std::shared_ptr<Cell> cell) {
    sf::Vector2i coord = cell->getCoord();
    return m_grid[coord.x][coord.y - 1];
}

std::shared_ptr<Cell> Hexagrid::getBottomCell(std::shared_ptr<Cell> cell) {
    sf::Vector2i coord = cell->getCoord();
    return m_grid[coord.x][coord.y + 1];
}

std::shared_ptr<Cell> Hexagrid::getLeftTopCell(std::shared_ptr<Cell> cell) {
    sf::Vector2i coord = cell->getCoord();
    return m_grid[coord.x - 1][coord.y - (coord.x % 2)];
}

std::shared_ptr<Cell> Hexagrid::getLeftBottomCell(std::shared_ptr<Cell> cell) {
    sf::Vector2i coord = cell->getCoord();
    return m_grid[coord.x - 1][coord.y + (1 - (coord.x % 2))];
}

std::shared_ptr<Cell> Hexagrid::getRightTopCell(std::shared_ptr<Cell> cell) {
    sf::Vector2i coord = cell->getCoord();
    return m_grid[coord.x + 1][coord.y - (coord.x % 2)];
}

std::shared_ptr<Cell> Hexagrid::getRightBottomCell(std::shared_ptr<Cell> cell) {
    sf::Vector2i coord = cell->getCoord();
    return m_grid[coord.x + 1][coord.y + (1 - (coord.x % 2))];
}


std::list<std::shared_ptr<Cell>> Hexagrid::getAdjacents(std::shared_ptr<Cell> cell) {
    std::list<std::shared_ptr<Cell>> adjacents;
    adjacents.push_back(getTopCell(cell));
    adjacents.push_back(getBottomCell(cell));
    adjacents.push_back(getLeftTopCell(cell));
    adjacents.push_back(getLeftBottomCell(cell));
    adjacents.push_back(getRightTopCell(cell));
    adjacents.push_back(getRightBottomCell(cell));
    return adjacents;
}

sf::Vector2f Hexagrid::PixToCell(int xCursor, int yCursor) {
    int x;
    int y;
    float size = Cell::SIZE;
    float width = Cell::WIDTH;
    float height = Cell::HEIGHT;
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
void Hexagrid::update()
{
    for(std::vector<std::shared_ptr<Cell>> cells : m_grid) {
        for(std::shared_ptr<Cell> cell : cells) {
            cell->update();
        }
    }
}

// calls the draw function of each hexagon of the grid
void Hexagrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(std::vector<std::shared_ptr<Cell>> cells : m_grid) {
        for(std::shared_ptr<Cell> cell : cells) {
            cell->draw(target, states);
        }
    }
}

std::shared_ptr<Cell> createCell(int i, int j, bool halfCell, int type, int area) {
  switch(type) {
  case 0:
      return std::make_shared<PlainCell>(i, j, halfCell, area);
  case 1:
      return std::make_shared<MountainCell>(i, j, halfCell, area);
  case 2:
      return std::make_shared<SeaCell>(i, j, halfCell, area);
  case 3:
      return std::make_shared<SwampCell>(i, j, halfCell, area);
  case 4:
      return std::make_shared<ReefCell>(i, j, halfCell, area);

    default:
      throw std::logic_error("No cell associated to value ");
  }
}

