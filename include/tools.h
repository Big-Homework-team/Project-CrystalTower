#pragma once
class tools //道具数据
{
    private:
    int key1, key2, key3, money, weapon, armor, potion1, potion2, gem1, gem2;
    
    public:
    tools() {};
    ~tools() {};
    int getkey1() {return key1;}
    int getkey2() {return key2;}
    int getkey3() {return key3;}
    int getmoney() {return money;}
    int getweapon() {return weapon;}
    int getarmor() {return armor;}
    int getpotion1() {return potion1;}
    int getpotion2() {return potion2;}
    int getgem1() {return gem1;}
    int getgem2() {return gem2;}
    
    void setkey1(int key1) {this->key1 = key1;}
    void setkey2(int key2) {this->key2 = key2;}
    void setkey3(int key3) {this->key3 = key3;}
    void setmoney(int money) {this->money = money;}
    void setweapon(int weapon) {this->weapon = weapon;}
    void setarmor(int armor) {this->armor = armor;}
    void setpotion1(int potion1) {this->potion1 = potion1;}
    void setpotion2(int potion2) {this->potion2 = potion2;}
    void setgem1(int gem1) {this->gem1 = gem1;}
    void setgem2(int gem2) {this->gem2 = gem2;}

};