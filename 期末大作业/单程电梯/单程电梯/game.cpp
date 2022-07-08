#undef UNICODE
#undef _UNICODE
#include"game.h"


void initSnakeFood(struct Snake* snake, struct Food* food)
{
	//��ǰ���ڵ�����д��������ʼ������
	/*snake->xy[2].x = 300;
	snake->xy[2].y = 400;*/

	snake->xy[1].x = 300;
	snake->xy[1].y = 410;

	snake->xy[0].x = 300;
	snake->xy[0].y = 420;

	snake->num = 2;//��ʼ������

	snake->postion = freeze;//��ʼ������Ϊ��

	food->eatgrade = 0;

}

void drawSnake(struct Snake* snake)
{
	for (int i = 0; i < 2; i++)
	{
		setlinecolor(BLACK);//���α߿��ߵ���ɫ
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//�ڲ������ɫ
		fillrectangle(snake->xy[i].x, snake->xy[i].y, snake->xy[i].x + 10, snake->xy[i].y + 10);
	}
}

void moveSnake(struct Snake* snake)
{
	//���˵�һ��֮�⣬����ÿһ�ڶ���ǰ��һ�ڵ�����
	for (int i = snake->num; i > 0; i--)
	{
		snake->xy[i].x = snake->xy[i - 1].x;
		snake->xy[i].y = snake->xy[i - 1].y;
	}
	//��һ�ڵĴ���
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

	//���ʳ������������ϣ����²�������
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
	setlinecolor(BLACK);//���α߿��ߵ���ɫ
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food->fdxy.x, food->fdxy.y, food->fdxy.x + 10, food->fdxy.y + 10);
}

void eatFood(struct Food* food, struct Snake* snake)
{
	//�߱߳�
	//ʳ����������
	//outtextxy(200, 200, "����");
	//��������
	if (snake->xy[0].y == food->fdxy.y&&snake->postion==down)
	{
		//outtextxy(200, 200, "������");
		snake->num++;
		snake->curnum++;
		food->eatgrade += 10;
		food->flag = 0;
	}
}

//����������Ϸ����
int snakeDie(struct Snake* snake)
{
	if (snake->xy[0].x > 640 || snake->xy[0].x < 0 || snake->xy[0].y>480 || snake->xy[0].y < 0 || (snake->xy[0].x + 10) > 640 || (snake->xy[0].x + 10) < 0 || (snake->xy[0].y + 10) > 480 || (snake->xy[0].y + 10) < 0)
	{
		outtextxy(200, 200, "ײǽ");
		//MessageBox(hwnd, "��Ϸ���������ȷ�����¿�ʼ", "ײǽ", MB_OKCANCEL);
		return 1;//����1����Ϸ����
	}
	for (int i = 1; i < snake->num; i++)
	{
		if (snake->xy[0].x == snake->xy[i].x && snake->xy[0].y == snake->xy[i].y)
		{
			outtextxy(200, 200, "��ɱ");
			//MessageBox(hwnd, "��Ϸ���������ȷ�����¿�ʼ", "��ɱ", MB_OKCANCEL);
			return 1;
		}
	}
	return 0;
}
int winGame(struct Snake* snake)
{
	if (snake->num == length)
	{
		outtextxy(200, 200, "ʤ������ϲͨ��");
		//MessageBox(hwnd, "��Ϸ���������ȷ�����¿�ʼ", "��ϲͨ��", MB_OKCANCEL);
		return 1;//����1����Ϸ����
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
	outtextxy(560, 20, "����");
	outtextxy(610, 20, grade);
}

void pauseMoment()
{
	if (_getch() == 32)
	{
		while (_getch() != 32);
	}
}

//����¥��
void drawfloor()
{

	for (int i = 0; i < 5; i++)
	{
		char grade[100] = "";
		sprintf(grade, "%d", i + 1);
		setbkmode(TRANSPARENT);
		settextcolor(LIGHTBLUE);
		outtextxy(355, 410 - i * 100, grade);


		setlinecolor(BLACK);//���α߿��ߵ���ɫ
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(340, 410 - i * 100, 340 + 10, 410 - i * 100 + 10);
		outtextxy(365, 410 - i * 100, "¥");
	}
}


//��ʾ�����м���
void showfood(struct Snake* snake)
{
	char grade[100] = "";
	sprintf(grade, "%d", snake->curnum);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(510, 50, "��������");
	outtextxy(610, 50, grade);
	outtextxy(410, 100, "��n����n��������Ҫ��������");
}


void showerror()
{
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(200, 200, "������");
}