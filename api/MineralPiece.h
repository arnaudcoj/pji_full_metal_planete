#ifndef MINERALPIECE_H
#define MINERALPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"
#include <string>

class MineralPiece : public Piece
{
private:
    std::string m_type = "mineral";

public:
    MineralPiece();

    virtual bool canBeCarried(Container::Type containerType) const;

    virtual std::string getType();
};

#endif // MINERALPIECE_H
