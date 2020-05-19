#include "handleKey.h"
#include "move.h"
#include <cctype>


#include <iostream>
using namespace std;
//上两行仅用于测试

void handle(char action) //处理按键
{
    cout << action << endl;
    if(action == 27) //ESC 的键码是 27.
	{
		return ; //结束游戏.
	}
    action = tolower(action); //转换大小写
    if(action == 'a' || action == 'd' || action == 's' || action == 'w')
        move(action);
}