#pragma once
#include <string>
using namespace std;

class monster //怪物类
{
private:
    int healthPoint, defence, attack;
    int money;
    string name;
public:
    monster(){};
    ~monster() {};
    int getHealthPoint() {return healthPoint;}
    int getDefence() {return defence;}
    int getAttack() {return attack;}
    int getMoney() {return money;}
    string getName() {return name;}
    void setMoney(int money) {this->money = money;}
    void setHealthPoint(int healthPoint) {this->healthPoint = healthPoint;}
    void setDefence(int defence) {this->defence = defence;}
    void setAttack(int attack) {this->attack = attack;}
    void setName(string name) {this->name = name;}
};