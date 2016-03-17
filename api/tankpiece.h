#ifndef TANKPIECE_H
#define TANKPIECE_H

#include "piece.h"

class TankPiece : public Piece
{
private:
    std::string m_type = "tank";

public:
    TankPiece();
    virtual bool canBeCarried(Container::Type containerType) const;
    virtual std::string getType();
};

#endif // TANKPIECE_H
