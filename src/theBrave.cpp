#include "theBrave.h"

const int initialHealthPoint = 1000;
const int initialDefence = 10;
const int initialAttack = 10;
const int initialX = 1;
const int initialY = 6;
const int initialFloor = 1;

theBrave::theBrave()
{
    healthPoint = initialHealthPoint;
    defence = initialDefence;
    attack = initialAttack;
    x = initialX;
    y = initialY;
    floor = initialFloor;
}