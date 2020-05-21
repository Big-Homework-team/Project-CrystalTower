#include <graphics.h>
#include "draw.h"
#include "map.h"
#include "theBrave.h"

void createFrame() {
    //left
    bar(16, 16, 144, 48); // 层数
    bar(64, 80, 128, 112); // 生命
    bar(64, 128, 128, 160); // 攻击力
    bar(64, 176, 128, 208); // 防御力
    bar(64, 224, 128, 256); // 金币
    // right
    bar(608, 32, 704, 128); // 黄钥匙
    //bar(640, 64, 704, 96);  红钥匙
    //bar(640, 112, 704, 144);  蓝钥匙
    bar(592, 5 * 32, 720, 7 * 32);
    bar(592, 8* 32 - 16, 720, 384); // 怪物
}

void setBackground(picture pic) {
    for(int i = 0; i < 23; i++) {
        for(int j = 0; j < 23; j++) {
            putimage(i * 32, j * 32, pic.block[99]);
        }
    }
    setfillcolor(DARKGRAY);
    createFrame();

    putimage(16, 80,  pic.block[98]); // 生命
    putimage(16, 128, pic.block[97]); // 攻击力
    putimage(16, 176, pic.block[96]); // 防御力
    putimage(16, 224, pic.block[95]); // 金币

    for(int i = 592; i <= 688; i += 32) {
        for(int j = 160; j <= 192; j += 32) {
            putimage(i, j, pic.block[0]);
        }
    }
    for(int i = 608; i <= 672; i += 32) {
        for(int j = 32; j <= 96; j += 32) {
            putimage(i, j, pic.block[0]);
        }
    }

    putimage(608, 32, pic.block[31]); //黄
    putimage(608, 63, pic.block[32]); //红
    putimage(608, 96, pic.block[33]); //蓝
    
    putimage(592, 9 * 32, pic.block[94]); // 三合一贴图
    line(592, 9 * 32, 720, 9 * 32);
}

void drawMap(theBrave aStrongBrave, map theBigMap, picture pic) {
    point thePosition = aStrongBrave.getPosition();
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 13; j++) {
            putimage(i * 32 + OriginX, j * 32 + OriginY, pic.block[theBigMap.getPoint(point(thePosition.getFloor(), i, j))]);
        }
    }
    putimage(thePosition.getX() * 32 + OriginX, thePosition.getY() * 32 + OriginY, pic.block[1]);
}



void updateInformation(theBrave aStrongBrave, tools usefulTools) {

}

void draw(theBrave aStrongBrave, tools usefulTools, map theBigMap, picture pic) //绘制地图与角色数据
{
    drawMap(aStrongBrave, theBigMap, pic);

    updateInformation(aStrongBrave, usefulTools);

}


