#include<bits/stdc++.h>
using	namespace	std;

template<class	T>
struct	Node{
	T	data;
	struct	Node<T>*next;
};

template<class	T>
class	Linklist
{
	public:
		Linklist(){front=new	Node<T>;front->next=NULL;}
		Linklist(T	a[],int	n);//无参构造函数 
		template <class Type>	friend	void	merge(Linklist<Type>&link1,Linklist<Type>&link2,Linklist<Type>&link3);//合并函数
		void	Printlist();
		~Linklist();
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
void	Linklist<T>::Printlist()
{
	Node<T>*s = front->next;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}


template<class	T>
void	merge(Linklist<T>&link1,Linklist<T>&link2,Linklist<T>&link3)//合并函数
{
	Node<T>*p = link1.front->next;
	Node<T>*q = link2.front->next;
	Node<T>*r = link3.front->next;
	while(p!=NULL&&q!=NULL)
	{
	
		if(p->data<q->data)
		{
			r->data=p->data;
			r=r->next;
			p=p->next;
		}
		else
		{
			r->data=q->data;
			r=r->next;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		r->data=p->data;
		r=r->next;
		p=p->next;
	}
	while(q!=NULL)
	{
		r->data=q->data;
		r=r->next;
		q=q->next;
	}
}

template<class	T>
Linklist<T>::~Linklist()
{
	Node<T>*p=front;
	while (p)
	{
		Node<T>* q = p;
		p = p->next;
		delete q;
		q = NULL;
	}

}

	
	
	
