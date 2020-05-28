#include "tool.h"
#include <graphics.h>

void tool::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    //获得道具
    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    setcolor(WHITE);                       //字体颜色
    setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT);                //字体背景色块调为透明
    int id = theBigMap.getPoint(destination);
    if (id == 35)
    {
        MUSIC se;
        se.OpenFile("static\\se\\获得道具.mp3");
        se.Play(0);
        usefulTools.setDraft(1);
        theBigMap.setPoint(destination, 0);
        bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
        outtextxy(5 * 32, 9 * 32, "获得了消耗类物品 镐子！");
        outtextxy(5 * 32, 9 * 32 + 1 * 16, "可以破坏使用者面前的墙壁，按 U 可使用。");
        char action = '.';
        while (action != 32)
        {
            action = getch();
        }
    }
    else if (id == 37)
    {
        MUSIC se;
        se.OpenFile("static\\se\\获得道具.mp3");
        se.Play(0);
        usefulTools.setTransmitter(1);
        theBigMap.setPoint(destination, 0);
        bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
        outtextxy(5 * 32, 9 * 32, "获得了消耗类物品 传送器！");
        outtextxy(5 * 32, 9 * 32 + 1 * 16, "可以传送至对称地点，按 I 可使用。");
        char action = '.';
        while (action != 32)
        {
            action = getch();
        }
    }
    else if (id == 38)
    {
        MUSIC se;
        se.OpenFile("static\\se\\获得道具.mp3");
        se.Play(0);
        usefulTools.setBoom(1);
        theBigMap.setPoint(destination, 0);
        bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
        outtextxy(5 * 32, 9 * 32, "获得了消耗类物品 炸弹！。");
        outtextxy(5 * 32, 9 * 32 + 1 * 16, "可以炸掉使用者面前的怪物，按 O 可使用。");
        char action = '.';
        while (action != 32)
        {
            action = getch();
        }
    }
}