#ifndef LOWTIDE_H
#define LOWTIDE_H

#include "tide.h"
#include <string>

class LowTide : public Tide
{
public:
    LowTide();
    virtual std::string toString();
    virtual ~LowTide() {};
};

#endif // LOWTIDE_H
