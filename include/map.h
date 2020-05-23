#pragma once
#include "point.h"

const int high = 6;
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
    int getTheMap(point position); //查询地图值，用于判断史莱姆机关前是否触发隐藏
    void setPoint(point position, int val);
};