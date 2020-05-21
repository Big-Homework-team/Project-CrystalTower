#pragma once
#include "point.h"
#include "theBrave.h"
#include "tools.h"
#include "map.h"

class object
{
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap) = 0;
};