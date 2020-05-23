#include "handleMonster.h"
#include "monster.h"
#include "draw.h"

const int tim = 300;

void handleMonster::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int id=theBigMap.getPoint(destination);
    monster nowMonster = bigMonster[id];

    /*drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), nowMonster.getHealthPoint(), nowMonster.getAttack(), nowMonster.getDefence(), pic);
    Sleep(tim);*///开始时显示怪物信息？
    int healthPoint=aStrongBrave.getHealthPoint();
    int attack=aStrongBrave.getAttack() - nowMonster.getDefence();
    int defence=nowMonster.getAttack() - aStrongBrave.getDefence();
    int monsterHealth=nowMonster.getHealthPoint();
    if(attack <= 0) attack = 0;
    if(defence <= 0) defence = 0;

    if(id == 55 && attack > 1) attack = 1; //打石头人最多 1 点

    if(attack == 0) {
        if (theBigMap.getTheMap(point(2, 8, 11)) == 7 && theBigMap.getTheMap(point(2, 6, 4)) == 13 && id == 52)
        {
            setfillcolor(DARKGRAY);                //设置背景填充色为深灰
            bar(5 * 32, 9 * 32, 18 * 32, 14 * 32); //绘制矩形作为背景
            setcolor(WHITE);                       //字体颜色
            setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
            setbkmode(TRANSPARENT);                //字体背景色块调为透明
            outtextxy(5 * 32, 9 * 32 + 0 * 16, "神秘的声音：");
            outtextxy(5 * 32, 9 * 32 + 1 * 16, "看起来你陷入了陷阱,");
            outtextxy(5 * 32, 9 * 32 + 1 * 16, "不打败眼前的怪物似乎就无法离开，");
            outtextxy(5 * 32, 9 * 32 + 2 * 16, "不如观察一下地图怪异的地方，在那里往往会有隐藏着的宝物。");
            outtextxy(5 * 32, 9 * 32 + 3 * 16, "如果暂时逃脱不了陷阱，不如利用存档再次挑战。");
            char action = '.';
            while (action != 32)
            {
                action = getch();
            }
            theBigMap.setPoint(point(2, 8, 11), 45);
        }
        else if (theBigMap.getTheMap(point(2, 8, 11)) == 0 && theBigMap.getTheMap(point(2, 6, 4)) == 13 && id == 52)
        {
            bar(5 * 32, 9 * 32, 18 * 32, 14 * 32); //绘制矩形作为背景
            outtextxy(5 * 32, 9 * 32 + 0 * 16, "神秘的声音：");
            outtextxy(5 * 32, 9 * 32 + 1 * 16, "看起来你无法战胜面前的怪物，");
            outtextxy(5 * 32, 9 * 32 + 2 * 16, "手上是否还有没有利用到的道具呢？");
            outtextxy(5 * 32, 9 * 32 + 3 * 16, "及时到上一层回收之前没有使用的物品也是重要的策略。");
            outtextxy(5 * 32, 9 * 32 + 4 * 16, "如果暂时逃脱不了陷阱，不如利用存档再次挑战。");
            char action = '.';
            while (action != 32)
            {
                action = getch();
            }
            theBigMap.setPoint(point(2, 8, 11), 45);
        }
        return ;
    }

    int time=monsterHealth/attack;
    if(monsterHealth%attack==0) time--;

    if(id == 53) time ++; //小蝙蝠先手

    if(time*defence >= healthPoint){
        return ;//没打过
    }

    if(id == 53) healthPoint -= defence, //小蝙蝠先手
    putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[93]),
    drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), healthPoint, monsterHealth, nowMonster.getAttack(), nowMonster.getDefence(), pic),
    Sleep(tim),
    putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[1]);

    while(healthPoint>0 && monsterHealth>0){
        monsterHealth -= attack;
        //攻击一下怪物；
        putimage(5 * 32 + 32 * destination.getX(), 32 * destination.getY(), pic.block[93]),
        drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), healthPoint, monsterHealth, nowMonster.getAttack(), nowMonster.getDefence(), pic),
        Sleep(tim),
        putimage(5 * 32 + 32 * destination.getX(), 32 * destination.getY(), pic.block[id]);

        if(monsterHealth <= 0) break;

        healthPoint -= defence;
        //攻击一下勇者；
        putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[93]),
        drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), healthPoint, monsterHealth, nowMonster.getAttack(), nowMonster.getDefence(), pic),
        Sleep(tim),
        putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[1]);

        if(healthPoint<=0) break;
    }

    aStrongBrave.setHealthPoint(healthPoint);
    theBigMap.setPoint(destination,0);
    aStrongBrave.setPosition(destination);

    int money=usefulTools.getMoney();
    money+=nowMonster.getMoney();
    usefulTools.setMoney(money);

    if(id == 52) //打败了黑史莱姆
    {
        theBigMap.setPoint(point(2, 6, 4), 0); //生成机关门
        theBigMap.setPoint(point(2, 6, 8), 0); //生成机关门
    }
}