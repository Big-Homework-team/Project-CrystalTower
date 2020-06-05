#include <graphics.h>
#include "runGame.h"
#include "draw.h" //绘制地图与角色数据
#include "handleKey.h" //处理键盘事件
#include "monster.h"
#include "menu.h"
#include "file.h"
#include "event.h"
#include "cast.h"

void runGame::initialize(picture &pic)
{
	initgraph(736, 416, 0); // 初始化窗口
    setbkcolor(BLACK); //窗口底色
    setcaption("Crystal_Tower"); // 窗口标题
	for(int i = 0; i < blockNumber; i++) {
        pic.block[i] = newimage();
    }
    for(int i = 0; i < blockNumber; i++) {
        string name = "";
        name += char(i / 10 + '0');
        name += char(i % 10 + '0');
        string path = "static\\img\\" + name + ".png";
        getimage(pic.block[i], path.c_str());
    }
	createMenu();
}



void runGame::run()
{
	MUSIC music1, music2;
	music1.OpenFile("static\\music\\what for.mp3");
	music1.Play(0);//播放BGM
	music2.OpenFile("static\\music\\祖堅正慶 - 影をもたらす者 ～ハーデス前哨戦～.mp3");

	theBrave initaStrongBrave;
	tools initusefulTools;
	map inittheBigMap;
	monster bigMonster[100];
	//设置怪物属性
    bigMonster[51].setHealthPoint(20);
    bigMonster[51].setAttack(20);
    bigMonster[51].setDefence(1);
    bigMonster[51].setMoney(6);
    bigMonster[51].setName("绿史莱姆");

    bigMonster[52].setHealthPoint(10);
    bigMonster[52].setAttack(15);
    bigMonster[52].setDefence(11);
    bigMonster[52].setMoney(2);
    bigMonster[52].setName("黑史莱姆");

    bigMonster[53].setHealthPoint(80);
    bigMonster[53].setAttack(35);
    bigMonster[53].setDefence(5);
    bigMonster[53].setMoney(4);
    bigMonster[53].setName("小蝙蝠");

    bigMonster[54].setHealthPoint(100);
    bigMonster[54].setAttack(30);
    bigMonster[54].setDefence(22);
    bigMonster[54].setMoney(7);
    bigMonster[54].setName("大蝙蝠");

    bigMonster[55].setHealthPoint(30);
    bigMonster[55].setAttack(30);
    bigMonster[55].setDefence(21);
    bigMonster[55].setMoney(7);
    bigMonster[55].setName("石头人");

    bigMonster[56].setHealthPoint(100);
    bigMonster[56].setAttack(40);
    bigMonster[56].setDefence(3);
    bigMonster[56].setMoney(5);
    bigMonster[56].setName("骷髅人");

	bigMonster[82].setHealthPoint(2333);
    bigMonster[82].setAttack(250);
    bigMonster[82].setDefence(150);
    bigMonster[82].setMoney(0);
    bigMonster[82].setName("哈迪斯");
	picture pic;
    initialize(pic); //图形界面初始化
	int choice = 0;
	for(;is_run(); delay_fps(60)) {
		if(music2.GetPlayStatus() != MUSIC_MODE_STOP) music2.Stop();
		if(music1.GetPlayStatus() == MUSIC_MODE_STOP) music1.Play(0);
		createMenu();
		createChoice(choice);
		char menuAction = '.';
		//if(kbhit()) 
		menuAction = getch();
		if(menuAction == 'w' || menuAction == 38) choice = (choice - 1 + menuLength) % menuLength;
		if(menuAction == 's' || menuAction == 40) choice = (choice + 1 + menuLength) % menuLength;
		if(menuAction == 32) { // 空格
			if(choice == 0) { //游戏
				theBrave aStrongBrave;
				tools usefulTools;
				map theBigMap;
				setBackground(pic);
				draw(aStrongBrave, usefulTools, theBigMap, pic); //绘制图形界面
				for(;is_run(); delay_fps(60))
				{
					if(aStrongBrave.getPosition().getFloor() == 5)
					{
						if(music1.GetPlayStatus() != MUSIC_MODE_STOP) music1.Stop();
						if(music2.GetPlayStatus() == MUSIC_MODE_STOP) music2.Play(0);
					}
					else
					{
						if(music2.GetPlayStatus() != MUSIC_MODE_STOP) music2.Stop();
						if(music1.GetPlayStatus() == MUSIC_MODE_STOP) music1.Play(0);
					}
					if(aStrongBrave.getPosition().getFloor() == 5 && aStrongBrave.getIsTakeBossEvent() == 0) //触发剧情1
					{
						takeBossEvent(aStrongBrave, usefulTools, theBigMap, bigMonster, pic);
						aStrongBrave.setIsTakeBossEvent(1);
					}
					char action = '.';
					//if(kbhit()) 
					action = getch();
   	 				if(action == 27) //ESC 的键码是 27.
					{
						CreateMenu();
						break ; //结束游戏.
					}
        			handle(action, aStrongBrave, usefulTools, theBigMap, bigMonster, pic); //处理按键
    				draw(aStrongBrave, usefulTools, theBigMap, pic);
					if(theBigMap.getPoint(point(5, 6, 6)) == 0)
					{
						//游戏结束
						//播放制作人员名单
						
						music1.Stop();
						music2.Stop();
						music2.OpenFile("static\\music\\上海アリス幻樂団 - Eternal Dream ～ 幽玄の槭樹.mp3");
						music2.Play(0);
						printCast();
						music2.Stop();
						music2.OpenFile("static\\music\\祖堅正慶 - 影をもたらす者 ～ハーデス前哨戦～.mp3");
						CreateMenu();
						break;
					}
				}
				
			}
			if(choice == 1) {
				theBrave aStrongBrave;
				tools usefulTools;
				map theBigMap;
				int result = optionReadFile(aStrongBrave, usefulTools, theBigMap);
				if(result != 0) continue;
				setBackground(pic);
				draw(aStrongBrave, usefulTools, theBigMap, pic); //绘制图形界面
				for(;is_run(); delay_fps(60))
				{
					if(aStrongBrave.getPosition().getFloor() == 5)
					{
						if(music1.GetPlayStatus() != MUSIC_MODE_STOP) music1.Stop();
						if(music2.GetPlayStatus() == MUSIC_MODE_STOP) music2.Play(0);
					}
					else
					{
						if(music2.GetPlayStatus() != MUSIC_MODE_STOP) music2.Stop();
						if(music1.GetPlayStatus() == MUSIC_MODE_STOP) music1.Play(0);
					}
					if(aStrongBrave.getPosition().getFloor() == 5 && aStrongBrave.getIsTakeBossEvent() == 0) //触发剧情1
					{
						takeBossEvent(aStrongBrave, usefulTools, theBigMap, bigMonster, pic);
						aStrongBrave.setIsTakeBossEvent(1);
					}
					char action = '.';
					//if(kbhit()) 
					action = getch();
   	 				if(action == 27) //ESC 的键码是 27.
					{
						CreateMenu();
						break ; //结束游戏.
					}
        			handle(action, aStrongBrave, usefulTools, theBigMap, bigMonster, pic); //处理按键
    				draw(aStrongBrave, usefulTools, theBigMap, pic);
					if(theBigMap.getPoint(point(5, 6, 6)) == 0)
					{
						//游戏结束
						//播放制作人员名单
						music1.Stop();
						music2.Stop();
						music2.OpenFile("static\\music\\上海アリス幻樂団 - Eternal Dream ～ 幽玄の槭樹.mp3");
						music2.Play(0);
						printCast();
						music2.Stop();
						music2.OpenFile("static\\music\\祖堅正慶 - 影をもたらす者 ～ハーデス前哨戦～.mp3");
						CreateMenu();
						break;
					}
				}
			}
			if(choice == 2) {
				
				//播放制作人员名单
				music1.Stop();
				music2.Stop();
				music2.OpenFile("static\\music\\上海アリス幻樂団 - Eternal Dream ～ 幽玄の槭樹.mp3");
				music2.Play(0);
				printCast();
				music2.Stop();
				music2.OpenFile("static\\music\\祖堅正慶 - 影をもたらす者 ～ハーデス前哨戦～.mp3");
				CreateMenu();
			}
			if(choice == 3) {
				return;
			}
		}
	}
}