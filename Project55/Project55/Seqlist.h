#include<iostream>
using	namespace	std;

template<class	T, int	N>
class	Seqlist
{
public:
	Seqlist(T	a[], int	n);
	void	Printlist();
	template <class Type, int	NN> friend	void	reverse(Seqlist<Type, NN>&list1);
private:
	T	data[N];
	int	length;
};

template<class	T, int	N>
Seqlist<T,N>::Seqlist(T	a[], int	n)
{
	if (n > N)
		throw"数组长度超过顺序表最大长度";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}

template<class	T, int	N>
void	Seqlist<T, N>::Printlist()
{
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}