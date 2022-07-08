#undef UNICODE
#undef _UNICODE
#include"game.h"

//��ʼ��������
void initmaiLift(struct Lift*lift)
{
	lift->xy[1].x = 355;
	lift->xy[1].y = 490;

	lift->xy[0].x = 355;
	lift->xy[0].y = 500;

	lift->num = 2;//��ʼ������

	lift->postion = freeze;//��ʼ������Ϊ��ֹ
}

//��ʼ��������
void initsubLift(struct Lift*lift)
{
	lift->xy[1].x = 270;
	lift->xy[1].y = 490;

	lift->xy[0].x = 270;
	lift->xy[0].y = 500;

	lift->num = 2;//��ʼ������

	lift->postion = freeze;//��ʼ������Ϊ��ֹ
}

//������
void drawLift(struct Lift* lift)
{
	for (int i = 0; i < 2; i++)
	{
		setlinecolor(BLACK);//���α߿��ߵ���ɫ
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//�ڲ������ɫ
		fillrectangle(lift->xy[i].x, lift->xy[i].y, lift->xy[i].x + 10, lift->xy[i].y + 10);
	}
}

//�ƶ�����
void moveLift(struct Lift* lift)
{
	//���˵�һ��֮�⣬����ÿһ�ڶ���ǰ��һ�ڵ�����
	for (int i = lift->num; i > 0; i--)
	{
		lift->xy[i].x = lift->xy[i - 1].x;
		lift->xy[i].y = lift->xy[i - 1].y;
	}
	//��һ�ڵĴ���
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


//��ʼ������
void initButton(struct Button* button, int x, int y,int na)
{
	button->fdxy.x = x;
	button->fdxy.y = y;
	button->flag = 1;
	button->nature = na;
}

//�������ڲ�����
void drawButton(struct Button* button)
{
	setlinecolor(BLACK);//���α߿��ߵ���ɫ
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillcircle(button->fdxy.x, button->fdxy.y, 5);
}

//���°���
void drawdoButton(struct Button* button)
{
	setlinecolor(BLACK);//���α߿��ߵ���ɫ
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	int pts[] = { button->fdxy.x, button->fdxy.y,  button->fdxy.x + 10, button->fdxy.y,  button->fdxy.x + 5, button->fdxy.y+10 };
	fillpolygon((POINT*)pts, 3);
}

//���ϰ���
void drawupButton(struct Button* button)
{
	setlinecolor(BLACK);//���α߿��ߵ���ɫ
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	int pts[] = { button->fdxy.x, button->fdxy.y,  button->fdxy.x + 10, button->fdxy.y,  button->fdxy.x + 5, button->fdxy.y - 10 };
	fillpolygon((POINT*)pts, 3);
}

//��ȥ����
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

//չʾ��ʾ
void showwords()
{
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(10, 10, "ʹ��˵����");
	outtextxy(10, 30, "1~4��Ӧ¥��1~4�ϼ�");
	outtextxy(10, 50, "5~8��Ӧ¥��2~5�¼�");
	outtextxy(10, 70, "Q~T��Ӧ����1~5����");

	outtextxy(440, 10, "¥�㰴��");
	outtextxy(300, 10, "���ڰ���");
}

//�ո���ͣ
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
		outtextxy(410, 490 - i * 100, grade);


		setlinecolor(BLACK);//���α߿��ߵ���ɫ
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(395, 490 - i * 100, 395 + 10, 490 - i * 100 + 10);
		outtextxy(420, 490 - i * 100, "¥");
	}
}

//��ʾ�����м���
void showbutton(struct Lift* lift)
{
	char grade[100] = "";
	sprintf(grade, "%d", lift->curnum);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(510, 50, "��������");
	outtextxy(610, 50, grade);
	outtextxy(410, 100, "��n����n��������Ҫ��������");
}

//������
void showerror()
{
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(200, 200, "������");
}

void drawifuse(int x)
{
	if(x==1)
		outtextxy(10, 90, "�����ݱ�����");
	else
		outtextxy(10, 90, "������δ����");
}
