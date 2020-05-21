#include "handleKey.h"
#include "move.h"
#include "draw.h"
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
    if(theBigMap.getPoint(destination) == 0)
    {
        aStrongBrave.setPosition(destination);
        draw(aStrongBrave, usefulTools, theBigMap);
    }
}