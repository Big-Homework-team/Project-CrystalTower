#include <graphics.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

struct Circle{
	int x, y, r;
};

int main () {

	const int R = 255, G = 255, B = 255;
	// 背景色
	////////////////////////////// 最小半径？这注释是啥？
	const int radius = 50;
	// 最大半径
	const int WW = 800, WH = 600, times = 3000;
	// 窗口宽度，窗口高度，圈数
	// 在这个程序里，窗口的大小决定了生成图片的大小
	std::vector <Circle> CircleList;
	int count = 0;
	// 圆圈计数器

	srand (time (nullptr));
	initgraph (WW, WH);

	do {
		int x = rand () % WW;
		int y = rand () % WH;
		int r = rand () % radius;
		// 取模 防止圆 get 不到 pixel，限定园大小为 50 px
		for (auto a : CircleList) {
			int l = sqrt (pow (abs (x - a.x), 2) +
			              pow (abs (y - a.y), 2)
						 ) - a.r;
			// 当前坐标点下的最大半径
			// 需遍历每一个圆（照理这里应该有优化，但是我没有做，导致到了后面速度就非常慢了
			r = r > l ? l : r;
			// 选择半径较小的那一个
			if (r <= 0) break;
			// 如果不合法跳过这次循环(外面 while 的那个)
			// 也就是圆要是出现在了别的圆里就跳过这个数据
		}

		// circle (x, y, r);
		// 手动选择实心还是空心
		fillellipse (x, y, r, r);
		// 画出图形
		CircleList.push_back ({x,y,r});
		count += 1;
		// 计数值加一

	} while (count <= times);

	closegraph ();

	return 0;
}