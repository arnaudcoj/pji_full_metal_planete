#include "hexagrid.h"

using namespace std;

Hexagrid::Hexagrid(int width, int height) {
    int i, j;

    m_grid.resize(width);
    for (int i = 0; i < width; ++i)
      m_grid[i].resize(height);

    for(i = 1; i < width - 1; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = Cell(i, j, false);
    }

    //1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = Cell(0, j, true);

    //derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = Cell(width - 1, j, true);

    //premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = Cell(i, 0, true);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = Cell(i, 0, false);
    }

    //derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = Cell(i, height - 1, false);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = Cell(i, height - 1, true);
    }
}

Hexagrid::Hexagrid(string gridFile) {/*
    int i, j;

    YAML::Node gridInfo = YAML::LoadFile(gridFile);


    m_grid.resize(width);
    for (int i = 0; i < width; ++i)
      m_grid[i].resize(height);

    for(i = 1; i < width - 1; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = Cell(i, j, false);
    }

    //1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = Cell(0, j, true);

    //derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = Cell(width - 1, j, true);

    //premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = Cell(i, 0, true);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = Cell(i, 0, false);
    }

    //derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = Cell(i, height - 1, false);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = Cell(i, height - 1, true);
    }*/
}

int Hexagrid::getWidth() {
    return m_grid.size();
}

int Hexagrid::getHeight() {
    return m_grid[0].size();
}

std::shared_ptr<Cell> Hexagrid::getCell(int x, int y) {
    return std::make_shared<Cell>(m_grid[x][y]);
}

std::shared_ptr<Cell> Hexagrid::getTopCell(int x, int y) {
    return std::make_shared<Cell>(Cell(x, y - 1));
}

std::shared_ptr<Cell> Hexagrid::getBottomCell(int x, int y) {
    return std::make_shared<Cell>(Cell(x, y + 1));
}

std::shared_ptr<Cell> Hexagrid::getLeftTopCell(int x, int y) {
    return std::make_shared<Cell>(Cell(x - 1, y - (x % 2)));
}

std::shared_ptr<Cell> Hexagrid::getLeftBottomCell(int x, int y) {
    return std::make_shared<Cell>(Cell(x - 1, y + (1 - (x % 2))));
}

std::shared_ptr<Cell> Hexagrid::getRightTopCell(int x, int y) {
    return std::make_shared<Cell>(Cell(x + 1, y - (x % 2)));
}

std::shared_ptr<Cell> Hexagrid::getRightBottomCell(int x, int y) {
    return std::make_shared<Cell>(Cell(x + 1, y + (1 - (x % 2))));
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
