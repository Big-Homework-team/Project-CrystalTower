#pragma once
#include "point.h"

class theBrave //勇者数据
{
private:
    int healthPoint, defence, attack, times;
    int face; //面向，下为0，上为1，左为2，右为3
    point position;
    int isTakeBossEvent;

public:
    theBrave();
    ~theBrave() {};
    point getPosition() {return position;}
    int getHealthPoint() {return healthPoint;}
    int getDefence() {return defence;}
    int getAttack() {return attack;}
    int getTimes() {return times;}
    int getFace() {return face;}
    int getIsTakeBossEvent() {return isTakeBossEvent;}

    void setPosition(point position) {this->position = position;}
    void setHealthPoint(int healthPoint) {this->healthPoint = healthPoint;}
    void setDefence(int defence) {this->defence = defence;}
    void setAttack(int attack) {this->attack = attack;}
    void setTimes(int times) {this->times = times;}
    void setFace(int face) {this->face = face;}
    void setIsTakeBossEvent(int isTakeBossEvent) {this->isTakeBossEvent = isTakeBossEvent;}
};

