#include "hexagrid.h"

using namespace std;

Hexagrid::Hexagrid(int width, int height) {
    int i, j;

    m_grid.resize(width);
    for (int i = 0; i < width; ++i)
      m_grid[i].resize(height);

    for(i = 1; i < width - 1; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = make_shared<Cell>(i, j, false);
    }

    //1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = make_shared<Cell>(0, j, true);

    //derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = make_shared<Cell>(width - 1, j, true);

    //premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = make_shared<Cell>(i, 0, true);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = make_shared<Cell>(i, 0, false);
    }

    //derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = make_shared<Cell>(i, height - 1, false);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = make_shared<Cell>(i, height - 1, true);
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
            m_grid[i][j] = make_shared<Cell>(i, j, false, yGrid[j][i][1]);
    }

    //1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = make_shared<Cell>(0, j, true, yGrid[j][0][1]);

    //derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = make_shared<Cell>(width - 1, j, true, yGrid[j][width - 1][1]);

    //premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = make_shared<Cell>(i, 0, true, yGrid[0][i][1]);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = make_shared<Cell>(i, 0, false, yGrid[0][i][1]);
    }

    //derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = make_shared<Cell>(i, height - 1, false, yGrid[height - 1][i][1]);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = make_shared<Cell>(i, height - 1, true, yGrid[height - 1][i][1]);
    }
}

int Hexagrid::getWidth() {
    return m_grid.size();
}

int Hexagrid::getHeight() {
    return m_grid[0].size();
}

std::shared_ptr<Cell> Hexagrid::getCell(int x, int y) {
    return m_grid[x][y];
}

std::shared_ptr<Cell> Hexagrid::getTopCell(int x, int y) {
    return m_grid[x][y - 1];
}

std::shared_ptr<Cell> Hexagrid::getBottomCell(int x, int y) {
    return m_grid[x][y + 1];
}

std::shared_ptr<Cell> Hexagrid::getLeftTopCell(int x, int y) {
    return m_grid[x - 1][y - (x % 2)];
}

std::shared_ptr<Cell> Hexagrid::getLeftBottomCell(int x, int y) {
    return m_grid[x - 1][y + (1 - (x % 2))];
}

std::shared_ptr<Cell> Hexagrid::getRightTopCell(int x, int y) {
    return m_grid[x + 1][y - (x % 2)];
}

std::shared_ptr<Cell> Hexagrid::getRightBottomCell(int x, int y) {
    return m_grid[x + 1][y + (1 - (x % 2))];
}


std::list<std::shared_ptr<Cell>> Hexagrid::getAdjacents(int x, int y) {
    std::list<std::shared_ptr<Cell>> adjacents;
    adjacents.push_back(getTopCell(x, y));
    adjacents.push_back(getBottomCell(x, y));
    adjacents.push_back(getLeftTopCell(x, y));
    adjacents.push_back(getLeftBottomCell(x, y));
    adjacents.push_back(getRightTopCell(x, y));
    adjacents.push_back(getRightBottomCell(x, y));
    return adjacents;
}
