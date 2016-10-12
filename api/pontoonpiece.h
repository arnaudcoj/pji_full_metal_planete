#ifndef PONTOONPIECE_H
#define PONTOONPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class PontoonPiece : public Piece
{

public:
    PontoonPiece();
    virtual bool canBeCarried(Container container) const;
    virtual std::string getType();
};

#endif // PONTOONPIECE_H
