#include<iostream>
#include"Seqlist.h"
#include<string>
using namespace std;
int	main()
{
	int	a[10]={2,0,0,3,0,7,1,4};
	Seqlist<int,100>Seq(a,8);
	cout<<"获取顺序表长度："<<endl;
	cout<<Seq.Getlength()<<endl;
	cout<<"遍历打印顺序表："<<endl;
	Seq.Printlist();
	cout<<"在第二个位置插入数字9"<<endl;
	Seq.Insert(2,9);
	Seq.Printlist();
	cout<<"删除第三个数字"<<endl;
	Seq.Printlist();
	cout<<"获取第五个元素的值"<<endl;
	cout<<Seq.Get(5)<<endl; 
}

