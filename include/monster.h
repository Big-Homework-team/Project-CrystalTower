#pragma once
#include "object.h"

class monster: public object
{
private:
    int healthPoint, defence, attack;
    point position;
    int id;
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap);
    monster() {};
    ~monster() {};
    point getPosition() {return position;}
    int getHealthPoint() {return healthPoint;}
    int getDefence() {return defence;}
    int getAttack() {return attack;}
    int getId() {return id;}
    void setId(int id)  {this->id = id;}
    void setPosition(point position) {this->position = position;}
    void setHealthPoint(int healthPoint) {this->healthPoint = healthPoint;}
    void setDefence(int defence) {this->defence = defence;}
    void setAttack(int attack) {this->attack = attack;}
};