#pragma once
#include "point.h"
#include "theBrave.h"
#include "tools.h"
#include "map.h"
#include <string>

class object
{
public:
    virtual void takeEvent(point destination, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap) = 0;
};

class MCreature: public object {
private:
    int healthPoint, defence, attack;
    std::string name;
    point position;
public:
    MCreature();
    MCreature(std::string name_, int healthPoint_, int defence, int attack);

    point getPosition() { return this->position; }
    void setPosition(point position_) { this->position = position_; }
    void setName(std::string name_);

    virtual void takeAttack(MCreature * obj) = 0;
    virtual void takeHurt(MCreature * from) = 0;
    virtual void takeAttackFightBack(MCreature * obj) = 0;
};