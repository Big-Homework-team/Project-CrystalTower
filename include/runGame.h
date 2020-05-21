#pragma once
#include "theBrave.h"
#include "tools.h"
#include "map.h"
#include "picture.h"

class runGame
{
private:
    void initialize(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, picture &pic); //图形界面初始化
    picture pic;
public:
    void run(); //开始游戏
};