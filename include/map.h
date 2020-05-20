#pragma once
const int high = 4;
const int length = 13;
const int width = 13;


class map //地图数据
{
private:
    int theMap[high][length][width];
    bool checkPoint(int floor, int x, int y);

public:
    map();
    ~map() {};
    int getPoint(int floor, int x, int y);
    void setPoint(int floor, int x, int y, int val);
};