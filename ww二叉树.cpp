#include<stack>
#include<iostream>
using namespace std;
class binode
{
public:
	int data;
	binode *lch;
	binode *rch;
	binode() : lch(NULL), rch(NULL) {};
};

binode*search(binode *R, int key)
{
	if (R == NULL)
		cout << "������" << endl;
	return NULL;
	if (R->data == key)
		return R;
	if (key < R->data)
		return  search(R->lch, key);
	if (key > R->data)
		return search(R->rch, key);
}

void insert(binode*&R, binode *s)//R Ϊ���ڵ㣬sΪ�½ڵ�
{
	if (R == NULL)
		R = s;
	else if (s->data < R->data)
		insert(R->lch, s);//����������
	else
		insert(R->rch, s);
}
binode*create(int r[], int n)
{
	binode*R = new binode;
	R = NULL;
	for (int i = 0; i < n; i++)
	{
		binode*s = new binode ;
		s->data = r[i];
		insert(R, s);//����
	}
	return R;
}
void Delete(binode*&R)
{
	binode*q = new binode;
	binode*s = new binode;
	if (R->lch == NULL)
	{
		q = R;
		R = R->rch;
		delete q;
	}
	else if (R->rch == NULL)
	{
		q = R;
		R = R->lch;
		delete q;
	}
	else
	{
		q = R; s = R->lch;
		while (s->rch != NULL)
		{
			q = s;
			s = s->rch;
		}
		R->data = s->data;
		if (q != R)
			q->rch = s->lch;
		else
			R->lch = s->lch;
		delete s;
	}
}
bool Deletedata(binode*&R, int key)
{
	if (R == NULL)
		return 0 ;
	else
	{
		if ( R->data== key)
		{
			Delete(R);
		}
		else if (key < R->data)
	 Deletedata(R->lch, key);
		else (key > R->data);
		return Deletedata(R->rch, key);
	}
}
void deleteall(binode*&R, int data[], int n)
{
	for (int i = 0; i < n; i++)
	{
		Deletedata(R, data[i]);
	}
}



int main()
{
	int tr[100] = {1,2,3,4,5,6,7 };
	binode *root;
	root = NULL;
	root = create(tr, 7);
	cout << "��������Ҫ���ҵ����ݣ�" << endl;
	int a, c, q;
	cin >> a;
	binode *R;
	R=search(root, a);
	if (R->lch != NULL)
	{
		cout << "�����ݽ������Ϊ��" << R->lch->data;
	}
	if (R->rch != NULL)
	{
		cout << "�����ݽ���Һ���Ϊ��" << R->rch->data;
	}
	if (R->lch == NULL && R->rch == NULL)
	{
		cout << "�����ݽ��ΪҶ�ӽ�㡣";
	}
	cout << endl << "��������Ҫ�������ݣ�" << endl;
	cin >> q;
	binode *w = new binode;
	w->data = q;
	insert(root, w);
	cout << "��������Ҫɾ�������ݣ�" << endl;
	cin >> c;
	Deletedata(root, c);
	cout << "��ɾ��" << c << endl;
	cout << "����ƽ�������" << endl;
}

