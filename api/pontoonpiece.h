#ifndef PONTOONPIECE_H
#define PONTOONPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class PontoonPiece : public Piece
{
private:
    std::string m_type = "pontoon";

public:
    PontoonPiece();
    virtual bool canBeCarried(Container::Type containerType) const;
    virtual std::string getType();
};

#endif // PONTOONPIECE_H
