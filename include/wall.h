#pragma once
#include "object.h"

class wall: public object
{
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic);
};