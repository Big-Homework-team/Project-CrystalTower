#include "handleKey.h"
#include "move.h"
#include "draw.h"
#include "object.h"
#include "distinguishObject.h"
#include <cctype>


void handle(char action, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap) //处理按键
{
    action = tolower(action); //转换大小写
    point position, destination;
    destination = position = aStrongBrave.getPosition();
    if(action == 'a' || action == 37) destination.setX(position.getX() - 1);
    if(action == 'd' || action == 39) destination.setX(position.getX() + 1);
    if(action == 'w' || action == 38) destination.setY(position.getY() - 1);
    if(action == 's' || action == 40) destination.setY(position.getY() + 1);

    object *newObject = distinguishObject(theBigMap.getPoint(destination)); //根据 ID 获取相应的派生类指针
    newObject->takeEvent(destination, aStrongBrave, usefulTools, theBigMap);
}