#include<iostream>
#include<algorithm>
#include<stack>
using	namespace	std;
#define	MAXSIZE	10
struct	ArcNode {
	int	adjvex;//数据域，邻接顶点下标
	ArcNode	*nextarc;//指针域，指向下一条弧结点 (疑教材有误） 
};//弧结点 
struct	VertexNode {
	char	vertex;//数据域，顶点信息 
	ArcNode	*firstarc;//指针域：指向第一条弧 
};//顶点结点 



template<class	T>class	ALGraph
{
public:
	ALGraph();
	//~ALGraph();
	//void	DFS(int	v);
	//void	BFS(int	v);
	void	staDFS(int v);
	void	insert(int start, int	end);//将每一条路插入进邻接表里 
	void	print();
private:
	VertexNode	adjlist[MAXSIZE];//结点 
	int	vNum, arcNum;//顶点数目和弧的数目 
};


template<class	T>
ALGraph<T>::ALGraph()
{
	int	n, m;
	int	start, end;
	cout << "请输入你所要构建的图的顶点数目和边的数目" << endl;
	cin >> n >> m;
	vNum = n;
	arcNum = m;
	cout << "请依次输入各顶点的值" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> adjlist[i].vertex;
		adjlist[i].firstarc = NULL;
	}
	cout << "请输入每条边的两个顶点" << endl;
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
	}//当头结点是孤岛时的情况，做直接连接 
	else
	{
		ArcNode	*Node = new ArcNode;
		Node->adjvex = end;
		Node->nextarc = adjlist[start].firstarc;
		adjlist[start].firstarc = Node;
	}//当头节点已经有路的时候，做链表插入 
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
	int	vis[vNum+1];//标记是否访问 
	stack<int>s;
	s.push(v);
	while(s.empty()!=1)//当栈非空时 
	{
		ArcNode	*Node=adjlist[s.top()].firstarc;
		while(Node)//不是空结点时，向后推进 
		{
			int	npop=0;//判断是否弹出栈顶，1时弹出 
			if(vis[Node->adjvex]==0)//该结点还没有被访问过
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
	}//以加入或弹出为单独一次操作 
	cout<<endl;
}







