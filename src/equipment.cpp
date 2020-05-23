#include "equipment.h"

void equipment::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id = theBigMap.getPoint(destination);
    if(id == 19)
    {
        aStrongBrave.setAttack(aStrongBrave.getAttack() + 10);
        usefulTools.setWeapon(1);
        theBigMap.setPoint(destination, 0);
    }
    else if(id == 20)
    {
        aStrongBrave.setDefence(aStrongBrave.getDefence() + 10);
        usefulTools.setArmor(1);
        theBigMap.setPoint(destination, 0);
    }
    if(id == 19 || id == 20) aStrongBrave.setPosition(destination);
}