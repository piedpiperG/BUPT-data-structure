#include<bits/stdc++.h>
#include"Seqlist.h"
//�����㷨��
template<class	T,int	N>
void	Seqlist<T,N>::reverse()
{
	int	i=0,j=length-1;//ǰ�����
	int	temp;//���ɱ��� 
	while(i<j)
	{
		temp=data[i];
		data[i++]=data[j];
		data[j--]=temp;
	}
	
}

using namespace std;
int	main()
{
	int	a[10]={2,0,2,1,1,0,2,7};
	Seqlist<int,100>Seq(a,8);
	cout<<"˳������ݣ�"<<endl;
	Seq.Printlist();	
	Seq.reverse();
	cout<<"˳������ݣ�"<<endl;
	Seq.Printlist();
}

