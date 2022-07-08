
#include"Seqlist.h"
using	namespace	std;

template<class T, int N>
Seqlist<T, N>::Seqlist(T a[], int n)
{
	if (n > N)
		throw"���鳤�ȳ���˳������󳤶�";
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
		throw"�����쳣";
	if(i<1||i>=length+1)
		throw"λ���쳣";
	for(int	j=length;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=x;
	length++;
}
template<class T, int N>
T Seqlist<T, N>::Delete(int i)
{
	if (0 == length)
		throw"�����쳣";
		if (i<1 || i>length)
			throw"λ���쳣";
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
		throw"����λ�÷Ƿ�";
	return data[i - 1];
}

