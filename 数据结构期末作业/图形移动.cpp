#include<stdio.h>
#include<easyx.h>
//#include<graphics.h>//包含图像库头文件,仅仅适用于C++
int main()
{
	//创建一个窗口，initgraph();
	initgraph(650, 650, EW_SHOWCONSOLE);
	int x = 100;
	int y = 100;
	while (true)
	{
		FlushBatchDraw();
		cleardevice();//清除上一次绘画的图形防止发生重叠
		solidcircle(x, y, 10);//无边框填充画圆
		setfillcolor(YELLOW);
		EndBatchDraw();
		if (GetAsyncKeyState(VK_UP))
		{
			y -= 1;
			printf("向上运动");
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			y += 1;
			printf("向下运动");
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 1;
			printf("向左运动");
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 1;
			printf("向右运动");
		}
	}
	getchar();
	//关闭窗口，closegraph();
	closegraph();
	return 0;
}

