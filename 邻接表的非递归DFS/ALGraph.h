#include<iostream>
#include<algorithm>
#include<stack>
using	namespace	std;
#define	MAXSIZE	10
struct	ArcNode {
	int	adjvex;//�������ڽӶ����±�
	ArcNode	*nextarc;//ָ����ָ����һ������� (�ɽ̲����� 
};//����� 
struct	VertexNode {
	char	vertex;//�����򣬶�����Ϣ 
	ArcNode	*firstarc;//ָ����ָ���һ���� 
};//������ 



template<class	T>class	ALGraph
{
public:
	ALGraph();
	//~ALGraph();
	//void	DFS(int	v);
	//void	BFS(int	v);
	void	staDFS(int v);
	void	insert(int start, int	end);//��ÿһ��·������ڽӱ��� 
	void	print();
private:
	VertexNode	adjlist[MAXSIZE];//��� 
	int	vNum, arcNum;//������Ŀ�ͻ�����Ŀ 
};


template<class	T>
ALGraph<T>::ALGraph()
{
	int	n, m;
	int	start, end;
	cout << "����������Ҫ������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ" << endl;
	cin >> n >> m;
	vNum = n;
	arcNum = m;
	cout << "����������������ֵ" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> adjlist[i].vertex;
		adjlist[i].firstarc = NULL;
	}
	cout << "������ÿ���ߵ���������" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> start >> end;
		insert(start, end);
		insert(end, start);
	}
}

//template<class	T>
//void	ALGraph<T>::DFS(int	v)
//{
//	int	visited[MAXSIZE];
//	memset(visited, 0, sizeof(visited));
//	cout << adjlist[v].vertex << endl;
//	visited[v] = 1;
//	ArcNode	*p = adjlist[v].firstarc;
//	while (p)
//	{
//		int	j = p->adjvex;
//		if (visited[j] == 0)
//			DFS(j);
//		p = p->nextarc;
//	}
//}


template<class	T>
void	ALGraph<T>::insert(int	start, int	end)
{
	
	

	if (adjlist[start].firstarc == NULL)
	{
		ArcNode	*Node = new ArcNode;
		Node->adjvex = end;
		adjlist[start].firstarc = Node;
		Node->nextarc = NULL;
	}//��ͷ����ǹµ�ʱ���������ֱ������ 
	else
	{
		ArcNode	*Node = new ArcNode;
		Node->adjvex = end;
		Node->nextarc = adjlist[start].firstarc;
		adjlist[start].firstarc = Node;
	}//��ͷ�ڵ��Ѿ���·��ʱ����������� 
}


template<class	T>
void	ALGraph<T>::print()
{
	for (int i = 1; i <= vNum; i++)
	{
		ArcNode	*Node = adjlist[i].firstarc;
		cout << adjlist[i].vertex << "->";
		while (Node)
		{
			cout << Node->adjvex << "->";
			Node = Node->nextarc;
		}
		cout << endl;
	}
}


template<class	T>
void	ALGraph<T>::staDFS(int	v)
{
	int	vis[vNum+1];//����Ƿ���� 
	stack<int>s;
	s.push(v);
	while(s.empty()!=1)//��ջ�ǿ�ʱ 
	{
		ArcNode	*Node=adjlist[s.top()].firstarc;
		while(Node)//���ǿս��ʱ������ƽ� 
		{
			int	npop=0;//�ж��Ƿ񵯳�ջ����1ʱ���� 
			if(vis[Node->adjvex]==0)//�ý�㻹û�б����ʹ�
			{
				s.push(Node->adjvex);
				npop=1;
				break;
			}
		}
		if(npop)
		{
			cout<<adjlist[s.top()].vertex<<" ";
			s.pop();
		}
	}//�Լ���򵯳�Ϊ����һ�β��� 
	cout<<endl;
}







