#include "wall.h"

void wall::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id = theBigMap.getPoint(destination);
    if(id == 2 && usefulTools.getUsingDraft() == 1)
    {
        MUSIC se;
        se.OpenFile("static\\se\\开门.mp3");
        se.Play(0);
        delay_ms(300);
        usefulTools.setUsingDraft(0);
        theBigMap.setPoint(destination, 0);
    }
    else if(id == 7)
    {
        MUSIC se;
        se.OpenFile("static\\se\\开门.mp3");
        se.Play(0);
        delay_ms(300);
        theBigMap.setPoint(destination, 31); //生成黄钥匙
    }
}