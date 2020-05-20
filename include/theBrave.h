#pragma once
class theBrave //勇者数据
{
private:
    int healthPoint, defence, attack;
    int x, y, floor;  
    

public:
    theBrave() {}
    ~theBrave() {}
    int getx() {return x;}
    int gety() {return y;}
    int getHealthPoint() {return healthPoint;}
    int getDefence() {return defence;}
    int getAttack() {return attack;}
    int getFloor() {return floor;}


    void setx(int x) {this->x = x;}
    void sety(int y) {this->y = y;}
    void setHealthPoint(int healthPoint) {this->healthPoint = healthPoint;}
    void setDefence(int defence) {this->defence = defence;}
    void setAttack(int attack) {this->attack = attack;}
    void setFloor(int floor) {this->floor = floor;}

};

