#include<bits/stdc++.h>
#include"Seplist.h"
using	namespace	std;
int	main()
{
	//template<class	T,int	N>
	int	a[]={2,0,0,3,0,7,1,4,2,3};
	Seplist<int,100>Sep(a,10);
	//Sep(a,100);
	cout<<"顺序表长度为："<<Sep.Getlength()<<endl;
	return	0;
}
