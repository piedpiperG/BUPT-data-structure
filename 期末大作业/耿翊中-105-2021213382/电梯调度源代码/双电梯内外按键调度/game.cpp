#undef UNICODE
#undef _UNICODE
#include"game.h"

//初始化主电梯
void initmaiLift(struct Lift*lift)
{
	lift->xy[1].x = 355;
	lift->xy[1].y = 490;

	lift->xy[0].x = 355;
	lift->xy[0].y = 500;

	lift->num = 2;//开始有三节

	lift->postion = freeze;//初始化方向为静止
}

//初始化副电梯
void initsubLift(struct Lift*lift)
{
	lift->xy[1].x = 270;
	lift->xy[1].y = 490;

	lift->xy[0].x = 270;
	lift->xy[0].y = 500;

	lift->num = 2;//开始有三节

	lift->postion = freeze;//初始化方向为静止
}

//画电梯
void drawLift(struct Lift* lift)
{
	for (int i = 0; i < 2; i++)
	{
		setlinecolor(BLACK);//矩形边框线的颜色
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//内部填充颜色
		fillrectangle(lift->xy[i].x, lift->xy[i].y, lift->xy[i].x + 10, lift->xy[i].y + 10);
	}
}

//移动电梯
void moveLift(struct Lift* lift)
{
	//除了第一节之外，后面每一节都是前面一节的坐标
	for (int i = lift->num; i > 0; i--)
	{
		lift->xy[i].x = lift->xy[i - 1].x;
		lift->xy[i].y = lift->xy[i - 1].y;
	}
	//第一节的处理
	switch (lift->postion)
	{
	case down:
		lift->xy[0].y += 10;
		break;
	case up:
		lift->xy[0].y -= 10;
	case freeze:
		break;
	default:
		break;
	}
}


//初始化按键
void initButton(struct Button* button, int x, int y,int na)
{
	button->fdxy.x = x;
	button->fdxy.y = y;
	button->flag = 1;
	button->nature = na;
}

//画电梯内部按键
void drawButton(struct Button* button)
{
	setlinecolor(BLACK);//矩形边框线的颜色
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillcircle(button->fdxy.x, button->fdxy.y, 5);
}

//画下按键
void drawdoButton(struct Button* button)
{
	setlinecolor(BLACK);//矩形边框线的颜色
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	int pts[] = { button->fdxy.x, button->fdxy.y,  button->fdxy.x + 10, button->fdxy.y,  button->fdxy.x + 5, button->fdxy.y+10 };
	fillpolygon((POINT*)pts, 3);
}

//画上按键
void drawupButton(struct Button* button)
{
	setlinecolor(BLACK);//矩形边框线的颜色
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	int pts[] = { button->fdxy.x, button->fdxy.y,  button->fdxy.x + 10, button->fdxy.y,  button->fdxy.x + 5, button->fdxy.y - 10 };
	fillpolygon((POINT*)pts, 3);
}

//消去按键
void eatButton(struct Button* button, struct Lift* lift)
{
	if ((lift->xy[0].y+5 == button->fdxy.y|| lift->xy[0].y - 5 == button->fdxy.y) &&
											( (lift->postion==down&&button->nature==2)
												|| (lift->postion == up && button->nature == 1)
													||	button->nature==3	)	)
	{
		button->flag = 0;
	}
}

//展示提示
void showwords()
{
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(10, 10, "使用说明：");
	outtextxy(10, 30, "1~4对应楼层1~4上键");
	outtextxy(10, 50, "5~8对应楼层2~5下键");
	outtextxy(10, 70, "Q~T对应电梯1~5按键");

	outtextxy(440, 10, "楼层按键");
	outtextxy(300, 10, "梯内按键");
}

//空格暂停
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
		outtextxy(410, 490 - i * 100, grade);


		setlinecolor(BLACK);//矩形边框线的颜色
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(395, 490 - i * 100, 395 + 10, 490 - i * 100 + 10);
		outtextxy(420, 490 - i * 100, "楼");
	}
}

//显示电梯有几人
void showbutton(struct Lift* lift)
{
	char grade[100] = "";
	sprintf(grade, "%d", lift->curnum);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(510, 50, "梯中人数");
	outtextxy(610, 50, grade);
	outtextxy(410, 100, "按n代表n层有人需要乘坐电梯");
}

//纠错函数
void showerror()
{
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(200, 200, "我来啦");
}

void drawifuse(int x)
{
	if(x==1)
		outtextxy(10, 90, "副电梯被启用");
	else
		outtextxy(10, 90, "副电梯未启用");
}
