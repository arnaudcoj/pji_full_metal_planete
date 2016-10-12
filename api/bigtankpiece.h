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
    virtual bool canBeCarried(Container container) const;
    virtual std::string getType();
};

#endif // BIGTANKPIECE_H
