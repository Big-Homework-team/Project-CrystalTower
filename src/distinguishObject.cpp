#include "distinguishObject.h"

object *distinguishObject(int id) //处理事件
{
    //根据 ID 获取对应的类指针
    object *newObject = NULL;
    if(id == 0 || id == 14) newObject = new space; //空地
    else if(id == 3 || id == 4) newObject = new floor; //上下层
    else if(id == 10 || id == 11 || id == 12) newObject = new door; //门
    else if(id == 15 || id == 16 || id == 17 || id == 18) newObject = new prop; //道具
    else if(id == 19 || id == 20) newObject = new equipment; //装备
    else if(id == 31 || id == 32 || id == 33) newObject = new key; //钥匙
    else if(id == 35 || id == 37 || id == 38) newObject = new tool; //道具
    else if(id == 41) newObject = new theElderly; //老人
    else if(id == 42) newObject = new shop; //商店
    else if(51 <= id && id <= 80) newObject = new handleMonster; //怪物
    else if(id == 82) newObject = new boss; //boss
    else newObject = new wall; //没找到就返回墙
    return newObject;
}