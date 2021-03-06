#include "door.h"

void door::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id = theBigMap.getPoint(destination);
    if(id == 10) //黄门
    {
        if(usefulTools.getYellowKey() > 0) //黄钥匙够就开
        {
            usefulTools.setYellowKey(usefulTools.getYellowKey() - 1);
            MUSIC se;
            se.OpenFile("static\\se\\开门.mp3");
            se.Play(0);
            delay_ms(300);
            theBigMap.setPoint(destination, 0);
        }
    }
    else if(id == 11) //蓝门
    {
        if(usefulTools.getBlueKey() > 0)
        {
            usefulTools.setBlueKey(usefulTools.getBlueKey() - 1);
            MUSIC se;
            se.OpenFile("static\\se\\开门.mp3");
            se.Play(0);
            delay_ms(300);
            theBigMap.setPoint(destination, 0);
        }
    }
    else if(id == 12) //红门
    {
        if(usefulTools.getRedKey() > 0)
        {
            usefulTools.setRedKey(usefulTools.getRedKey() - 1);
            MUSIC se;
            se.OpenFile("static\\se\\开门.mp3");
            se.Play(0);
            delay_ms(300);
            theBigMap.setPoint(destination, 0);
        }
    }
}