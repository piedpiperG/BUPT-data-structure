#include<iostream>
#include"CircleQueue.h"
using	namespace	std;
int	main()
{
	int	arr[10]={2,0,2,2,0,4,0,1};
	CircleQueue<int>qu;
	for(int	i=0;i<8;i++)
		qu.EnQueue(arr[i]);
	cout<<"���Ӻ����Ϊ��"<<endl;
	qu.Print();
	cout<<endl;
	
	for(int	i=0;i<4;i++)
		qu.DeQueue();
	cout<<"��λ���Ӻ���Ϊ"<<endl;
	qu.Print();
	cout<<endl;
	
	cout<<"�ӳ���Ϊ��"<<endl;
	cout<<qu.GetLength()<<endl;
	
	qu.Delete();
	cout<<"�ÿնӺ�"<<endl;
	qu.Print();
}
