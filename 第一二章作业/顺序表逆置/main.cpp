#include<iostream>
#include"Seqlist.h"
#include<string>
using namespace std;
int	main()
{
	int	a[10]={2,0,0,3,0,7,1,4};
	Seqlist<int,100>Seq(a,8);
	cout<<"��ȡ˳����ȣ�"<<endl;
	cout<<Seq.Getlength()<<endl;
	cout<<"������ӡ˳���"<<endl;
	Seq.Printlist();
	cout<<"�ڵڶ���λ�ò�������9"<<endl;
	Seq.Insert(2,9);
	Seq.Printlist();
	cout<<"ɾ������������"<<endl;
	Seq.Printlist();
	cout<<"��ȡ�����Ԫ�ص�ֵ"<<endl;
	cout<<Seq.Get(5)<<endl; 
}

