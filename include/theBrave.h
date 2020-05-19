#pragma once
class theBrave //勇者数据
{
    private:
    int hp, def, atk; 
    int x, y, floor;  
    

    public:
    theBrave() {}
    ~theBrave() {}
    int getx() {return x;}
    int gety() {return y;}
    int gethp() {return hp;}
    int getdef() {return def;}
    int getatk() {return atk;}
    int getfloor() {return floor;}


    void setx(int x) {this->x = x;}
    void sety(int y) {this->y = y;}
    void sethp(int hp) {this->hp = hp;}
    void setdef(int def) {this->def = def;}
    void setatk(int atk) {this->atk = atk;}
    void setfloor(int floor) {this->floor = floor;}

};

