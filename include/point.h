#pragma once

class point
{
private:
    int floor, x, y;
public:
    point() {};
    point(int floor, int x, int y): floor(floor), x(x), y(y) {};
    ~point() {};
    int getFloor() {return floor;}
    int getX() {return x;}
    int getY() {return y;}
    void setFloor(int floor) {this->floor = floor;}
    void setX(int x) {this->x = x;}
    void setY(int y) {this->y = y;}
};