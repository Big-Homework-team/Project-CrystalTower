#pragma once
#include "point.h"
#include "theBrave.h"
#include "tools.h"
#include "map.h"
#include "monster.h"
#include "picture.h"

class object //事件虚基类
{
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic) = 0;
};