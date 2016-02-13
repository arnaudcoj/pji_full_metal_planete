#ifndef TIDE_H
#define TIDE_H

#include <string>

class Tide
{
public:
    Tide();
    virtual std::string toString() = 0;
    virtual ~Tide() {};
};

#endif // TIDE_H
