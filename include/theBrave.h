#pragma once
#include "point.h"

class theBrave //勇者数据
{
private:
    int healthPoint, defence, attack, times;
    point position;
    

public:
    theBrave();
    ~theBrave() {};
    point getPosition() {return position;}
    int getHealthPoint() {return healthPoint;}
    int getDefence() {return defence;}
    int getAttack() {return attack;}
    int getTimes() {return times;}

    void setPosition(point position) {this->position = position;}
    void setHealthPoint(int healthPoint) {this->healthPoint = healthPoint;}
    void setDefence(int defence) {this->defence = defence;}
    void setAttack(int attack) {this->attack = attack;}
    void setTimes(int times) {this->times = times;}
};

