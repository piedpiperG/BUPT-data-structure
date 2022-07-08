#include<bits/stdc++.h>
#include"Seplist.h"
using	namespace	std;

template<class	T,int	N>
Seplist<T,N>::Seplist(T	a[],int	n)
{
	if(n>N)
		throw"数组长度超过顺序表最大长度";
	for(int	i=0;i<n;i++)
		data[i]=a[i];
	length=n; 
}

template<class	T,int	N>
void	Seplist<T,N>::PrintList()
{
	cout<<"按序号扫描线性表各个数据的元素："<<endl;
	for(int	i=0;i<length;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}

template<class	T,int	N>
void	Seplist<T,N>::Insert(int	i,T	x)
{
	if(length>=N)
		throw"上溢异常";
	if(i<1||i>=length+1)
		throw"位置异常";
	for(int	j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;
}

template<class	T,int	N>
T	Seplist<T,N>::Delete(int	i)
{
	if(length==0)
		throw"下溢异常";
	if(i<1||i>length)
		throw"位置异常";
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
		throw"查找位置非法";
	return	data[i-1];	
} 

template<class	T,int	N>
int	Seplist<T,N>::Locate(T	x)
{
	for(int	i=0;i<length;i++)
		if(data[i]==x)
			return	i++;
	return	0;//查找失败 			
}



