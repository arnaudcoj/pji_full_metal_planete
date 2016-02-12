#ifndef PIECE_H
#define PIECE_H

#include <memory>

class Cell;

class Piece
{

    std::weak_ptr<Cell> m_cell;

public:
    Piece();
    bool isOnCell();
    std::shared_ptr<Cell> getCell();
    void setCell(std::shared_ptr<Cell> cell);
    bool removeCell();
};

#endif // PIECE_H
