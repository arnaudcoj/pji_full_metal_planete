#ifndef MEDIUMTIDE_H
#define MEDIUMTIDE_H

#include "tide.h"
#include <string>

class MediumTide : public Tide
{
public:
    MediumTide();
    virtual std::string toString();
    virtual ~MediumTide() {};
};

#endif // MEDIUMTIDE_H
