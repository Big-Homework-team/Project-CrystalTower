#pragma once
#include "object.h"

class monster: public object
{
private:
    int healthPoint, defence, attack;
    int money;
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap);
    monster(){};
    ~monster() {};
    int getHealthPoint() {return healthPoint;}
    int getDefence() {return defence;}
    int getAttack() {return attack;}
    int getMoney() {return money;}
    void setMoney(int money) {this->money = money;}
    void setHealthPoint(int healthPoint) {this->healthPoint = healthPoint;}
    void setDefence(int defence) {this->defence = defence;}
    void setAttack(int attack) {this->attack = attack;}
};