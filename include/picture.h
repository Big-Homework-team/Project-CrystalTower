#pragma once 
#include "graphics.h"
#include <string>
using namespace std;

const int blockNumber = 100;

class picture {
    public:
        PIMAGE block[blockNumber], back;
        picture() {}
};
