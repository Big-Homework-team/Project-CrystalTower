#include "handleMonster.h"
#include "monster.h"
#include "draw.h"


void handleMonster::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int tim = 300;
    int id=theBigMap.getPoint(destination);

    MUSIC se;

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
        if (theBigMap.getPoint(point(2, 8, 11)) == 7 && theBigMap.getPoint(point(2, 6, 4)) == 13 && id == 52)
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
        else if ((theBigMap.getPoint(point(2, 8, 11)) == 0 || theBigMap.getPoint(point(2, 8, 11)) == 31) && theBigMap.getPoint(point(2, 6, 4)) == 13 && id == 52)
        {
            int flag = theBigMap.getPoint(point(2, 8, 11));
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
            theBigMap.setPoint(point(2, 8, 11), flag);
        }
        return ;
    }

    int time=monsterHealth/attack;
    if(monsterHealth%attack==0) time--;

    if(id == 53) time ++; //小蝙蝠先手

    if(time*defence >= healthPoint){
        return ;//没打过
    }
    tim = 300;
    if(id == 53) {
        se.OpenFile("static\\se\\蝙蝠.mp3");
        se.Play(0);
        healthPoint -= defence; //小蝙蝠先手
        putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[93]);
        drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), healthPoint, monsterHealth, nowMonster.getAttack(), nowMonster.getDefence(), pic);
        delay_ms(tim);
        int id; //根据勇者面向决定图片 id
        if(aStrongBrave.getFace() == 0) id = 1;
        if(aStrongBrave.getFace() == 1) id = 48;
        if(aStrongBrave.getFace() == 2) id = 49;
        if(aStrongBrave.getFace() == 3) id = 50;
        putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[id]);
    }
    while(healthPoint>0 && monsterHealth>0) { 
	    if(usefulTools.getWeapon()) se.OpenFile("static\\se\\剑击.mp3");
        else se.OpenFile("static\\se\\空手.mp3");
        se.Play(0);
        monsterHealth -= attack;
        //攻击一下怪物；
        if(tim) putimage(5 * 32 + 32 * destination.getX(), 32 * destination.getY(), pic.block[93]);
        drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), healthPoint, monsterHealth, nowMonster.getAttack(), nowMonster.getDefence(), pic);
        if(tim) delay_ms(tim);
        if(tim) putimage(5 * 32 + 32 * destination.getX(), 32 * destination.getY(), pic.block[id]);
        if(monsterHealth <= 0) break;


        if(kbhit() || keystate(VK_UP) || keystate(VK_DOWN) || keystate(VK_LEFT) || keystate(VK_RIGHT) || keystate('w') || keystate('s') || keystate('a') || keystate('d'))
            tim = 0;
        if(id == 53 || id == 54) se.OpenFile("static\\se\\蝙蝠.mp3");
        else se.OpenFile("static\\se\\空手.mp3");
        se.Play(0);
        healthPoint -= defence;
        //攻击一下勇者；
        if(tim) putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[93]);
        drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), healthPoint, monsterHealth, nowMonster.getAttack(), nowMonster.getDefence(), pic);
        if(tim) delay_ms(tim);
        if(tim)
        {
            int id; //根据勇者面向决定图片 id
            if(aStrongBrave.getFace() == 0) id = 1;
            if(aStrongBrave.getFace() == 1) id = 48;
            if(aStrongBrave.getFace() == 2) id = 49;
            if(aStrongBrave.getFace() == 3) id = 50;
            putimage(5 * 32 + 32 * aStrongBrave.getPosition().getX(), 32 * aStrongBrave.getPosition().getY(), pic.block[id]);
        }
         
        if(healthPoint<=0) break;

        if(kbhit() || keystate(VK_UP) || keystate(VK_DOWN) || keystate(VK_LEFT) || keystate(VK_RIGHT) || keystate('w') || keystate('s') || keystate('a') || keystate('d'))
            tim = 0; 
    }
    tim = 300;
    aStrongBrave.setHealthPoint(healthPoint);
    theBigMap.setPoint(destination,0);

    int money=usefulTools.getMoney();
    money+=nowMonster.getMoney();
    usefulTools.setMoney(money);

    if(id == 52) //打败了黑史莱姆
    {
        delay_ms(300);
        MUSIC se;
        se.OpenFile("static\\se\\开门.mp3");
        se.Play(0);
        delay_ms(300);
        theBigMap.setPoint(point(2, 6, 4), 0); //消除机关门
        theBigMap.setPoint(point(2, 6, 8), 0); //消除机关门
    }
}