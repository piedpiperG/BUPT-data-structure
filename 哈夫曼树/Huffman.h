#include<iostream>
#include<algorithm>
using	namespace	std;
#define	manum	0x3f3f3f3f
struct	HNode
{
	int	weight;//结点权值
	int	parent;//双亲数组下标
	int	LChild;//左孩子数组下标	
	int	RChild;//右孩子数组下标 
};//每个结点的结构体 

struct	HCode
{
	char	data;//存储节点的内存 
	string	code;//存储结点对应的编码 
};//记录每个节点的编码 

class	Huffman
{
private:
	HNode*HTree;//哈夫曼树节点 
	HCode*HCodeTable;//存储编码表 
	int	N;//叶子节点数量 
	void	code(int	i, string	newcode);//递归函数，对第i个节点编码
public:
	Huffman() {
		HTree = new	HNode;	HCodeTable = new	HCode;	N = 0;
	};
	void	CreateHTree(int	a[], int	n, char	name[]);//构建哈夫曼树
	void	CreateCodeTable();//创建编码表
	void	Encode(string	s, char	*d);//编码 
	void	Decode(char	*s, char	*d);//解码
	~Huffman();//析构函数 
	void	SelectMin(int	&x, int	&y, int	a, int	b);//辅助搜索最小值函数 
	void	Printeach(int	retime);//打印每一个字母对应的编码 
};//类的定义


/****************************类的成员函数的实现*/
//辅助函数，搜索数列中最小的两个结点值

void	Huffman::SelectMin(int	&x, int	&y, int	a, int	b)
{
	//cout << a << " " << b << endl;
	//cout << HTree[b - 1].weight << endl;
	int	m = manum, n = manum;//最小的两个数 
	for (int i = a; i < b; i++)
	{
		if (HTree[i].weight < m)
		{
			m = HTree[i].weight;
			x = i;
		}
	}
	for (int i = a; i < b; i++)
	{
		if (HTree[i].weight < n&&HTree[i].weight != HTree[x].weight)
		{
			n = HTree[i].weight;
			y = i;
		}
	}
}


//构造哈夫曼树 
//a[]存储每种字符的权值，n为字符的种类,name为各个字符的内容 
void	Huffman::CreateHTree(int	a[], int	n, char	name[])
{
	N = n;
	HCodeTable = new	HCode[N];
	HTree = new	HNode[2 * N - 1];//2*n-1为总结点个数
	for (int i = 0; i < N; i++)
	{
		HTree[i].weight = a[i];
		HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;
		HCodeTable[i].data = name[i];
	}
	int	x, y;
	for (int i = n; i < 2 * N - 1; i++)//开始构建哈夫曼树
	{
		SelectMin(x, y, 0, i);//从1~i中选出两个权值最小的结点
		//cout << "x=" << x <<" "<<HTree[x].weight<<endl;
		//cout << "y=" << y <<" "<<HTree[y].weight<<endl;
		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].LChild = x;
		HTree[i].RChild = y;
		HTree[i].parent = -1;
		HTree[x].weight = HTree[y].weight = manum;
	}
}


//生成哈夫曼对应编码 
void	Huffman::code(int	i, string	newcode)
{
	if (HTree[i].LChild == -1)
	{
		HCodeTable[i].code = newcode;
		return;
	}
	code(HTree[i].LChild, newcode + '0');
	code(HTree[i].RChild, newcode + '1');
}
void	Huffman::CreateCodeTable()//生成编码表
{
	code(2 * N - 2, "");
}


//进行编码
void	Huffman::Encode(string	s, char		*d)
{
	int	n2 = 0;//控制s的变量 
	while (s[n2] != '\0')
	{
		for (int i = 0; i < N; i++)
		{
			if (HCodeTable[i].data == s[n2])
			{
				int	k = 0;
				while (HCodeTable[i].code[k] != '\0')
					k++;
				for (int j = 0; j < k; j++)
				{
					*d = HCodeTable[i].code[j];
					d++;
				}
			}
		}
		n2++;
	}
	d--;
}

//进行解码
void	Huffman::Decode(char	*s, char	*d)
{
	while (*s != '\0')
	{
		int	parent = 2 * N - 2;//根结点在HTree的下标（有改动，原书中为2*n-2）
		while (HTree[parent].LChild != -1)//如果叶子结点不是根结点 
		{
			if (*s == '0')
				parent = HTree[parent].LChild;
			else
				parent = HTree[parent].RChild;
			s++;
		}
		*d = HCodeTable[parent].data;
		d++;
	}
}


//打印函数，打印每一个字符的编码
void	Huffman::Printeach(int	retime)
{
	cout << "每一个字符对应的编码如下：" << endl;
	for (int i = 0; i < retime; i++)
	{
		cout << "i=" << i << " " << HCodeTable[i].data << " " << HCodeTable[i].code << endl;
	}
}


//析构函数
Huffman::~Huffman()
{
	N=0;
	HTree=NULL;
	HCodeTable=NULL;		
} 






