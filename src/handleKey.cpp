#include "handleKey.h"
#include "draw.h"
#include "object.h"
#include "distinguishObject.h"
#include "monsterMannual.h"
#include <cctype>
#include "file.h"


void handle(char action, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic) //处理按键
{
    action = tolower(action); //转换大小写
    point position, destination;
    destination = position = aStrongBrave.getPosition();
    if(action == 'u')
    {
        //使用稿子
        if(usefulTools.getDraft() == 1)
        {
            usefulTools.setUsingDraft(1);
            usefulTools.setDraft(0);
        }
    }
    else if(action == 'r')
    {
        //读档
        optionReadFile(aStrongBrave, usefulTools, theBigMap);
    }
    else if(action == 'f')
    {
        //存档
        optionWriteFile(aStrongBrave, usefulTools, theBigMap);
    }
    else if(action == 'h')
    {
        if(usefulTools.getMonsterManual() == 1)
        {
            //使用怪物手册
            useMonsterMannual(aStrongBrave, theBigMap, bigMonster, pic);
        }
    }
    else if(action == 'i')
    {
        if(usefulTools.getTransmitter() == 1)
        {
            destination.setX(12 - destination.getX());
            destination.setY(12 - destination.getY());
            if(theBigMap.getPoint(destination) == 0) //使用传送器
            {
                usefulTools.setTransmitter(0);
                aStrongBrave.setPosition(destination);
            }
        }
    }
    else if(action == 'o')
    {
        if(usefulTools.getBoom() == 1)
        {
            //使用炸弹
            for(int i = -1; i <= 1; i ++)
                for(int j = -1; j <= 1; j ++)
                {
                    int id = theBigMap.getPoint(point(destination.getFloor(), destination.getX() + i, destination.getY() + j));
                    if(51 <= id && id <= 80)
                        theBigMap.setPoint(point(destination.getFloor(), destination.getX() + i, destination.getY() + j), 0);
                }
            usefulTools.setBoom(0);
            MUSIC se;
            se.OpenFile("static\\se\\火击.mp3");
            se.Play(0);
            delay_ms(300);
        }
    }
    else if(action == 'a' || action == 37 || action == 'd' || action == 39 || action == 'w' || action == 38 || action == 's' || action == 40)
    {
        //处理上下移动触发的事件
        if(action == 'a' || action == 37) destination.setX(position.getX() - 1);
        if(action == 'd' || action == 39) destination.setX(position.getX() + 1);
        if(action == 'w' || action == 38) destination.setY(position.getY() - 1);
        if(action == 's' || action == 40) destination.setY(position.getY() + 1);
        if(!theBigMap.checkPoint(destination)) return ;
        object *newObject = distinguishObject(theBigMap.getPoint(destination)); //根据 ID 获取相应的派生类指针
        newObject->takeEvent(destination, aStrongBrave, usefulTools, theBigMap, bigMonster, pic);
    }
}