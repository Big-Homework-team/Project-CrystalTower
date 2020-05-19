#include <graphics.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <image.h>


struct Circle{
	int x, y, r;
};

int main () {
	initgraph(1600, 900, 0); // 0 取消ege开场动画
    setbkcolor(BLACK);
	getchar();
	closegraph ();
	return 0;
}