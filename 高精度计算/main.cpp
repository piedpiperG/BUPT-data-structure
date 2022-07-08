#include<bits/stdc++.h>
#include"Linklist.h"
using	namespace	std;
int	NOTI=0;
struct HugeInt {
	int len;
	int num[100001];
};

HugeInt a, b, w;        //w为结果 
char c[100001], d[100001];//存储两个大整数 
bool negative;//存储正负号 

void Scan_HugeInt()
{   //读入两个大整数
	cout << "请输入第一个大数：" << endl;
	cin >> c;
	cout << "请输入第二个大数：" << endl;
	cin >> d;
	if((strlen(c) < strlen(d)) || (strlen(c) == strlen(d) && strcmp(c, d) < 0)) 
	{ //若被减数小 交换 记为负数 
		negative = true;
		swap(c, d);
	}
	a.len = strlen(c); //strlen求串长 
	b.len = strlen(d);
	for (int i = 0; i < a.len; i++) a.num[a.len - i] = c[i] - '0'; //逆序存储 
	for (int i = 0; i < b.len; i++) b.num[b.len - i] = d[i] - '0';
}

template<class	T>//加法运算 
void	Plus(Linklist<T>&link1, Linklist<T>&link2, Linklist<T>&link3)
{
	Node<T>*p = link1.front->next;
	Node<T>*q = link2.front->next;
	Node<T>*r = link3.front->next;
	while (r->next)
	{
		r->data += (p->data + q->data);
		r->next->data = r->data / 10;
		r->data%=10;
		
		r = r->next;
		p = p->next;
		q = q->next;
	}
	if(r->data!=0)
		NOTI=1;
}


template<class	T>//减法运算 
void	Minus(Linklist<T>&link1, Linklist<T>&link2, Linklist<T>&link3)
{
	Node<T>*p = link1.front->next;
	Node<T>*q = link2.front->next;
	Node<T>*r = link3.front->next;
	while(r->next)
	{
		if(p->data<q->data)
		{
			p->next->data--;
			p->data+=10;
		}
		r->data+=p->data-q->data;
		r = r->next;
		p = p->next;
		q = q->next;
	}
}



int	main()
{ 
	Scan_HugeInt();
	w.len = max(a.len, b.len);
	int	Res[20000];
	memset(Res, 0, sizeof(Res));
	Linklist<int>link1(a.num, w.len + 2);
	Linklist<int>link2(b.num, w.len + 2);
	//进行加法运算 
	Linklist<int>link3(Res, w.len + 2);//加法结果链表
	Plus(link1, link2, link3);
	cout<<"两数相加结果为：";
	/*if(NOTI)
		cout<<"1";*/
	link3.Printshow();
	//进行减法运算 
	Linklist<int>link4(Res, w.len + 2);//减法结果链表 
	Minus(link1, link2, link4);
	cout<<"两数相减结果为：";
	if(negative)
		cout<<"-";
	link4.Printshow();
	
	/*link1.Printlist();
	link2.Printlist();
	link3.Printlist();
	link4.Printlist();*/
}
