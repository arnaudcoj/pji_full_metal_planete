#ifndef PATROLBOATPIECE_H
#define PATROLBOATPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class PatrolBoatPiece : public Piece
{

public:
    PatrolBoatPiece();
    virtual std::string getType();
};

#endif // PATROLBOATPIECE_H
