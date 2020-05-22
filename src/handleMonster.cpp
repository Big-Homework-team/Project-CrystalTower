#include "handleMonster.h"
#include "monster.h"

void handleMonster::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    monster bigMonster[100];
    //设置怪物属性
    bigMonster[51].setHealthPoint(20);
    bigMonster[51].setAttack(20);
    bigMonster[51].setDefence(1);
    bigMonster[51].setMoney(6);

    bigMonster[52].setHealthPoint(10);
    bigMonster[52].setAttack(15);
    bigMonster[52].setDefence(11);
    bigMonster[52].setMoney(2);

    bigMonster[53].setHealthPoint(80);
    bigMonster[53].setAttack(35);
    bigMonster[53].setDefence(5);
    bigMonster[53].setMoney(4);

    bigMonster[54].setHealthPoint(100);
    bigMonster[54].setAttack(30);
    bigMonster[54].setDefence(22);
    bigMonster[54].setMoney(7);

    bigMonster[55].setHealthPoint(30);
    bigMonster[55].setAttack(30);
    bigMonster[55].setDefence(21);
    bigMonster[55].setMoney(7);

    bigMonster[56].setHealthPoint(100);
    bigMonster[56].setAttack(40);
    bigMonster[56].setDefence(3);
    bigMonster[56].setMoney(5);

    int id=theBigMap.getPoint(destination);
    monster nowMonster = bigMonster[id];

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

    if(id == 53) healthPoint -= defence; //小蝙蝠先手

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

    if(id == 52) //打败了黑史莱姆
    {
        theBigMap.setPoint(point(2, 6, 4), 0); //生成机关门
        theBigMap.setPoint(point(2, 6, 8), 0); //生成机关门
    }
}