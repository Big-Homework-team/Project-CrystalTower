#pragma once
#include "theBrave.h"
#include "tools.h"
#include "map.h"

class runGame
{
private:
    void initialize(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap); //图形界面初始化
public:
    void run(); //开始游戏
};