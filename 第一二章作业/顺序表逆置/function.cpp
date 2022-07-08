
#include"Seqlist.h"
using	namespace	std;

template<class T, int N>
Seqlist<T, N>::Seqlist(T a[], int n)
{
	if (n > N)
		throw"数组长度超过顺序表的最大长度";
		for (int i = 0; i < n; i++)
			data[i] = a[i];
	length = n;
}
template<class T, int N>
void Seqlist<T, N>::Printlist()
{
	for (int i = 0; i < length; i++)
		cout<<data[i]<<" ";
	cout<<endl;
}
template<class	T,int	N>
void	Seqlist<T,N>::Insert(int	i,T	x)
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
template<class T, int N>
T Seqlist<T, N>::Delete(int i)
{
	if (0 == length)
		throw"下溢异常";
		if (i<1 || i>length)
			throw"位置异常";
			T x = data[i - 1];
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}
template<class T, int N>
T Seqlist<T, N>::Get(int i)
{
	if (i<1 || i>length)
		throw"查找位置非法";
	return data[i - 1];
}

