//  走迷宫程序，共有2种难度 
#include <stdio.h>
#include <stdlib.h>

//插入代码段************************************* 
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<string.h>
using	namespace	std;
#define	inf	0x3f3f3f3f
#define	size	205
int		m, n;//行纵
char	Map[size][size];//记录地形 
int		vis[size][size];//记录是否走过 
int		Mappp[size][size];//最终走出方式 
int		fa, fb;// 老鼠所在坐标 
int		result;//所需要的最小步数 
int		aa, ab;// 终点坐标 
int 	dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };	//移动指示坐标 
struct pos
{
	int a, b, steps;//横纵坐标，步数 
	int	Mapp[size][size];//记录走出方式 
};//状态量 
int	bfs();//进行运算 
int	judge(int	a, int	b);//判断所在点是否出边界，出界返回0，未出界返回1 
void	menu2();
//插入代码段************************************* 

//定义了通过控制台进行数据输入和输出的函数，主要是通过键盘进行的操作，如getch()
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
//2种迷宫画图函数 
void draw1(void);
void draw2(void);
 
//控制函数
void control1(void);
void control2(void); 
//菜单函数
void menu(void);
//移动后位置交换函数
void move(int *i,int *j); 

//主函数 
int main()
{
	while(1)
	{
	
		int	Swit;
		printf("~~~~~~~~~~~~~~~~~~~~~~~人机对战-迷宫小游戏~~~~~~~~~~~~~~~~~~~~~~~\n");
		cout<<"你有两种选择，自己设计迷宫交由电脑作答；或者是电脑设计迷宫，自己解答"<<endl;
		cout<<"给电脑设计迷宫请按1，自己走迷宫请按2，退出游戏请按0"<<endl;
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

//菜单函数
void menu(void)
{
    int x; 
    printf("                      \n游戏说明\n");
    printf("~~~~~.在游戏过程中，玩家可以通过键盘方向键使小人移动，走出迷宫。\n");
    printf("~~~~~.在游戏过程中，玩家可以通过按Esc键返回游戏菜单；也可以可以按0直接退出游戏。\n");
    printf("                      1: 开始游戏\n");
    printf("                      0: 退出游戏\n");
    scanf("%d",&x); 
    switch(x)
    {
        case 1: { system("cls");
                  printf("~~~~~1.简单难度\n~~~~~2.中等难度\n~~~~~0.退出游戏\n"); 
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
//移动后位置交换函数
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
    do{  //每一次移动前找到小人的位置 
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                if(s1[i][j]==2)
                {
                    a=i;
                    b=j;
                    break; 
                }
        //接收控制         
        num=getch();
        switch(num)
        {
            case 72:if(s1[a-1][b]!=1)  //向上 
			        {
				        move(&s1[a][b],&s1[a-1][b]);
				        system("cls");
				        draw1();
				        break;
			        }
			        else continue; 
	        case 80:if(a==9) continue; //向下，如果小人站在起点处，不能使用向下键 
                    else if(s1[a+1][b]!=1)
			        {
			   	        move(&s1[a][b],&s1[a+1][b]);
				        system("cls");
			            draw1();
			            break;
			        }
			        else continue;

		    case 75:if(s1[a][b-1]!=1) //向左 
			        {   
				        move(&s1[a][b],&s1[a][b-1]);
				        system("cls");
				        draw1();
			            break;
			        }
			        else continue;
			case 77:if(s1[a][b+1]!=1) //向右 
			        {
				        move(&s1[a][b],&s1[a][b+1]);
				        system("cls");
                        draw1();
		                break;
			        } 
			        else continue;
		    case 27:system("cls"); //ESE返回菜单 
				    menu();    break;
            case 48:exit(0); //退出游戏 
		    default:continue;  
	    } 
		if(s1[0][5]==2)   //到达终点 
		{
            printf("\n\t------------------you are winner!--------------------\n\n\n");
            s1[0][5]=3;  //重置起点及终点 
            s1[9][3]=2; 
		    menu();
	    }
    }while(1);
} 

void control2(void)
{
    int a,b;
    char num;
    do{  //每一次移动前找到小人的位置 
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                if(s2[i][j]==2)
                {
                    a=i;
                    b=j;
                    break; 
                }
        //接收控制         
        num=getch();
        switch(num)
        {
            case 72:if(s2[a-1][b]!=1)  //向上 
			        {
				        move(&s2[a][b],&s2[a-1][b]);
				        system("cls");
				        draw2();
				        break;
			        }
			        else continue; 
	        case 80:if(s2[a+1][b]!=1)//向下 
			        {
			   	        move(&s2[a][b],&s2[a+1][b]);
				        system("cls");
			            draw2();
			            break;
			        }
			        else continue;

		    case 75:if(s2[a][b-1]!=1) //向左 
			        {   
				        move(&s2[a][b],&s2[a][b-1]);
				        system("cls");
				        draw2();
			            break;
			        }
			        else continue;
			case 77:if(b==19) continue;//向右，小人不能走出地图 
                    else if(s2[a][b+1]!=1) 
			        {
				        move(&s2[a][b],&s2[a][b+1]);
				        system("cls");
                        draw2();
		                break;
			        } 
			        else continue;
		    case 27:system("cls"); //ESE返回菜单 
				    menu();    break;
            case 48:exit(0); //退出游戏 
		    default:continue;  
	    } 
		if(s2[1][0]==2)   //到达终点 
		{
            printf("\n\t------------------you are great!--------------------\n\n\n");
            s2[1][0]=3;  //重置起点及终点 
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
	cur.Mapp[cur.a][cur.b] = 1; 	//初始化起点坐标 
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
	cout << "请输入迷宫(X*Y)的X和Y值" << endl;
	cin >> m >> n;
	cout << "请输入你所绘制的迷宫(.代表路#代表墙)" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];
	cout << "请输入起始位置的坐标(从0开始)" << endl;
	cin >> fa >> fb;
	cout << "请输入终点出口的坐标(从0开始且出口唯一)" << endl;
	cin >> aa >> ab;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Map[i][j] == '#')
				vis[i][j] = 1;
		}
	}//对地图进行标记
	result = bfs();//进行广度优先搜索 
	if (result == inf)
		cout << "无法走出迷宫" << endl;
	else
		cout << "走出迷宫至少需要" << result << "步" << endl;
	cout << "走出迷宫的方式如下图" << endl;
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
