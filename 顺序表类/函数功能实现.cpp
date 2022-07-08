#include<bits/stdc++.h>
#include"Seplist.h"
using	namespace	std;

template<class	T,int	N>
Seplist<T,N>::Seplist(T	a[],int	n)
{
	if(n>N)
		throw"���鳤�ȳ���˳�����󳤶�";
	for(int	i=0;i<n;i++)
		data[i]=a[i];
	length=n; 
}

template<class	T,int	N>
void	Seplist<T,N>::PrintList()
{
	cout<<"�����ɨ�����Ա�������ݵ�Ԫ�أ�"<<endl;
	for(int	i=0;i<length;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}

template<class	T,int	N>
void	Seplist<T,N>::Insert(int	i,T	x)
{
	if(length>=N)
		throw"�����쳣";
	if(i<1||i>=length+1)
		throw"λ���쳣";
	for(int	j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;
}

template<class	T,int	N>
T	Seplist<T,N>::Delete(int	i)
{
	if(length==0)
		throw"�����쳣";
	if(i<1||i>length)
		throw"λ���쳣";
	T	x=data[i-1];
	for(int	j=i;j<length;j++)
		data[j-1]=data[j];
	length--;
	return	x;
}

template<class	T,int	N>
T	Seplist<T,N>::Get(int	i)
{
	if(i<1||i>length)
		throw"����λ�÷Ƿ�";
	return	data[i-1];	
} 

template<class	T,int	N>
int	Seplist<T,N>::Locate(T	x)
{
	for(int	i=0;i<length;i++)
		if(data[i]==x)
			return	i++;
	return	0;//����ʧ�� 			
}



