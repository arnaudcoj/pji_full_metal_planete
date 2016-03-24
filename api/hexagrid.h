#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <utility>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cmath>
#include <yaml-cpp/yaml.h>

#include "player.h"
#include "cell.h"
#include "piece.h"
#include "tide.h"
#include "plaincell.h"
#include "mountaincell.h"
#include "seacell.h"
#include "swampcell.h"
#include "reefcell.h"

class Hexagrid
{

    std::vector<std::vector<std::shared_ptr<Cell> > > m_grid;

public:
    Hexagrid(int width = 10, int height = 10);
    Hexagrid(std::string gridFile);
    Hexagrid(YAML::Node gridInfo);
    int getWidth() const;
    int getHeight() const;
    std::shared_ptr<Cell> getCell(int x, int y) const;
    std::shared_ptr<Cell> getTopCell(std::shared_ptr<Cell> cell) const;
    std::shared_ptr<Cell> getBottomCell(std::shared_ptr<Cell> cell) const;
    std::shared_ptr<Cell> getLeftTopCell(std::shared_ptr<Cell> cell) const;
    std::shared_ptr<Cell> getLeftBottomCell(std::shared_ptr<Cell> cell) const;
    std::shared_ptr<Cell> getRightTopCell(std::shared_ptr<Cell> cell) const;
    std::shared_ptr<Cell> getRightBottomCell(std::shared_ptr<Cell> cell) const;

    std::list<std::shared_ptr<Cell> > getDirectNeighbours(std::shared_ptr<Cell> origin) const;
    std::list<std::shared_ptr<Cell> >
    getDirectPracticableNeighbours(std::shared_ptr<Cell> origin, std::shared_ptr<Piece> piece) const;

    void update(Tide tide);

    // gets the cells where a piece can move
    std::unordered_set<std::shared_ptr<Cell> > getAccessibleCells(Player& player, std::shared_ptr<Piece> piece);

    // gets the cell in a given range from origin
    std::list<std::shared_ptr<Cell> > getCellsInRange(std::shared_ptr<Cell> origin, int range = 1) const;

    // computes the shortest practicable path from origin to dest
    // the returned stack contains from the origin cell to the destination cell (both included)
    std::stack<std::shared_ptr<Cell> > getPath_Astar(std::shared_ptr<Cell> origin,
        std::shared_ptr<Cell> dest,
        std::shared_ptr<Piece> piece) const;

private:
    //used by getAccessibleCells
    std::unordered_set<std::shared_ptr<Cell> > getAccessibleCells_rec(Player& player,
        std::shared_ptr<Piece> piece,
        std::unordered_set<std::shared_ptr<Cell> >& cells,
        std::shared_ptr<Cell> currentCell,
        std::vector<std::vector<bool> >& alreadyVisited,
        int actionPoints);
};

#endif // HEXAGRID_H
