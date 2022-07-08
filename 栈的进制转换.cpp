#include<iostream>
#include<stack>
using	namespace	std;
int	main()
{
	int	n;
	int	m;
	while(1)
	{
		stack<int>is;
		cout<<"请输入你要进行转换的十进制数"<<endl;
		cin>>n;
		cout<<"请输入你想将它转换为几进制数"<<endl;
		cin>>m;
		int	x=1;
		int	y; 
		while(x>0)
		{
			x=n/m;
			y=n%m;
			is.push(y);
			n=x;
		}
		cout<<"转换结果为："<<endl;
		while(is.empty()!=1)
		{
			cout<<is.top();
			is.pop();
		}
		cout<<endl;
	}
	
}
