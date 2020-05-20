#pragma once
class tools //道具数据
{
private:
    int yellowKey, blueKey, redKey, money, weapon, armor;
    
public:
    tools()
    {
        yellowKey = blueKey = redKey = money = weapon = armor = 0;
    }
    ~tools() {};
    int getYellowKey() {return yellowKey;}
    int getBlueKey() {return blueKey;}
    int getRedKey() {return redKey;}
    int getMoney() {return money;}
    int getWeapon() {return weapon;}
    int getArmor() {return armor;}
    
    void setYellowKey(int yellowKey) {this->yellowKey = yellowKey;}
    void setBlueKey(int blueKey) {this->blueKey = blueKey;}
    void setRedKey(int redKey) {this->redKey = redKey;}
    void setMoney(int money) {this->money = money;}
    void setWeapon(int weapon) {this->weapon = weapon;}
    void setArmor(int armor) {this->armor = armor;}

};