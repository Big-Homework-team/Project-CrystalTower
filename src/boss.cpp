#include "boss.h"

void boss::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id = theBigMap.getPoint(destination);
    if(id != 82) return ;

    //触发剧情2
}