#include"game.h"

int main()
{
	//mciSendString(L"open 1.mp3 alias bkmusic", NULL, 0, NULL);//�������ļ�
	//mciSendString(L"play bkmusic repeat", NULL, 0, NULL);     //ѭ����������
	srand((unsigned int)time(NULL));//���������
	struct Snake snake;//������
	struct Food food[10];//����ʳ��
	int N = 4;//�˿���������
	hwnd = initgraph(640, 480);//��ʼ������
	setbkcolor(WHITE);//���ô���Ϊ��ɫ
	//snake.postion=freeze;//����0Ϊ��ֹ��1Ϊ���ϣ�2Ϊ����
	int key = 0;//�������յĵ���ָ��ж��Ƿ������Ϸ

	do
	{
		initSnakeFood(&snake, &food[0]);//��ʼ���ߺ�ʳ��ķ���
		key = 0;
		while (1)
		{
			BeginBatchDraw(); //��������ӡ����ֹ����
			cleardevice();//ˢ��
		//���ó˿�����
			while (_kbhit())//����а�������룬���򲻽���ѭ��
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
				//pauseMoment();//��ͣ
			}

			for(int i=0;i<N;i++)
				if (food[i].flag != 0)
					drawFood(&food[i]);//��ʳ��
			for(int i=0;i<N;i++)
				eatFood(&food[i], &snake);//�Ƿ��ʳ��
			//showGrade(&food);//չʾ����
			showfood(&snake);
			drawSnake(&snake);//����
			drawfloor();//��¥����Ϣ
			EndBatchDraw();//��������ӡ
			//if (snakeDie(&snake))//�ж��Ƿ�����
			//{
			//	break;
			//}
			if (winGame(&snake))//�ж��Ƿ�ʤ��
			{
				break;
			}

			//while (_kbhit())//����а�������룬���򲻽���ѭ��
			//{
			//	pauseMoment();//��ͣ
			//	keyDown(&snake);
			//}



			//�ƶ�ģ��
			if (snake.xy[0].y == 420)	//�������ڵײ�ʱ
			{
				if (snake.postion == down)	//�������ǽ���˿����е��ײ�ʱ�����ˣ�ֹͣ
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
				int jud=1;//�жϵ�ǰ�Ƿ�Ϊ��ߣ����������ߣ���ֵ�޸�Ϊ0
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

			


			moveSnake(&snake);//�ƶ���
			Sleep(100);
		}//notice
		key = MessageBox(hwnd, L"���ȷ�����¿�ʼ", L"��Ϸ����", MB_OKCANCEL);

	} while (key == IDOK);//������ȷ���������¿�ʼ��Ϸ
	closegraph();//�ر�ͼ��ģʽ���ͷ���ͼ��ϵͳ����������ڴ�
	system("pause");
	return 0;
}
