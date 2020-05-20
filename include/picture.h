#pragma once 
#include "graphics.h"

const int blockNumber = 4;

class picture {
    public:
        PIMAGE block[blockNumber];
        picture() {
            for(int i = 0; i < blockNumber; i++) {
                block[i] = newimage();
            }
            getimage(block[0], "static\\img\\space.png");
            getimage(block[1], "static\\img\\theBrave.png");
            getimage(block[2], "static\\img\\wall.png");
        }

        ~picture() {
            for(int i = 0; i < blockNumber; i++) {
                delimage(block[i]);
            }
        }
        
        void change(int x, int y, int kind);
};
