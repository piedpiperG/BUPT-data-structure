#include<iostream>
#include<algorithm>
using	namespace	std;
#define	manum	0x3f3f3f3f
struct	HNode
{
	int	weight;//���Ȩֵ
	int	parent;//˫�������±�
	int	LChild;//���������±�	
	int	RChild;//�Һ��������±� 
};//ÿ�����Ľṹ�� 

struct	HCode
{
	char	data;//�洢�ڵ���ڴ� 
	string	code;//�洢����Ӧ�ı��� 
};//��¼ÿ���ڵ�ı��� 

class	Huffman
{
private:
	HNode*HTree;//���������ڵ� 
	HCode*HCodeTable;//�洢����� 
	int	N;//Ҷ�ӽڵ����� 
	void	code(int	i, string	newcode);//�ݹ麯�����Ե�i���ڵ����
public:
	Huffman() {
		HTree = new	HNode;	HCodeTable = new	HCode;	N = 0;
	};
	void	CreateHTree(int	a[], int	n, char	name[]);//������������
	void	CreateCodeTable();//���������
	void	Encode(string	s, char	*d);//���� 
	void	Decode(char	*s, char	*d);//����
	~Huffman();//�������� 
	void	SelectMin(int	&x, int	&y, int	a, int	b);//����������Сֵ���� 
	void	Printeach(int	retime);//��ӡÿһ����ĸ��Ӧ�ı��� 
};//��Ķ���


/****************************��ĳ�Ա������ʵ��*/
//����������������������С���������ֵ

void	Huffman::SelectMin(int	&x, int	&y, int	a, int	b)
{
	//cout << a << " " << b << endl;
	//cout << HTree[b - 1].weight << endl;
	int	m = manum, n = manum;//��С�������� 
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


//����������� 
//a[]�洢ÿ���ַ���Ȩֵ��nΪ�ַ�������,nameΪ�����ַ������� 
void	Huffman::CreateHTree(int	a[], int	n, char	name[])
{
	N = n;
	HCodeTable = new	HCode[N];
	HTree = new	HNode[2 * N - 1];//2*n-1Ϊ�ܽ�����
	for (int i = 0; i < N; i++)
	{
		HTree[i].weight = a[i];
		HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;
		HCodeTable[i].data = name[i];
	}
	int	x, y;
	for (int i = n; i < 2 * N - 1; i++)//��ʼ������������
	{
		SelectMin(x, y, 0, i);//��1~i��ѡ������Ȩֵ��С�Ľ��
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


//���ɹ�������Ӧ���� 
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
void	Huffman::CreateCodeTable()//���ɱ����
{
	code(2 * N - 2, "");
}


//���б���
void	Huffman::Encode(string	s, char		*d)
{
	int	n2 = 0;//����s�ı��� 
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

//���н���
void	Huffman::Decode(char	*s, char	*d)
{
	while (*s != '\0')
	{
		int	parent = 2 * N - 2;//�������HTree���±꣨�иĶ���ԭ����Ϊ2*n-2��
		while (HTree[parent].LChild != -1)//���Ҷ�ӽ�㲻�Ǹ���� 
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


//��ӡ��������ӡÿһ���ַ��ı���
void	Huffman::Printeach(int	retime)
{
	cout << "ÿһ���ַ���Ӧ�ı������£�" << endl;
	for (int i = 0; i < retime; i++)
	{
		cout << "i=" << i << " " << HCodeTable[i].data << " " << HCodeTable[i].code << endl;
	}
}


//��������
Huffman::~Huffman()
{
	N=0;
	HTree=NULL;
	HCodeTable=NULL;		
} 






