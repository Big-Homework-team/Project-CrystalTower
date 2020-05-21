#include "tool.h"

void tool::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    int id = theBigMap.getPoint(destination);
    if(id == 35)
    {
        usefulTools.setDraft(1);
        theBigMap.setPoint(destination, 0);
    }
    else if(id == 37)
    {
        usefulTools.setTransmitter(1);
        theBigMap.setPoint(destination, 0);
    }
    else if(id == 38)
    {
        usefulTools.setBoom(1);
        theBigMap.setPoint(destination, 0);
    }
    if(id == 35 || id == 37 || id == 38) aStrongBrave.setPosition(destination);
}