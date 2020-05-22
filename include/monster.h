#pragma once

class monster
{
private:
    int healthPoint, defence, attack;
    int money;
public:
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