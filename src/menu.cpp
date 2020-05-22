#include "menu.h"

void createMenu() {
    setcolor(BLACK);                       //字体颜色
	setfont(-16, 0, "黑体");
	setbkmode(TRANSPARENT);
    PIMAGE backPicture = newimage();
    getimage(backPicture, "static\\img\\crystal.png");
    putimage(0, 0, backPicture);
}

void createChoice(int choice) {
    LOGFONT font;
    int x = 544, cnt = 1, y = 96;
    
    outtextxy(x, y, "开始游戏"); y += 64; 
    outtextxy(x, y, "继续游戏"); y += 64;
    outtextxy(x, y, "制作人员"); y += 64; 
    outtextxy(x, y, "退出游戏");

    outtextxy(x + 96, 96 + choice * 64, "<<<");
}