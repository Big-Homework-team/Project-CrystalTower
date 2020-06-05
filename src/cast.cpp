#include "cast.h"

const int castNumber = 5;
/*
组长
组员
贴图音乐素材
游戏模式借鉴
游戏剧情借鉴


*/

char title[5][100] = {
    "组长",
    "组员",
    "贴图音乐素材",
    "游戏模式借鉴",
    "游戏剧情借鉴"
};

char content[5][100] = {
    "           刘知源",
    "周雪妍     廖浩深     吴咏蔚",
    "  《魔塔》  《最终幻想14》",
    "          《魔塔》",
    "       《最终幻想14》"
};
void createCast(int move) {
    int posy[castNumber], posx = 480;
    posy[0] = 352 - move;
    for(int i = 1; i < castNumber; i++) posy[i] = posy[i-1] + 64;
    for(int i = 0; i < castNumber; i++) {
        if(posy[i] < 352) {
            outtextxy(posx - 32, posy[i], title[i]);
            outtextxy(posx, posy[i] + 20, content[i]);
        }
    }
}

void printCast() {
    setcolor(WHITE);
    int move = 0, allowExit = 0, p = 0;
    PIMAGE back = newimage();
    getimage(back, "static\\img\\castBack.png");
    putimage(0, 0, back);
    for(;is_run(); delay_fps(60)) {
        if(allowExit) {
            if(kbhit()) p = getch();
            if(p == key_esc) {
                setcolor(BLACK);
                return ;
            }
        }
        if(move < 310) move++;
        putimage(0, 0, back);
        createCast(move);
        if(move == 310) {
            allowExit = 1;
        }
        if(allowExit) outtextxy(544, 384, "按 ESC 退出");
    }
}