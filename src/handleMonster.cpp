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

    if(attack == 0) return ;

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