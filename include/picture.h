#pragma once 
#include "graphics.h"
#include <string>
using namespace std;

const int blockNumber = 36;

class picture {
    public:
        PIMAGE block[blockNumber];
        picture() {
            for(int i = 0; i < blockNumber; i++) {
                block[i] = newimage();
            }
            for(int i = 0; i < blockNumber; i++) {
                string name = "";
                name += char(i / 10 + '0');
                name += char(i % 10 + '0');
                string path = "static\\img\\" + name + ".png";
                getimage(block[i], path.c_str());
            }
        }
        ~picture() {
            for(int i = 0; i < blockNumber; i++) {
                delimage(block[i]);
            }
        }
        
        void change(int x, int y, int kind);
};
