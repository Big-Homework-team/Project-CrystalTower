#include "shop.h"
#include <graphics.h>
#include <cmath>

void shop::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{

    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32); //绘制矩形作为背景
    setcolor(WHITE);                       //字体颜色
    setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT);                //字体背景色块调为透明
    outtextxy(5 * 32, 9 * 32, "商会老板 罗薇娜：");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "亲爱的光之战士,");
    outtextxy(5 * 32, 9 * 32 + 3 * 16, "您可以通过花费金币来增强自己。");
    outtextxy(5 * 32, 9 * 32 + 4 * 16, "第一次需花费20金币，之后每次购买的花费为上次的两倍。");
    char action = '.';
    int cost = pow(2, aStrongBrave.getTimes()) * 10;
    while (action != 32)
    {
        action = getch();
    }
    if (action == 32)
    {
        bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
        outtextxy(5 * 32, 9 * 32, "商会老板 罗薇娜：");
        outtextxy(5 * 32, 9 * 32 + 2 * 16, "请输出数字代表选择：");
        outtextxy(5 * 32, 9 * 32 + 3 * 16, "1:增加400点生命值");
        outtextxy(5 * 32, 9 * 32 + 4 * 16, "2:增加3点攻击值");
        outtextxy(5 * 32, 9 * 32 + 5 * 16, "3:增加4点防御值");
        outtextxy(5 * 32, 9 * 32 + 6 * 16, "4:暂时还不需要");
        while (action != '1' && action != '2' && action != '3' && action != '4')
        {
            action = getch();
        }
        if (action == '1' || action == '2' || action == '3')
        {
            if (usefulTools.getMoney() >= cost)
            {
                if (action == '1')
                {
                    aStrongBrave.setHealthPoint(aStrongBrave.getHealthPoint() + 400);
                    aStrongBrave.setTimes(aStrongBrave.getTimes() + 1);
                    usefulTools.setMoney(usefulTools.getMoney() - cost);
                }
                if (action == '2')
                {
                    aStrongBrave.setAttack(aStrongBrave.getAttack() + 3);
                    aStrongBrave.setTimes(aStrongBrave.getTimes() + 1);
                    usefulTools.setMoney(usefulTools.getMoney() - cost);
                }
                if (action == '3')
                {
                    aStrongBrave.setDefence(aStrongBrave.getDefence() + 4);
                    aStrongBrave.setTimes(aStrongBrave.getTimes() + 1);
                    usefulTools.setMoney(usefulTools.getMoney() - cost);
                }
                bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
                outtextxy(5 * 32, 9 * 32, "商会老板 罗薇娜：");
                outtextxy(5 * 32, 9 * 32 + 2 * 16, "感谢您的惠顾，");
                outtextxy(5 * 32, 9 * 32 + 3 * 16, "愿十二神保佑您。");
            }
            else
            {
                bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
                outtextxy(5 * 32, 9 * 32, "商会老板 罗薇娜：");
                outtextxy(5 * 32, 9 * 32 + 2 * 16, "您的钱还不够进行购买，");
                outtextxy(5 * 32, 9 * 32 + 3 * 16, "可以考虑通过讨伐魔物赚取金币。");
            }
        }
        else if (action == '4')
        {
            bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
            outtextxy(5 * 32, 9 * 32, "商会老板 罗薇娜：");
            outtextxy(5 * 32, 9 * 32 + 2 * 16, "考虑后再进行购买是明智的行为，");
            outtextxy(5 * 32, 9 * 32 + 3 * 16, "期待您的下次光临。");
        }
        action = '.';
        while (action != 32)
        {
            action = getch();
        }
    }
}