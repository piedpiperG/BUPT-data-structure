#include <iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
template<class T>
struct Node {
	T data;
	struct Node*next;
};
template<class T>
class LinkList {
public:
	LinkList(T a[], int n);//使用数组初始化	、头插
	int GetLength();//获取长度
	void destory(LinkList<T> * T);
	void LinkList2(T b[], int m);//尾插
	int Get(int i);//获取第i个
	int Locate(T x);//查找第x个
	void Insert(int i, T x);//在第i个插入x
	T Delete(int i);//删除第i个
private:
	Node<T>*first;//定义头指针
};
template<class T>
LinkList< T >::LinkList(T a[], int n)//头插法
{
	first = new Node<T>;
	first->next = NULL;//构造空链表
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T> * s = new Node<T>;//建立新结点	
		s->data = a[i];//把a【i】写入
		s->next = first - next;//修改新指针
		first->next = s;//修改头结点的指针域
	}
}
template<class T>
void LinkList< T >::LinkList2(T b[], int m)//尾插法
{
	first = new Node<T>;
	Node<T>*r = first;
	for (int i = 0; i < m; i++)
	{
		Node<T> * s = new Node<T>;
		s->data = b[i];
		r->next = s;
		r = s;
		r->next = NULL;
	}
}
template<class T>
void LinkList< T >::Insert(int i, T x)//插入
{
	Node<T>*p = first;
	if (i != 1)p = Get(i - 1);
	if (p) {
		Node<T>*s = new Node <T>;
		s->date = x;
		s->next = p->next;
		p->next = s;
	}
	else throw "插入位置错误";
}
template<class T>
T LinkList<T>::Delete(int i)//删除
{
	Node<T>*p = first;
	if (i != 1)p = Get(i - 1);
	Node<T>*q = p->next;
	T x = q->data;
	delete q;
}
template<class T>
int LinkList<T>::Get(int i)//按顺序查找
{
	Node<T>*p = first->next;
	int j = 1;
	while (p&&j != 1)
	{
		p = p->next;
		j++;
	}
	return p;
}
template<class T>
int LinkList<T>::GetLength()//获取长度
{
	int n = 0;
	LinkList *p;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return(n);
}
template<class T>
void LinkList<T>::destory(LinkList<T>*first)//销毁
{
	LinkList *f = first;
	while (first)
	{
		f = first;
		first = first->next;
		free(f);
	}
	free(first);
}
template<class T>
int main()
{

	int n, q, c, a, b, d, e,x;
	cout << "请输入链表长度" << endl;
	while (cin >> n)
	{
		Node* first;
		first = (Node*)malloc(sizeof(Node));
		cout << "请输入" << n << "个数据存入链表\n";
		first = create(T, n);
		cout << "请输入你要进行的操作:" << endl;
		cout << "1.输出链表" << endl;
		cout << "2.删除链表第q个位置的数据" << endl;
		cout << "3.输入一个数据插入到第q个位置" << endl;
		cout << "4.查找某个元素所在节点的位置" << endl;
		cout << "5.获取链表长度" << endl;
		cout << "6.销毁" << endl;
	}
	cin >> q >> endl;
	linked_list* h = first;
	if (q ==1)
	{
		h = first;
		LinkList<T>::LinkList (T a[n], int n)
			while (h)
			{
				cout << h->data << " ";
				h = h->next;
			}
		cout <<  endl << "你还要进行什么操作？" << endl;
	}
	else if (q == 2)
	{
		cout << "请输入你要删除的位置:";
		cin >> c;
		T LinkList<T>::Delete(int c)
		cout << "你已删除第" << c << "位置的数据";
		n--;
	}
	else if (q == 3)
	{
		cout << "请输入你要插入的位置和数值:";
		cin >> a>>x;
		void LinkList< T >::Insert(int a, T x)
			n++;
	}
	else if (q == 4)
	{
		cout << "请输入你要查找的元素是第几个";
		cin >> d;
		int LinkList<T>::Get(int d)
			cout >> p;
	}
	else if (q == 5)
	{
		int LinkList<T>::GetLength()
			cout >>"长度为"<< n;
	}
	else if (q == 6)
	{
		void LinkList<T>::destory(LinkList*first)
	}
}
