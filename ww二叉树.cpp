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
		cout << "不存在" << endl;
	return NULL;
	if (R->data == key)
		return R;
	if (key < R->data)
		return  search(R->lch, key);
	if (key > R->data)
		return search(R->rch, key);
}

void insert(binode*&R, binode *s)//R 为根节点，s为新节点
{
	if (R == NULL)
		R = s;
	else if (s->data < R->data)
		insert(R->lch, s);//插入左子树
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
		insert(R, s);//插入
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
	cout << "请输入你要查找的内容：" << endl;
	int a, c, q;
	cin >> a;
	binode *R;
	R=search(root, a);
	if (R->lch != NULL)
	{
		cout << "该数据结点左孩子为：" << R->lch->data;
	}
	if (R->rch != NULL)
	{
		cout << "该数据结点右孩子为：" << R->rch->data;
	}
	if (R->lch == NULL && R->rch == NULL)
	{
		cout << "该数据结点为叶子结点。";
	}
	cout << endl << "请输入你要插入数据：" << endl;
	cin >> q;
	binode *w = new binode;
	w->data = q;
	insert(root, w);
	cout << "请输入你要删除的内容：" << endl;
	cin >> c;
	Deletedata(root, c);
	cout << "已删除" << c << endl;
	cout << "销毁平衡二叉树" << endl;
}

