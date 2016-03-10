#ifndef BIGTANKPIECE_H
#define BIGTANKPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"


class BigTankPiece : public Piece
{
public:
    BigTankPiece();
    virtual bool canBeCarried(Container::Type containerType) const;
};

#endif // BIGTANKPIECE_H
