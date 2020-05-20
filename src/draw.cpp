#include <graphics.h>
#include "draw.h"
#include "map.h"
#include "theBrave.h"


const int OriginX = 100;
const int OriginY = 100;

void drawMap(theBrave aStrongBrave, map theBigMap) {
    point thePosition = aStrongBrave.getPosition();
    picture pic;
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 13; j++) {
            putimage(i * 32 + OriginX, j * 32 + OriginY, pic.block[theBigMap.getPoint(thePosition.getFloor(), i, j)]);
        }
    }
    putimage(thePosition.getX() * 32 + OriginX, thePosition.getY() * 32 + OriginY, pic.block[1]);
}

void createFrame() {

}

void createInformation(theBrave aStrongBrave, tools usefulTools) {
    createFrame();
}

void draw(theBrave aStrongBrave, tools usefulTools, map theBigMap) //绘制地图与角色数据
{
    drawMap(aStrongBrave, theBigMap);

    createInformation(aStrongBrave, usefulTools);

}


