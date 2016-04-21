#include "hexagrid.h"

using namespace std;

std::shared_ptr<Cell> createCell(int i, int j, bool halfCell, int type, int area);

Hexagrid::Hexagrid(int width, int height)
{
    int i, j;

    m_grid.resize(width);
    for(int i = 0; i < width; ++i)
        m_grid[i].resize(height);

    for(i = 1; i < width - 1; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = createCell(i, j, false, 0, 0);
    }

    // 1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = createCell(0, j, true, 0, 0);

    // derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = createCell(width - 1, j, true, 0, 0);

    // premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, true, 0, 0);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, false, 0, 0);
    }

    // derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, false, 0, 0);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, true, 0, 0);
    }
}

// appelle Hexagrid(YAML::Node gridInfo) avec comme node le fichier yaml donné en paramètre
Hexagrid::Hexagrid(string gridFile)
    : Hexagrid(YAML::LoadFile(gridFile))
{
}

// a reproprer
Hexagrid::Hexagrid(YAML::Node gridInfo)
{
    unsigned int i, j;
    size_t width, height;

    std::vector<std::vector<std::vector<int> > > yGrid =
        gridInfo["cells"].as<std::vector<std::vector<std::vector<int> > > >();

    // plus simple d'écrire ligne par ligne dans yaml mais nous on écrit colonnes par colonnes, donc inversons i, j,
    // width et height
    width = yGrid[0].size();
    height = yGrid.size();

    m_grid.resize(width);
    for(i = 0; i < width; ++i)
        m_grid[i].resize(height);

    for(i = 1; i < width - 1; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = createCell(i, j, false, yGrid[j][i][0], yGrid[j][i][1]);
    }

    // 1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = createCell(0, j, true, yGrid[j][0][0], yGrid[j][0][1]);

    // derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = createCell(width - 1, j, true, yGrid[j][width - 1][0], yGrid[j][width - 1][1]);

    // premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, true, yGrid[0][i][0], yGrid[0][i][1]);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = createCell(i, 0, false, yGrid[0][i][0], yGrid[0][i][1]);
    }

    // derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, false, yGrid[height - 1][i][0], yGrid[height - 1][i][1]);
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = createCell(i, height - 1, true, yGrid[height - 1][i][0], yGrid[height - 1][i][1]);
    }
}

int Hexagrid::getWidth() const
{
    return m_grid.size();
}

int Hexagrid::getHeight() const
{
    return m_grid[0].size();
}

std::shared_ptr<Cell> Hexagrid::getCell(int x, int y) const
{
    int width = m_grid.size();
    int height = m_grid.front().size();

    if(0 <= x && x < width && 0 <= y && y < height)
        return m_grid[x][y];
    else
        return nullptr;
}

std::shared_ptr<Cell> Hexagrid::getTopCell(std::shared_ptr<Cell> cell) const
{
    sf::Vector2i coord = cell->getCoord();
    return getCell(coord.x, coord.y - 1);
}

std::shared_ptr<Cell> Hexagrid::getBottomCell(std::shared_ptr<Cell> cell) const
{
    sf::Vector2i coord = cell->getCoord();
    return getCell(coord.x, coord.y + 1);
}

std::shared_ptr<Cell> Hexagrid::getLeftTopCell(std::shared_ptr<Cell> cell) const
{
    sf::Vector2i coord = cell->getCoord();
    return getCell(coord.x - 1, coord.y - (coord.x % 2));
}

std::shared_ptr<Cell> Hexagrid::getLeftBottomCell(std::shared_ptr<Cell> cell) const
{
    sf::Vector2i coord = cell->getCoord();
    return getCell(coord.x - 1, coord.y + (1 - (coord.x % 2)));
}

std::shared_ptr<Cell> Hexagrid::getRightTopCell(std::shared_ptr<Cell> cell) const
{
    sf::Vector2i coord = cell->getCoord();
    return getCell(coord.x + 1, coord.y - (coord.x % 2));
}

std::shared_ptr<Cell> Hexagrid::getRightBottomCell(std::shared_ptr<Cell> cell) const
{
    sf::Vector2i coord = cell->getCoord();
    return getCell(coord.x + 1, coord.y + (1 - (coord.x % 2)));
}

std::list<std::shared_ptr<Cell> > Hexagrid::getCellsInRange(std::shared_ptr<Cell> origin, int range) const
{
    assert(origin != nullptr);
    assert(range >= 0);
    std::list<std::shared_ptr<Cell> > cellsInRange;
    std::shared_ptr<Cell> tmpCell = nullptr;

    int x = origin->getX();
    int y = origin->getY();

    int lineHeightTop = 1;
    int lineHeightBottom = 0;

    for(int i = range; i > 0; i--) {

        for(int j = 1; j <= lineHeightTop; j++) {
            tmpCell = getCell(x - j, y - i);
            if(tmpCell != nullptr)
                cellsInRange.push_back(tmpCell);

            tmpCell = getCell(x + j, y - i);
            if(tmpCell != nullptr)
                cellsInRange.push_back(tmpCell);
        }

        tmpCell = getCell(x, y - i);
        if(tmpCell != nullptr)
            cellsInRange.push_back(tmpCell);

        lineHeightTop = std::min(lineHeightTop + 2, range);

        for(int j = 1; j <= lineHeightBottom; j++) {
            tmpCell = getCell(x - j, y + i);
            if(tmpCell != nullptr)
                cellsInRange.push_back(tmpCell);

            tmpCell = getCell(x + j, y + i);
            if(tmpCell != nullptr)
                cellsInRange.push_back(tmpCell);
        }

        tmpCell = getCell(x, y + i);
        if(tmpCell != nullptr)
            cellsInRange.push_back(tmpCell);

        lineHeightBottom = std::min(lineHeightBottom + 2, range);
    }

    for(int j = 1; j <= lineHeightBottom; j++) {
        tmpCell = getCell(x - j, y);
        if(tmpCell != nullptr)
            cellsInRange.push_back(tmpCell);

        tmpCell = getCell(x + j, y);
        if(tmpCell != nullptr)
            cellsInRange.push_back(tmpCell);
    }

    tmpCell = getCell(x, y);
    if(tmpCell != nullptr)
        cellsInRange.push_back(tmpCell);

    return cellsInRange;
}

bool Hexagrid::areNeighbours(std::shared_ptr<Cell> cell1, std::shared_ptr<Cell> cell2) const 
{
    assert(cell1);
    assert(cell2);
    assert(cell1 != cell2);
    
    std::list<std::shared_ptr<Cell> > neighbours = getDirectNeighbours(cell1);
    return std::find(neighbours.begin(), neighbours.end(), cell2) != neighbours.end();
}

std::list<std::shared_ptr<Cell> > Hexagrid::getDirectNeighbours(std::shared_ptr<Cell> origin) const
{
    assert(origin != nullptr);
    std::list<std::shared_ptr<Cell> > neighbours;

    if(getBottomCell(origin) != nullptr) {
        neighbours.push_back(getBottomCell(origin));
    }

    if(getLeftBottomCell(origin) != nullptr) {
        neighbours.push_back(getLeftBottomCell(origin));
    }

    if(getLeftTopCell(origin) != nullptr) {
        neighbours.push_back(getLeftTopCell(origin));
    }

    if(getTopCell(origin) != nullptr) {
        neighbours.push_back(getTopCell(origin));
    }

    if(getRightTopCell(origin) != nullptr) {
        neighbours.push_back(getRightTopCell(origin));
    }

    if(getRightBottomCell(origin) != nullptr) {
        neighbours.push_back(getRightBottomCell(origin));
    }

    return neighbours;
}

void Hexagrid::update(Tide tide)
{
    for(std::vector<std::shared_ptr<Cell> > column : m_grid) {
        for(std::shared_ptr<Cell> cell : column) {
            cell->setTide(tide);
        }
    }
}

std::list<std::shared_ptr<Cell> > Hexagrid::getDirectPracticableNeighbours(std::shared_ptr<Cell> origin,
    std::shared_ptr<Piece> piece) const
{
    assert(piece != nullptr);
    assert(origin != nullptr);

    std::list<std::shared_ptr<Cell> > neighbours;
    std::shared_ptr<Cell> tmpCell = nullptr;

    tmpCell = getBottomCell(origin);
    if(tmpCell != nullptr && tmpCell->isPracticable(piece) && !tmpCell->isOccupied()) {
        neighbours.push_back(tmpCell);
    }

    tmpCell = getLeftBottomCell(origin);
    if(tmpCell != nullptr && tmpCell->isPracticable(piece) && !tmpCell->isOccupied()) {
        neighbours.push_back(tmpCell);
    }

    tmpCell = getLeftTopCell(origin);
    if(tmpCell != nullptr && tmpCell->isPracticable(piece) && !tmpCell->isOccupied()) {
        neighbours.push_back(tmpCell);
    }

    tmpCell = getTopCell(origin);
    if(tmpCell != nullptr && tmpCell->isPracticable(piece) && !tmpCell->isOccupied()) {
        neighbours.push_back(tmpCell);
    }

    tmpCell = getRightTopCell(origin);
    if(tmpCell != nullptr && tmpCell->isPracticable(piece) && !tmpCell->isOccupied()) {
        neighbours.push_back(tmpCell);
    }

    tmpCell = getRightBottomCell(origin);
    if(tmpCell != nullptr && tmpCell->isPracticable(piece) && !tmpCell->isOccupied()) {
        neighbours.push_back(tmpCell);
    }

    return neighbours;
}

// heuristic for the A* algorithm
int heuristic(std::shared_ptr<Cell> origin, std::shared_ptr<Cell> dest)
{
    sf::Vector2i coordOrigin = origin->getCoord();
    sf::Vector2i coordDest = dest->getCoord();

    return abs(coordOrigin.x - coordDest.x) + abs(coordOrigin.y - coordDest.y);
}

std::list<std::shared_ptr<Cell> >
Hexagrid::getPath_Astar(std::shared_ptr<Cell> origin, std::shared_ptr<Cell> dest, std::shared_ptr<Piece> piece) const
{
    // on associe un entier (priorité) et un pointeur de Cell
    // afin d'utiliser une priority_queue qui conservera l'élment de priorité la plus basse en top
    typedef std::pair<int, std::shared_ptr<Cell> > priorityCell;
    std::priority_queue<priorityCell, vector<priorityCell>, std::greater<priorityCell> > frontier;
    std::unordered_map<std::shared_ptr<Cell>, std::shared_ptr<Cell> > cameFrom;
    std::unordered_map<std::shared_ptr<Cell>, int> cost;

    frontier.emplace(0, origin);
    cameFrom[origin] = origin;
    cost[origin] = 0;

    while(!frontier.empty()) {
        std::shared_ptr<Cell> current = frontier.top().second;
        frontier.pop();

        if(current == dest)
            break;

        for(std::shared_ptr<Cell> neighbour : getDirectPracticableNeighbours(current, piece)) {
            int new_cost = cost[current] + 1;
            int zone = neighbour->getArea();
            if(!cost.count(neighbour) || new_cost < cost[neighbour]) {
                cost[neighbour] = new_cost;
                int priority = new_cost + heuristic(neighbour, dest);
                frontier.emplace(priority, neighbour);
                cameFrom[neighbour] = current;
            }
        }
    }

    std::list<std::shared_ptr<Cell> > path;
    std::shared_ptr<Cell> current = dest;
    path.push_front(current);
    while(current != origin) {
        current = cameFrom[current];
        path.push_front(current);
    }

    return path;
}
/*
std::unordered_set<std::shared_ptr<Cell> > Hexagrid::getAccessibleCells(Player& player, std::shared_ptr<Piece> piece)
{
    assert(piece != nullptr);
    assert(piece->getCell() != nullptr);
    std::vector<std::vector<bool> > alreadyVisited(getWidth());
    for(int i = 0; i < getWidth(); i++) {
        alreadyVisited[i] = std::vector<bool>(getHeight(), false);
    }
    sf::Vector2i coord = piece->getCell()->getCoord();
    alreadyVisited[coord.x][coord.y] = true;

    std::unordered_set<std::shared_ptr<Cell> > cells;

    return getAccessibleCells_rec(player, piece, cells, piece->getCell(), alreadyVisited, player.getActionPoints());
}

std::unordered_set<std::shared_ptr<Cell> > Hexagrid::getAccessibleCells_rec(Player& player,
    std::shared_ptr<Piece> piece,
    std::unordered_set<std::shared_ptr<Cell> >& cells,
    std::shared_ptr<Cell> currentCell,
    std::vector<std::vector<bool> >& alreadyVisited,
    int actionPoints)
{
    if(currentCell != nullptr && actionPoints > 0) {
        for(std::shared_ptr<Cell> neighbour : getDirectPracticableNeighbours(currentCell, piece)) {
            sf::Vector2i coord = neighbour->getCoord();
            if(!alreadyVisited[coord.x][coord.y]) {
                alreadyVisited[coord.x][coord.y] = true;
                cells.insert(neighbour);
            }
            getAccessibleCells_rec(player, piece, cells, neighbour, alreadyVisited, actionPoints - 1);
        }
    }

    return cells;
}
*/

std::unordered_set<std::shared_ptr<Cell> > Hexagrid::getAccessibleCells(Player& player, std::shared_ptr<Piece> piece)
{
    assert(piece != nullptr);
    assert(piece->getCell() != nullptr);

    std::unordered_set<std::shared_ptr<Cell> > cells;

    // return an empty set  (range < 1)
    if(!piece->getCell()->isPracticable(piece) || player.getActionPoints() < 1) {
        return cells;
    }

    std::list<std::list<std::shared_ptr<Cell> > > fringes;

    // add first cell's neighbours (range = 1)
    fringes.emplace_back();
    for(std::shared_ptr<Cell> neighbour : getDirectPracticableNeighbours(piece->getCell(), piece)) {
        if(!cells.count(neighbour)) {
            cells.insert(neighbour);
            fringes.back().push_back(neighbour);
        }
    }

    // flood-fill for the other cells (range > 2)
    for(int k = 1; k < player.getActionPoints(); k++) {
        fringes.emplace_back();
        for(std::shared_ptr<Cell> cell : fringes.front()) {
            for(std::shared_ptr<Cell> neighbour : getDirectPracticableNeighbours(cell, piece)) {
                if(!cells.count(neighbour)) {
                    cells.insert(neighbour);
                    fringes.back().push_back(neighbour);
                }
            }
        }
        fringes.pop_front();
    }
    
    return cells;
}

std::shared_ptr<Cell> createCell(int i, int j, bool halfCell, int type, int area)
{
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
        throw std::logic_error("No cell associated to value");
    }
}
