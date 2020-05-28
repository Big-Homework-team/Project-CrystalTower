#include "space.h"
#include "draw.h"

void space::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id = theBigMap.getPoint(destination);
    if (id == 0){
        if (theBigMap.getPoint(point(2, 8, 11)) == 7 && theBigMap.getPoint(point(2, 6, 4)) == 13)
        {
            setfillcolor(DARKGRAY);                //设置背景填充色为深灰
            bar(5 * 32, 9 * 32, 18 * 32, 14 * 32); //绘制矩形作为背景
            setcolor(WHITE);                       //字体颜色
            setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
            setbkmode(TRANSPARENT);                //字体背景色块调为透明
            outtextxy(5 * 32, 9 * 32 + 0 * 16, "神秘的声音：");
            outtextxy(5 * 32, 9 * 32 + 1 * 16, "看起来你陷入了陷阱,");
            outtextxy(5 * 32, 9 * 32 + 2 * 16, "不打败眼前的怪物似乎就无法离开，");
            outtextxy(5 * 32, 9 * 32 + 3 * 16, "不如观察一下地图怪异的地方，那里往往会有隐藏的宝物。");
            outtextxy(5 * 32, 9 * 32 + 4 * 16, "如果暂时逃脱不了陷阱，不如利用存档再次挑战。");
            char action = '.';
            while (action != 32)
            {
                action = getch();
            }
            theBigMap.setPoint(point(2, 8, 11), 45);
        }
        aStrongBrave.setPosition(destination);
    }
    else if (id == 14)
    {
        theBigMap.setPoint(point(2, 6, 7), 0);  //生成空地
        theBigMap.setPoint(point(2, 6, 6), 52); //生成黑史莱姆
        aStrongBrave.setPosition(destination);
        draw(aStrongBrave, usefulTools, theBigMap, pic);
        MUSIC se;
        se.OpenFile("static\\se\\开门.mp3");
        se.Play(0);
        delay_ms(300);
        theBigMap.setPoint(point(2, 6, 4), 13); //生成机关门
        theBigMap.setPoint(point(2, 6, 8), 13); //生成机关门
    }
}