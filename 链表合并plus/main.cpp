#include<iostream>
#include<algorithm>
#include"Linklist.h"
#include<bits/stdc++.h>
using	namespace	std;
bool	cmp(int	a,int	b)
{
	return	a<b;
}
int	a[10001], b[10001];
int	c[10001];

int	main()
{
	int	n1, n2;
	memset(c, 0, sizeof(c));
	cout << "请输入链表一数据元素的长度" << endl;
	cin >> n1;
	cout << "请输入链表一中的数据" << endl;
	for (int i = 0; i < n1; i++)
		cin >> a[i];
	cout << "请输入链表二数据元素的长度" << endl;
	cin >> n2;
	cout << "请输入链表二中的数据" << endl;
	for (int i = 0; i < n2; i++)
		cin >> b[i];
	sort(a, a + n1,cmp);
	sort(b, b + n2,cmp);
	Linklist<int>link1(a, n1);
	Linklist<int>link2(b, n2);
	Linklist<int>link3(c, n1 + n2);
	merge(link1, link2, link3);
	cout << "链表1：" << endl;
	link1.Printlist();
	cout << "链表2：" << endl;
	link2.Printlist();
	cout << "合并链表为：" << endl;
	link3.Printlist();
}

