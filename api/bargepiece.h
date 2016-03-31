#ifndef BARGEPIECE_H
#define BARGEPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class BargePiece : public Piece
{

public:
    BargePiece();
    virtual std::string getType();
};

#endif // BARGEPIECE_H
