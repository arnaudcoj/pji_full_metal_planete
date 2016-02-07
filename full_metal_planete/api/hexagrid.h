#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
#include <string>
#include <yaml-cpp/yaml.h>

#include "cell.h"

class Hexagrid {

    std::vector<std::vector<Cell>> m_grid;

public:

    Hexagrid(int width = 10, int height = 10);
    Hexagrid(std::string gridFile);
    int getWidth();
    int getHeight();
    std::shared_ptr<Cell> getCell(int x, int y);
    std::shared_ptr<Cell> getTopCell(int x, int y);
    std::shared_ptr<Cell> getBottomCell(int x, int y);
    std::shared_ptr<Cell> getLeftTopCell(int x, int y);
    std::shared_ptr<Cell> getLeftBottomCell(int x, int y);
    std::shared_ptr<Cell> getRightTopCell(int x, int y);
    std::shared_ptr<Cell> getRightBottomCell(int x, int y);
    std::list<std::shared_ptr<Cell> > getAdjacents(int x, int y);
};


#endif //HEXAGRID_H
