#include<iostream>
#include"CircleQueue.h"
using	namespace	std;
int	main()
{
	int	arr[10]={2,0,2,2,0,4,0,1};
	CircleQueue<int>qu;
	for(int	i=0;i<8;i++)
		qu.EnQueue(arr[i]);
	cout<<"进队后队列为："<<endl;
	qu.Print();
	cout<<endl;
	
	for(int	i=0;i<4;i++)
		qu.DeQueue();
	cout<<"四位出队后结果为"<<endl;
	qu.Print();
	cout<<endl;
	
	cout<<"队长度为："<<endl;
	cout<<qu.GetLength()<<endl;
	
	qu.Delete();
	cout<<"置空队后"<<endl;
	qu.Print();
}
