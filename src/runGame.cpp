#include <graphics.h>
#include "runGame.h"
#include "draw.h" //绘制地图与角色数据
#include "handleKey.h" //处理键盘事件

void runGame::initialize(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
	initgraph(1600, 900, 0); // 初始化窗口
    setbkcolor(BLACK); //窗口底色
    setcaption("Crystal_Tower"); // 窗口标题
	draw(aStrongBrave, usefulTools, theBigMap); //绘制图形界面
}

void runGame::run()
{
	theBrave aStrongBrave;
	tools usefulTools;
	map theBigMap;
    initialize(aStrongBrave, usefulTools, theBigMap); //图形界面初始化
	for(;is_run(); delay_fps(60))
	{
		char action = getch();
    	if(action == 27) //ESC 的键码是 27.
		{
			return ; //结束游戏.
		}
        handle(action, aStrongBrave, usefulTools, theBigMap); //处理按键
	}
}