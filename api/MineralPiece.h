#ifndef MINERALPIECE_H
#define MINERALPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"
#include <string>

class MineralPiece : public Piece
{

public:
    MineralPiece();

    virtual bool canBeCarried(Container container) const;

    virtual std::string getType();
};

#endif // MINERALPIECE_H
