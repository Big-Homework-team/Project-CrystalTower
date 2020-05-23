#include "file.h"

void writeFile(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
    FILE *fp;
	fp = fopen("save.txt","w");

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

void readFile(theBrave &aStrongBrave, tools &usefulTools, map &theBigMap)
{
	FILE *fp;
	fp = fopen("save.txt","r");

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