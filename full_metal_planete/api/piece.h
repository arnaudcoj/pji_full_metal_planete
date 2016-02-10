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
    Cell getCell();
    void setCell(Cell& cell);
    bool removeCell();
};

#endif // PIECE_H
