#include "wall.h"

void wall::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    int id = theBigMap.getPoint(destination);
    if(id == 2 && usefulTools.getUsingDraft() == 1)
    {
        usefulTools.setUsingDraft(0);
        theBigMap.setPoint(destination, 0);
    }
}