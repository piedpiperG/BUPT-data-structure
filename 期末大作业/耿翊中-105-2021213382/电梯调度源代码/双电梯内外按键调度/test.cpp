#include"game.h"

int main()
{
	struct Lift lift[3];		//创建电梯（双电梯1，2）
	struct Button button[22];	//创建按钮（1~4为1~4层的向上按键，5~8为2~5层的向下按钮，11~15为主电梯内部1~5层的按钮，16~20为副电梯内部1~5层的按钮）
	int N = 21;		//按钮个数
	hwnd = initgraph(650, 550);	//初始化窗口
	setbkcolor(WHITE);			//设置窗口为白色
	int ifuse = 0;				//副电梯开关，1为启用，0为关闭
	initmaiLift(&lift[1]);
	initsubLift(&lift[2]);
	while (1)
	{
		BeginBatchDraw(); //缓冲区打印，防止闪屏
		cleardevice();//刷新

		//进行按键处理
		while (_kbhit())//如果有按键则进入，否则不进入循环
		{
			char userkey = 0;
			userkey = _getch();
			//初始化上按键
			if (userkey == '1')
				initButton(&button[1], 440, 495 - 0 * 100, 1);
			else if (userkey == '2')
				initButton(&button[2], 440, 495 - 1 * 100, 1);
			else if (userkey == '3')
				initButton(&button[3], 440, 495 - 2 * 100, 1);
			else if (userkey == '4')
				initButton(&button[4], 440, 495 - 3 * 100, 1);
			//初始化下按键
			else if (userkey == '5')
				initButton(&button[5], 440, 495 - 1 * 100, 2);
			else if (userkey == '6')
				initButton(&button[6], 440, 495 - 2 * 100, 2);
			else if (userkey == '7')
				initButton(&button[7], 440, 495 - 3 * 100, 2);
			else if (userkey == '8')
				initButton(&button[8], 440, 495 - 4 * 100, 2);
			//初始化主电梯内部按键
			else if (userkey == 'q')
				initButton(&button[11], 315, 495 - 0 * 100, 3);
			else if (userkey == 'w')
				initButton(&button[12], 315, 495 - 1 * 100, 3);
			else if (userkey == 'e')
				initButton(&button[13], 315, 495 - 2 * 100, 3);
			else if (userkey == 'r')
				initButton(&button[14], 315, 495 - 3 * 100, 3);
			else if (userkey == 't')
				initButton(&button[15], 315, 495 - 4 * 100, 3);

			else if (userkey == 'p')
			{
				if (ifuse == 1)
					ifuse = 0;
				else
					ifuse = 1;
			}
			//pauseMoment();//暂停
		}

		//进行按键绘制
		for (int i = 1; i <= 4; i++)
			if(button[i].flag)
				drawupButton(&button[i]);
		for (int i = 5; i <= 8; i++)
			if (button[i].flag)
				drawdoButton(&button[i]);
		for (int i = 11; i <= 15; i++)
			if (button[i].flag)
				drawButton(&button[i]);

		//绘制电梯
		drawLift(&lift[1]);
		drawLift(&lift[2]);

		//绘制楼层信息
		drawfloor();

		//绘制提示语
		showwords();
		drawifuse(ifuse);

		//消去按钮
		for (int i = 1; i <= N; i++)
		{
			eatButton(&button[i], &lift[1]);
			if(ifuse)
				eatButton(&button[i], &lift[2]);
		}


		/***********主电梯移动原理内核***************/
		if (lift[1].postion == freeze)
		{
			for (int i = 1; i <= N; i++)
			{
				if (button[i].flag == 1)
				{
					//showerror();
					if (button[i].fdxy.y < lift[1].xy[0].y)
						lift[1].postion = up;
					else
						lift[1].postion = down;
				}
			}
		}

		else if (lift[1].postion == up)
		{
			int maxheight = -1;
			int jud = 1;//判断当前是否为最高，如果不是最高，则值修改为0
			for (int i = 1; i <= N; i++)
			{
				if (button[i].fdxy.y - 2 < lift[1].xy[0].y&&button[i].flag)
					jud = 0;
			}
			if (jud)
			{
				lift[1].postion = freeze;
			}
		}

		else if (lift[1].postion == down)
		{
			int maxheight = -1;
			int jud = 1;//判断当前是否为最低，如果不是最低，则值修改为0
			for (int i = 1; i <= N; i++)
			{
				if (button[i].fdxy.y + 2 > lift[1].xy[0].y&&button[i].flag)
					jud = 0;
			}
			if (jud)
			{
				lift[1].postion = freeze;
			}
		}


		/******************************/

		/***********副电梯移动原理内核***************/
		int judgeup = 0;	//判断是否有按键在主电梯下方
		int judgedo = 0;	//判断是否有按键在主电梯上方
		for (int i = 1; i <= N; i++)
			if (button[i].flag&&button[i].fdxy.y < lift[1].xy[0].y)
				judgeup = 1;
			else if (button[i].flag&&button[i].fdxy.y > lift[1].xy[0].y)
				judgedo = 1;
		if ((lift[1].postion == up && judgedo == 1)
			|| (lift[1].postion == down && judgeup == 1))
		{
			if (lift[2].postion == freeze)
			{
				for (int i = 1; i <= N; i++)
				{
					if (button[i].flag == 1)
					{
						//showerror();
						if (button[i].fdxy.y < lift[2].xy[0].y)
							lift[2].postion = up;
						else
							lift[2].postion = down;
					}
				}
			}
		}

			if (lift[2].postion == up)
			{
				int maxheight = -1;
				int jud = 1;//判断当前是否为最高，如果不是最高，则值修改为0
				for (int i = 1; i <= N; i++)
				{
					if (button[i].fdxy.y - 2 < lift[2].xy[0].y&&button[i].flag)
						jud = 0;
				}
				if (jud)
				{
					lift[2].postion = freeze;
				}
			}

			else if (lift[2].postion == down)
			{
				int maxheight = -1;
				int jud = 1;//判断当前是否为最低，如果不是最低，则值修改为0
				for (int i = 1; i <= N; i++)
				{
					if (button[i].fdxy.y + 2 > lift[2].xy[0].y&&button[i].flag)
						jud = 0;
				}
				if (jud)
				{
					lift[2].postion = freeze;
				}
			}

		
		/******************************/

		

		//移动电梯
		moveLift(&lift[1]);
		if(ifuse)
			moveLift(&lift[2]);

		EndBatchDraw();//缓冲区打印
		Sleep(100);
	}







}