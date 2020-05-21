#include "draft.h"

void draft::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    int id = theBigMap.getPoint(destination);
    if(id == 35)
    {
        usefulTools.setDraft(1);
        theBigMap.setPoint(destination, 0);
    }
    if(id == 35) aStrongBrave.setPosition(destination);
}