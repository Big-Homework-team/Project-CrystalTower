#include "boss.h"
#include "draw.h"

void boss::takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, monster bigMonster[], picture pic)
{
    int tim = 300;
    int id = theBigMap.getPoint(destination);
    if(id != 82) return ;

    MUSIC se;

    monster nowMonster = bigMonster[id];

    /*drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), nowMonster.getHealthPoint(), nowMonster.getAttack(), nowMonster.getDefence(), pic);
    Sleep(tim);*///开始时显示怪物信息？
    int healthPoint=aStrongBrave.getHealthPoint();
    int attack=aStrongBrave.getAttack() - nowMonster.getDefence();
    int defence=nowMonster.getAttack() - aStrongBrave.getDefence();
    int monsterHealth=nowMonster.getHealthPoint();

    if(attack <= 0) return ;

    int time=monsterHealth/attack;
    if(monsterHealth%attack==0) time--;

    if(time*defence >= healthPoint){
        return ;//没打过
    }
    tim = 300;
    while(healthPoint>0 && monsterHealth>0) { 
	    if(usefulTools.getWeapon()) se.OpenFile("static\\se\\剑击.mp3");
        else se.OpenFile("static\\se\\空手.mp3");
        se.Play(0);
        monsterHealth -= attack;
        //攻击一下怪物；
        drawMonsterImformation(aStrongBrave, id, nowMonster.getName(), healthPoint, monsterHealth, nowMonster.getAttack(), nowMonster.getDefence(), pic);
        if(tim) delay_ms(tim);
        if(monsterHealth <= 0) break;


        if(kbhit() || keystate(VK_UP) || keystate(VK_DOWN) || keystate(VK_LEFT) || keystate(VK_RIGHT) || keystate('w') || keystate('s') || keystate('a') || keystate('d'))
            tim = 0;
        se.OpenFile("static\\se\\火击（暴击）.mp3");
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

    //触发剧情2

    //清空boss贴图
    theBigMap.setPoint(destination,0);
    destination.setY(destination.getY() + 1);
    theBigMap.setPoint(destination,0);
    destination.setY(destination.getY() + 1);
    theBigMap.setPoint(destination,0);
    destination.setX(destination.getX() + 1);
    theBigMap.setPoint(destination,6);
    destination.setY(destination.getY() - 1);
    theBigMap.setPoint(destination,6);
    destination.setY(destination.getY() - 1);
    theBigMap.setPoint(destination,6);
    destination.setX(destination.getX() - 2);
    theBigMap.setPoint(destination,6);
    destination.setY(destination.getY() + 1);
    theBigMap.setPoint(destination,6);
    destination.setY(destination.getY() + 1);
    theBigMap.setPoint(destination,6);
    draw(aStrongBrave, usefulTools, theBigMap, pic);

    //触发剧情3
}