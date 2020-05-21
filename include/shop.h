#pragma once
#include "object.h"

class shop: public object
{
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap);
};