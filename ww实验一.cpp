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
	LinkList(T a[], int n);//ʹ�������ʼ��	��ͷ��
	int GetLength();//��ȡ����
	void destory(LinkList<T> * T);
	void LinkList2(T b[], int m);//β��
	int Get(int i);//��ȡ��i��
	int Locate(T x);//���ҵ�x��
	void Insert(int i, T x);//�ڵ�i������x
	T Delete(int i);//ɾ����i��
private:
	Node<T>*first;//����ͷָ��
};
template<class T>
LinkList< T >::LinkList(T a[], int n)//ͷ�巨
{
	first = new Node<T>;
	first->next = NULL;//���������
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T> * s = new Node<T>;//�����½��	
		s->data = a[i];//��a��i��д��
		s->next = first - next;//�޸���ָ��
		first->next = s;//�޸�ͷ����ָ����
	}
}
template<class T>
void LinkList< T >::LinkList2(T b[], int m)//β�巨
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
void LinkList< T >::Insert(int i, T x)//����
{
	Node<T>*p = first;
	if (i != 1)p = Get(i - 1);
	if (p) {
		Node<T>*s = new Node <T>;
		s->date = x;
		s->next = p->next;
		p->next = s;
	}
	else throw "����λ�ô���";
}
template<class T>
T LinkList<T>::Delete(int i)//ɾ��
{
	Node<T>*p = first;
	if (i != 1)p = Get(i - 1);
	Node<T>*q = p->next;
	T x = q->data;
	delete q;
}
template<class T>
int LinkList<T>::Get(int i)//��˳�����
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
int LinkList<T>::GetLength()//��ȡ����
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
void LinkList<T>::destory(LinkList<T>*first)//����
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
	cout << "������������" << endl;
	while (cin >> n)
	{
		Node* first;
		first = (Node*)malloc(sizeof(Node));
		cout << "������" << n << "�����ݴ�������\n";
		first = create(T, n);
		cout << "��������Ҫ���еĲ���:" << endl;
		cout << "1.�������" << endl;
		cout << "2.ɾ�������q��λ�õ�����" << endl;
		cout << "3.����һ�����ݲ��뵽��q��λ��" << endl;
		cout << "4.����ĳ��Ԫ�����ڽڵ��λ��" << endl;
		cout << "5.��ȡ������" << endl;
		cout << "6.����" << endl;
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
		cout <<  endl << "�㻹Ҫ����ʲô������" << endl;
	}
	else if (q == 2)
	{
		cout << "��������Ҫɾ����λ��:";
		cin >> c;
		T LinkList<T>::Delete(int c)
		cout << "����ɾ����" << c << "λ�õ�����";
		n--;
	}
	else if (q == 3)
	{
		cout << "��������Ҫ�����λ�ú���ֵ:";
		cin >> a>>x;
		void LinkList< T >::Insert(int a, T x)
			n++;
	}
	else if (q == 4)
	{
		cout << "��������Ҫ���ҵ�Ԫ���ǵڼ���";
		cin >> d;
		int LinkList<T>::Get(int d)
			cout >> p;
	}
	else if (q == 5)
	{
		int LinkList<T>::GetLength()
			cout >>"����Ϊ"<< n;
	}
	else if (q == 6)
	{
		void LinkList<T>::destory(LinkList*first)
	}
}
