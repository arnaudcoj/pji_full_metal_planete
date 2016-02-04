#ifndef PIECE_H
#define PIECE_H

#include <memory>

class Cell;

class Piece
{

    std::shared_ptr<Cell> m_cell;

public:
    Piece();
    bool isOnCell();
    std::shared_ptr<Cell> getCell();
    void setCell(std::shared_ptr<Cell> cell);
};

#include "cell.h"

#endif // PIECE_H
