#ifndef MINERALPIECE_H
#define MINERALPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class MineralPiece : public Piece
{
public:
    MineralPiece();
    
    virtual bool canBeCarried(Container::Type containerType) const;
};

#endif // MINERALPIECE_H
