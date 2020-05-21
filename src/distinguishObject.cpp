#include "distinguishObject.h"

object *distinguishObject(int id)
{
    //根据 ID 获取对应的类指针
    object *newObject = NULL;
    if(id == 0) newObject = new space;
    else if(id == 3 || id == 4) newObject = new floor;
    else if(id == 10 || id == 11 || id == 12) newObject = new door;
    else if(id == 15 || id == 16 || id == 17 || id == 18) newObject = new prop;
    else if(id == 19 || id == 20) newObject = new equipment;
    else if(id == 31 || id == 32 || id == 33) newObject = new key;
    else if(id == 35) newObject = new draft;
    else if(id == 41) newObject = new theElderly;
    else if(id == 42) newObject = new shop;
    else if(51 <= id && id <= 80) newObject = new monster;
    else if(id == 81) newObject = new boss;
    else newObject = new wall; //没找到就返回墙
    return newObject;
}