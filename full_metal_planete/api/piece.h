#ifndef PIECE_H
#define PIECE_H

class Cell;

class Piece
{

    Cell* m_cell;

public:
    Piece();
    Cell* getCell();
    void setCell(Cell* cell);
};

#include "cell.h"

#endif // PIECE_H
