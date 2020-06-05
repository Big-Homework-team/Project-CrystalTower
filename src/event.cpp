#include "event.h"

void takeBossEvent(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    char action = '.';
    //触发剧情1
    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    setcolor(WHITE);                       //字体颜色
    setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT);                //字体背景色块调为透明

    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "哈迪斯：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "你就是国王选中的光之战士吗？");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "能靠自己的力量走到这里，确实不错，");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "只不过想要与我一战，你的实力尚且不够。");
    while(action != ' ') action = getch();
    action = '.';
    
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "你：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "魔王哈迪斯。");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "如果你现在选择让公主和我离开，");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "神明或许还会给与你宽恕。");
    while(action != ' ') action = getch();
    action = '.';
    
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "哈迪斯：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "果然是弱小而不自知的愚昧的人类啊。");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "");
    while(action != ' ') action = getch();
    action = '.';

    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "古拉哈提亚：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "勇者阁下！");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "我来助你一臂之力！");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "");
    while(action != ' ') action = getch();
    action = '.';

    //画召唤阵
    theBigMap.setPoint(point(5, 6, 0), 60);
    theBigMap.setPoint(point(5, 4, 1), 61);
    theBigMap.setPoint(point(5, 4, 3), 61);
    theBigMap.setPoint(point(5, 5, 4), 61);
    theBigMap.setPoint(point(5, 7, 4), 61);
    theBigMap.setPoint(point(5, 8, 3), 61);
    theBigMap.setPoint(point(5, 8, 1), 61);
    draw(aStrongBrave, usefulTools, theBigMap, pic);

    
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "古拉哈提亚：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "其他世界中的勇者们，现身吧！");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "请借给勇者大人力量吧！");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "");
    while(action != ' ') action = getch();
    action = '.';

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

    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
    outtextxy(5 * 32, 9 * 32 + 0 * 16, "哈迪斯：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "使出你的全力吧，");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "我也将以自己完全的形态来应战！");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "");
    while(action != ' ') action = getch();
    action = '.';
}