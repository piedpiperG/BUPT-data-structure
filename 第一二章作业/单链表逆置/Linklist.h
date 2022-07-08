#include<bits/stdc++.h>
using	namespace	std;
template<class	T>
struct	Node
{
	T	data;
	struct	Node<T>*next;
};

template<class	T>
class	Linklist
{
	public:
		Linklist(){front=new	Node<T>;front->next=NULL;}//无参构造函数
		Linklist(T	a[],int	n);//有参构造函数
		void	Printlist();
		~Linklist();
		void	reverse();
	private:
		Node<T>*front;
};

template<class	T>
Linklist<T>::Linklist(T	a[],int	n)
{
	front=new	Node<T>;
	Node<T>*r=front;
	for(int	i=0;i<n;i++)
	{
		Node<T>*s=new	Node<T>;
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

template<class	T>
Linklist<T>::~Linklist()
{
	Node<T>*p=front;
	while (p)
	{
		Node<T>*q=p;
		p=p->next;
		delete q;
		q=NULL;
	}

}

template<class	T>
void	Linklist<T>::Printlist()
{
	Node<T>*s=front->next;;
	while(s!=NULL)
	{
		cout<<s->data<<" ";
		s=s->next;
	}
}
