#ifndef HIGHTIDE_H
#define HIGHTIDE_H

#include "tide.h"
#include <string>

class HighTide : public Tide
{
public:
    HighTide();
    virtual std::string toString();
    virtual ~HighTide() {};
};

#endif // HIGHTIDE_H
