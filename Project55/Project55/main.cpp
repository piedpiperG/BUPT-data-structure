#include<iostream>
#include"Seqlist.h"
using	namespace	std;

template<class	T, int	N>
void	reverse(Seqlist<T, N>&list1)
{
	int	temp;//中间变量
	for (int i = 0, j = list1.length - 1; i <j; i++, j--)
	{
		temp = list1.data[i];
		list1.data[i] = list1.data[j];
		list1.data[j] = temp;
		//cout << list1.data[i] << " " << list1.data[j] << endl;
		//cout << i << " " << j << endl;
	}
}

int	main()
{
	int	arr[10] = { 2,0,2,2,0,3,3,1 };
	Seqlist<int, 10>list1(arr, 8);
	cout << "原顺序表：" << endl;
	list1.Printlist();

	reverse(list1);
	cout << "新顺序表：" << endl;
	list1.Printlist();
}