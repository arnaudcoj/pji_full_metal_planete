#ifndef BARGEPIECE_H
#define BARGEPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class BargePiece : public Piece
{
private:
    std::string m_type = "barge";

public:
    BargePiece();
    virtual std::string getType();
};

#endif // BARGEPIECE_H
