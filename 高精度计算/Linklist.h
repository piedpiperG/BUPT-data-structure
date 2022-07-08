#include<iostream>
using	namespace	std;
template<class	T>
struct	Node
{
	T	data;
	struct	Node<T>*prior;
	struct	Node<T>*next;
};

template<class	T>
class	Linklist
{
public:
	Linklist() { front = new	Node<T>; front = NULL; end = NULL; };
	Linklist(T	a[], int	n);//构造函数 
	void	Printlist();//打印函数
	void	Printshow();
	~Linklist();
	Node<T>*front;
	Node<T>*end;
};

template<class	T>
Linklist<T>::Linklist(T	a[], int	n)
{
	front = new Node<T>;
	end = new	Node<T>;
	Node<T>*r, *s;
	r = front;
	for (int i = 0; i < n; ++i)
	{
		s = new Node<T>;
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
		end = r;
	}
	r->next = NULL;
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
void	Linklist<T>::Printshow()
{
	Node<T>*s = end;
	int	con=0;//控制负数前的0 
	while (s->prior != front)
	{
		if(s->data!=0||con) 
		{
			cout<<s->data;
			con=1;
		}
		s = s->prior;
	}
	cout << endl;
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



