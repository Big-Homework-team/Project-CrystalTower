#include "theBrave.h"

const int initialHealthPoint = 60;
const int initialDefence = 10;
const int initialAttack = 10;
const int initialX = 6;
const int initialY = 12;
const int initialFloor = 0;
const int initialTimes = 1;
const int initialFace = 0;

theBrave::theBrave()
{
    healthPoint = initialHealthPoint;
    defence = initialDefence;
    attack = initialAttack;
    times = initialTimes;
    face = initialFace;

    position.setFloor(initialFloor);
    position.setX(initialX);
    position.setY(initialY);

    isTakeBossEvent = 0;
}