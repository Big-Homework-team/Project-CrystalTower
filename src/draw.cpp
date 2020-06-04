#include <graphics.h>
#include "draw.h"
#include "map.h"
#include "theBrave.h"

void drawMonsterImformation(theBrave aStrongBrave, int id, string name, int healthPoint, int monsterHealth, int attack, int defence, picture pic)
{
    if(monsterHealth < 0) monsterHealth = 0;
    setcolor(WHITE);                       //字体颜色
	setfont(16, 0, "黑体");
    //left
    bar(64, 80, 128, 112); // 生命
    putimage(16, 80,  pic.block[98]); // 生命

    char s[20];

    sprintf(s, "%d", healthPoint);
    outtextxy(70, 86, s); //
    //right
    bar(592, 8* 32 - 16, 720, 384); // 怪物
    //592-624-656-688-720
    //240--288-320-352-384
    for(int i = 592 + 16; i <= 688 - 16; i += 32) {//怪物信息1
            putimage(i, 8* 32 - 16, pic.block[0]);
            putimage(i, 8* 32 + 16, pic.block[0]);
    }
    putimage(592, 8* 32 - 16, pic.block[0]);
    putimage(592, 8* 32 + 16, pic.block[0]);
    putimage(688, 8* 32 - 16, pic.block[0]);
    putimage(688, 8* 32 + 16, pic.block[0]);

    if(id == 82) putimage(640, 240, pic.block[90]); //boss小贴图
    else putimage(640, 240, pic.block[id]);
    
    for(int i = 592 + 32; i <= 688; i += 32) {//怪物信息2
        for(int j = 9 * 32; j <= 9 * 32 + 64; j += 32) {
            putimage(i, j, pic.block[0]);
        }
    }
    putimage(592, 9 * 32, pic.block[94]); // 三合一贴图
    line(592, 9 * 32, 720, 9 * 32);
    outtextxy(656 - 8, 288 + 8, to_string(monsterHealth).c_str());
    outtextxy(656 - 8, 288 + 32 + 8, to_string(attack).c_str());
    outtextxy(656 - 8, 288 + 64 + 8, to_string(defence).c_str());
}

void createFrame(picture pic) {
    //left
    bar(16, 16, 144, 48); // 层数
    bar(64, 80, 128, 112); // 生命
    bar(64, 128, 128, 160); // 攻击力
    bar(64, 176, 128, 208); // 防御力
    bar(64, 224, 128, 256); // 金币
    //right
    bar(592, 8* 32 - 16, 720, 384); // 怪物

    for(int i = 592; i <= 688; i += 32) {  //道具
        for(int j = 160; j <= 192; j += 32) {
            putimage(i, j, pic.block[0]);
        }
    }
    for(int i = 640; i <= 672; i += 32) {//钥匙
        for(int j = 32; j <= 96; j += 32) {
            putimage(i, j, pic.block[0]);
        }
    }
    //592-624-656-688-720
    //240--288-320-352-384
    for(int i = 592 + 16; i <= 688 - 16; i += 32) {//怪物信息1
            putimage(i, 8* 32 - 16, pic.block[0]);
            putimage(i, 8* 32 + 16, pic.block[0]);
    }
    putimage(592, 8* 32 - 16, pic.block[0]);
    putimage(592, 8* 32 + 16, pic.block[0]);
    putimage(688, 8* 32 - 16, pic.block[0]);
    putimage(688, 8* 32 + 16, pic.block[0]);
    for(int i = 592 + 32; i <= 688; i += 32) {//怪物信息2
        for(int j = 9 * 32; j <= 9 * 32 + 64; j += 32) {
            putimage(i, j, pic.block[0]);
        }
    }
    putimage(592, 9 * 32, pic.block[94]); // 三合一贴图
    line(592, 9 * 32, 720, 9 * 32);
}

void setBackground(picture pic) {
    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    setcolor(WHITE);                       //字体颜色
	setfont(-16, 0, "黑体");
    for(int i = 0; i < 23; i++) { // 铺蓝色背景
        for(int j = 0; j < 23; j++) {
            putimage(i * 32, j * 32, pic.block[99]);
        }
    }

    createFrame(pic);

    putimage(16, 80,  pic.block[98]); // 生命
    putimage(16, 128, pic.block[97]); // 攻击力
    putimage(16, 176, pic.block[96]); // 防御力
    putimage(16, 224, pic.block[95]); // 金币

    

    putimage(608, 32, pic.block[31]); //黄
    putimage(608, 64, pic.block[32]); //蓝
    putimage(608, 96, pic.block[33]); //红
    
    
}

void drawMap(theBrave aStrongBrave, map theBigMap, picture pic) {
    point thePosition = aStrongBrave.getPosition();
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 13; j++) {
            putimage(i * 32 + OriginX, j * 32 + OriginY, pic.block[theBigMap.getPoint(point(thePosition.getFloor(), i, j))]);
        }
    }
    int id; //根据勇者面向决定图片 id
    if(aStrongBrave.getFace() == 0) id = 1;
    if(aStrongBrave.getFace() == 1) id = 48;
    if(aStrongBrave.getFace() == 2) id = 49;
    if(aStrongBrave.getFace() == 3) id = 50;
    putimage(thePosition.getX() * 32 + OriginX, thePosition.getY() * 32 + OriginY, pic.block[id]);
}



void updateInformation(theBrave aStrongBrave, tools usefulTools, picture pic) {
    createFrame(pic);
    int floor = (aStrongBrave.getPosition()).getFloor();
    string floor_ch = "";
    floor_ch += char(floor + '0');
    string floorInformation = "水晶塔第" + floor_ch + "层";
    outtextxy(35, 23, floorInformation.c_str());

    char s[20];

    sprintf(s, "%d", aStrongBrave.getHealthPoint());
    outtextxy(70, 86, s); //
    sprintf(s, "%d", aStrongBrave.getAttack());
    outtextxy(70, 134, s);
    sprintf(s, "%d", aStrongBrave.getDefence());
    outtextxy(70, 182, s);
    sprintf(s, "%d", usefulTools.getMoney());
    outtextxy(70, 234, s);

    sprintf(s, "%d", usefulTools.getYellowKey());
    outtextxy(670, 40, s);
    sprintf(s, "%d", usefulTools.getRedKey());
    outtextxy(670, 72, s); //
    sprintf(s, "%d", usefulTools.getBlueKey());
    outtextxy(670, 104, s); //
    if(usefulTools.getDraft()) 
        putimage(592, 176, pic.block[35]);
    if(usefulTools.getMonsterManual()) 
        putimage(624, 176, pic.block[36]); //
    if(usefulTools.getTransmitter())
        putimage(656, 176, pic.block[37]);
    if(usefulTools.getBoom())
        putimage(688, 176, pic.block[38]);
}

void updateMonsterInformation(monster theMonster, picture pic) {
    createFrame(pic);
    //sprintf(s, "%d", theMonster.);
    //outtextxy(640, 32, s);
    char s[20];
    sprintf(s, "%d", theMonster.getHealthPoint());
    outtextxy(660, 32 * 9 + 8, s);
    sprintf(s, "%d", theMonster.getAttack());
    outtextxy(660, 32 * 10 + 8, s);
    sprintf(s, "%d", theMonster.getDefence());
    outtextxy(660, 32 * 11 + 8, s);
}

void draw(theBrave aStrongBrave, tools usefulTools, map theBigMap, picture pic) //绘制地图与角色数据
{
    drawMap(aStrongBrave, theBigMap, pic);

    updateInformation(aStrongBrave, usefulTools, pic);

}


