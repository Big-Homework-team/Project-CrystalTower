#include "handleKey.h"
#include "move.h"
#include <cctype>


void handle(char action, theBrave &aStrongBrave, tools &usefulTools, map &theBigMap) //处理按键
{
    action = tolower(action); //转换大小写
    if(action == 'a' || action == 'd' || action == 's' || action == 'w')
        move(action, aStrongBrave, theBigMap);
}