#pragma once
#include <graphics.h>
#include "runGame.h"
#include "draw.h" //绘制地图与角色数据
#include "handleKey.h" //处理键盘事件

void runGame::initialize()
{
	draw(); //绘制图形界面
}

void runGame::run()
{
    initialize(); //图形界面初始化
	while(1)
	{
		char action = getch();
        handle(action); //处理按键
	}
}