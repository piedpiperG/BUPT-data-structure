#include<bits/stdc++.h>
#include"Linklist.h"
//逆置算法
template<class	T>
void	Linklist<T>::reverse()

{
    Node<T>*p,*q;
    if(front->next&&front->next->next)
    {
    	p=front->next;
    	q=p->next;
    	p->next=NULL;
    	while(q)
    	{
    		p=q;
    		q=q->next;
    		p->next=front->next;
    		front->next=p;
		}
	}	
}

using	namespace	std;
int	main()
{
	int	a[10]={2,0,0,3,0,7,1,4};
	Linklist<int>list(a,8);
	cout<<"初始表：";
	list.Printlist();
	cout<<endl;
	list.reverse();
	cout<<"逆置表："; 
	list.Printlist();
}
