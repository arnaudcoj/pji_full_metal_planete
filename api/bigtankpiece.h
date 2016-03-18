#ifndef BIGTANKPIECE_H
#define BIGTANKPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class BigTankPiece : public Piece
{
private:
    std::string m_type = "big_tank";

public:
    BigTankPiece();
    virtual bool canBeCarried(Container::Type containerType) const;
    virtual std::string getType();
};

#endif // BIGTANKPIECE_H
