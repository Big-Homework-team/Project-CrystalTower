#include "monsterMannual.h"
using namespace std;


void useMonsterMannual(theBrave aStrongBrave, map theBigMap, picture pic)
{
    monster bigMonster[100];
    string name[100];
    //设置怪物属性
    bigMonster[51].setHealthPoint(20);
    bigMonster[51].setAttack(20);
    bigMonster[51].setDefence(1);
    bigMonster[51].setMoney(6);
    name[51] = "绿史莱姆";

    bigMonster[52].setHealthPoint(10);
    bigMonster[52].setAttack(15);
    bigMonster[52].setDefence(11);
    bigMonster[52].setMoney(2);
    name[52] = "黑史莱姆";

    bigMonster[53].setHealthPoint(80);
    bigMonster[53].setAttack(35);
    bigMonster[53].setDefence(5);
    bigMonster[53].setMoney(4);
    name[53] = "小蝙蝠";

    bigMonster[54].setHealthPoint(100);
    bigMonster[54].setAttack(30);
    bigMonster[54].setDefence(22);
    bigMonster[54].setMoney(7);
    name[54] = "大蝙蝠";

    bigMonster[55].setHealthPoint(30);
    bigMonster[55].setAttack(30);
    bigMonster[55].setDefence(21);
    bigMonster[55].setMoney(7);
    name[55] = "石头人";

    bigMonster[56].setHealthPoint(100);
    bigMonster[56].setAttack(40);
    bigMonster[56].setDefence(3);
    bigMonster[56].setMoney(5);
    name[56] = "骷髅人";

    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    bar(5 * 32, 0 * 32, 18 * 32, 13 * 32); //绘制矩形作为背景
    setcolor(WHITE);                       //字体颜色
    setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT);                //字体背景色块调为透明

    for(int x = 0; x < 13; x ++)
        for(int y = 0; y < 13; y ++)
            putimage((5 + x) * 32, y * 32, pic.block[0]); //背景

    int have[100], vis[100]; int num = 0;
    for(int i = 0; i < 100; i ++) have[i] = vis[i] = 0;
    for(int x = 0; x < 13; x ++)
        for(int y = 0; y < 13; y ++)
        {
            int id = theBigMap.getPoint(point(aStrongBrave.getPosition().getFloor(), x, y));
            if(51 <= id && id <= 81 && vis[id] == 0)
            {
                vis[id] = 1;
                have[++ num] = id;
            }
        }
    for(int i = 1; i <= num && i <= 6; i ++)
    {
        int id = have[i];
        monster nowMonster = bigMonster[id];

        int healthPoint=aStrongBrave.getHealthPoint();
        int attack=aStrongBrave.getAttack() - nowMonster.getDefence();
        int defence=nowMonster.getAttack() - aStrongBrave.getDefence();
        int monsterHealth=nowMonster.getHealthPoint();
        if(attack <= 0) attack = 0;
        if(defence <= 0) defence = 0;

        if(id == 55 && attack > 1) attack = 1; //打石头人最多 1 点

        string consume = "";
        if(attack == 0) consume = "???";
        else
        {
            int time=monsterHealth/attack;
            if(monsterHealth%attack==0) time--;

            if(id == 53) time ++; //小蝙蝠先手
            int consumeNum = time * defence;
            while(consumeNum)
            {
                consume = char(consumeNum % 10 + '0') + consume;
                consumeNum /= 10;
            }
        }

        int det = (i >= 4);

        consume = "消耗" + consume;
        putimage(5 * 32 + det * 32 * 8, (0 + 3 * ((i - 1) % 3)) * 32, pic.block[id]); // 怪物贴图
        putimage(8 * 32 + det * 32 * 8, (0 + 3 * ((i - 1) % 3)) * 32, pic.block[94]); // 三合一贴图
        outtextxy(6 * 32 + det * 32 * 8, (0 + 3 * ((i - 1) % 3)) * 32 + 8, name[id].c_str());
        outtextxy(6 * 32 + det * 32 * 8, (0 + 3 * ((i - 1) % 3) + 1) * 32 + 8, consume.c_str());
        outtextxy(6 * 32 + det * 32 * 8, (0 + 3 * ((i - 1) % 3) + 2) * 32 + 8, "点体力");
        outtextxy(9 * 32 + 2 + det * 32 * 8, (0 + 3 * ((i - 1) % 3)) * 32 + 8, to_string(nowMonster.getHealthPoint()).c_str());
        outtextxy(9 * 32 + 2 + det * 32 * 8, (0 + 3 * ((i - 1) % 3) + 1) * 32 + 8, to_string(nowMonster.getAttack()).c_str());
        outtextxy(9 * 32 + 2 + det * 32 * 8, (0 + 3 * ((i - 1) % 3) + 2) * 32 + 8, to_string(nowMonster.getDefence()).c_str());

        if(id == 53)
        {
            outtextxy(5 * 32 + det * 32 * 8, 16 + (0 + 3 * ((i - 1) % 3) + 1) * 32 + 8, "先");  
            outtextxy(15 + 5 * 32 + det * 32 * 8, 16 + (0 + 3 * ((i - 1) % 3) + 1) * 32 + 8, "攻");
        }
        if(id == 55)
        {
            outtextxy(5 * 32 + det * 32 * 8, 16 + (0 + 3 * ((i - 1) % 3) + 1) * 32 + 8, "坚");  
            outtextxy(15 + 5 * 32 + det * 32 * 8, 16 + (0 + 3 * ((i - 1) % 3) + 1) * 32 + 8, "固");
        }
    }
    outtextxy(14 * 32, 12 * 32, "按空格键退出");
    char action = '.';
    while (action != 32)
    {
        action = getch();
    }
}