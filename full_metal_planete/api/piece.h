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

#endif // PIECE_H
