#pragma once

class point
{
private:
    int x, y, floor;
public:
    point() {};
    point(int x, int y, int floor): x(x), y(y), floor(floor) {};
    ~point() {};
    int getX() {return x;}
    int getY() {return y;}
    int getFloor() {return floor;}
    void setX(int x) {this->x = x;}
    void setY(int y) {this->y = y;}
    void setFloor(int floor) {this->floor = floor;}
};