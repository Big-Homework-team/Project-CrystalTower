#include "file.h"

void writeFile(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, char option)
{
    if(!('1' <= option && option <= '5')) return ;
    FILE *fp;
    string path = "static\\save\\";
    string fileName = "save";
    fileName = fileName + option + ".txt";
    path += fileName;
    fp = fopen(path.c_str(),"w");

    fprintf(fp, "%d %d %d %d\n", aStrongBrave.getHealthPoint(), aStrongBrave.getDefence(), aStrongBrave.getAttack(), aStrongBrave.getTimes());
    fprintf(fp, "%d %d %d\n", aStrongBrave.getPosition().getFloor(), aStrongBrave.getPosition().getX(), aStrongBrave.getPosition().getY());

    fprintf(fp, "%d %d %d %d %d %d\n", usefulTools.getYellowKey(), usefulTools.getBlueKey(), usefulTools.getRedKey(), usefulTools.getMoney(), usefulTools.getWeapon(), usefulTools.getArmor());
    fprintf(fp, "%d %d %d %d %d\n", usefulTools.getDraft(), usefulTools.getTransmitter(), usefulTools.getBoom(), usefulTools.getMonsterManual(), usefulTools.getUsingDraft());
    
    for(int i = 0; i < high; i ++)
    {
        for(int j = 0; j < length; j ++)
        {
            for(int k = 0; k < width; k ++)
            {
                fprintf(fp, "%d ", theBigMap.getPoint(point(i, j, k)));
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n");
    }
	fclose(fp);
}

void readFile(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap, char option)
{
    if(!('1' <= option && option <= '5')) return ;
    FILE *fp;
    string path = "static\\save\\";
    string fileName = "save";
    fileName = fileName + option + ".txt";
    path += fileName;
    fp = fopen(path.c_str(),"r");

    int healthPoint, defence, attack, times;
    int floor, x, y; point position;
    fscanf(fp, "%d%d%d%d", &healthPoint, &defence, &attack, &times);
    fscanf(fp, "%d%d%d", &floor, &x, &y); position = point(floor, x, y);
    aStrongBrave.setHealthPoint(healthPoint);
    aStrongBrave.setDefence(defence);
    aStrongBrave.setAttack(attack);
    aStrongBrave.setTimes(times);
    aStrongBrave.setPosition(position);

    int yellowKey, blueKey, redKey, money, weapon, armor;
    int draft, transmitter, boom, monsterManual, usingDraft;
    fscanf(fp, "%d%d%d%d%d%d", &yellowKey, &blueKey, &redKey, &money, &weapon, &armor);
    fscanf(fp, "%d%d%d%d%d", &draft, &transmitter, &boom, &monsterManual, &usingDraft);
    usefulTools.setYellowKey(yellowKey);
    usefulTools.setBlueKey(blueKey);
    usefulTools.setRedKey(redKey);
    usefulTools.setMoney(money);
    usefulTools.setWeapon(weapon);
    usefulTools.setArmor(armor);
    usefulTools.setDraft(draft);
    usefulTools.setTransmitter(transmitter);
    usefulTools.setBoom(boom);
    usefulTools.setMonsterManual(monsterManual);
    usefulTools.setUsingDraft(usingDraft);

    int theMap[high][length][width];
    for(int i = 0; i < high; i ++)
        for(int j = 0; j < length; j ++)
            for(int k = 0; k < width; k ++)
            {
                fscanf(fp, "%d", &theMap[i][j][k]);
                theBigMap.setPoint(point(i, j, k), theMap[i][j][k]);
            }
	fclose(fp);
}


void optionWriteFile(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    bar(5 * 32, 0 * 32, 18 * 32, 13 * 32); //绘制矩形作为背景
    setcolor(WHITE);                       //字体颜色
    setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT);                //字体背景色块调为透明
    int floor[6], healthPoint[6], attack[6], defence[6];
    for(char c = '1'; c <= '5'; c ++)
    {
        FILE *fp;
        string path = "static\\save\\";
        string fileName = "save";
        fileName = fileName + c + ".txt";
        path += fileName;
        fp = fopen(path.c_str(),"r");

        int times;
        fscanf(fp, "%d%d%d%d", &healthPoint[c - '0'], &defence[c - '0'], &attack[c - '0'], &times);
        fscanf(fp, "%d", &floor[c - '0']);
        fclose(fp);
    }
    int choice = 1, menuLength = 6;
    char action = '.';
    while (action != 32) //实现滑动选择可视化
    {
        bar(5 * 32, 0 * 32, 18 * 32, 13 * 32); //绘制矩形作为背景
        outtextxy(5 * 32 + 4 * 32, 22, "请选择要覆盖的存档");
        outtextxy(5 * 32 + 1 * 32, 2 * 32 + (choice - 1) * 64, ">>>");
        for(char c = '1'; c <= '5'; c ++)
        { 
            string imformation = "";
            imformation += c;
            imformation += ": " + to_string(floor[c - '0']) + " 层，";
            imformation += to_string(healthPoint[c - '0']) + " 生命值，";
            imformation += to_string(attack[c - '0']) + " 攻，";
            imformation += to_string(defence[c - '0']) + " 防";
            outtextxy(6 * 32 + 1 * 32, 2 * 32 + (c - '0' - 1) * 64, imformation.c_str());
        }
        outtextxy(6 * 32 + 1 * 32, 2 * 32 + (6 - 1) * 64, "取消");
        action = getch();
        if (action == 'w' || action == 38)
            choice = (choice - 1 - 1 + menuLength) % menuLength + 1;
        if (action == 's' || action == 40)
            choice = (choice - 1 + 1 + menuLength) % menuLength + 1;
    }
    if(choice != 6)
    {
        writeFile(aStrongBrave, usefulTools, theBigMap, '0' + choice);
        bar(5 * 32, 0 * 32, 18 * 32, 13 * 32); //绘制矩形作为背景
        outtextxy(6 * 32 + 4 * 32 + 16, 22, "存档成功");
        action = getch();
    }
}
int optionReadFile(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    setfillcolor(DARKGRAY);                //设置背景填充色为深灰
    bar(5 * 32, 0 * 32, 18 * 32, 13 * 32); //绘制矩形作为背景
    setcolor(WHITE);                       //字体颜色
    setfont(16, 0, "黑体");                //文字高度16像素，宽度自适应，字体类型
    setbkmode(TRANSPARENT);                //字体背景色块调为透明
    int floor[6], healthPoint[6], attack[6], defence[6];
    for(char c = '1'; c <= '5'; c ++)
    {
        FILE *fp;
        string path = "static\\save\\";
        string fileName = "save";
        fileName = fileName + c + ".txt";
        path += fileName;
        fp = fopen(path.c_str(),"r");

        int times;
        fscanf(fp, "%d%d%d%d", &healthPoint[c - '0'], &defence[c - '0'], &attack[c - '0'], &times);
        fscanf(fp, "%d", &floor[c - '0']);
        fclose(fp);
    }
    int choice = 1, menuLength = 6;
    char action = '.';
    while (action != 32) //实现滑动选择可视化
    {
        bar(5 * 32, 0 * 32, 18 * 32, 13 * 32); //绘制矩形作为背景
        outtextxy(5 * 32 + 4 * 32, 22, "请选择要读取的存档");
        outtextxy(5 * 32 + 1 * 32, 2 * 32 + (choice - 1) * 64, ">>>");
        for(char c = '1'; c <= '5'; c ++)
        { 
            string imformation = "";
            imformation += c;
            imformation += ": " + to_string(floor[c - '0']) + " 层，";
            imformation += to_string(healthPoint[c - '0']) + " 生命值，";
            imformation += to_string(attack[c - '0']) + " 攻，";
            imformation += to_string(defence[c - '0']) + " 防";
            outtextxy(6 * 32 + 1 * 32, 2 * 32 + (c - '0' - 1) * 64, imformation.c_str());
        }
        outtextxy(6 * 32 + 1 * 32, 2 * 32 + (6 - 1) * 64, "取消");
        action = getch();
        if (action == 'w' || action == 38)
            choice = (choice - 1 - 1 + menuLength) % menuLength + 1;
        if (action == 's' || action == 40)
            choice = (choice - 1 + 1 + menuLength) % menuLength + 1;
    }
    if(choice != 6)
    {
        readFile(aStrongBrave, usefulTools, theBigMap, '0' + choice);
        bar(5 * 32, 0 * 32, 18 * 32, 13 * 32); //绘制矩形作为背景
        outtextxy(6 * 32 + 4 * 32 + 16, 22, "读档成功");
        action = getch();
        return 0;
    }
    if(choice == 6) return 1;
}