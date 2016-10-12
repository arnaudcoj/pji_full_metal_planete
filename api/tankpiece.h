#ifndef TANKPIECE_H
#define TANKPIECE_H

#include "piece.h"

class TankPiece : public Piece
{

public:
    TankPiece();
    virtual bool canBeCarried(Container container) const;
    virtual std::string getType();
};

#endif // TANKPIECE_H
