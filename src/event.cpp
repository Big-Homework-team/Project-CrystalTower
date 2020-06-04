#include "event.h"

void takeBossEvent(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    char action = '.';
    //触发剧情1

    //画召唤阵
    theBigMap.setPoint(point(5, 6, 0), 60);
    theBigMap.setPoint(point(5, 4, 1), 61);
    theBigMap.setPoint(point(5, 4, 3), 61);
    theBigMap.setPoint(point(5, 5, 4), 61);
    theBigMap.setPoint(point(5, 7, 4), 61);
    theBigMap.setPoint(point(5, 8, 3), 61);
    theBigMap.setPoint(point(5, 8, 1), 61);
    draw(aStrongBrave, usefulTools, theBigMap, pic);

    while(action != ' ')  action = getch();
    aStrongBrave.setHealthPoint(aStrongBrave.getHealthPoint() * 10);
    aStrongBrave.setAttack(aStrongBrave.getAttack() * 10);
    aStrongBrave.setDefence(aStrongBrave.getDefence() * 10);
    
    //消召唤阵
    theBigMap.setPoint(point(5, 6, 0), 0);
    theBigMap.setPoint(point(5, 4, 1), 6);
    theBigMap.setPoint(point(5, 4, 3), 6);
    theBigMap.setPoint(point(5, 5, 4), 6);
    theBigMap.setPoint(point(5, 7, 4), 6);
    theBigMap.setPoint(point(5, 8, 3), 6);
    theBigMap.setPoint(point(5, 8, 1), 6);
    draw(aStrongBrave, usefulTools, theBigMap, pic);

}