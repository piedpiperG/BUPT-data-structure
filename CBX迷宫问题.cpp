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
int	main()
{
	memset(Map, 0, sizeof(Map));
	memset(vis, 0, sizeof(vis));
	cout << "�������Թ�(X*Y)��X��Yֵ" << endl;
	cin >> m >> n;
	cout << "�������������Ƶ��Թ�(.����·#����ǽ)" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];
	cout << "������������ʼλ�õ�����(��0��ʼ)" << endl;
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
		cout << "�����޷��߳��Թ�" << endl;
	else
		cout << "�����߳��Թ�������Ҫ" << result << "��" << endl;
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
