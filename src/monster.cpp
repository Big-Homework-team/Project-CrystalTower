#include "monster.h"

void monster::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    monster bigMonster[100];
    int i=theBigMap.getPoint(destination);
    monster nowMonster = bigMonster[i];

    int healthPoint=aStrongBrave.getHealthPoint();
    int attack=aStrongBrave.getAttack() - nowMonster.getDefence();
    int defence=nowMonster.getAttack() - aStrongBrave.getDefence();
    int monsterHealth=nowMonster.getHealthPoint();
    if(attack <= 0) attack = 1;
    if(defence <= 0) defence = 1;

    int time=monsterHealth/attack;
    if(monsterHealth%attack==0) time--;
    if(time*defence >= healthPoint){
        return ;//没打过
    }

    while(healthPoint>0 && monsterHealth>0){
        monsterHealth -= attack;
        //攻击一下怪物；
        if(monsterHealth <= 0) break;
        healthPoint -= defence;
        //攻击一下勇者；
        if(healthPoint<=0) break;
    }

    aStrongBrave.setHealthPoint(healthPoint);
    theBigMap.setPoint(destination,0);
    aStrongBrave.setPosition(destination);

    int money=usefulTools.getMoney();
    money+=nowMonster.getMoney();
    usefulTools.setMoney(money);
}