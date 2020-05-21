#include "shop.h"
#include <graphics.h>

void shop::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{

    setfillcolor(BLACK);                   //设置背景填充色为黑
    bar(5 * 32, 9 * 32, 18 * 32, 14 * 32); //绘制矩形作为背景

    setcolor(WHITE);        //字体颜色
    setfont(16, 0, "宋体"); //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT); //字体背景色块调为透明
    outtextxy(5 * 32, 9 * 32, "商会老板 罗薇娜：");
    outtextxy(5 * 32, 9 * 32 + 1 * 16, "亲爱的光之战士,");
    outtextxy(5 * 32, 9 * 32 + 2 * 16, "您可以通过花费20金币来增强自己。");
    char action;
    while (action != 13)
    {
        action = getch();
    }
    if (action == 13)
    {
        setfillcolor(BLACK);
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
        if (action == '1' || action == '2' || action == '3' || action == '4')
        {
            if (action == '1')
            {
                aStrongBrave.setHealthPoint(aStrongBrave.getHealthPoint() + 400);
                usefulTools.setMoney(usefulTools.getMoney() - 20);
            }
            if (action == '2')
            {
                aStrongBrave.setAttack(aStrongBrave.getAttack() + 3);
                usefulTools.setMoney(usefulTools.getMoney() - 20);
            }
            if (action == '3')
            {
                aStrongBrave.setDefence(aStrongBrave.getDefence() + 4);
                usefulTools.setMoney(usefulTools.getMoney() - 20);
            }
            setfillcolor(BLACK);
            bar(5 * 32, 9 * 32, 18 * 32, 14 * 32);
            outtextxy(5 * 32, 9 * 32, "商会老板 罗薇娜：");
            outtextxy(5 * 32, 9 * 32 + 2 * 16, "感谢您的惠顾，");
            outtextxy(5 * 32, 9 * 32 + 3 * 16, "愿十二神保佑您。");
        }
    }
}