#include <map.h>

const int initialMap[high][length][width] = 
{
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, //0层
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 5, 5, 5,
    2, 2, 2, 2, 2, 2, 2, 2, 41, 2, 2, 2, 2,
    3, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2,
    5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,

    
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, //1层
    2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 0, 16, 0, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 10, 2, 2, 2, 2, 2, 
    0, 0, 2, 15, 0, 2, 0, 0, 0, 2, 0, 0, 2, 
    4, 0, 51, 0, 0, 51, 0, 31, 0, 51, 0, 17, 3, 
    0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 
    2, 2, 2, 2, 2, 2, 2, 10, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 0, 15, 0, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 

    
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, //2层
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 6, 6, 6, 6, 6, 2, 2, 2, 2,
    2, 2, 2, 2, 6, 17, 0, 0, 6, 2, 2, 0, 2,
    2, 2, 2, 0, 0, 0, 52, 0, 0, 0, 0, 0, 4,
    2, 2, 2, 0, 6, 17, 0, 0, 6, 2, 2, 0, 2,
    2, 2, 2, 0, 6, 6, 6, 6, 6, 2, 2, 31, 2,
    2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2,


    
    6, 6, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, //3层
    0, 0, 6, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    0, 0, 6, 35, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    0, 0, 6, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    6, 6, 6, 0, 2, 2, 53, 2, 2, 2, 2, 2, 2, 
    6, 6, 6, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 
    6, 6, 6, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    6, 6, 6, 0, 2, 2, 53, 2, 2, 2, 2, 2, 2, 
    0, 0, 6, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    19, 0, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    0, 0, 6, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 
    6, 6, 6, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 

    0, 53, 31, 17, 2, 0, 17, 0, 2, 0, 2, 2, 2, //4层
    10, 2, 2, 2, 2, 31, 0, 53, 10, 0, 2, 15, 17, 
    17, 17, 53, 0, 2, 0, 17, 0, 2, 0, 2, 0, 0, 
    2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 55, 0, 0, 
    16, 17, 56, 0, 2, 0, 15, 0, 2, 0, 2, 31, 32, 
    2, 2, 2, 0, 10, 53, 0, 17, 56, 0, 2, 2, 2, 
    0, 0, 2, 0, 2, 0, 31, 0, 2, 0, 2, 0, 4, 
    3, 0, 54, 0, 2, 2, 11, 2, 2, 0, 0, 17, 0, 
    0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 
    2, 2, 2, 0, 2, 2, 56, 2, 2, 0, 2, 17, 0, 
    43, 0, 2, 0, 2, 0, 0, 0, 2, 0, 53, 0, 56, 
    42, 0, 53, 0, 10, 53, 0, 16, 2, 0, 2, 2, 10, 
    44, 17, 2, 0, 2, 0, 17, 0, 2, 0, 2, 15, 16, 
};

#include <iostream>
using namespace std;
map::map()
{
    for(int floor = 0; floor < high; floor ++)
        for(int x = 0; x < length; x ++)
            for(int y = 0; y < width; y ++)
                theMap[floor][x][y] = initialMap[floor][x][y];
}

bool map::checkPoint(point position)
{
    int floor = position.getFloor();
    int x = position.getX();
    int y = position.getY();
    return 0 <= floor && floor < high 
           && 0 <= x && x < length 
           && 0 <= y && y < width;
}

int map::getPoint(point position)
{
    int floor = position.getFloor();
    int x = position.getX();
    int y = position.getY();
    if(checkPoint(position)) 
        return theMap[floor][x][y];
    return 0;
}

void map::setPoint(point position, int val)
{
    int floor = position.getFloor();
    int x = position.getX();
    int y = position.getY();
    if(checkPoint(position)) 
        theMap[floor][x][y] = val;
}