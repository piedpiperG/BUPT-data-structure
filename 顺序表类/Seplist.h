#include<bits/stdc++.h>
using	namespace	std;
template<class	T,int	N>//定义模板类，N表示顺序表最大长度，实例化时输出

class	Seplist
{
public:
	Seplist(){length=0;}//无参构造函数 
	Seplist(T	a[],int	n);//有参构造函数，使用含有n个元素的数组a初始化
	int		Getlength(){return	length;}
	void	PrintList();
	void	Insert(int	i,T	x);
	T		Delete(int	i);
	T		Get(int	i);	//按位查找 
	int		Locate(T	x);//按值查找 
private:
	T	data[N];//储存顺序表数据元素的属组 
	int	length;//顺序表长度 
};

