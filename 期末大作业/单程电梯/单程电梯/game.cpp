#undef UNICODE
#undef _UNICODE
#include"game.h"


void initSnakeFood(struct Snake* snake, struct Food* food)
{
	//把前三节的属性写出来，初始化数据
	/*snake->xy[2].x = 300;
	snake->xy[2].y = 400;*/

	snake->xy[1].x = 300;
	snake->xy[1].y = 410;

	snake->xy[0].x = 300;
	snake->xy[0].y = 420;

	snake->num = 2;//开始有三节

	snake->postion = freeze;//初始化方向为右

	food->eatgrade = 0;

}

void drawSnake(struct Snake* snake)
{
	for (int i = 0; i < 2; i++)
	{
		setlinecolor(BLACK);//矩形边框线的颜色
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//内部填充颜色
		fillrectangle(snake->xy[i].x, snake->xy[i].y, snake->xy[i].x + 10, snake->xy[i].y + 10);
	}
}

void moveSnake(struct Snake* snake)
{
	//除了第一节之外，后面每一节都是前面一节的坐标
	for (int i = snake->num; i > 0; i--)
	{
		snake->xy[i].x = snake->xy[i - 1].x;
		snake->xy[i].y = snake->xy[i - 1].y;
	}
	//第一节的处理
	switch (snake->postion)
	{
	case right:
		snake->xy[0].x += 10;
		break;
	case left:
		snake->xy[0].x -= 10;
		break;
	case down:
		snake->xy[0].y += 10;
		break;
	case up:
		snake->xy[0].y -= 10;
	case freeze:
		break;
	default:
		break;
	}
}

void keyDown(struct Snake* snake)
{
	char userkey = 0;
	userkey = _getch();
	switch (userkey)
	{
	case right:
		if (snake->postion != left)
			snake->postion = right;
		break;
	case left:
		if (snake->postion != right)
			snake->postion = left;
		break;
	case down:
		if (snake->postion != up)
			snake->postion = down;
		break;
	case up:
		if (snake->postion != down)
			snake->postion = up;
		break;
	}
}

void initFood(struct Food* food, struct Snake* snake, int x, int y)
{
	food->fdxy.x = x;
	food->fdxy.y = y;
	food->flag = 1;

	//如果食物出现在蛇身上，重新产生坐标
	/*for (int i = 0; i > snake->num; i++)
	{
		if (food->fdxy.x == snake->xy[i].x && food->fdxy.y == snake->xy[i].y)
		{
			food->fdxy.x = rand() % 64 * 10;
			food->fdxy.y = rand() % 48 * 10;
		}
	}*/

}

void drawFood(struct Food* food)
{
	setlinecolor(BLACK);//矩形边框线的颜色
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food->fdxy.x, food->fdxy.y, food->fdxy.x + 10, food->fdxy.y + 10);
}

void eatFood(struct Food* food, struct Snake* snake)
{
	//蛇边长
	//食物重新生成
	//outtextxy(200, 200, "来啦");
	//分数增加
	if (snake->xy[0].y == food->fdxy.y&&snake->postion==down)
	{
		//outtextxy(200, 200, "又来啦");
		snake->num++;
		snake->curnum++;
		food->eatgrade += 10;
		food->flag = 0;
	}
}

//蛇死亡，游戏结束
int snakeDie(struct Snake* snake)
{
	if (snake->xy[0].x > 640 || snake->xy[0].x < 0 || snake->xy[0].y>480 || snake->xy[0].y < 0 || (snake->xy[0].x + 10) > 640 || (snake->xy[0].x + 10) < 0 || (snake->xy[0].y + 10) > 480 || (snake->xy[0].y + 10) < 0)
	{
		outtextxy(200, 200, "撞墙");
		//MessageBox(hwnd, "游戏结束，点击确定重新开始", "撞墙", MB_OKCANCEL);
		return 1;//返回1，游戏结束
	}
	for (int i = 1; i < snake->num; i++)
	{
		if (snake->xy[0].x == snake->xy[i].x && snake->xy[0].y == snake->xy[i].y)
		{
			outtextxy(200, 200, "自杀");
			//MessageBox(hwnd, "游戏结束，点击确定重新开始", "自杀", MB_OKCANCEL);
			return 1;
		}
	}
	return 0;
}
int winGame(struct Snake* snake)
{
	if (snake->num == length)
	{
		outtextxy(200, 200, "胜利，恭喜通关");
		//MessageBox(hwnd, "游戏结束，点击确定重新开始", "恭喜通关", MB_OKCANCEL);
		return 1;//返回1，游戏结束
	}
	else
	{
		return 0;
	}
}
void showGrade(struct Food* food)
{
	char grade[100] = "";
	sprintf(grade, "%d", food->eatgrade);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(560, 20, "分数");
	outtextxy(610, 20, grade);
}

void pauseMoment()
{
	if (_getch() == 32)
	{
		while (_getch() != 32);
	}
}

//绘制楼层
void drawfloor()
{

	for (int i = 0; i < 5; i++)
	{
		char grade[100] = "";
		sprintf(grade, "%d", i + 1);
		setbkmode(TRANSPARENT);
		settextcolor(LIGHTBLUE);
		outtextxy(355, 410 - i * 100, grade);


		setlinecolor(BLACK);//矩形边框线的颜色
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(340, 410 - i * 100, 340 + 10, 410 - i * 100 + 10);
		outtextxy(365, 410 - i * 100, "楼");
	}
}


//显示电梯有几人
void showfood(struct Snake* snake)
{
	char grade[100] = "";
	sprintf(grade, "%d", snake->curnum);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(510, 50, "梯中人数");
	outtextxy(610, 50, grade);
	outtextxy(410, 100, "按n代表n层有人需要乘坐电梯");
}


void showerror()
{
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(200, 200, "我来啦");
}