#pragma once
#include "object.h"

class key: public object
{
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap);
};