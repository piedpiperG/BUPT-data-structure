#include<iostream>
using namespace std;
const int QueueSize = 1000;
template<class T>
class CircleQueue
{
public:
	CircleQueue() { front = rear = 0; }
	void EnQueue(T x);
	T DeQueue();
	T GetFront();
	int GetLength();
	bool Empty() { return front == rear ? true : false; }
	void	Delete();
	void	Print();
private:
	T data[QueueSize];
	int front;
	int rear;
};
template<class T>
void CircleQueue<T>::EnQueue(T x)//入队
{
	if ((rear + 1) % QueueSize == front)
		throw"overflow";
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}
template<class T>
T CircleQueue<T>::DeQueue()//出队
{
	if (rear == front)
		throw"underflow";
	front = (front + 1) % QueueSize;
	return data[front];
}
template<class T>
T CircleQueue<T>::GetFront()//查找队头元素
{
	if (rear == front)
		throw"underflow";
	return data[(front + 1) % QueueSize];
}
template<class T>
int CircleQueue<T>::GetLength()//求队列长度
{
	return(rear - front + QueueSize) % QueueSize;
}
template<class	T>
void	CircleQueue<T>::Delete()//置空队
{
	for(int	i=0;i<QueueSize;i++)
		data[i]=0;
} 
template<class	T>
void	CircleQueue<T>::Print()//打印 
{
	for(int	i=front+1;i<=rear;i++)	
		cout<<data[i]<<" ";
}
