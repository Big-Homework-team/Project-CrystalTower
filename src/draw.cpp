#include <graphics.h>
#include "draw.h"
#include "map.h"
#include "theBrave.h"


const int OriginX = 100;
const int OriginY = 100;

void setBlock(int kind, int x, int y) {
    picture pic;
    putimage(x, y, pic.block[kind]);
}

void drawMap(map theBigMap, int floor = 1) {
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 13; j++) {
            setBlock(theBigMap.getPoint(floor, i, j), i * 32 + OriginX, j * 32 + OriginY);
        }
    }
}

void createFrame() {

}

void createInformation(theBrave astrongBrave, tools usefulTools) {
    createFrame();
}

void draw(theBrave aStrongBrave, tools usefulTools, map theBigMap) //绘制地图与角色数据
{
    drawMap(theBigMap);

    createInformation(aStrongBrave, usefulTools);

}


