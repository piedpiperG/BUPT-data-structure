#include"game.h"

int main()
{
	//mciSendString(L"open 1.mp3 alias bkmusic", NULL, 0, NULL);//打开音乐文件
	//mciSendString(L"play bkmusic repeat", NULL, 0, NULL);     //循环播放音乐
	srand((unsigned int)time(NULL));//随机数种子
	struct Snake snake;//创建蛇
	struct Food food[10];//创建食物
	int N = 4;//乘客最多的数量
	hwnd = initgraph(640, 480);//初始化窗口
	setbkcolor(WHITE);//设置窗口为白色
	//snake.postion=freeze;//大方向，0为静止，1为向上，2为向下
	int key = 0;//接收最终的弹窗指令，判断是否继续游戏

	do
	{
		initSnakeFood(&snake, &food[0]);//初始化蛇和食物的分数
		key = 0;
		while (1)
		{
			BeginBatchDraw(); //缓冲区打印，防止闪屏
			cleardevice();//刷新
		//放置乘客区域
			while (_kbhit())//如果有按键则进入，否则不进入循环
			{
				char userkey = 0;
				userkey = _getch();
				switch (userkey)
				{
				case '1':
					if (food[0].flag == 0)
						initFood(&food[0], &snake, 390, 410 - 0 * 100);
					else if (food[1].flag == 0)
						initFood(&food[1], &snake, 390, 410 - 0 * 100);
					else if (food[2].flag == 0)
						initFood(&food[2], &snake, 390, 410 - 0 * 100);
					else if (food[3].flag == 0)
						initFood(&food[3], &snake, 390, 410 - 0 * 100);
					break;
				case '2':
					if (food[0].flag == 0)
						initFood(&food[0], &snake, 390, 410 - 1 * 100);
					else if (food[1].flag == 0)
						initFood(&food[1], &snake, 390, 410 - 1 * 100);
					else if (food[2].flag == 0)
						initFood(&food[2], &snake, 390, 410 - 1 * 100);
					else if (food[3].flag == 0)
						initFood(&food[3], &snake, 390, 410 - 1 * 100);
					break;
				case '3':
					if (food[0].flag == 0)
						initFood(&food[0], &snake, 390, 410 - 2 * 100);
					else if (food[1].flag == 0)
						initFood(&food[1], &snake, 390, 410 - 2 * 100);
					else if (food[2].flag == 0)
						initFood(&food[2], &snake, 390, 410 - 2 * 100);
					else if (food[3].flag == 0)
						initFood(&food[3], &snake, 390, 410 - 2 * 100);
					break;
				case '4':
					if (food[0].flag == 0)
						initFood(&food[0], &snake, 390, 410 - 3 * 100);
					else if (food[1].flag == 0)
						initFood(&food[1], &snake, 390, 410 - 3 * 100);
					else if (food[2].flag == 0)
						initFood(&food[2], &snake, 390, 410 - 3 * 100);
					else if (food[3].flag == 0)
						initFood(&food[3], &snake, 390, 410 - 3 * 100);
					break;
					/*case up:
						if (snake->postion != down)
							snake->postion = up;
						break;*/
				}
				//pauseMoment();//暂停
			}

			for(int i=0;i<N;i++)
				if (food[i].flag != 0)
					drawFood(&food[i]);//画食物
			for(int i=0;i<N;i++)
				eatFood(&food[i], &snake);//是否吃食物
			//showGrade(&food);//展示分数
			showfood(&snake);
			drawSnake(&snake);//画蛇
			drawfloor();//画楼层信息
			EndBatchDraw();//缓冲区打印
			//if (snakeDie(&snake))//判断是否死亡
			//{
			//	break;
			//}
			if (winGame(&snake))//判断是否胜利
			{
				break;
			}

			//while (_kbhit())//如果有按键则进入，否则不进入循环
			//{
			//	pauseMoment();//暂停
			//	keyDown(&snake);
			//}



			//移动模块
			if (snake.xy[0].y == 420)	//当电梯在底层时
			{
				if (snake.postion == down)	//当电梯是接完乘客下行到底层时，放人，停止
				{
					snake.postion = freeze;
					snake.curnum = 0;
					//snake.num = 0;
				}
				else if (snake.postion == freeze)
				{
					
					for (int i = 0; i < N; i++)
					{
						if (food[i].fdxy.y <snake.xy[0].y&&food[i].flag)
						{
							snake.postion = up;
							showerror();
						}
					}
				}
			}

			else if (snake.postion == up)
			{
				int maxheight=-1;
				int jud=1;//判断当前是否为最高，如果不是最高，则值修改为0
				for (int i = 0; i < N; i++)
				{
					if (food[i].fdxy.y-1 < snake.xy[0].y&&food[i].flag)
						jud=0;
				}
				if (jud)
				{
					snake.postion = down;
				}
			}

			


			moveSnake(&snake);//移动蛇
			Sleep(100);
		}//notice
		key = MessageBox(hwnd, L"点击确定重新开始", L"游戏结束", MB_OKCANCEL);

	} while (key == IDOK);//如果点击确定，则重新开始游戏
	closegraph();//关闭图形模式，释放由图形系统分配的所有内存
	system("pause");
	return 0;
}
