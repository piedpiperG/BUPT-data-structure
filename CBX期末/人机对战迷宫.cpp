//  ���Թ����򣬹���2���Ѷ� 
#include <stdio.h>
#include <stdlib.h>

//��������************************************* 
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<string.h>
using	namespace	std;
#define	inf	0x3f3f3f3f
#define	size	205
int		m, n;//����
char	Map[size][size];//��¼���� 
int		vis[size][size];//��¼�Ƿ��߹� 
int		Mappp[size][size];//�����߳���ʽ 
int		fa, fb;// ������������ 
int		result;//����Ҫ����С���� 
int		aa, ab;// �յ����� 
int 	dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };	//�ƶ�ָʾ���� 
struct pos
{
	int a, b, steps;//�������꣬���� 
	int	Mapp[size][size];//��¼�߳���ʽ 
};//״̬�� 
int	bfs();//�������� 
int	judge(int	a, int	b);//�ж����ڵ��Ƿ���߽磬���緵��0��δ���緵��1 
void	menu2();
//��������************************************* 

//������ͨ������̨�����������������ĺ�������Ҫ��ͨ�����̽��еĲ�������getch()
#include <conio.h>
int s1[10][10]={{1,1,1,1,1,3,1,1,1,1},
                {1,0,0,0,1,0,0,0,0,1},
                {1,0,1,0,0,1,1,1,0,1},
                {1,0,1,0,0,1,0,0,0,1},
                {1,0,0,1,0,0,1,0,1,1},
                {1,1,0,0,1,0,1,0,0,1},
                {1,0,0,1,0,0,0,0,1,1},
                {1,1,0,1,1,1,0,0,1,1},
                {1,0,0,0,1,0,1,0,1,1},
                {1,1,1,2,1,1,1,1,1,1}};                 
    
    
int s2[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		        {3,0,0,0,1,1,0,0,0,1,0,0,1,1,1,0,0,0,1,1},
		        {1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1},
		        {1,1,0,1,0,1,0,1,1,0,1,1,1,1,0,1,0,0,1,1},
		        {1,0,0,0,1,1,0,1,0,0,0,1,0,1,1,0,1,0,0,1},
		        {1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1},
		        {1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1},
		        {1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,1,0,1,1},
		        {1,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,1,0,0,1},
		        {1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,1},
		        {1,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,1,1,1},
		        {1,0,0,0,1,1,0,0,1,0,1,1,0,1,1,0,0,1,0,1},
		        {1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1},
		        {1,0,0,1,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1},
                {1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,1,0,0,1},
		        {1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,1},
	            {1,1,0,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,1},
		        {1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,1},
	            {1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,2},
		        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}; 
//2���Թ���ͼ���� 
void draw1(void);
void draw2(void);
 
//���ƺ���
void control1(void);
void control2(void); 
//�˵�����
void menu(void);
//�ƶ���λ�ý�������
void move(int *i,int *j); 

//������ 
int main()
{
	while(1)
	{
	
		int	Swit;
		printf("~~~~~~~~~~~~~~~~~~~~~~~�˻���ս-�Թ�С��Ϸ~~~~~~~~~~~~~~~~~~~~~~~\n");
		cout<<"��������ѡ���Լ�����Թ����ɵ������𣻻����ǵ�������Թ����Լ����"<<endl;
		cout<<"����������Թ��밴1���Լ����Թ��밴2���˳���Ϸ�밴0"<<endl;
		cin>>Swit;
		if(Swit==2)
		{
	    	menu();   
    		//system("pause");
	    	//return 0;
	    }
    	else	if(Swit==1)
    	{
	    	menu2();
	    	//return	0;
		}
		else	if(Swit==0)
		{
			break;	
		} 
	
	}
} 

//�˵�����
void menu(void)
{
    int x; 
    printf("                      \n��Ϸ˵��\n");
    printf("~~~~~.����Ϸ�����У���ҿ���ͨ�����̷����ʹС���ƶ����߳��Թ���\n");
    printf("~~~~~.����Ϸ�����У���ҿ���ͨ����Esc��������Ϸ�˵���Ҳ���Կ��԰�0ֱ���˳���Ϸ��\n");
    printf("                      1: ��ʼ��Ϸ\n");
    printf("                      0: �˳���Ϸ\n");
    scanf("%d",&x); 
    switch(x)
    {
        case 1: { system("cls");
                  printf("~~~~~1.���Ѷ�\n~~~~~2.�е��Ѷ�\n~~~~~0.�˳���Ϸ\n"); 
                  int y;
                  scanf("%d",&y);
                  switch (y)
                  {
                        case 1:system("cls");
                               draw1();
                               control1();    break;
                        case 2:system("cls");
                               draw2();
                               control2();    break;
                        case 0:return;            
                  } 
                }break;
        case 0:return; 
      } 
} 
//�ƶ���λ�ý�������
void move(int *i,int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
} 

void draw1(void)
{
    int i,j,ch,num=0;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {
            ch=s1[i][j];
            switch (ch)
            {
                case 0:printf(" "); break;
                case 1:printf("#"); break;
                case 2:printf("0"); break;
                case 3:printf(" "); break;
            } 
            num++;
            if(num%10==0)
                printf("\n"); 
        }    
    } 
    
void draw2(void) 
{
    int i,j,ch,num=0;
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
        {
            ch=s2[i][j];
            switch (ch)
            {
                case 0:printf(" "); break;
                case 1:printf("#"); break;
                case 2:printf("0"); break;
                case 3:printf(" "); break;
            } 
            num++;
            if(num%20==0)
                printf("\n"); 
        }    
} 

void control1(void)
{
    int a,b;
    char num;
    do{  //ÿһ���ƶ�ǰ�ҵ�С�˵�λ�� 
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                if(s1[i][j]==2)
                {
                    a=i;
                    b=j;
                    break; 
                }
        //���տ���         
        num=getch();
        switch(num)
        {
            case 72:if(s1[a-1][b]!=1)  //���� 
			        {
				        move(&s1[a][b],&s1[a-1][b]);
				        system("cls");
				        draw1();
				        break;
			        }
			        else continue; 
	        case 80:if(a==9) continue; //���£����С��վ����㴦������ʹ�����¼� 
                    else if(s1[a+1][b]!=1)
			        {
			   	        move(&s1[a][b],&s1[a+1][b]);
				        system("cls");
			            draw1();
			            break;
			        }
			        else continue;

		    case 75:if(s1[a][b-1]!=1) //���� 
			        {   
				        move(&s1[a][b],&s1[a][b-1]);
				        system("cls");
				        draw1();
			            break;
			        }
			        else continue;
			case 77:if(s1[a][b+1]!=1) //���� 
			        {
				        move(&s1[a][b],&s1[a][b+1]);
				        system("cls");
                        draw1();
		                break;
			        } 
			        else continue;
		    case 27:system("cls"); //ESE���ز˵� 
				    menu();    break;
            case 48:exit(0); //�˳���Ϸ 
		    default:continue;  
	    } 
		if(s1[0][5]==2)   //�����յ� 
		{
            printf("\n\t------------------you are winner!--------------------\n\n\n");
            s1[0][5]=3;  //������㼰�յ� 
            s1[9][3]=2; 
		    menu();
	    }
    }while(1);
} 

void control2(void)
{
    int a,b;
    char num;
    do{  //ÿһ���ƶ�ǰ�ҵ�С�˵�λ�� 
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                if(s2[i][j]==2)
                {
                    a=i;
                    b=j;
                    break; 
                }
        //���տ���         
        num=getch();
        switch(num)
        {
            case 72:if(s2[a-1][b]!=1)  //���� 
			        {
				        move(&s2[a][b],&s2[a-1][b]);
				        system("cls");
				        draw2();
				        break;
			        }
			        else continue; 
	        case 80:if(s2[a+1][b]!=1)//���� 
			        {
			   	        move(&s2[a][b],&s2[a+1][b]);
				        system("cls");
			            draw2();
			            break;
			        }
			        else continue;

		    case 75:if(s2[a][b-1]!=1) //���� 
			        {   
				        move(&s2[a][b],&s2[a][b-1]);
				        system("cls");
				        draw2();
			            break;
			        }
			        else continue;
			case 77:if(b==19) continue;//���ң�С�˲����߳���ͼ 
                    else if(s2[a][b+1]!=1) 
			        {
				        move(&s2[a][b],&s2[a][b+1]);
				        system("cls");
                        draw2();
		                break;
			        } 
			        else continue;
		    case 27:system("cls"); //ESE���ز˵� 
				    menu();    break;
            case 48:exit(0); //�˳���Ϸ 
		    default:continue;  
	    } 
		if(s2[1][0]==2)   //�����յ� 
		{
            printf("\n\t------------------you are great!--------------------\n\n\n");
            s2[1][0]=3;  //������㼰�յ� 
            s2[18][19]=2; 
		    menu();
	    }
    }while(1);
} 

int	bfs()
{
	pos	cur, nex;
	cur.a = fa;
	cur.b = fb;
	cur.steps = 0;
	memset(cur.Mapp, 0, sizeof(cur.Mapp));
	cur.Mapp[cur.a][cur.b] = 1; 	//��ʼ��������� 
	queue<pos>qu;
	qu.push(cur);
	vis[cur.a][cur.b] = 1;
	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		if (cur.a == aa && cur.b == ab)
		{
			memcpy(Mappp, cur.Mapp, sizeof(cur.Mapp));
			return	cur.steps;
		}
		for (int i = 0; i < 4; i++)
		{
			nex.a = cur.a + dir[i][0];
			nex.b = cur.b + dir[i][1];
			nex.steps = cur.steps + 1;
			memcpy(nex.Mapp, cur.Mapp, sizeof(cur.Mapp));
			nex.Mapp[nex.a][nex.b] = 1;
			if (vis[nex.a][nex.b] == 0 && judge(nex.a, nex.b))
			{
				
				vis[nex.a][nex.b] = 1;
				qu.push(nex);
			}
		}
	}
	return	inf;
}
int	judge(int	a, int	b)
{
	if (a < 0 || a >= m || b < 0 || b >= n)
		return	0;
	return	1;
}

void	menu2()
{
	memset(Map, 0, sizeof(Map));
	memset(vis, 0, sizeof(vis));
	cout << "�������Թ�(X*Y)��X��Yֵ" << endl;
	cin >> m >> n;
	cout << "�������������Ƶ��Թ�(.����·#����ǽ)" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];
	cout << "��������ʼλ�õ�����(��0��ʼ)" << endl;
	cin >> fa >> fb;
	cout << "�������յ���ڵ�����(��0��ʼ�ҳ���Ψһ)" << endl;
	cin >> aa >> ab;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Map[i][j] == '#')
				vis[i][j] = 1;
		}
	}//�Ե�ͼ���б��
	result = bfs();//���й���������� 
	if (result == inf)
		cout << "�޷��߳��Թ�" << endl;
	else
		cout << "�߳��Թ�������Ҫ" << result << "��" << endl;
	cout << "�߳��Թ��ķ�ʽ����ͼ" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Mappp[i][j] == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}
