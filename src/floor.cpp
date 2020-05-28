#include "floor.h"

void floor::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id = theBigMap.getPoint(destination);
    point position = aStrongBrave.getPosition();
    if(id == 3)
    {
        destination.setFloor(position.getFloor() + 1);
        if(destination.getFloor() == 5) destination.setX(destination.getX() - 1);
        for(int x = 0; x < 13; x ++)
            for(int y = 0; y < 13; y ++)
                if(theBigMap.getPoint(point(destination.getFloor(), x, y)) == 4)
                {
                    destination.setX(x);
                    destination.setY(y);
                    break;
                }
        aStrongBrave.setPosition(destination);
    }
    else if(id == 4)
    {
        destination.setFloor(position.getFloor() - 1);
        for(int x = 0; x < 13; x ++)
            for(int y = 0; y < 13; y ++)
                if(theBigMap.getPoint(point(destination.getFloor(), x, y)) == 3)
                {
                    destination.setX(x);
                    destination.setY(y);
                    break;
                }
        aStrongBrave.setPosition(destination);
    }
    if(id == 3 || id == 4)
    {
        MUSIC se;
        se.OpenFile("static\\se\\上下楼.mp3");
        se.Play(0);
        delay_ms(300);
    }
}