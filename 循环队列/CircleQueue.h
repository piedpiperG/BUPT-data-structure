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
void CircleQueue<T>::EnQueue(T x)//���
{
	if ((rear + 1) % QueueSize == front)
		throw"overflow";
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}
template<class T>
T CircleQueue<T>::DeQueue()//����
{
	if (rear == front)
		throw"underflow";
	front = (front + 1) % QueueSize;
	return data[front];
}
template<class T>
T CircleQueue<T>::GetFront()//���Ҷ�ͷԪ��
{
	if (rear == front)
		throw"underflow";
	return data[(front + 1) % QueueSize];
}
template<class T>
int CircleQueue<T>::GetLength()//����г���
{
	return(rear - front + QueueSize) % QueueSize;
}
template<class	T>
void	CircleQueue<T>::Delete()//�ÿն�
{
	for(int	i=0;i<QueueSize;i++)
		data[i]=0;
} 
template<class	T>
void	CircleQueue<T>::Print()//��ӡ 
{
	for(int	i=front+1;i<=rear;i++)	
		cout<<data[i]<<" ";
}
