#pragma once
#include "point.h"

const int high = 4;
const int length = 13;
const int width = 13;


class map //地图数据
{
private:
    int theMap[high][length][width];

public:
    map();
    ~map() {};
    bool checkPoint(point position);
    int getPoint(point position);
    void setPoint(point position, int val);
};