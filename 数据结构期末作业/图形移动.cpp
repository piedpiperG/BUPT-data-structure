#include<stdio.h>
#include<easyx.h>
//#include<graphics.h>//����ͼ���ͷ�ļ�,����������C++
int main()
{
	//����һ�����ڣ�initgraph();
	initgraph(650, 650, EW_SHOWCONSOLE);
	int x = 100;
	int y = 100;
	while (true)
	{
		FlushBatchDraw();
		cleardevice();//�����һ�λ滭��ͼ�η�ֹ�����ص�
		solidcircle(x, y, 10);//�ޱ߿���仭Բ
		setfillcolor(YELLOW);
		EndBatchDraw();
		if (GetAsyncKeyState(VK_UP))
		{
			y -= 1;
			printf("�����˶�");
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			y += 1;
			printf("�����˶�");
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 1;
			printf("�����˶�");
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 1;
			printf("�����˶�");
		}
	}
	getchar();
	//�رմ��ڣ�closegraph();
	closegraph();
	return 0;
}

