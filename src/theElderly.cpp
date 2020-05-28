#include "theElderly.h"
#include <graphics.h>

void theElderly::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32); //绘制矩形作为背景
    setcolor(WHITE);                       //字体颜色
    setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT);                //字体背景色块调为透明
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "老者：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "年轻人，我看你相貌不凡，");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "谈吐间流露出一种王霸之气，");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "我就将这本怪物手册交付与你，");
    outtextxy(5 * 32, 9 * 32 + 4 * 16, "你可以通过它来获取你遇到的怪物的信息，请多加使用。");
    char action = '.';
    while (action != 32)
    {
        action = getch();
    }
    
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "老者：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "顺便提醒你，此塔凶险，");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "按 F 可以存档，而按 R 可以读档。");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "当你无法预测即将到来的危机时，");
    outtextxy(5 * 32, 9 * 32 + 4 * 16, "多加存档或许可以让你幸免于难。");
    action = '.';
    while (action != 32)
    {
        action = getch();
    }
    MUSIC se;
    se.OpenFile("static\\se\\获得道具.mp3");
    se.Play(0);
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "获得了永久类物品 怪物手册！");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "可以记录怪物的生命值、攻击、防御和特性，按 H 可使用。");
    action = '.';
    while (action != 32)
    {
        action = getch();
    }

    theBigMap.setPoint(destination, 0);
    usefulTools.setMonsterManual(1);
}