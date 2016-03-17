#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
#include <string>
#include <cmath>
#include <yaml-cpp/yaml.h>

#include "cell.h"
#include "plaincell.h"
#include "mountaincell.h"
#include "seacell.h"
#include "swampcell.h"
#include "reefcell.h"

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
    std::list<std::shared_ptr<Cell> > getDirectNeighbours(std::shared_ptr<Cell> origin);
    std::list<std::shared_ptr<Cell> > getCellsInRange(std::shared_ptr<Cell> origin, int range = 1);

    sf::Vector2f PixToCell(int xCursor, int yCursor);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states);
};


#endif //HEXAGRID_H
