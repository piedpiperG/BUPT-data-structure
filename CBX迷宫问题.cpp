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
int	main()
{
	memset(Map, 0, sizeof(Map));
	memset(vis, 0, sizeof(vis));
	cout << "请输入迷宫(X*Y)的X和Y值" << endl;
	cin >> m >> n;
	cout << "请输入你所绘制的迷宫(.代表路#代表墙)" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];
	cout << "请输入老鼠起始位置的坐标(从0开始)" << endl;
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
		cout << "老鼠无法走出迷宫" << endl;
	else
		cout << "老鼠走出迷宫至少需要" << result << "步" << endl;
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
	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << Mappp[i][j] << " ";
		}
		cout << endl;
	}*/

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
