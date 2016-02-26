#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
#include <string>
#include <yaml-cpp/yaml.h>

#include "cell.h"
#include "hillcell.h"

class Hexagrid {

    std::vector<std::vector<std::shared_ptr<Cell>>> m_grid;

public:

    Hexagrid(int width = 10, int height = 10);
    Hexagrid(std::string gridFile);
    Hexagrid(YAML::Node gridInfo);
    int getWidth();
    int getHeight();
    std::shared_ptr<Cell> getCell(int x, int y);
    std::shared_ptr<Cell> getTopCell(std::shared_ptr<Cell> cell);
    std::shared_ptr<Cell> getBottomCell(std::shared_ptr<Cell> cell);
    std::shared_ptr<Cell> getLeftTopCell(std::shared_ptr<Cell> cell);
    std::shared_ptr<Cell> getLeftBottomCell(std::shared_ptr<Cell> cell);
    std::shared_ptr<Cell> getRightTopCell(std::shared_ptr<Cell> cell);
    std::shared_ptr<Cell> getRightBottomCell(std::shared_ptr<Cell> cell);
    std::list<std::shared_ptr<Cell> > getAdjacents(std::shared_ptr<Cell> cell);
};


#endif //HEXAGRID_H
