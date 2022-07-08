#include"game.h"

int main()
{
	struct Lift lift[3];		//�������ݣ�˫����1��2��
	struct Button button[22];	//������ť��1~4Ϊ1~4������ϰ�����5~8Ϊ2~5������°�ť��11~15Ϊ�������ڲ�1~5��İ�ť��16~20Ϊ�������ڲ�1~5��İ�ť��
	int N = 21;		//��ť����
	hwnd = initgraph(650, 550);	//��ʼ������
	setbkcolor(WHITE);			//���ô���Ϊ��ɫ
	int ifuse = 0;				//�����ݿ��أ�1Ϊ���ã�0Ϊ�ر�
	initmaiLift(&lift[1]);
	initsubLift(&lift[2]);
	while (1)
	{
		BeginBatchDraw(); //��������ӡ����ֹ����
		cleardevice();//ˢ��

		//���а�������
		while (_kbhit())//����а�������룬���򲻽���ѭ��
		{
			char userkey = 0;
			userkey = _getch();
			//��ʼ���ϰ���
			if (userkey == '1')
				initButton(&button[1], 440, 495 - 0 * 100, 1);
			else if (userkey == '2')
				initButton(&button[2], 440, 495 - 1 * 100, 1);
			else if (userkey == '3')
				initButton(&button[3], 440, 495 - 2 * 100, 1);
			else if (userkey == '4')
				initButton(&button[4], 440, 495 - 3 * 100, 1);
			//��ʼ���°���
			else if (userkey == '5')
				initButton(&button[5], 440, 495 - 1 * 100, 2);
			else if (userkey == '6')
				initButton(&button[6], 440, 495 - 2 * 100, 2);
			else if (userkey == '7')
				initButton(&button[7], 440, 495 - 3 * 100, 2);
			else if (userkey == '8')
				initButton(&button[8], 440, 495 - 4 * 100, 2);
			//��ʼ���������ڲ�����
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
			//pauseMoment();//��ͣ
		}

		//���а�������
		for (int i = 1; i <= 4; i++)
			if(button[i].flag)
				drawupButton(&button[i]);
		for (int i = 5; i <= 8; i++)
			if (button[i].flag)
				drawdoButton(&button[i]);
		for (int i = 11; i <= 15; i++)
			if (button[i].flag)
				drawButton(&button[i]);

		//���Ƶ���
		drawLift(&lift[1]);
		drawLift(&lift[2]);

		//����¥����Ϣ
		drawfloor();

		//������ʾ��
		showwords();
		drawifuse(ifuse);

		//��ȥ��ť
		for (int i = 1; i <= N; i++)
		{
			eatButton(&button[i], &lift[1]);
			if(ifuse)
				eatButton(&button[i], &lift[2]);
		}


		/***********�������ƶ�ԭ���ں�***************/
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
			int jud = 1;//�жϵ�ǰ�Ƿ�Ϊ��ߣ����������ߣ���ֵ�޸�Ϊ0
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
			int jud = 1;//�жϵ�ǰ�Ƿ�Ϊ��ͣ����������ͣ���ֵ�޸�Ϊ0
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

		/***********�������ƶ�ԭ���ں�***************/
		int judgeup = 0;	//�ж��Ƿ��а������������·�
		int judgedo = 0;	//�ж��Ƿ��а������������Ϸ�
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
				int jud = 1;//�жϵ�ǰ�Ƿ�Ϊ��ߣ����������ߣ���ֵ�޸�Ϊ0
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
				int jud = 1;//�жϵ�ǰ�Ƿ�Ϊ��ͣ����������ͣ���ֵ�޸�Ϊ0
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

		

		//�ƶ�����
		moveLift(&lift[1]);
		if(ifuse)
			moveLift(&lift[2]);

		EndBatchDraw();//��������ӡ
		Sleep(100);
	}







}