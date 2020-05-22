#include <graphics.h>
#include "runGame.h"
#include "draw.h" //绘制地图与角色数据
#include "handleKey.h" //处理键盘事件

void runGame::initialize(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, picture &pic)
{
	initgraph(736, 416, 0); // 初始化窗口
    setbkcolor(BLACK); //窗口底色
    setcaption("Crystal_Tower"); // 窗口标题
    setcolor(WHITE);                       //字体颜色
    setfillcolor(DARKGRAY);
	setfont(-16, 0, "黑体");
	setbkmode(TRANSPARENT);
	for(int i = 0; i < blockNumber; i++) {
        pic.block[i] = newimage();
    }
    for(int i = 0; i < blockNumber; i++) {
        string name = "";
        name += char(i / 10 + '0');
        name += char(i % 10 + '0');
        string path = "static\\img\\" + name + ".png";
        getimage(pic.block[i], path.c_str());
    }

	setBackground(pic);
	draw(aStrongBrave, usefulTools, theBigMap, pic); //绘制图形界面
}

void runGame::run()
{
	theBrave aStrongBrave;
	tools usefulTools;
	map theBigMap;
	picture pic;
	
    initialize(aStrongBrave, usefulTools, theBigMap, pic); //图形界面初始化
	for(;is_run(); delay_fps(60))
	{
		char action = getch();
    	if(action == 27) //ESC 的键码是 27.
		{
			return ; //结束游戏.
		}
        handle(action, aStrongBrave, usefulTools, theBigMap, pic); //处理按键
    	draw(aStrongBrave, usefulTools, theBigMap, pic);
	}
}