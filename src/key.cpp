#include "key.h"

void key::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id = theBigMap.getPoint(destination);
    if(id == 31)
    {
        usefulTools.setYellowKey(usefulTools.getYellowKey() + 1);
        theBigMap.setPoint(destination, 0);
    }
    else if(id == 32)
    {
        usefulTools.setBlueKey(usefulTools.getBlueKey() + 1);
        theBigMap.setPoint(destination, 0);
    }
    else if(id == 33)
    {
        usefulTools.setRedKey(usefulTools.getRedKey() + 1);
        theBigMap.setPoint(destination, 0);
    }
    if(id == 31 || id == 32 || id == 33) aStrongBrave.setPosition(destination);
}