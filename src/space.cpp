#include "space.h"

void space::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    int id = theBigMap.getPoint(destination);
    if(id == 0) aStrongBrave.setPosition(destination);
    else if(id == 14)
    {
        theBigMap.setPoint(point(2, 6, 7), 0); //生成空地
        theBigMap.setPoint(point(2, 6, 6), 52); //生成黑史莱姆
        aStrongBrave.setPosition(destination);
        theBigMap.setPoint(point(2, 6, 4), 13); //生成机关门
        theBigMap.setPoint(point(2, 6, 8), 13); //生成机关门
    }
}