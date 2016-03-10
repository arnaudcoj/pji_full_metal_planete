#ifndef CRABPIECE_H
#define CRABPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"


class CrabPiece : public Piece
{
public:
    CrabPiece();
    virtual bool canBeCarried(Container::Type containerType) const;
};

#endif // CRABPIECE_H
