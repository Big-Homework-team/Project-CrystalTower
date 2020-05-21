#pragma once
#include "theBrave.h"
#include "tools.h"
#include "map.h"
#include "picture.h"
#include "monster.h"


const int OriginX = 160;
const int OriginY = 0;

void draw(theBrave aStrongBrave, tools usefulTools, map theBigMap, picture pic); //绘制地图与角色数据

void setBackground(picture pic);

void createFrame(picture pic);

void updateInfomation();

void updateInformation(theBrave aStrongBrave, tools usefulTools, picture pic);

void updateMonsterInformation(monster theMonster);