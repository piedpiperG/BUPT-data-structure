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
		cout<<"��������Ҫ����ת����ʮ������"<<endl;
		cin>>n;
		cout<<"���������뽫��ת��Ϊ��������"<<endl;
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
		cout<<"ת�����Ϊ��"<<endl;
		while(is.empty()!=1)
		{
			cout<<is.top();
			is.pop();
		}
		cout<<endl;
	}
	
}
