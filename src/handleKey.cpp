#include "handleKey.h"
#include "move.h"
#include "draw.h"
#include <cctype>


void handle(char action, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap) //处理按键
{
    action = tolower(action); //转换大小写
    point position, destination;
    destination = position = aStrongBrave.getPosition();
    if(action == 'a') destination.setX(position.getX() - 1);
    if(action == 'd') destination.setX(position.getX() + 1);
    if(action == 'w') destination.setY(position.getY() - 1);
    if(action == 's') destination.setY(position.getY() + 1);
    if(theBigMap.getPoint(destination) == 0)
    {
        aStrongBrave.setPosition(destination);
        draw(aStrongBrave, usefulTools, theBigMap);
    }
}