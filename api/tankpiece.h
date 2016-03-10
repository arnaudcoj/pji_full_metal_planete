#ifndef TANKPIECE_H
#define TANKPIECE_H

#include "piece.h"

class TankPiece : public Piece
{
public:
    TankPiece();
    virtual bool canBeCarried(Container::Type containerType) const;
};

#endif // TANKPIECE_H
