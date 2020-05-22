#include <graphics.h>
#include "runGame.h"
#include "draw.h" //绘制地图与角色数据
#include "handleKey.h" //处理键盘事件
#include "monster.h"
#include "menu.h"

void runGame::initialize(picture &pic)
{
	initgraph(736, 416, 0); // 初始化窗口
    setbkcolor(BLACK); //窗口底色
    setcaption("Crystal_Tower"); // 窗口标题
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
	createMenu();
}



void runGame::run()
{
	
	picture pic;
    initialize(pic); //图形界面初始化
	int choice = 0;
	for(;is_run(); delay_fps(60)) {
		createMenu();
		createChoice(choice);
		char menuAction = getch();
		if(menuAction == 'w' || menuAction == 38) choice = (choice - 1 + menuLength) % menuLength;
		if(menuAction == 's' || menuAction == 40) choice = (choice + 1 + menuLength) % menuLength;
		if(menuAction == 32) { // 空格
			if(choice == 0) { //游戏
				theBrave aStrongBrave;
				tools usefulTools;
				map theBigMap;
				setBackground(pic);
				draw(aStrongBrave, usefulTools, theBigMap, pic); //绘制图形界面
				for(;is_run(); delay_fps(60))
				{
					char action = getch();
   	 				if(action == 27) //ESC 的键码是 27.
					{
						CreateMenu();
						break ; //结束游戏.
					}
        			handle(action, aStrongBrave, usefulTools, theBigMap, pic); //处理按键
    				draw(aStrongBrave, usefulTools, theBigMap, pic);
				}
				
			}
			if(choice == 1) {

			}
			if(choice == 2) {
				
			}
			if(choice == 3) {
				return;
			}
		}
	}
}